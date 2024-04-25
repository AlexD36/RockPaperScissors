#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Functie pentru a genera miscarea calculatorului
int generareMiscareCalculator() {
    return rand() % 3 + 1; // Genereaza un numar intre 1 si 3
}

// Functie pentru a afisa optiunile disponibile
void afisareOptiuni() {
    cout << "0. Iesi\n";
    cout << "1. Piatra\n";
    cout << "2. Foarfeca\n";
    cout << "3. Hartie\n";
}

// Functie pentru a determina rezultatul jocului si a actualiza scorul
void determinaCastigatorul(int miscareJucator, int miscareCalculator, int& scorJucator, int& scorCalculator) {
    if (miscareJucator == 0) {
        cout << "Iesire din joc.\n";
    }
    else if (miscareJucator == miscareCalculator) {
        cout << "Egalitate!\n";
    }
    else if ((miscareJucator == 1 && miscareCalculator == 2) ||
        (miscareJucator == 2 && miscareCalculator == 3) ||
        (miscareJucator == 3 && miscareCalculator == 1)) {
        cout << "Ai castigat!\n";
        scorJucator++;
    }
    else {
        cout << "Calculatorul a castigat!\n";
        scorCalculator++;
    }
}

int main() {
    int miscareJucator;
    int miscareCalculator;
    int scorJucator = 0;
    int scorCalculator = 0;

    // Initializare pentru generarea de numere aleatorii
    srand(time(0));

    cout << "Bine ati venit la jocul Piatra, Foarfeca, Hartie!\n";

    do {
        cout << "Alege o miscare (0 pentru iesire):\n";
        afisareOptiuni();
        cin >> miscareJucator;

        // Verificare validitate miscare jucator
        while (miscareJucator < 0 || miscareJucator > 3) {
            cout << "Miscare invalida! Te rog alege o miscare valida:\n";
            afisareOptiuni();
            cin >> miscareJucator;
        }

        if (miscareJucator != 0) {
            miscareCalculator = generareMiscareCalculator();
            cout << "Calculatorul a ales: " << miscareCalculator << endl;
            cout << "Jucatorul a ales: " << miscareJucator << endl;

            determinaCastigatorul(miscareJucator, miscareCalculator, scorJucator, scorCalculator);

            cout << "Scorul curent:\n";
            cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl;
        }
    } while (miscareJucator != 0);

    cout << "Multumim pentru joc! Scor final:\n";
    cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl;

    return 0;
}
