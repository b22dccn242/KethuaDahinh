#include <bits/stdc++.h>
using namespace std;

string chuanhoans(string ns){
    if(ns[1] == '/') ns.insert(0 , "0") ; 
    if(ns[4] == '/') ns.insert(3 , "0") ; 
    return ns ; 
}

class person{
protected : 
    string ten , nsdc , ns ="" , dc= ""  ;
public : 
    person(){
        ten = nsdc = "" ; 
    }
    person(string ten , string nsdc ){
        this->ten = ten ; 
        this->nsdc = nsdc ; 
    }
    void nhap(){ // phuong thuc toString 
        getline(cin , ten ) ;  
        getline(cin , nsdc ) ;  // nhap , tach ns va dc 
        for(int i=0 ; i<nsdc.size() ; i++){
            if(isdigit(nsdc[i]) || nsdc[i] == '/') {
                ns += nsdc[i] ; 
            }
            else{
                dc += nsdc[i] ; 
            }
        }
    }    
    
    void chuanhoaten(string ten){
        stringstream ss(ten) ;  
        string tmp , name = "" ;  
        while(ss >> tmp ){
            name += toupper(tmp[0]) ; 
            for(int j=1 ; j<tmp.size() ; j++){
                name += tolower(tmp[j]) ; 
            }
            name += ' ' ; 
        }
        name.pop_back() ; 
        this->ten = name ; 
    }
    
    void xuat(){
        chuanhoaten(ten) ; 
        cout << ten <<' ' << chuanhoans(ns) << ' ' << dc <<' ' ; 
    }
};

class student : public person{
private : 
    string lop ; 
    double gpa ; 
public : 
    void nhap(){
        person :: nhap() ; 
        getline(cin , lop ) ; 
        cin >> gpa ;   
    }
    void xuat(int stt){
        string tmp = to_string(stt) ; 
        while(tmp.size() < 4 ){
            tmp = "0" + tmp ;  
        }
        cout << tmp <<' ' ; 
        person :: xuat() ; 
        cout << lop <<' '<< fixed << setprecision(2) << gpa << endl ; 
    }
};


int main() {  
    int n ; cin >> n ; 
    student a[n] ; 
    for(int i=0 ; i<n ;i++){
        cin.ignore() ; 
        a[i].nhap() ; 
    }
    for(int i=0 ; i<n ; i++){
        a[i].xuat(i+1) ; 
    }
    return 0  ; 
}


