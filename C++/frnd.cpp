#include<iostream>
using namespace std;
class myclass{
    int a,b;
    public:
        myclass(int,int);
        friend int addsum(myclass);
};
myclass::myclass(int i,int j){
    a=i;
    b=j;
}
int addsum(myclass x){
    return x.a+x.b;
}
int main(){
    int p,q;
    cout<<"Enter the numbers to add :";
    cin>>p;
    cin>>q;
    myclass n(p,q);
    cout<<addsum(n);
    return 0;
}