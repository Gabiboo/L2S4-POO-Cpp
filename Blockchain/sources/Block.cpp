#include "../headers/Block.h"
#include <iostream>

using namespace std;

class Block{
private:
    static int indice;
    int indiceBloc;
    std::string timeStamp;
    std::string donnee;
    std::string hash;
    std::string hashPrecedent;

public:
    //parameterized constructeur
    Block(int indice, string timeStamp, string donnee, string hashPrecedent);
    void set(int indice, string timeStamp, string donnee, string hashPrecedent);
    void print();
    string calculateHash();

    int returnIndice();

    string returnDonnee();

    string returnTimestamp();

    string returnHash();

    string returnHashPrecedent();

    void getDonnee(string donnee);

    int returnIndiceBloc();

    void getHashPrecedent(string hashPrecedent);

    void AfficherBlock();

    void putHash();

    void putIndice();

    void putIndiceBlock();
};

Block::Block(int indice, string timeStamp, string donnee, string hashPrecedent)
{
    this->indice = indice;
    this->timeStamp = timeStamp;
    this->donnee = donnee;
    this->hashPrecedent = hashPrecedent;
}

void Block::set(int indice, string timeStamp, string donnee, string hashPrecedent) {
    this->indice = indice;
    this->timeStamp = timeStamp;
    this->donnee = donnee;
    this->hashPrecedent = hashPrecedent;
}

void Block::print() {
    cout << "Valeur de l'indice : " << indice <<endl;
    cout << "Valeur de timeStamp : " << timeStamp <<endl;
    cout << "Valeur de la donnee : " << donnee <<endl;
    cout << "Valeur du hashPrecedent : " << hashPrecedent <<endl;
    cout << "Hashcode : " << hash <<endl;
}
void Block::putHash()
{
    cout << "Hash : " << hash <<endl;
}

void Block::putIndice()
{
    cout << "Indice : " << indice <<endl;
}
void Block::putIndiceBlock()
{
    cout << "indice du bloc : " << indiceBloc <<endl;
}


int Block :: indice =- 1;

string Block::calculateHash()
{
    string c_hash = std::to_string(indice) + timeStamp + donnee + hashPrecedent;
    return c_hash;
}

int Block::returnIndice()
{
    return this->indice;
}
int Block::returnIndiceBloc(){
    return this->indice;
}
string Block::returnDonnee(){
    return this->donnee;
}
string Block::returnTimestamp(){
    return this->timeStamp;
}
string Block::returnHash(){
    return this->hash;
}
string Block::returnHashPrecedent(){
    return this->hashPrecedent;
}
void Block::getHashPrecedent(string hashPrecedent){
    this->hashPrecedent = hashPrecedent;
}
void Block::getDonnee(string donnee){
    this->donnee = donnee;
}
/*
void Block::AfficherBlock() {
    this.at(0).puthash();
    chaine_de_blocs.at(0).putIndice();
    //cout << chaine_de_blocs.at(0).puthash() << "!" << chaine_de_blocs.at(0).putIndice() << endl;
}*/


class BlockChain
{
public:
    BlockChain();
    Block createGenesisBloc();
    void afficher_premier_block();
    void afficher_blocs();
    void addBloc(Block ref_bloc);
    Block getIthBloc(int i);
    int isChainValid();

private:
    deque<Block> chaine_de_blocs;
};

BlockChain::BlockChain(){
    //Constructeur qui permet d'initialiser la blockchain avec un premier bloc
    Block premier_bloc = createGenesisBloc();
    chaine_de_blocs.push_front(premier_bloc);
}

Block BlockChain::createGenesisBloc(){

    char * tmstamp = "01/01/2019";
    char * donnee = "Genesis Bloc";
    char * hshprecedent = "";

    return Block(tmstamp, donnee, hshprecedent);
}

void BlockChain::afficher_premier_block(){
    chaine_de_blocs.at(0).puthash();
    chaine_de_blocs.at(0).putIndice();
    //cout << chaine_de_blocs.at(0).puthash() << "!" << chaine_de_blocs.at(0).putIndice() << endl;
}

void BlockChain::addBloc(Block ref_bloc){

    int taille_chaine_de_blocs = chaine_de_blocs.size();

    //mettre a jour le hash precedent
    if(taille_chaine_de_blocs > 0){
        Block dernier_bloc = chaine_de_blocs.at(taille_chaine_de_blocs-1);
        ref_bloc.getHashPrecedent(dernier_bloc.returnHash());
        ref_bloc.calculateHash();//recalculer le hash apres mise a jour du hashprecedent
        chaine_de_blocs.push_back(ref_bloc);
    }
    //ref_bloc. = dernier_bloc.
    //chaine_de_blocs.push_back(ref_bloc);
}

Block BlockChain:: getIthBloc(int i){

    Block c("null", "null", "null");
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
    Block b("26-05-2019", "data1", "hashprec");
    //b.puthash();
    //b.putIndice();
    blocchain.addBloc(b);

    //Bloc bref = blocchain.getIthBloc(0);

    blocchain.afficher_blocs();

    cout << "Verifier si la chaine est valide avant la mise a jour" << endl;
    blocchain.isChainValid();


    return 0;
}
