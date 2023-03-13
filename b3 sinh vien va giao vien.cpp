#include <bits/stdc++.h> 
using namespace std;

class person{
protected : 
    string ma , ten , ns , dc ; 

public : 
    person(string ma , string ten , string ns , string dc ){
        this->ma = ma ; 
        this->ten = ten ; 
        this-> ns = ns ; 
        this->dc = dc;   
    }
    void chuanhoaNs(){
        if(ns[1] == '/') ns.insert(0 , "0" ) ; 
        if(ns[4] == '/') ns.insert(3 , "0" ) ; 
    }
    void chuanhoaTen(){
        stringstream ss(this->ten) ; 
        string tmp , name = "" ;
        while(ss >> tmp ){
            name +=  toupper(tmp[0]) ; 
            for(int j=1 ; j<tmp.size() ; j++){
                name += tolower(tmp[j]) ; 
            }
            name += ' ' ; 
        }
        name.pop_back () ; 
        this->ten = name  ; 
    }
};

class Student : public person {
private : 
    string lop ; 
    double gpa ;
public : 
    Student(string ma , string ten , string ns , string dc ,string lop , double gpa ):person(ma , ten , ns , dc ) {
        chuanhoaTen() ; 
        chuanhoaNs() ;
        this->lop =  lop ; 
        this->gpa = gpa ;  
    }
    friend ostream& operator << (ostream& , Student) ;    
};

ostream& operator << (ostream&out , Student x ) {
    out << x.ma <<' '<<x.ten <<' ' << x.ns <<' ' << x.dc <<' '<< x.lop <<' ' << fixed << setprecision(2) << x.gpa << endl ;
    return out ; 
}

class Teacher : public person{
private : 
    string khoa ; 
    int luong ; 
public : 
    Teacher(string ma , string ten , string ns , string dc , string khoa , int luong ) : person(ma ,ten ,ns ,dc) {
        chuanhoaTen() ;
        chuanhoaNs() ;
        this->luong = luong ; 
        this->khoa = khoa ;
    }
    friend ostream& operator << (ostream &  , Teacher ) ;
};

ostream& operator << (ostream &out  , Teacher x ){
    out << x.ma <<' ' <<x.ten <<' '<<x.ns <<' ' <<x.dc <<' ' << x.khoa <<' ' << x.luong <<endl ; 
    return out ;
}

int main() {
    vector<Student> v1 ; 
    vector<Teacher> v2 ; 
    int n ; cin >> n; 
    for(int i=0 ; i<n ; i++){
        string ma ; cin >> ma ; 
        string ten , ns , dc ;
        if(ma.substr(0 , 2 ) == "GV"){
            cin.ignore() ; 
            getline(cin , ten ) ; 
            getline(cin , ns ) ;
            getline(cin , dc ) ;
            string khoa ; getline(cin , khoa) ; 
            int luong ; cin >> luong ; 
            v2.push_back(Teacher(ma , ten , ns , dc , khoa , luong )) ; 
        }
        else{
            cin.ignore() ; 
            getline(cin , ten ) ; 
            getline(cin , ns ) ; 
            getline(cin , dc ) ; 
            string lop ; getline(cin , lop ) ; 
            double gpa ; cin >> gpa ; 
            v1.push_back(Student(ma , ten , ns , dc ,lop , gpa )) ;
        }
    }
    cout <<"DANH SACH GIAO VIEN :" << endl ;
    for(Teacher x : v2 ){
        cout << x ; 
    }
    cout << "DANH SACH SINH VIEN :" << endl ; 
    for(Student x : v1){
        cout << x ; 
    }
    return 0;
}

