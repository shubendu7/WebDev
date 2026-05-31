#include<iostream>
using namespace std;
template<class t>
void swapargs(t&a,t&b){
    t temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"Swapped args : "<<a<<" "<<b<<endl;
}
int main(){
    cout<<"Enter the choices :\n1.INTEGERS\n2.CHARACTERS\n3.DOUBLES"<<endl;
    int ch;
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter the integers : ";
            int x1,x2;
            cin>>x1>>x2;
            cout<<"Original integers :"<<x1<<" "<<x2<<endl;
            swapargs(x1,x2);
            break;
        case 2:
            cout<<"Enter the charcters : ";
            char c1,c2;
            cin>>c1>>c2;
            cout<<"Original characters :"<<c1<<" "<<c2<<endl;
            swapargs(c1,c2);
            break;
        case 3:
            cout<<"Enter the doubles : ";
            double d1,d2;
            cin>>d1>>d2;
            cout<<"Original doubles :"<<d1<<" "<<d2<<endl;
            swapargs(d1,d2);
            break;
    }
    return 0;
}