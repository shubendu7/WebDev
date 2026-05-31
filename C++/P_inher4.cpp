#include<iostream>
using namespace std;
class Base{
    protected:
        int i;
    public:
        Base(int);
        ~Base();
};
inline Base::Base(int x){
    i=x;
    cout<< "Constructing Base\n";
}
inline Base::~Base(){cout<<"Destructing Base\n";}
class derived:public Base{
    int j;
    public:
        derived(int,int);
        ~derived();
        void show();
};

inline derived::derived(int x,int y):Base(y){
    j=x;
    cout<<"Constructing derived\n";
};
inline derived::~derived(){cout<<"Destructing derived\n";}
inline void derived::show(){
    cout<<"i = "<<i<<" j = "<<j<<endl;
}
int main(){
    derived obd(3,4);
    obd.show();// display 4 3
    return 0;
}