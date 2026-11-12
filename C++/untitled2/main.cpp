#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <format>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////Constantai/////////////////

const double GBP_Bendras   = 0.8729;
const double GBP_Pirkti    = 0.8600;
const double GBP_Parduoti  = 0.9220;

const double USD_Bendras   = 1.1793;
const double USD_Pirkti    = 1.1460;
const double USD_Parduoti  = 1.2340;

const double INR_Bendras   = 104.6918;
const double INR_Pirkti    = 101.3862;
const double INR_Parduoti  = 107.8546;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;


void Palyginimas_FUNKCIJA(string valiuta);
void Pardavimas_FUNKCIJA(string valiuta);
void Pirkimas_FUNKCIJA(string valiuta);


int main() {
    string valiuta;




    int meniu = 0, testi=0;
    // meniu - pasirinkimas meniu /

    ////////////////////////////////////////////////
again:
    cout << "\n-----  MENIU -----\n";
    cout << "Galimos valiutos: \nEur, GBP, USD INR\n";
    cout << "1. Palyginti valiuta\n";
    cout << "2. Pirkti  valiuta\n";
    cout << "3. Parduoti valiuta\n";
    cout << "0. Baigti programa\n";
    beggining:
    cout << "\nPasirinkite funkcija:\n";
    cin >> meniu;

    cout<<endl;
    ////////////////////////////////////////////////

    switch (meniu) {
        case 1:
            cout<<"-  Valiuto palyginimas  -"<<endl<<endl;
            Palyginimas_FUNKCIJA (valiuta);
            break;
        case 2:
            cout<<"-  Valiuto  pirkimas  -"<<endl;
            Pirkimas_FUNKCIJA( valiuta);
            break;
        case 3:
            cout<<"-  Valiuto pardavimas  -"<<endl;
            Pardavimas_FUNKCIJA(valiuta);
            break;

        case 0:
            cout<<"Aciu kad naudojates musu paslaugus"<<endl;
            break;
        default:
            cout<<"-  Tokios operacijos nera  -"<<endl;
            goto beggining;
    }

    cout <<endl<<endl<< "Norite atlikti kita operacija?" <<endl;
    cout << "0 -> NE\n1 -> TAIP" <<endl;
    cin >> testi;
    if (testi==0) {
        cout<<"Aciu kad naudojates musu paslaugus"<<endl;
        return testi;
    } else if (testi==1) {
        goto again;
    }else {
        cout << "---  Tokios operacijos nera  ---" <<endl;
    }



    return 0;
}


///////Funkcijos////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Palyginimas_FUNKCIJA (string valiuta) {


cout<< "Pasirinkite valiuta:" << endl;
    beggining:
        cout<< "GBP, USD ar INR - " <<endl;
        cin>>valiuta;
        if (valiuta == "GBP") {
            cout << "1 EUR = " << GBP_Bendras << " GBP";
        }else if (valiuta == "USD") {
            cout << "1 EUR = " << USD_Bendras << " USD";
        }else if (valiuta == "INR") {
            cout << "1 EUR = " << INR_Bendras << " INR";
        }else {
            cout << "Tokios valiutos nera"<<endl;
            goto beggining;
        }
}
void Pardavimas_FUNKCIJA (string valiuta) {
double kiekis, answer;
cout << "Pasirinkite valiuta" << endl;
    beggining:
        cout<< "GBP, USD ar INR - " <<endl;
        cin>>valiuta;
if (valiuta == "GBP") {
            cout << "1 EUR = " << GBP_Pirkti << " GBP" <<endl;
    Beg_GBP:
            cout << "Kiek nori pirkti " << valiuta << " kiekis?" <<endl;
cin>>kiekis;       if (kiekis <= 0) {
    cout << "Iveskite daugiau 0" <<endl;
    goto Beg_GBP;}      answer = GBP_Pirkti * kiekis;
    cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

        }else if (valiuta == "USD") {
            cout << "1 EUR = " << USD_Pirkti << " USD" <<endl;
            Beg_USD:
            cout << "Kiek nori pirkti " << valiuta << " kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_USD;}  answer = USD_Pirkti * kiekis;
            cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

        }else if (valiuta == "INR") {
            cout << "1 EUR = " << INR_Pirkti << " INR" <<endl;
            Beg_INR:
            cout << "Kiek nori pirkti " << valiuta << " kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_INR;}  answer = INR_Pirkti * kiekis;
            cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

        }else {
            cout << "Tokios valiutos nera" <<endl;
            goto beggining;
}}
void Pirkimas_FUNKCIJA (string valiuta) {
    double kiekis, answer;
    cout << "Pasirinkite valiuta" << endl;
    beggining:
        cout<< "GBP, USD ar INR - " <<endl;
    cin>>valiuta;
    if (valiuta == "GBP") {
        cout << "1 EUR = " << GBP_Parduoti << " GBP" <<endl;
        Beg_GBP:
                cout << "Kiek nori parduoti " << valiuta << " kiekis?" <<endl;
        cin>>kiekis;       if (kiekis <= 0) {
            cout << "Iveskite daugiau 0" <<endl;
            goto Beg_GBP;}      answer = GBP_Parduoti * kiekis;
        cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

    }else if (valiuta == "USD") {
        cout << "1 EUR = " << USD_Parduoti << " USD" <<endl;
        Beg_USD:
        cout << "Kiek nori parduoti " << valiuta << " kiekis?" <<endl;
        cin>>kiekis;       if (kiekis <= 0) {
            cout << "Iveskite daugiau 0" <<endl;
            goto Beg_USD;}  answer = USD_Parduoti * kiekis;
        cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

    }else if (valiuta == "INR") {
        cout << "1 EUR = " << INR_Parduoti << " INR" <<endl;
        Beg_INR:
        cout << "Kiek nori parduoti " << valiuta << " kiekis?" <<endl;
        cin>>kiekis;       if (kiekis <= 0) {
            cout << "Iveskite daugiau 0" <<endl;
            goto Beg_INR;}  answer = INR_Parduoti * kiekis;
        cout << "Eur "<< kiekis << " = " << answer << valiuta << endl;

    }else {
        cout << "Tokios valiutos nera" <<endl;
        goto beggining;
    }
}