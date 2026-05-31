#include<iostream>
using namespace std;
class Base{
    public:
        virtual void print(){
            cout<<"Base Print func"<<endl;
        }
        virtual void show(){
            cout<<"Base Show func"<<endl;
        }      
};
class derived:public Base{
    public:
        void print(){
            cout<<"Derived Print func"<<endl;
        }
        void show(){
            cout<<"Derived Base func"<<endl;
        }
};
int main(){
    Base *ptr;
    derived objd;
    ptr=&objd;

    ptr->Base::print();
    ptr->print();

    ptr->Base::show();
    ptr->show();
    

    return 0;
}