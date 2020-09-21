#include <iostream>
#include <deque>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

class Ville{
public:
    Ville();
    Ville(string name, int codeP, int pop, double sup, double dens, bool tourist,
          bool maritim, string caracteristique);

    Ville(Ville &ref_ville);

    virtual ~Ville();

    int getId() const;

    const string &getNom() const;

    const int *getCodePostale() const;

    int getPopulation() const;

    double getSuperficie() const;

    double getDensité() const;

    bool isTouristique() const;

    bool isMaritime() const;

    const string getCaracteristiques() const;

    void setNom(const string &nom);

    void setPopulation(int population);

    void setSuperficie(double superficie);

    void setDensité(double densité);

    void setTouristique(bool touristique);

    void setMaritime(bool maritime);

    void setCaracteristiques(string caracteristiques);


private:
    int id;
    std::string nom;
    int codePostale[5];
    int population;
    double superficie;
    double densité;
    bool touristique;
    bool maritime;
    std::string caracteristiques;

    int returnId();

    string returnNom();

    int returnPopulation();

    double returnSuperficie();

    double returnDensite();

    bool returnTourist();

    bool returnMaritime();

    string returnCaracteristique();

    int returnCodeP();

    bool ComprareVille(Ville &v);


    int CompareVille(Ville *v, bool Sondage);
};

Ville::Ville(string name, int codeP, int pop, double sup, double dens, bool tourist, bool maritim,
             string caracteristique) {
    name = nom;
    codeP = codePostale[5];
    pop = population;
    sup = superficie;
    dens = densité;
    tourist = touristique;
    maritim = maritime;
    caracteristique = caracteristiques;
}

Ville::~Ville() {

}

int Ville::getId() const {
    return id;
}

const string &Ville::getNom() const {
    return nom;
}

const int *Ville::getCodePostale() const {
    return codePostale;
}

int Ville::getPopulation() const {
    return population;
}

double Ville::getSuperficie() const {
    return superficie;
}

double Ville::getDensité() const {
    return densité;
}

bool Ville::isTouristique() const {
    return touristique;
}

bool Ville::isMaritime() const {
    return maritime;
}

const string Ville::getCaracteristiques() const {
    return caracteristiques;
}

void Ville::setNom(const string &nom) {
    Ville::nom = nom;
}

void Ville::setPopulation(int population) {
    Ville::population = population;
}

void Ville::setSuperficie(double superficie) {
    Ville::superficie = superficie;
}

void Ville::setDensité(double densité) {
    Ville::densité = densité;
}

void Ville::setTouristique(bool touristique) {
    Ville::touristique = touristique;
}

void Ville::setMaritime(bool maritime) {
    Ville::maritime = maritime;
}

void Ville::setCaracteristiques(const string caracteristiques) {
    Ville::caracteristiques = caracteristiques;
}

Ville::Ville(Ville &ref_ville) {
    this->id = ref_ville.returnId();
    this-> nom = ref_ville.returnNom();
    this->population = ref_ville.returnPopulation();
    this->superficie = ref_ville.returnSuperficie();
    this->densité = ref_ville.returnDensite();
    this->touristique = ref_ville.returnTourist();
    this->maritime = ref_ville.returnMaritime();
    this->caracteristiques = ref_ville.returnCaracteristique();
    this->codePostale = ref_ville.returnCodeP();
}

int Ville::returnId()
{
    return this->id;
}
string Ville::returnNom()
{
    return this->nom;
}
int Ville::returnPopulation()
{
    return this->population;
}
double Ville::returnSuperficie()
{
    return this->superficie;
}
double Ville::returnDensite()
{
    return this->densité;
}
bool Ville::returnTourist()
{
    return this->touristique;
}
bool Ville::returnMaritime()
{
    return this->maritime;
}
string Ville::returnCaracteristique()
{
    return this->caracteristiques;
}
int Ville::returnCodeP(){
    for(int i = 0; i < 5; i++)
    {
        return this->codePostale[i];
    }

}

bool Ville::ComprareVille(Ville& v)
{
    if((this->getPopulation()-v.getPopulation()) < 1000 || (v.getPopulation()-this->getPopulation()) < 1000)
    {
        if(this->getSuperficie()-v.getSuperficie() <= 2 || v.getSuperficie()-this->getSuperficie() <= 2)
        {
            return true;
        } else
            return false;
    } else
        cout << "La Difference de population est trop importante. Elles ne sont pas similaires. \n";
        return false;

}

int Ville::CompareVille (Ville* v, bool Sondage)
{
    int n=0;

    if((this->getPopulation() - v->getPopulation()) > 1000 || (v->getPopulation() - this->getPopulation()) > 1000)
    {
        n++;

        if(this->getSuperficie() - v->getSuperficie() > 2 || v->getSuperficie() - this->getSuperficie() > 2)
        {
            n++;
            if(this->isMaritime() != v->isMaritime())
            {
                n++;
                if(this->isTouristique() != v->isTouristique())
                {
                    n++;
                } else
                    cout << "Les deux villes sont touristiques.\n";
            } else
                cout << "La deux villes sont maritimes\n";

        } else
            cout << "La différence de superficie est inférieur à 2\n";
    } else
        cout << "La Difference de population est trop inférieur a 1000.\n";

    return n;
}

int main(){
    Ville v1 = Ville();

    Ville vil("tours", 37000, 100000, 100, 25, true, false, "architectures");
    Ville vil1("chartres", 28000, 99765, 97, 12, true, true, "cathedrale");

    Ville v2 = (Ville& v1);
    vil.ComprareVille(vil1);
    //vil.CompareVille(vil1, );
}