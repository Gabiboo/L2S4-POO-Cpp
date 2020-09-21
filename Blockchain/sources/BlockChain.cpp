#include <iostream>
#include <deque>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

//Partie 1: Classe Bloc

class Bloc
{
public:
    Bloc();
    //Bloc(Bloc &ref_bloc);
    Bloc(string tmstamp, string donnee, string hshprecedent);
    string calculerhash();
    void puthash();
    void putIndice();
    void putIndiceBloc();
    int returnIndiceBloc();
    void set(Bloc bc);

    int returnIndice();
    string returnDonnee();
    string returnTimestamp();
    string returnHash();
    string returnHashPrecedent();

    void getHashPrecedent(string hashprec);
    void getDonnee(string donnee);

private:
    static int Indice;
    int IndiceBloc;
    std::string Timestamp;
    std::string Donnee;
    std::string Hash;
    std::string HashPrecedent;
};

Bloc::Bloc(string tmstamp, string donnee, string hshprecedent)
{
    if(std::strcmp(donnee.c_str(), "null") < 0){//A remarquer que strcmp prend en paramtre deux char* et non pas deux string
        Indice = Indice + 1;
        IndiceBloc = Indice;
    }
    Timestamp = tmstamp;
    Donnee = donnee;
    HashPrecedent = hshprecedent;
    Hash = calculerhash();//mise a jour du constructeur
}

int Bloc :: Indice = -1;

void Bloc::puthash()
{
    cout << "Hash : " << Hash <<endl;
}
void Bloc::putIndice()
{
    cout << "Indice : " << Indice <<endl;
}
void Bloc::putIndiceBloc(){
    cout << "IndiceBloc : " << IndiceBloc <<endl;
}
string Bloc::calculerhash(){
    Hash = to_string(IndiceBloc) + Donnee + HashPrecedent + Timestamp ;
    return Hash;
}
void Bloc::set(Bloc ref_bloc){
    this->Indice = ref_bloc.returnIndice();
    this->Timestamp = ref_bloc.returnTimestamp();
    this->Donnee = ref_bloc.returnDonnee();
    this->HashPrecedent = ref_bloc.returnHashPrecedent();
    this->Hash = ref_bloc.returnHash();
}
int Bloc::returnIndice(){
    return this->Indice;
}
int Bloc::returnIndiceBloc(){
    return this->IndiceBloc;
}
string Bloc::returnDonnee(){
    return this->Donnee;
}
string Bloc::returnTimestamp(){
    return this->Timestamp;
}
string Bloc::returnHash(){
    return this->Hash;
}
string Bloc::returnHashPrecedent(){
    return this->HashPrecedent;
}
void Bloc::getHashPrecedent(string hashprec){
    this->HashPrecedent = hashprec;
}
void Bloc::getDonnee(string donnee){
    this->Donnee = donnee;
}
/*
void Bloc::afficher_block(){
    this.at(0).puthash();
    chaine_de_blocs.at(0).putIndice();
    //cout << chaine_de_blocs.at(0).puthash() << "!" << chaine_de_blocs.at(0).putIndice() << endl;
}
*/

// Partie 2: Classe BlockChain
class BlockChain
{
public:
    BlockChain();
    Bloc createGenesisBloc();
    void afficher_premier_block();
    void afficher_blocs();
    void addBloc(Bloc ref_bloc);
    Bloc getIthBloc(int i);
    int isChainValid();

private:
    deque<Bloc> chaine_de_blocs;
};

BlockChain::BlockChain(){
    //Constructeur qui permet d'initialiser la blockchain avec un premier bloc
    Bloc premier_bloc = createGenesisBloc();
    chaine_de_blocs.push_front(premier_bloc);
}

Bloc BlockChain::createGenesisBloc(){

    char * tmstamp = "01/01/2019";
    char * donnee = "Genesis Bloc";
    char * hshprecedent = "";

    return Bloc(tmstamp, donnee, hshprecedent);
}

void BlockChain::afficher_premier_block(){
    chaine_de_blocs.at(0).puthash();
    chaine_de_blocs.at(0).putIndice();
    //cout << chaine_de_blocs.at(0).puthash() << "!" << chaine_de_blocs.at(0).putIndice() << endl;
}

void BlockChain::addBloc(Bloc ref_bloc){

    int taille_chaine_de_blocs = chaine_de_blocs.size();

    //mettre a jour le hash precedent
    if(taille_chaine_de_blocs > 0){
        Bloc dernier_bloc = chaine_de_blocs.at(taille_chaine_de_blocs-1);
        ref_bloc.getHashPrecedent(dernier_bloc.returnHash());
        ref_bloc.calculerhash();//recalculer le hash apres mise a jour du hashprecedent
        chaine_de_blocs.push_back(ref_bloc);
    }
    //ref_bloc. = dernier_bloc.
    //chaine_de_blocs.push_back(ref_bloc);
}

Bloc BlockChain:: getIthBloc(int i){

    Bloc c("null", "null", "null");
    if(i < chaine_de_blocs.size()){
        c.set(chaine_de_blocs.at(i));
    }

    return c;
}

void BlockChain::afficher_blocs(){
    for (int i(0); i < chaine_de_blocs.size(); i++){
        cout << " i " << i << endl;
        chaine_de_blocs.at(i).puthash();
        chaine_de_blocs.at(i).putIndiceBloc();
    }
}

int BlockChain::isChainValid(){
    cout << ">>>>>>>> Verifier si la chaine est valide " << endl;
    int i(0);
    string hash1;
    string hash2;
    int breakloop = 0;
    while (i < chaine_de_blocs.size() && breakloop == 0){
        hash1 = chaine_de_blocs.at(i).returnHash();
        hash2 = chaine_de_blocs.at(i).calculerhash();
        hash2 = chaine_de_blocs.at(i).returnHash();
        cout << "hash original " << hash1 << endl;
        cout << "hash new " << hash2 << endl;
        if(strcmp(hash1.c_str(), hash2.c_str()) != 0){
            breakloop == 1;
            cout << "Attention ! Chaine non valide !!";;
        }
        i++;
    }
    cout << "Chaine valide !!";
    return breakloop;
}

int main()
{
    BlockChain blocchain = BlockChain();
    //bc.afficher_premier_block();
    Bloc b("26-05-2019", "data1", "hashprec");
    //b.puthash();
    //b.putIndice();
    blocchain.addBloc(b);

    //Bloc bref = blocchain.getIthBloc(0);

    blocchain.afficher_blocs();

    cout << "Verifier si la chaine est valide avant la mise a jour" << endl;
    blocchain.isChainValid();


    return 0;
}