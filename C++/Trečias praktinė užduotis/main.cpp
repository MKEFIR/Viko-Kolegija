#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
const int max_ilosc=100;

struct Uzsakymas {
    string typ;
    string nazwa;
    string cena;   //stod
    string ilosc;  //stod
};

void perzureti_Function (int n, const Uzsakymas uzs[], int l, int ll);
void perzureti_konk_Function (int n, const Uzsakymas uzs[], int l, int ll, int lll, int m, const string Kategorijos[]);
void suma_Function (int n, const Uzsakymas uzs[]);
void suma_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]);
void parodyti_Function(int n, int l, int ll, int lll, const Uzsakymas uzs[]);
void isaugoti_Function (int n, int l, int ll, int lll, const Uzsakymas uzs[]);


    int main() {
        int n=0, m=1, meniu=0, l=0, ll=0, lll=0;
        Uzsakymas uzs[max_ilosc]; string Kategorijos[max_ilosc]={};

        ifstream fin("uzsakymas.txt");
        if (!fin.is_open()) {
            cout << "Nepavyko atidaryti failo.\n";
            perror("Reason");
            return 1;
        }

        fin>>n;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            bool yra = false;
            for (int j = 0; j < m; j++) {
                if (Kategorijos[j] == uzs[i].typ) {
                    yra = true;
                    break;
                }
            }
            if (!yra) {
                Kategorijos[m] = uzs[i].typ;
                m++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (l<uzs[i].typ.length()) {}
            l=uzs[i].typ.length();
        }l++;if (l<10) {l=10;}
        for (int i = 0; i < n; i++) {
            if (ll<uzs[i].nazwa.length()) {}
            ll=uzs[i].nazwa.length();
        }ll++;if (ll<6) {l=6;}
        for (int i = 0; i < n; i++) {
            if (lll<uzs[i].cena.length()) {}
            lll=uzs[i].cena.length();
        }lll+=2;
        cout << fixed << setprecision(2);

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
                perzureti_Function (n, uzs, l, ll);
                break;
            case 2:
                cout<<"-  Perziureti pasirinktos kategorijos prekes  -"<<endl;
                perzureti_konk_Function (n, uzs, l, ll, lll, m, Kategorijos);
                break;
            case 3:
                suma_Function (n, uzs);
                break;
            case 4:
                suma_konk_Function (n, uzs, m, Kategorijos);
                break;
            case 5:
                cout<<"-  Parodyti visa uzsakymo ataskaita  -"<<endl;
                parodyti_Function (n, l, ll, lll, uzs);
                break;
            case 6:
                cout<<"-  Issaugoti visa ataskaita i faila  -"<<endl;
                isaugoti_Function (n, l, ll, lll, uzs);
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
void perzureti_Function(int n, const Uzsakymas uzs[], int l, int ll) {
    int temp=l+ll+23;
        cout<<"Kategorija | Prekes";
        for (int i=0; i < ll-6; i++) {cout<<" ";}
        cout<<" |  Kaina  | Vnt |"<<endl;

        for (int i = 0; i < temp; i++) {cout<<"-";}
        cout<<endl;

        for (int i = 0; i < n; i++) {
            cout << uzs[i].typ;
            for (int j = 0; j < l-uzs[i].typ.length(); j++) {cout<<" ";}
            cout <<" | "<<uzs[i].nazwa;
            for (int k = 0; k < ll-uzs[i].nazwa.length(); k++) {cout<<" ";}
            cout<<" | "<< uzs[i].cena;
            for (int k = 0; k < 7-uzs[i].cena.length(); k++) {cout<<" ";}
            cout<<" | "<< uzs[i].ilosc;
            for (int k = 0; k < 3-uzs[i].ilosc.length(); k++) {cout<<" ";}
            cout<<" |\n";
        }

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_konk_Function (int n, const Uzsakymas uzs[], int l, int ll, int lll, int m, const string Kategorijos[]) {
int kat=0;

        back:
        cout << "Irasykite Kokia kategorija norite apozvelgti\n";
        for (int i = 1; i < m; i++) {
          cout << i <<"-"<<Kategorijos[i]<<endl;
        }
        cout  << "0-Baigti\n";
        cin>>kat;
        int temp=l+ll+23;
        cout<<"Kategorija | Prekes";
        for (int i=0; i < ll-6; i++) {cout<<" ";}
        cout<<" |  Kaina  | Vnt |"<<endl;

        for (int i = 0; i < temp; i++) {cout<<"-";}
        cout<<endl;
        if (kat == 0) { return;
        } else  if (kat < 0 || kat >= m) {
            cout << "Nera tokios kategorijos\n\n";
            goto back;
        } else {
           for (int i = 0; i < n; i++) {
                if (uzs[i].typ==Kategorijos[kat]) {
                    cout << uzs[i].typ;
                    for (int j = 0; j < l-uzs[i].typ.length(); j++) {cout<<" ";}
                    cout <<" | "<<uzs[i].nazwa;
                    for (int k = 0; k < ll-uzs[i].nazwa.length(); k++) {cout<<" ";}
                    cout<<" | "<< uzs[i].cena;
                    for (int k = 0; k < 7-uzs[i].cena.length(); k++) {cout<<" ";}
                    cout<<" | "<< uzs[i].ilosc;
                    for (int k = 0; k < 3-uzs[i].ilosc.length(); k++) {cout<<" ";}
                    cout<<" |\n";
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void suma_Function (int n, const Uzsakymas uzs[]){
double suma=0, result=0;
        
        for (int i = 0; i < n; i++) {
            suma += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
            if (stod(uzs[i].ilosc)>=10) {
                result += 0.9*(stod(uzs[i].cena) * stod(uzs[i].ilosc));
            }else {
            result += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
            }
        }
        cout<<"-----Viso uzsakymo sumas----"<<endl;
        if (suma-result == 0) {
            cout <<"| Moketina suma: " << suma << endl;
        } else {
            cout <<"| Suma lygu: " << suma << endl;
            cout <<"| Nuakaida: " << suma-result << endl;
            cout <<"| Moketina suma: " << result << endl;
        }
        cout <<"----------------------------";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void suma_konk_Function (int n, const Uzsakymas uzs[], int m, const string Kategorijos[]){
double suma=0, result=0;
int kat;
        back:
        cout << "Irasykite Kokia kategorija norite apozvelgti\n";
        for (int i = 1; i < m; i++) {
            cout << i <<"-"<<Kategorijos[i]<<endl;
        }
        cout  << "0-Baigti\n";
        cin>>kat;

        if (kat == 0) { return;
        } else  if (kat < 0 || kat >= m) {
            cout << "Nera tokios kategorijos\n\n";
            goto back;
        } else {
            for (int i = 0; i < n; i++) {
                if (uzs[i].typ==Kategorijos[kat]) {
                    suma += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
                    if (stod(uzs[i].ilosc)>=10) {
                        result += 0.9*(stod(uzs[i].cena) * stod(uzs[i].ilosc));
                    }else {
                        result += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
        }   }   }   }
        cout<<"---Kategorijos uzsakymo sumas---"<<endl;
        cout <<"| Kategorija: "<<Kategorijos[kat]<<endl;
        if (suma-result == 0) {
        cout << "| Moketina suma: " << suma << endl;
        } else {
        cout << "| Suma lygu: " << suma << endl;
        cout << "| Nuakaida: " << suma-result << endl;
        cout << "| Moketina suma: " << result << endl;
    }   cout <<"-------------------------------";}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void parodyti_Function(int n, int l, int ll, int lll, const Uzsakymas uzs[]) {

        int temp=l+ll+lll+12;
        cout<<"Kategorija | Prekes";
        for (int i=0; i < ll-6; i++) {cout<<" ";}
        cout<<" |   Suma   | Noulaida | Galutine suma"<<endl;

        for (int i = 0; i < temp; i++) {cout<<"-";}
        cout<<endl;

        for (int i = 0; i < n; i++) {
        double suma=0, result=0;
            cout << uzs[i].typ;
            for (int j = 0; j < l-uzs[i].typ.length(); j++) {cout<<" ";}
            cout <<" | "<< uzs[i].nazwa;
            for (int k = 0; k < ll-uzs[i].nazwa.length(); k++) {cout<<" ";}
            cout <<" | ";

                    suma += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
                    if (stod(uzs[i].ilosc)>=10) {
                        result += 0.9*(stod(uzs[i].cena) * stod(uzs[i].ilosc));
                    }else {
                        result += (stod(uzs[i].cena) * stod(uzs[i].ilosc));
                    }
            if (suma-result == 0) {
                cout << suma << endl;
            } else {
                cout << suma <<" | "<<suma-result <<" | "<< result<<endl;
            }

            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isaugoti_Function (int n, int l, int ll, int lll, const Uzsakymas uzs[]){
            ofstream fout("ataskaita.txt");
            if (!fout.is_open()) {
                cout << "Nepavyko atidaryti failo.\n";
                perror("Reason");
                return;
            }

            fout << fixed << setprecision(2);
            int temp=l+ll+lll+12;
            fout<<"Kategorija | Prekes"<<endl;
            for (int i=0; i < ll-6; i++) {fout<<" ";}
            fout<<"|";

            for (int i = 0; i < temp; i++) {fout<<"-";}
            fout<<endl;

            for (int i = 0; i < n; i++) {
                fout << uzs[i].typ;
                for (int j = 0; j < l-uzs[i].typ.length(); j++) {fout<<" ";}
                fout <<" | "<< uzs[i].nazwa;
                for (int k = 0; k < ll-uzs[i].nazwa.length(); k++) {fout<<" ";}
                fout <<" | ";
                fout<< uzs[i].cena;
                for (int l = 0; l < lll-uzs[i].cena.length(); l++) {fout<<" ";}
                fout<< " | "<< uzs[i].ilosc << endl;
            }
        }