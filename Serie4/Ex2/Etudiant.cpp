#include <iostream>
#include <sys/param.h>

using namespace std;

class Etudiant{
private:
    char name[30];
    int rollNo;
    int total;
    int perc;

public:
    void getDetails(void);
    void putDetails(void);
};

void Etudiant::getDetails(void)
{
    cout << "nom de l'étudiant : " << endl;
    cin >> name;
    cout << "num étu :";
    cin >> rollNo;
    cout << "Somme des points accumulés dans différents modules : ";
    cin >> total;
    perc = float((100 * total)/500);

}

void Etudiant::putDetails(void)
{
    cout << "Détails concérnant l'étudiant : " << rollNo;
    cout << "\nNom : " << name << "\nPoucentage des points accumulés sur la note finale : " << perc << "%" << endl;
}

int main(){

    int MAX = 41;
    Etudiant etu[MAX]; //Creation d'un tableau d'objet
    int n, loop;

    cout << "Nombre d'étudiant : ";
    cin >> n;
    if(n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Entrez les details de l'étudiant numéro " << i+1 << " :\n ";
            etu[i].getDetails();
        }
        for(int i = 0; i < n; i++)
        {
            cout << "Voici les détails de l'étudiant numéro " << i + 1 << " : \n";
            etu[i].putDetails();
        }
    } else
        perror("Veuillez choisir un nombre valide.");

    return 0;
}