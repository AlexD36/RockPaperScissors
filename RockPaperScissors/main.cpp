#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Functie pentru a genera miscarea calculatorului
int generareMiscareCalculator() {
    return rand() % 3 + 1; // Genereaza un numar intre 1 si 3
}

// Functie pentru a transforma miscarea numerica a calculatorului in denumirea corespunzatoare
string transformaMiscare(int miscare) {
    switch (miscare) {
    case 1:
        return "Piatra";
    case 2:
        return "Foarfeca";
    case 3:
        return "Hartie";
    default:
        return "Miscare invalida";
    }
}

// Functie pentru a afisa optiunile disponibile
void afisareOptiuni() {
    cout << "1. Piatra\n";
    cout << "2. Foarfeca\n";
    cout << "3. Hartie\n";
    cout << "0. Iesi\n";
}

// Functie pentru a determina rezultatul jocului si a actualiza scorul
void determinaCastigatorul(int miscareJucator, int miscareCalculator, int& scorJucator, int& scorCalculator) {
    if (miscareJucator == miscareCalculator) {
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
    int modJoc;

    // Initializare pentru generarea de numere aleatorii
    srand(time(0));

    cout << "Bine ati venit la jocul Piatra, Foarfeca, Hartie!\n";

    do {
        cout << "Alege un mod de joc:\n";
        cout << "1. Best of three\n";
        cout << "2. Endless\n";
        cout << "0. Iesi\n";
        cin >> modJoc;

        switch (modJoc) {
        case 0:
            cout << "Iesire din joc.\n";
            break;
        case 1: {
            int scorJucator = 0;
            int scorCalculator = 0;

            cout << "\nModul Best of three:\n";
            while (scorJucator < 2 && scorCalculator < 2) {
                cout << "\nAlege o miscare:\n";
                afisareOptiuni();

                int miscareJucator;
                cin >> miscareJucator;

                // Verificare validitate miscare jucator
                while (miscareJucator < 0 || miscareJucator > 3) {
                    cout << "Miscare invalida! Te rog alege o miscare valida:\n";
                    afisareOptiuni();
                    cin >> miscareJucator;
                }

                if (miscareJucator == 0) {
                    cout << "Ieșire din modul Best of three.\n";
                    break;
                }

                int miscareCalculator = generareMiscareCalculator();
                cout << "\nCalculatorul a ales: " << transformaMiscare(miscareCalculator) << endl;
                cout << "Jucatorul a ales: " << transformaMiscare(miscareJucator) << endl;

                determinaCastigatorul(miscareJucator, miscareCalculator, scorJucator, scorCalculator);

                cout << "Scorul curent:\n";
                cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl;
            }

            cout << "\n############################\nScor final:\n";
            cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl;
            if (scorJucator > scorCalculator) {
                cout << "Felicitari! Ai castigat jocul Best of three!\n";
            }
            else if (scorJucator < scorCalculator) {
                cout << "Calculatorul a castigat jocul Best of three!\n";
            }
            else {
                cout << "Este egalitate!\n";
            }

            cout << "Multumim pentru joc!\n############################\n\n";

            break;
        }
        case 2: {
            int miscareJucator;
            int miscareCalculator;
            int scorJucator = 0;
            int scorCalculator = 0;

            cout << "\nModul Endless:\n";
            do {
                cout << "Alege o miscare:\n";
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
                    cout << "\nCalculatorul a ales: " << transformaMiscare(miscareCalculator) << endl;
                    cout << "Jucatorul a ales: " << transformaMiscare(miscareJucator) << endl;

                    determinaCastigatorul(miscareJucator, miscareCalculator, scorJucator, scorCalculator);

                    cout << "\nScorul curent:\n";
                    cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl <<endl;
                }
            } while (miscareJucator != 0);

            cout << "\n############################\nScor final:\n";
            cout << "Jucator: " << scorJucator << " | Calculator: " << scorCalculator << endl;
            cout << "Multumim pentru joc!\n############################\n\n";

            break;
        }
        default:
            cout << "Mod de joc invalid! Te rog alege din nou.\n";
        }

    } while (modJoc != 0);

    return 0;
}
