#include<iostream>
using namespace std;
class Prime{
    int x;
    public :
        int isPrime(int x);
        void display(int ,int);
};
int Prime::isPrime(int x){
    int i;
    if(x<2)
        return 0;
    for(i=2;i<=x/i;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
void Prime::display(int low,int high){
    for(int i = low;i<=high;i++){
        if(isPrime(i))
            cout<<i<<" ";
    }
}
int main(){
    int l,h;
    cout<<"Enter the low limit : ";
    cin>>l;
    cout<<endl;
    cout<<"Enter the high limit : ";
    cin>>h;
    Prime p1;
    p1.display(l,h);
    return 0;
}