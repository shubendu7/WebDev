#include<iostream>
using namespace std;
class Base{
    public:
        virtual void vfunc(){cout<<"Base's vfunc\n";}
};
class derived1:public Base{
    public:
        void vfunc(){cout<<"derived1's vfunc\n";}
};
class derived2:public Base{
    public:
        //void vfunc(){cout<<"derived2's vfunc\n";}
};
int main(){
    Base *p,obj;
    derived1 obd1;
    derived2 obd2;
    p=&obj;
    p->vfunc();

    p=&obd1;
    p->vfunc();

    p=&obd2;
    p->vfunc();
    
   /*
   derived2 obj;
      obj.Base::vfunc();
      obj.vfunc();
   */
   
    return 0;
}