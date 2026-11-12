#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    int pm;
    double lit;
    string mar, mod, spalva;

cout << "Iveskite automobilio marke, modelis, pagaminimo metai, litrazas ir spalva." << endl;
    cin >> mar >> mod >>pm >> lit >> spalva;

string rez = format ("Automobilis {0} {1} yra pagamintas {2} metais. Jo motoras {3:.1f} l litrazo. Automobilis yra {4} spalvos.", mar, mod, pm, lit,  spalva);

cout << rez << endl;


    return 0;
}
