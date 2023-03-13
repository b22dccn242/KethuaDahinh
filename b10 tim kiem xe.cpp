#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Hangxe{
protected : 
    string ma , ten , hang , mau ; 
    int tocdo , gia ; 
public : 
    friend istream & operator >> (istream & in , Hangxe &x ){
        in >>x.ma >>  x.ten >> x.hang >> x.mau >> x.tocdo >> x.gia ; 
        return in ; 
    }
    friend ostream & operator << (ostream & out , Hangxe x){
        out << x.ma <<' '<<x.ten <<' ' <<x.hang <<' '<<x.mau <<' '<<x.tocdo <<' '<<x.gia << endl ; 
        return out ; 
    }
    string getma(){
        return this-> ma; 
    }
    string getten(){
        return this->ten ; 
    }  
};

int main() {
    vector<Hangxe> v1 ;
    vector<Hangxe> v2 ; 
    int n ; cin >> n; 
    Hangxe a[n] ; 
    for(int i= 0 ; i<n ; i++){
        cin >> a[i] ;
    }
    for(int i=0 ; i<n ; i++){
        string tmp = a[i].getma() ; 
        if(tmp.substr(0 , 2 ) == "XM"){
            v1.push_back(a[i]) ; 
        }
        else{
            v2.push_back(a[i]) ; 
        }
    }
    cout <<"DANH SACH OTO :" << endl ; 
    string name ; cin >> name ; 
    for(Hangxe x : v2){
        if(x.getten() == name )
            cout << x; 
    }
    cout <<"DANH SACH XE MAY :" << endl ; 
    for(Hangxe x : v1 ){
        if(x.getten() == name )
            cout << x ;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
