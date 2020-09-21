#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Combien vaut pi ?" << endl;
    double piUtilisateur(-1.); //On crŽe une case mŽmoire pour stocker unnombre rŽel
    cin >> piUtilisateur; //Et on remplit cette case avec ce qu'Žcritl'utilisateur

    cin.ignore();

    cout << "Quel est votre nom ?" << endl;
    string nomUtilisateur("Sans nom"); //On crŽe une case mŽmoire pour contenir une chaine de caractres
    getline(cin, nomUtilisateur); //On remplit cette case avec toute la ligne que l'utilisateur a Žcrit

    cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pivaut " << piUtilisateur << "." << endl;

    return 0;
}
