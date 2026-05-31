#include<iostream>
using namespace std;
class Base1{
    public:
        int i;
};
class derived1:public Base1{
    public:
        int j;
};
class derived2:public Base1{
    public:
        int k;
};
class derived3:public derived1,public derived2{
    public:
        int sum;
};
int main(){
    derived3 ob;
    ob.derived1::i=9;
    ob.derived2::i=10;
    ob.j=20;
    ob.k=30;
    ob.sum=ob.derived1::i+ob.k+ob.j;

    cout<<"i of base class (inherited by derived 1) = "<<ob.derived1::i<<endl;
    cout<<"i of base class (inherited by derived 2) = "<<ob.derived2::i<<endl;
    cout<<"j of derived class 1 = "<<ob.j<<endl;
    cout<<"k of derived class 2 = "<<ob.k<<endl;
    cout<<"sum of i,j&k = "<<ob.sum<<endl;

    return 0;
}