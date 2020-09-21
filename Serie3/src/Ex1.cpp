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

/*// 2ème DEMONSTRATION
// Created by Gabriel on 28/01/2020.
//

#include <iostream>

using namespace std;

void swap(int&,int&);

int main()
{
    int a=10, b=20;
    cout<<"\nVALUES BEFORE SWAPPING :\n";
    cout<<"A: " << a<<",B :"<< b;
    // function calling
    swap(a,b);
    cout<<"\nVALUES AFTER SWAPPING :\n";
    cout<<"A: " << a<<",B :"<< b;
    cout<<"\n";
    return 0;
}
//function definition
void swap(int &x, int &y){
    int t;
    t=x;
    x=y;
    y=t;
}*\