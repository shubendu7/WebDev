#include<iostream>
using namespace std;

// Function prototypes
int myAbs(int i);
double myAbs(double i);
long myAbs(long i);

int myAbs(int i){
    cout << "The abs value (int): " << endl;
    return i < 0 ? -i : i;
}

double myAbs(double i){
    cout << "The abs value (double): " << endl;
    return i < 0.0 ? -i : i;
}

long myAbs(long i){
    cout << "The abs value (long): " << endl;
    return i < 0 ? -i : i;
}

int main(){
    cout << myAbs(-10) << endl;
    cout << myAbs(-9.0) << endl;
    cout << myAbs(-11L) << endl;
    return 0;
}
