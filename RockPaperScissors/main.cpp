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
    cout << "1. Piatra\n";
    cout << "2. Foarfeca\n";
    cout << "3. Hartie\n";
}

// Functie pentru a determina rezultatul jocului
void determinaCastigatorul(int miscareJucator, int miscareCalculator) {
    if (miscareJucator == miscareCalculator) {
        cout << "Egalitate!\n";
    }
    else if ((miscareJucator == 1 && miscareCalculator == 2) ||
        (miscareJucator == 2 && miscareCalculator == 3) ||
        (miscareJucator == 3 && miscareCalculator == 1)) {
        cout << "Ai castigat!\n";
    }
    else {
        cout << "Calculatorul a castigat!\n";
    }
}

int main() {
    int miscareJucator;
    int miscareCalculator;

    // Initializare pentru generarea de numere aleatorii
    srand(time(0));

    cout << "Bine ati venit la jocul Piatra, Foarfeca, Hartie!\n";
    cout << "Alege o miscare:\n";
    afisareOptiuni();
    cin >> miscareJucator;

    // Verificare validitate miscare jucator
    while (miscareJucator < 1 || miscareJucator > 3) {
        cout << "Miscare invalida! Te rog alege o miscare valida:\n";
        afisareOptiuni();
        cin >> miscareJucator;
    }

    miscareCalculator = generareMiscareCalculator();
    cout << "Calculatorul a ales: " << miscareCalculator << endl;

    cout << "Jucatorul a ales: " << miscareJucator << endl;

    determinaCastigatorul(miscareJucator, miscareCalculator);

    return 0;
}
