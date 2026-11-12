#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
int ikm, vs; //ikm - Įkūrimo metai, vs - Vietų skaičius
 string pavadinimas, savininkas, arena;


cout << "Iveskite futbolo kluba Pavadinimas, Ikurimo metai, Savinininkas, Arena (gali buti stadionas), Vietu skaicius." << endl;
    cin >> pavadinimas >> ikm >> savininkas >> arena >>vs;

    string rez = format("{0} ikurtas {1}m., savinikas {2}, o zaide {3}, kur telpa {4} zmoniu", pavadinimas, ikm, savininkas, arena, vs);

cout << rez;

return 0;
}