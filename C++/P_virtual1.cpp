#include<iostream>
using namespace std;
class base{
    public:
        virtual void vfun();
};
inline void base::vfun(){
    cout<<"base's vfun"<<endl;
}
class derived1:public base{
    public:
        void vfun(){cout<<"derived1's vfun"<<endl;}
};
class derived2:public base{
    public:
        void vfun(){cout<<"derived2's vfun"<<endl;}
};
void f(base &r){
    r.vfun(); 
}
int main(){
    base obj;
    derived1 obd1;
    derived2 obd2;

    f(obj);
    f(obd1);
    f(obd2);

    return 0;
}