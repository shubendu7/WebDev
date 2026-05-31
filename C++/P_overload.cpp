#include<iostream>
using namespace std;
int myfunc(int a);
int myfunc(int a,int b);
int main(){
    int (*fp)(int a);
    int (*pf)(int a,int b);
    fp=myfunc;
    pf=myfunc;
    cout<<fp(5)<<endl;
    cout<<pf(fp(5),5);
    return 0;
}
int myfunc(int a){
    return a;
}
int myfunc(int a,int b){
    return a*b;
}