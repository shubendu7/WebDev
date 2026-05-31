#include<iostream>
using namespace std;
const int r=8;
template<class t>
void mytab(t data,int tab){
    for(;tab;tab--)
        for(int i=0;i<r;i++)
            cout<<' '<<endl;
        cout<<data<<endl;
}
int main(){
    mytab("Shubendu",0);
    mytab(100,1);
    mytab('X',2);
    mytab(10/3,3);
    return 0;
}