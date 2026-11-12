#include <iostream>
#include <fstream>
using namespace std;

void sukeisti(int &pirmas, int &antras);

int main() {
    int pirmas, antras;
 cout << "Iveskite pirma ir antra skacis" << endl;
cin >> pirmas;cin >> antras;

    sukeisti(pirmas, antras);


cout << pirmas << " " << antras << endl;

return 0;
}



void sukeisti(int &pirmas, int &antras) {
    int temp;

    temp = pirmas;
    pirmas = antras;
    antras = temp;

}