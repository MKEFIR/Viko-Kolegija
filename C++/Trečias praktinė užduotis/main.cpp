#include <iostream>
#include <fstream>
#include <string>
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
void perzureti_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]);
void suma_Function (int n, const Uzsakymas uzs[]);
void suma_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]);
void parodyti_Function (int n, const Uzsakymas uzs[]);
void isaugoti_Function (int n, const Uzsakymas uzs[]);


    int main() {
        int n=0, m=1, meniu=0;
        Uzsakymas uzs[max_ilosc]; string Kategorijos[max_ilosc]={};

        ifstream fin("uzsakymas.txt");
        if (!fin.is_open()) {
            cout << "Nepavyko atidaryti failo.\n";
            perror("Reason");
            return 1;
        }

        fin>>n;
        if (n<=0) {
            cout << "Failas yra tuscias.\n";
            return 1;
        }else if (n>max_ilosc) {
            cout << "Failas yra per dydelis.\n";
            return 1;
        }
        for (int i = 0; i < n; i++) {
            getline(fin, uzs[i].typ, ';');
            getline(fin, uzs[i].nazwa, ';');
            getline(fin, uzs[i].cena, ';');
            getline(fin, uzs[i].ilosc);
            /*
            bool yra = false;
            for (int j = 0; j <= m; j++) {
                if (Kategorijos[j] == uzs[i].typ) {
                    yra = true;
                    break;
                }
            }
            if (!yra) {
                Kategorijos[m] = uzs[i].typ;
                m++;
            }*/
        }
        for (int j = 0; j < m; j++) {
            cout << Kategorijos[j] << ", ";
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
                perzureti_konk_Function (n, uzs, m, Kategorijos);
                break;
            case 3:
                cout<<"-  Perziureti viso uzsakymo sumas  -"<<endl;
                suma_Function (n, uzs);
                break;
            case 4:
                cout<<"-  Perziureti sumas pagal kategorijas  -"<<endl;
                suma_konk_Function (n, uzs, m, Kategorijos);
                break;
            case 5:
                cout<<"-  Parodyti visa uzsakymo ataskaita  -"<<endl;
                parodyti_Function (n, uzs);
                break;
            case 6:
                cout<<"-  Issaugoti visa ataskaita i faila  -"<<endl;
                isaugoti_Function (n, uzs);
                break;
            case 0:
                cout<<"Aciu kad naudojates musu paslaugus"<<endl;
                return 0;
            default:
                cout<<"-  Tokios funkcijos nera  -"<<endl;
            goto again;     }
        cout<<endl<<endl; goto beggining;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_Function(int n, const Uzsakymas uzs[]) {
        for (int i = 0; i < n; i++) {
            cout << uzs[i].typ << ", "
            << uzs[i].nazwa << endl;
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]) {
int kat;

        back:
        cout << "Irasykite Kokia kategorija norite apozvelgti\n";
        cout  << "1-Dviraciai\n2-Dalys\n3-Aksesuarai-\n0-Baigti\n";
        cin>>kat;

        if (kat == 1) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Dviraciai") {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == 2) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Dalys") {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == 3) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Aksesuarai") {
                    cout << uzs[i].typ << ", "
               << uzs[i].nazwa << ", "
               << uzs[i].cena << ", "
               << uzs[i].ilosc << endl;
                }
            }
        } else  if (kat == 0) { return;
        } else  if (kat != 1 && kat != 2 && kat != 3 && kat!=0) {
            cout << "Nera tokios kategorijos\n\n";
            goto back;
        }


    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void suma_Function (int n, const Uzsakymas uzs[]){
double suma=0;
        
        for (int i = 0; i < n; i++) {

            if (stoi(uzs[i].ilosc)>=10) {
                suma += 0.9*(stod(uzs[i].cena) * stoi(uzs[i].ilosc));
            }else {
            suma += (stod(uzs[i].cena) * stoi(uzs[i].ilosc));
            }
        }

        cout << "Suma lygu: " << suma << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void suma_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]){
double suma=0;
int kat;

        back:
        cout << "Irasykite Kokia kategorija norite apozvelgti\n";
        cout  << "1-Dviraciai\n2-Dalys\n3-Aksesuarai-\n0-Baigti\n";
        cin>>kat;

        if (kat == 1) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Dviraciai") {
                    if (stoi(uzs[i].ilosc)>=10) {
                        suma += 0.9*(stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }else {
                        suma += (stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }
                }
            }
        } else  if (kat == 2) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Dalys") {
                    if (stoi(uzs[i].ilosc)>=10) {
                        suma += 0.9*(stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }else {
                        suma += (stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }
                }
            }
        } else  if (kat == 3) {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ=="Aksesuarai") {
                    if (stoi(uzs[i].ilosc)>=10) {
                        suma += 0.9*(stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }else {
                        suma += (stod(uzs[i].cena) * stoi(uzs[i].ilosc));
                    }
                }
            }
        } else  if (kat == 0) { return;
        } else  if (kat != 1 && kat != 2 && kat != 3 && kat!=0) {
            cout << "Nera tokios kategorijos\n\n";
            goto back;
        }

        cout << "Suma lygu: " << suma << endl;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void parodyti_Function(int n, const Uzsakymas uzs[]) {
        for (int i = 0; i < n; i++) {
            cout << uzs[i].typ << ", "
            << uzs[i].nazwa << ", "
            << uzs[i].cena << ", "
            << uzs[i].ilosc << endl;
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isaugoti_Function (int n, const Uzsakymas uzs[]){
    ofstream fout("ataskaita.txt");

    for (int i = 0; i < n; i++) {
        fout << uzs[i].typ << ", "
        << uzs[i].nazwa << ", "
        << uzs[i].cena << ", "
        << uzs[i].ilosc << endl;
}}