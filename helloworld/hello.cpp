#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Combien vaut pi ?" << endl;
    double piUtilisateur(-1.); //On cr�e une case m�moire pour stocker unnombre r�el
    cin >> piUtilisateur; //Et on remplit cette case avec ce qu'�critl'utilisateur

    cin.ignore();

    cout << "Quel est votre nom ?" << endl;
    string nomUtilisateur("Sans nom"); //On cr�e une case m�moire pour contenir une chaine de caract�res
    getline(cin, nomUtilisateur); //On remplit cette case avec toute la ligne que l'utilisateur a �crit

    cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pivaut " << piUtilisateur << "." << endl;

    return 0;
}
