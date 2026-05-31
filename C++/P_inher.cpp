#include<iostream>
using namespace std;
class Base{
    protected:
        int i,j;
    public:
        void set(int ,int );
        void show();
};
inline void Base::set(int a,int b){
    i=a;
    j=b;
}
inline void Base::show(){
    cout<<"i = "<<i<<" j = "<<j<<endl;
}
class derived1:public Base{
    int k;
    public:
        int setk();
        void showk();
};
inline int derived1::setk(){
    k=i*j;
    return k;
}
inline void derived1::showk(){
    cout<<"k = "<<k<<endl;
}
class derived2:public derived1{
    int m;
    public:
        void setm();
        void showm();
};
inline void derived2::setm(){
    m=setk()*(i+j);
}
inline void derived2::showm(){
    cout<<"m = "<<m<<endl;
}
int main(){
    derived2 ob2;

    ob2.set(2,3);
    ob2.show();
    ob2.setk();
    ob2.showk();
    ob2.setm();
    ob2.showm();

    return 0;
}