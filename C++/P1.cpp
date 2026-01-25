#include <iostream> 
using namespace std;
class teacher{
    private:
        double salary;
    public:
        string name;
        string dept;
        string sub;
        string word="sds2312@sds";

    void changedept(string newdept){
        dept = newdept;
    }

    //setter
    void setsalary(double sal){
        salary=sal;
    }

    //getter
    double getsalary(){
        return salary;
    }

};
int main() {
    teacher t1;
    t1.name="Shubend Das";
    t1.dept="CMSA";
    t1.sub="Computer Science";
    t1.setsalary(25000);

    cout<<t1.name<<endl<< t1.dept <<endl<< t1.sub <<endl;
    string pass;
    cout<<"Enter the password to access the salary"<<endl ;
    cin >> pass;

    if (pass == t1.word) {
        cout << "Salary: " << t1.getsalary() << endl;
    } else {
        cout << "Incorrect password." << endl;
    }
    return 0;
}
