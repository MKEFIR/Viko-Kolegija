#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <iomanip>

using namespace std;
const int max_ilosc=100;

struct Uzsakymas {
    string typ;
    string nazwa;
    string cena;   //stod
    string ilosc;  //stoi
};

void perzureti_Function (int n, const Uzsakymas uzs[]);
void perzureti_konk_Function (int n, const Uzsakymas uzs[]);
/*void _Function ();
void _Function ();
void _Function ();*/

    int main() {
        int n=0, m=0, meniu=0;
        Uzsakymas uzs[max_ilosc]; string Kategorijos[max_ilosc]={};

        ifstream fin("uzsakymas.txt");
        ofstream fout("ataskaita.txt");

        if (!fin.is_open()) {
            cout << "Nepavyko atidaryti failo.\n";
             return 1;
        }

        fin>>n;
        for (int i=0; i<n; i++) {
            getline(fin, uzs[i].typ, ';');
            getline(fin, uzs[i].nazwa, ';');
            getline(fin, uzs[i].cena, ';');
            getline(fin, uzs[i].ilosc);

            for (int j=0; j<m; j++) {


            }
        }


        beggining:
        cout << "\n-----  MENIU -----\n";
        cout << "1. Perziureti visas uzsakymo prekes\n";
        cout << "2. Perziureti pasirinktos kategorijos prekes\n";
        cout << "3. Perziureti viso uzsakymo sumas\n";
        cout << "4. Perziureti sumas pagal kategorijas\n";
        cout << "5. Parodyti visa uzsakymo ataskaita\n";
        cout << "6. Issaugoti visa ataskaita i faila\n";
        cout << "0. Iseiti\n";
        again:
        cout << "\nPasirinkite funkcija:\n";
        cin >> meniu;

        cout<<endl;
        ////////////////////////////////////////////////

        switch (meniu) {
            case 1:
                cout<<"-  Perziureti visas uzsakymo prekes  -"<<endl<<endl;
                perzureti_Function (n, uzs);
                break;
            case 2:
                cout<<"-  Perziureti pasirinktos kategorijos prekes  -"<<endl;
                perzureti_konk_Function (n, uzs);
                break;
            case 3:
                cout<<"-  Perziureti viso uzsakymo sumas  -"<<endl;

                break;
            case 4:
                cout<<"-  Perziureti sumas pagal kategorijas  -"<<endl;

                break;
            case 5:
                cout<<"-  Parodyti visa uzsakymo ataskaita  -"<<endl;

                break;
            case 6:
                cout<<"-  Issaugoti visa ataskaita i faila  -"<<endl;

                break;
            case 0:
                cout<<"Aciu kad naudojates musu paslaugus"<<endl;
                return 0;
            default:
                cout<<"-  Tokios funkcijos nera  -"<<endl;
            goto again;     }
        cout<<endl<<endl; goto beggining;
         return 0;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_Function(int n, const Uzsakymas uzs[]) {
        for (int i = 0; i < n; i++) {
            cout << uzs[i].typ << ", "
            << uzs[i].nazwa << ", "
            << uzs[i].cena << ", "
            << uzs[i].ilosc << endl;
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_konk_Function(int n, const Uzsakymas uzs[]) {
string kat;

        back:
        cout << "Irasyite \n";
        cout  << "-Dviraciai-, -Dalys- ar -Aksesuarai-\n-Baigti- kad baigti";
        cin>>kat;

        if (kat == "Dviraciai") {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ==kat) {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == "Dalys") {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ==kat) {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == "Aksesuarai") {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ==kat) {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == "Baigti") {
            cout << "\n";
            return;
        } else  if (kat != "Dviraciai" && kat != "Dalys" && kat != "Aksesuarai" && kat!="Baigti") {
            cout << "Nera tokios kategorijos\n\n";
            goto back;
        }


    }

