#include<iostream>
using namespace std;
class Base1{
    protected:
        int x;
    public:
        Base1(){cout<<"Contructing Base1\n";}
        ~Base1(){cout<<"Destructing Base1\n"; }
        void showx();
};
inline void Base1::showx(){
    cout<<"x = "<<x<<endl;
}
class Base2:public Base1{
    protected:
        int y;
    public:
        Base2(){cout<<"Contructing Base2\n";}
        ~Base2(){cout<<"Destructing Base2\n"; }
        void showy();
};
inline void Base2::showy(){
    cout<<"y = "<<y<<endl;
}
//multilevel inheritance
class derived:public Base2{
    protected:
        int var_der;
    public:
        derived(){cout<<"Contructing derived\n";}
        ~derived(){cout<<"Destructing derived\n"; }
        void cal(int,int);
        void showd();
};
void derived::cal(int a,int b){
    x=a;
    y=b;
}
inline void derived::showd(){
    cout<<"x+y = "<<x+y<<endl;
}

int main(){
    derived obd;
    obd.cal(10,20);//setting the values of x and y
    obd.showx();
    obd.showy();
    obd.showd();
    return 0;
}