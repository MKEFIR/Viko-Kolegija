#include <iostream>
#include <string>

using namespace std;

int main() {
string vardas, pavarde, grupe, spp;
    int amzius, kursas;

    cout << "Parasyk savo Varda, Pavarde ir amzius" << endl;
     cin >> vardas >> pavarde >>amzius;
    cout << "dabar amzius Grupe, Kursas ir Studiju programos pavadinimas" << endl;
     cin >> grupe >> kursas >> spp;

    cout << vardas << " " << pavarde << " " << amzius << "m. yra " << grupe << "grupe ant "<< kursas << " kurso, " <<spp;

    return 0;
}