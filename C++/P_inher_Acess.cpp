#include<iostream>
using namespace std;
class Base{
    //protected:
        int i;
    public : 
        int j,k;
        void seti(int);
        int geti();
};
inline void Base::seti(int x){
    i=x;
}
inline int Base::geti(){
    return i;
}
class derived:private Base{
    public:
        Base::j;
        Base::geti;
        Base::seti;
        //Base::i; inaccessible
        int a;
};
int main(){
    derived ob;
    //ob.i=10; cant be accessed
    ob.j=20;
    //ob.k=30; illegal
    ob.a=40;
    ob.seti(10);
    cout<<ob.geti()<<" "<<ob.j<<" "<<ob.a;
    return 0;
}
