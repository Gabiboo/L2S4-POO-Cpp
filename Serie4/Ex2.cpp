//**************** CHANGEMENT AVEC POINTEURS  ***********************
#include <iostream>
#include "Etudiant.h"

using namespace std;

class Etudiant
{
    char name[30];
    int rollNo;
    float total;
    float perc;
};

Etudiant :: Etudiant(char name, int rollNo, float total, float perc)
{
    this ->name = name;
    this ->rollNo = rollNo;
    this ->total = total;
    this ->perc = perc;

}

