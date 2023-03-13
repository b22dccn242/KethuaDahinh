#include <bits/stdc++.h>
using namespace std;

class Hangxe{
protected : 
    string ma , ten , hang , mau  ; 
    int tocdo , gia ; 
public : 
    friend istream & operator >> (istream & in , Hangxe &x  ){
        in >> x.ma >> x.ten >>x.hang >>x.mau >>x.tocdo >>x.gia ; 
        return in ; 
    }
    friend ostream & operator << (ostream & out , Hangxe x ){
        out << x.ma <<' '<<x.ten <<' '<<x.hang <<' '<<x.mau <<' ' <<x.tocdo <<' '<<x.gia << endl ; 
        return out ; 
    }
    string gethang(){
        return this->hang ; 
    }
    string getma(){
        return this->ma ; 
    }
};


int main() {
    vector<Hangxe> v1 ; 
    vector<Hangxe> v2 ; 
    int n ; cin >> n ; 
    Hangxe a[n] ; 
    for(int i=0  ; i<n ; i++){
       cin >> a[i] ; 
    }
    for(int i=0 ; i<n ; i++){
        if(a[i].getma().substr(0 , 3 ) == "OTO"){
            v1.push_back(a[i]) ; 
        }
        else{
            v2.push_back(a[i]) ; 
        }
    }
    string hang ; cin >> hang ; 
    cout << "DANH SACH XE HANG " + hang + " :" << endl ; 
    for(Hangxe x : v1){
        if(x.gethang() == hang) cout << x ;
    }
    for(Hangxe x : v2 ){
        if(x.gethang() == hang ) cout << x; 
    }
    
    return 0;
}
