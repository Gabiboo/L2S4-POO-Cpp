//****************** NOMBRE DE D'OCCURENCES S DANS UNE CHAINE DE CARACTÈRE ***********************

#include <iostream>

using namespace std;

int main()
{
    char* s = "Test Str";

    cout << s <<endl;

    int i(0); int cpt(0);

    while(s[i] != '\0'){
        if(s[i] == 'S'){
            cpt++;
        }
        i++;
    }

    cout << "nombre d'occurence de S dans : " << s << " : " << cpt <<endl;
}
