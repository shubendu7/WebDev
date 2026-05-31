#include<iostream>
using namespace std;
class Main{
    public:
        virtual void getarea()=0;
};
class circle:public Main{
    public:
        void getarea(){
            cout<<"Enter the radius of the circle : ";
            int r;
            cin>>r;
            cout<<"The area is : "<<3.14*r*r;
        }
};
class Rectangle:public Main{
    public:
        void getarea(){
            cout<<"Enter the length and breadth : ";
            int l,b;
            cin>>l>>b;
            cout<<"The area is : "<<l*b;
        }
};
int main(){
    Main *ptr;
    circle obc;
    Rectangle obr;
    ptr=&obc;
    ptr->getarea();
    return 0;
}