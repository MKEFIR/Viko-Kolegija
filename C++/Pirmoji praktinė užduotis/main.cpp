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


void Palyginimas_FUNKCIJA(int valiuta);
void Pardavimas_FUNKCIJA(int valiuta);
void Pirkimas_FUNKCIJA(int valiuta);


int main() {
    int valiuta = 0, meniu = 0, testi=0;
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
            cout<<"-  Tokios funkcijos nera  -"<<endl;
            goto beggining;}

            cout <<endl<<endl<< "//////////////////////////////" <<endl<< "Norite atlikti kita operacija?" <<endl;
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
    void Palyginimas_FUNKCIJA (int valiuta) {
    int side;
    beggining:
        cout << "Pasirinkite valiuta" << endl;
    cout<< "GBP - 1\nUSD - 2\nINR - 3" <<endl;
    cin>>valiuta;
        if (valiuta == 1) {
            cout << "Keisti GBP i EUR - 1\nKeisti EUR i GBP - 2"<<endl;
                cin >> side;
            if (side == 1){cout << "1 EUR = " << GBP_Bendras << " GBP" <<endl;}
            else if (side == 2){cout << "1 GBP = " << 1/GBP_Bendras << " EUR" <<endl;}
            else
            {cout << "---  Tokios operacijos nera  ---" <<endl; goto beggining;}
        }else if (valiuta == 2) {
            cout << "Keisti USD i EUR - 1\nKeisti EUR i USD - 2"<<endl;
            cin >> side;
            if (side == 1){cout << "1 EUR = " << USD_Bendras << " USD" <<endl;}
            else if (side == 2){cout << "1 USD = " << 1/USD_Bendras << " EUR" <<endl;}
            else
            {cout << "---  Tokios operacijos nera  ---" <<endl; goto beggining;}
        }else if (valiuta == 3) {
            cout << "Keisti INR i EUR - 1\nKeisti EUR i INR - 2"<<endl;
            cin >> side;
            if (side == 1){cout << "1 EUR = " << INR_Bendras << " INR" <<endl;}
            else if (side == 2){cout << "1 INR = " << 1/INR_Bendras << " EUR" <<endl;}
            else
            {cout << "---  Tokios operacijos nera  ---" <<endl; goto beggining;}
        }else {
            cout << "Tokios valiutos nera"<<endl;
            goto beggining;
        }
    }
    void Pirkimas_FUNKCIJA (int valiuta) {
        double kiekis, answer;
    beggining:
        cout << "Pasirinkite valiuta" << endl;
    cout<< "GBP - 1\nUSD - 2\nINR - 3" <<endl;
        cin>>valiuta;
        if (valiuta == 1) {
            cout << "1 EUR = " << GBP_Pirkti << " GBP" <<endl;
            Beg_GBP:
                    cout << "Kiek nori pirkti GBP kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_GBP;}      answer = kiekis /GBP_Pirkti;
            cout << "GBP " << kiekis << " = " << answer << " Eur" << endl;

        }else if (valiuta == 2) {
            cout << "1 EUR = " << USD_Pirkti << " USD" <<endl;
            Beg_USD:
            cout << "Kiek nori pirkti USD kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_USD;}  answer = kiekis / USD_Pirkti;
            cout << "USD " << kiekis << " = " << answer << " Eur" << endl;

        }else if (valiuta == 3) {
            cout << "1 EUR = " << INR_Pirkti << " INR" <<endl;
            Beg_INR:
            cout << "Kiek nori pirkti INR kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_INR;}  answer = kiekis / INR_Pirkti;
            cout << "INR " << kiekis << " = " << answer << " Eur" << endl;

        }else {
            cout << "Tokios valiutos nera" <<endl;
            goto beggining;
        }}
    void Pardavimas_FUNKCIJA (int valiuta) {
        double kiekis, answer;
        beggining:
           cout << "Pasirinkite valiuta" << endl;
    cout<< "GBP - 1\nUSD - 2\nINR - 3" <<endl;
        cin>>valiuta;
        if (valiuta == 1) {
            cout << "1 EUR = " << GBP_Parduoti << " GBP" <<endl;
            Beg_GBP:
                    cout << "Kiek nori parduoti GBP kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_GBP;}      answer = kiekis / GBP_Parduoti;
            cout << "GBP " << kiekis << " = " << answer << " Eur" << endl;

        }else if (valiuta == 2) {
            cout << "1 EUR = " << USD_Parduoti << " USD" <<endl;
            Beg_USD:
            cout << "Kiek nori parduoti USD kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_USD;}  answer = kiekis / USD_Parduoti;
            cout << "USD " << kiekis << " = " << answer << " Eur" << endl;

        }else if (valiuta == 3) {
            cout << "1 EUR = " << INR_Parduoti << " INR" <<endl;
            Beg_INR:
            cout << "Kiek nori parduoti INR kiekis?" <<endl;
            cin>>kiekis;       if (kiekis <= 0) {
                cout << "Iveskite daugiau 0" <<endl;
                goto Beg_INR;}  answer = kiekis / INR_Parduoti;
            cout << "INR " << kiekis << " = " << answer << " Eur" << endl;

        }else {
            cout << "Tokios valiutos nera" <<endl;
            goto beggining;
        }
    }