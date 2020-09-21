#include <iostream>
#include <string>
using namespace std;

class ServiceWeb{
public:
    void getDetails(string url,string catP,string catS,string archi[2],bool support,string requete[15],double qos);
    ServiceWeb(ServiceWeb &ref_serviceWeb);
    void putUrl();
    void putCatP();
    void putCatS();
    void putArchi();
    void putSupport();
    void putRequete();
    void putQos();

    string returnUrl();
    string returnCatP();
    string returnCatS();
    string returnarchi();
    double returnqos();
    bool returnSupport();
    string returnRequete();

    bool composable(ServiceWeb s);

    void set(ServiceWeb &ref_serviceWeb);
private:
    std::string url;
    std::string catP;
    std::string catS;
    std::string archi[2];
    bool support;
    std::string requete[15];
    double qos;



};

void ServiceWeb::getDetails(string url, string catP, string catS, string *archi, bool support, string *requete, double qos) {

}

void ServiceWeb::set(ServiceWeb &ref_serviceWeb) {
    this->url = ref_serviceWeb.returnUrl();
    this->catP = ref_serviceWeb.returnCatP();
    this->catS = ref_serviceWeb.returnCatS();
    this->archi = ref_serviceWeb.returnarchi();
    this->support = ref_serviceWeb.returnqos();
    this->requete = ref_serviceWeb.returnRequete();
    this->qos = ref_serviceWeb.returnqos();
}

void ServiceWeb::putUrl() {
    cout << "Url : " << url;
}

void ServiceWeb::putCatP() {
    cout << "Catégorie primaire  : " << catP;
}

void ServiceWeb::putCatS() {
    cout << "Catégorie secondaire  : " << catS;
}

void ServiceWeb::putArchi() {
    cout << "Architécture : " << archi;
}

void ServiceWeb::putSupport() {
    cout << "Support : " << support;
}

void ServiceWeb::putRequete() {
    cout << "Requete : " << requete;
}

void ServiceWeb::putQos() {
    cout << "QoS : " << qos;
}

string ServiceWeb::returnUrl() {
    return this->url;
}

string ServiceWeb::returnCatP() {
    return this->catP;
}

string ServiceWeb::returnCatS() {
    return this->catS;
}

string ServiceWeb::returnarchi() {
    return this->archi;
}

double ServiceWeb::returnqos() {
    return this->qos;
}

bool ServiceWeb::returnSupport() {
    return false;
}

bool ServiceWeb::composable(ServiceWeb s) {
    if (this->qos > 5) {
        return true;
    } else
        return false;

}