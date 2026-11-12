#include <iostream>
#include <fstream>

double skaiciuotiPlota(double, double, double);
double skaiciuotiPerimetra(double, double, double);

using namespace std;

int main() {

    double ilgis=0, plotis=0, plotas=0, perimetras=0;
    int choice;

    cout << "Iveskite Plotis it Ilgis\n";
    cout << "Plotis -\n";
    cin >> plotis;
    cout << "Ilgis -\n";
    cin >> ilgis;

    beggining:
    cout << "\n Apskaciuoti plota ar perimetra?";
    cout << "\nPlotas - 1\n";
    cout << "Perimetras - 2\n";
    cin >> choice;
    switch (choice) {
        case 1:
            plotas = skaiciuotiPlota(ilgis,  plotis,  plotas);
            cout << "Staciakampio plotas = "<<plotas;
            break;
        case 2:
            perimetras = skaiciuotiPerimetra(ilgis,  plotis,  perimetras);
            cout << "Staciakampio perimetras = " <<perimetras;
            break;
        default:
            cout<<"-  Tokios funkcijos nera  -"<<endl;
            goto beggining;}
    return 0;}



double skaiciuotiPlota(double ilgis, double plotis, double plotas) {

    plotas=ilgis*plotis;

    return plotas;
}

double skaiciuotiPerimetra(double ilgis, double plotis, double perimetras) {

    perimetras=2*(ilgis+plotis);

    return perimetras;
    cout <<endl<< plotis <<endl;
    cout <<endl<< ilgis <<endl;
    cout << "Staciakampio perimetras - " <<perimetras;
}