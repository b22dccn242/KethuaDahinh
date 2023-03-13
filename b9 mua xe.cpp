#include <bits/stdc++.h> 
using namespace std;

class loaixe{
protected : 
    string ma ; 
public :
    void nhap(){
        getline(cin , ma ) ; 
    }
    void xuat(){
        cout << ma <<' ' ; 
    }
};

class dacdiem : public loaixe{
private : 
    string tenxe , brand , color; 
    int maluc , gia ; 
public : 
    void nhap(){
        loaixe :: nhap() ;  
        getline(cin , tenxe ) ; 
        getline(cin , brand ) ; 
        getline(cin , color) ; 
        cin >> maluc >> gia ; 
    }
    void xuat(){
        loaixe :: xuat() ; 
        cout << tenxe <<' '<<brand <<' '<<color <<' ' << maluc <<' ' << gia <<endl; 
    }
    int getgia(){
        return this->gia ; 
    }
    string getma(){
        return this->ma ; 
    }
};


int main() {
    int n ; cin >> n ; 
    dacdiem a[n] ;  
    for(int i=0 ; i<n ; i++){
        cin.ignore() ; 
        a[i].nhap() ; 
    }
    int l , r  ; cin >> l >> r  ; 
    cout <<"DANH SACH OTO :" << endl ; 
    for(int i=0 ; i<n ; i++){
        if(a[i].getgia() <= r && a[i].getgia() >= l ){
            if(a[i].getma().substr(0 , 3 ) == "OTO"  ) {
                a[i].xuat() ; 
            }
        }
    }
    cout << "DANH SACH XE MAY :" << endl ; 
    for(int i=0 ; i<n ; i++){
        if(a[i].getgia() <= r && a[i].getgia() >= l ){
            if(a[i].getma().substr(0 , 2 ) == "XM"  ) {
                a[i].xuat() ; 
            }
        }
    }
    return 0;
}
