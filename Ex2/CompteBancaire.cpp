#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    int numero;
    string titulaire;
    double solde;

public:
    CompteBancaire(int num, const string& titu, double s)
        : numero(num), titulaire(titu), solde(s >= 0 ? s : 0) {}

    void deposer(double montant) {
        if (montant > 0)
            solde += montant;
        else
            cout << "Montant invalide." << endl;
    }

    void retirer(double montant) {
        if (montant > 0 && solde >= montant)
            solde -= montant;
        else
            cout << "Retrait impossible (montant invalide ou solde insuffisant)." << endl;
    }

    void afficher() const {
        cout << "Compte n° " << numero
             << " | Titulaire : " << titulaire
             << " | Solde : " << solde << endl;
    }
};

int main() {
    CompteBancaire c1(1, "Ali", 1000);
    CompteBancaire c2(2, "Sara", 500);

    c1.deposer(300);
    c2.retirer(200);

    c1.afficher();
    c2.afficher();
    return 0;
}
