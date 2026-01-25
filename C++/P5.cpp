// t1 = 12 : 45 : 55
// t2 = 07 : 22 : 20

#include<iostream>
using namespace std;
class Time{
    int hh,mm,ss;
    public :
        Time();
        Time(int ,int ,int);
        void display();
        Time addtime(Time);
        Time subtime(Time);
};
Time::Time(){}
Time::Time(int hh,int mm,int ss){
    this->hh=hh;
    this->mm=mm;
    this->ss=ss;
}
void Time::display(){
    cout<<hh<<" : "<<mm<<" : "<<ss<<endl;
}
Time Time::addtime(Time c){
    Time t;
    t.ss=ss+c.ss;
    t.mm=mm+c.mm;
    t.hh=hh+c.hh;
    if(t.ss>=60){t.ss=t.ss-60;t.mm++;}
    if(t.mm>=60){t.mm=t.mm-60;t.hh++;}
    if(t.hh>=12){t.hh=t.hh-12;}
}
Time Time::subtime(Time c){
    Time t;
    if(hh>c.hh){
        t.hh=hh-c.hh;
    }
}