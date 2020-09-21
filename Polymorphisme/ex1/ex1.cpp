//
// Created by Gabriel on 03/03/2020.
//

#include <iostream>
#include <string>
using namespace std;

class Vehicule{
private:
    string energie;
public:
   virtual void description();
   Vehicule(string energie);
   virtual ~Vehicule(){
        cout << "Destructor called" << endl;
    }
};

Vehicule::Vehicule(string energie){
    this -> energie = energie;
}

void Vehicule::description() {
    cout << "energie utilisée par le vehicule : " << energie << endl;
}

class Voiture:public Vehicule{
private:
    int vitesse;

public:
    virtual ~Voiture(){
        cout << "Destructor called" << endl;
    }
    virtual void description();
    Voiture(int vitesse, string energie):Vehicule(energie){
        this ->vitesse = vitesse;
    }
};

void Voiture::description() {
    cout << "Vitesse maximale de la voiture : " << vitesse << endl;

}

class Camion:public Vehicule{
private:
    int masse;

public:
    virtual ~Camion(){
        cout << "Destructor called" << endl;
    }
    virtual void description();
    Camion(int masse, string energie):Vehicule(energie){
        this -> masse = masse;
    }
};

void Camion::description() {
    cout << "Masse du camion : " << masse << endl;
}

void afficherDetails(Vehicule &v){
    v.description();
}


int main(){

    Vehicule v1("Diesel");
    Voiture v2(155, "Diesel");
    Camion c1(3000, "Essence");

    afficherDetails(v1);


}