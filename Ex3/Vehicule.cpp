#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string immatriculation;
    string marque;
    double vitesseMax;

public:
    Vehicule(const string& immat, const string& m, double v)
        : immatriculation(immat), marque(m), vitesseMax(v) {}

    virtual void afficherDetails() const {
        cout << "Immatriculation : " << immatriculation
             << ", Marque : " << marque
             << ", Vitesse max : " << vitesseMax << " km/h" << endl;
    }

    virtual ~Vehicule() {}
};

class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    Voiture(const string& immat, const string& m, double v,
            int portes, const string& carburant)
        : Vehicule(immat, m, v), nombrePortes(portes), typeCarburant(carburant) {}

    void afficherDetails() const override {
        cout << "[Voiture] ";
        Vehicule::afficherDetails();
        cout << "   Portes : " << nombrePortes
             << ", Carburant : " << typeCarburant << endl;
    }
};

class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    Camion(const string& immat, const string& m, double v,
           double charge, int essieux)
        : Vehicule(immat, m, v), capaciteCharge(charge), nombreEssieux(essieux) {}

    void afficherDetails() const override {
        cout << "[Camion] ";
        Vehicule::afficherDetails();
        cout << "   Capacité de charge : " << capaciteCharge
             << " t, Essieux : " << nombreEssieux << endl;
    }
};

int main() {
    Vehicule* tab[2];
    tab[0] = new Voiture("12345-A-6", "Toyota", 180, 5, "Diesel");
    tab[1] = new Camion("67890-B-1", "Volvo", 120, 20.5, 3);

    for (int i = 0; i < 2; i++)
        tab[i]->afficherDetails();   // appel polymorphe

    for (int i = 0; i < 2; i++)
        delete tab[i];

    return 0;
}
