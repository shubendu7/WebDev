#include<iostream>
using namespace std;
class Base{
    protected:
        int i,j;
    public:
        void set(int,int);
        void show();
};
inline void Base::set(int a,int b){i=a;j=b;}
inline void Base::show(){cout<<"i = "<<i<<" j = "<<j<<endl;}
class Derive1:public Base{
    int k;
    public:
        int setk();
        void showk(); 
};
inline int Derive1::setk(){
    k=i*j;
    return k;
}
inline void Derive1::showk(){
    cout<<"k = "<<k<<endl;
}
int main(){
    Derive1 ob1;

    ob1.set(2,3);
    ob1.showk();

    return 0;
}