#include<iostream>
using namespace std;
class Twovalues{
    int a,b;
    public:
        Twovalues(int,int);
        friend class Min;
};
Twovalues::Twovalues(int a,int b){
    this->a=a;
    this->b=b;
}
class Min{
    public:
        int checkval(Twovalues);
};
int Min::checkval(Twovalues x){
    return x.a>x.b?x.b:x.a;
}
int main(){
    Twovalues obj(3,4);
    Min m;
    cout<<m.checkval(obj);
    return 0;
}