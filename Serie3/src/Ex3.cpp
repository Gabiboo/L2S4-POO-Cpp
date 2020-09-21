//**************** CHANGEMENT AVEC POINTEURS  ***********************
#include <iostream>

using namespace std;
//function definition
void permuter(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int a=10, b=20;
    cout<<"\nValeurs avant pérmutation :\n";
    cout<<"A: " << a<<",B :"<< b;
    // function calling
    permuter(&a,&b);
    cout<<"\nValeurs après pérmutation :\n";
    cout<<"A: " << a<<",B :"<< b;
    cout<<"\n";
    return 0;
}


//**************** CHANGEMENT AVEC REFERENCE  ***********************

/*#include <iostream>

using namespace std;

void permuter(int&,int&);

int main()
{
    int a=10, b=20;
    cout<<"\nValeurs avant pérmutation :\n";
    cout<<"A: " << a<<",B :"<< b;
    // function calling
    permuter(a,b);
    cout<<"\nValeurs après pérmutation :\n";
    cout<<"A: " << a<<",B :"<< b;
    cout<<"\n";
    return 0;
}
//function definition
void permuter(int &x, int &y){
    int t;
    t=x;
    x=y;
    y=t;
}*/



