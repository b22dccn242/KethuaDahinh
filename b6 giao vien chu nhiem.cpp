#include <bits/stdc++.h> 
using namespace std;
class person{
protected : 
    string ma , name , ns , dc  ; 
public : 
    person(string ma , string name , string ns , string dc   ){
        this->ma =  ma ; 
        this->name = name ;
        this->ns = ns ;
        this->dc = dc ; 
    }
    void chuanhoaNs(){
        if(ns[1] == '/') ns.insert(0 , "0") ; 
        if(ns[4] == '/') ns.insert(3 , "0") ; 
    }
    void chuanhoaten(){
        stringstream ss(name) ; 
        string tmp , ten = "" ;
        while(ss >> tmp ){
            ten += toupper(tmp[0]) ; 
            for(int i=1 ; i<tmp.size() ; i++){
                ten += tolower(tmp[i]) ; 
            }
            ten += ' ' ; 
        }
        ten.pop_back() ; 
        this->name = ten ; 
    }
};

class Student : public person{
private : 
    string lop ; 
    double gpa ; 
public : 
    Student(string ma , string name , string ns , string dc , string lop , double gpa ) : person(ma , name ,ns , dc  ){
        this->lop = lop ; 
        this->gpa = gpa; 
        chuanhoaNs() ; 
        chuanhoaten() ; 
    }
    friend ostream& operator << (ostream & out , Student x ){
        out << x.ma <<' ' << x.name <<' '<<x.ns <<' ' <<x.dc<<' '<<x.lop <<fixed <<setprecision(2) <<' '<<x.gpa<<endl ; 
        return out ; 
    }
    string getlop(){
        return this->lop ; 
    }
};

class Teacher : public person{
private : 
    string khoa , lop2 ; 
    int luong ; 
public : 
    Teacher(string ma , string name , string ns , string dc , string khoa , int luong , string lop2  ) : person(ma , name , ns , dc ) {
        this->khoa = khoa ; 
        this->luong = luong ; 
        this->lop2 = lop2 ; 
        chuanhoaNs() ; 
        chuanhoaten() ; 
    }
    friend ostream& operator << (ostream &out , Teacher x ){
        out << x.ma <<' ' << x.name <<' '<<x.ns<<' '<<x.dc<<' '<<x.khoa <<' '<< x.luong <<' '<< x.lop2 <<endl;
        return out ; 
    }
    string getlop2(){
        return this->lop2 ; 
    }
};

int main() {
    vector<Student> v1 ; 
    vector<Teacher> v2 ;
    int n ; cin >> n ; 
    for(int i=0 ; i<n ; i++){
        string ma ; cin >> ma ; 
        string name , ns , dc , lop ; 
        if(ma.substr(0 , 2) == "SV"){
            cin.ignore() ; 
            getline(cin , name ) ; 
            getline(cin , ns ) ; 
            getline(cin , dc ) ; 
            getline(cin , lop ) ; 
            double gpa ; cin >> gpa ; 
            v1.push_back(Student(ma , name , ns , dc , lop , gpa)) ;
        }
        else{
            cin.ignore() ;
            getline(cin , name ) ; 
            getline(cin , ns ) ; 
            getline(cin , dc )  ; 
            string khoa; getline(cin , khoa ) ; 
            int luong ;  cin >> luong ; 
            string lop2 ; cin >> lop2 ; 
            v2.push_back(Teacher(ma , name , ns , dc , khoa , luong , lop2 )) ; 
        }
    }
    string tmp ; cin >> tmp ; 
    cout <<"DANH SACH GIAO VIEN PHU TRACH LOP " + tmp + " :" << endl ; 
    for(Teacher x : v2 ){
        if(x.getlop2() == tmp ){
            cout << x ; 
        }
    }
    cout <<"DANH SACH SINH VIEN LOP " + tmp + " :" << endl ; 
    for(Student x : v1 ){
        if(x.getlop() == tmp ){
            cout << x ; 
        }
    }
    return 0;
}
