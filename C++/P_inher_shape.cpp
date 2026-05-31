#include<iostream>
using namespace std;
//Base class 1
class Area{
    protected:
        int length,breadth;
        int a0;
    public:
        Area(int,int);
        ~Area();
        int calarea();
        void show();
};
inline Area::Area(int l,int b){
    cout<<"Constructing Area"<<endl;
    length=l;
    breadth=b;
}
inline Area::~Area(){cout<<"Destructing Area"<<endl;}
int Area::calarea(){
     a0=length*breadth;
    return a0;
}
inline void Area::show(){
    cout<<"Area of a square = "<<a0<<endl;
}
//Base class 2
class Volsph{
    int sph;
    int a;
    public:
        Volsph(int);
        ~Volsph();
        int calsph();
        void showsph();
};
inline Volsph::Volsph(int h){
    cout<<"Constructing Volsph"<<endl;
    sph=h;
}
inline Volsph::~Volsph(){
    cout<<"Destructing Volsph"<<endl;    
}
int Volsph::calsph(){
    
    a=(1.33)*(3.14)*sph*sph*sph;
    
    return a;
}
inline void Volsph::showsph(){
    cout<<"Volume of a sphere = "<<a<<endl;
}
//Derived class
class Volume:public Area,public Volsph{
    int heigth;
    public:
        Volume(int,int,int);
        ~Volume();
        void showvol();
};
inline Volume::Volume(int l,int b,int h):Area(l,b),Volsph(h){
    cout<<"Constructing Volume"<<endl;
    heigth=h;
}
inline Volume::~Volume(){cout<<"Destructing Volume"<<endl;}
void Volume::showvol(){
    cout<<"Volume of cube = "<<calarea()*heigth<<endl;
}

int main(){
    cout<<"Enter the sizes of  L1,L2,L3 : "<<endl;
    int L1,L2,L3;
    cin>>L1>>L2>>L3;
    Volume obj(L1,L2,L3);
   int ch;
   cout<<"Enter your choice : \n1. Area sq\n2. Volume cube\n3. Volume sph"<<endl;
   cin>>ch;
   switch(ch){
    case 1:
        obj.show();
        break;
    case 2:
        obj.showvol();
        break;
    case 3:
        obj.showsph();
        break;
   }
    return 0;
}