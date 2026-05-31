#include<iostream>
using namespace std;
int main(){
    cout<<"Start\n";

    try{
        cout<<"In the try block\n";
        throw(100);
        cout<<"This will not execute\n";
    }
    catch(int i){
        cout<<"In the catch block\n";
        cout<<i<<endl;
        
    }
    cout<<"End";
    return 0;
}