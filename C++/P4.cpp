//Adding two complex numbers

#include<iostream>
using namespace std;
class Complex{
    int real,img;
    public :
        void getdata(int ,int);
        void displaydata();
        Complex adddata(Complex);
        Complex subdata(Complex);
};
void Complex::getdata(int real,int img){
    this->real=real;
    this->img=img;
}
void Complex::displaydata(){
    cout<<real<<" +i"<<img<<endl;
}
Complex Complex::adddata(Complex c){
    Complex t;
    t.real=real+c.real;
    t.img=img+c.img;
    return t;
}
Complex Complex::subdata(Complex c){
    Complex t;
    t.real=real-c.real;
    t.img=img-c.img;
    return t;
}
int main(){
    Complex c1,c2,c3,c4;
    int m,n;
    cout<<"\nEnter the first number x+iy : ";
    cin>>n>>m;
    c1.getdata(n,m);
    cout<<"\nEnter the second number a+ib : ";
    cin>>n>>m;
    c2.getdata(n,m);
    c3=c1.adddata(c2);
    c4=c1.subdata(c2);
    c3.displaydata();
    c4.displaydata();
    return 0;
}