#include <iostream>

using namespace std;

int main()
{
    int student_age=10;
    int &age=student_age; // Reference variable

    cout<< " value of student age :"<< student_age << endl;
    cout<< " value of age : " << age << endl;

    age=age+10;
    cout<<"\nAFTER ADDING 10 INTO REFERENCE VARIABLE \n";
    cout<<"value of age : "<< student_age << endl;
    cout<< "value of age :"<< age << endl;
    return 0;
}
