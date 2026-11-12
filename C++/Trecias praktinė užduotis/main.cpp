#include <iostream>
#include <fstream>
//#include <iomanip>
#include <string>
#include <format>
#include <iomanip>

using namespace std;
const int stud_max=100; const int grade_max_count=10;
const int min_grade=1; const int max_grade=10;

void irasiti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);
void perzureti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);
void perzureti_konk_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);
void atnaujinti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);
void vidutinis_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);
void pasalinti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);

    int main() {
        int count=0, n=0, meniu=0;  //count - kiek dabar studentu sarase
        string NAMES[stud_max]={};
        int GRADES[stud_max][grade_max_count+1]={0};


        beggining:
        cout << "\n-----  MENIU -----\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        again:
        cout << "\nPasirinkite funkcija:\n";
        cin >> meniu;

        cout<<endl;
        ////////////////////////////////////////////////

        switch (meniu) {
            case 1:
                cout<<"-  Ivesti mokini ir jo pazymius  -"<<endl<<endl;
                irasiti_Function (NAMES, GRADES, count, n);
                break;
            case 2:
                cout<<"-  Perziureti visu mokinio pazymius  -"<<endl;
                perzureti_Function (NAMES, GRADES, count, n);
                break;
            case 3:
                cout<<"-  Perziureti konkretaus mokinio pazymius  -"<<endl;
                perzureti_konk_Function (NAMES, GRADES, count, n);
                break;
            case 4:
                cout<<"-  Atnaujinti pazymi  -"<<endl;
                atnaujinti_Function (NAMES, GRADES, count, n);
                break;
            case 5:
                cout<<"-  Apskaiciuoti mokinio vidurkii  -"<<endl;
                vidutinis_Function (NAMES, GRADES, count, n);
                break;
            case 6:
                cout<<"-  Pasalinti mokini  -"<<endl;
                pasalinti_Function (NAMES, GRADES, count, n);
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
void irasiti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
        int add_stud;
        repeat:
        if (count==0) {
            cout << "Studentu kiekis?\n";
        }else {
            cout << "Kiek dar studentu dateti?\n";
        }                                                                                                                        //gfvbbbbbbbbbbbs - mano katinas
            int now=count;   //now kiek studentu pries detames daugiau
            cin >> add_stud;
            count += add_stud;      //add_stud naudojama kad galima prideti daugiau
            if (count>stud_max) {
                cout<<"Studentu kiekis virs limito. Limitas - "<<stud_max<<endl;
                count=now;    //griztem pries virsat limita
                goto repeat;
            }

            for (int i = now; i < count; i++) {

                cout << "\nStudentas " << i+1 << endl;
                cout << "Vardas: \n";
                cin>>ws;
                getline(cin, NAMES[i]);
                back1:
                    cout << "Pazymiu kiekis\n";
                cin>>n;                     //rasikite tik vieno skaitmeni
                if (n>grade_max_count) {    //ar ne virsam studentu limita
                    cout << "-- Maximalus imanoma pazymiu kiekis yra "<<grade_max_count<<" --\n";
                    goto back1;
                }
                GRADES[i][0] = n; cout<<"Pazymai ( "<<min_grade<<" - "<<max_grade<<" )\n";
                for (int j = 1; j <= n; j++) {repeat1:
                cin>>GRADES[i][j];
                    if (GRADES[i][j]<min_grade || GRADES[i][j]>max_grade) { //ar irasom gerai pazymius
                        cout << format("Pazymis turi buti tarp {0} ir {1}\n", min_grade, max_grade);
                        goto repeat1;}
                }}
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n){
        if (count==0) {             //jeigu sarase nieko nera
            cout << "---  Sarasas Tuscias  ---\n";
        } else{

        for (int k = 0; k < count; k++) {   //israso visas sarasas
            cout<<endl<< "\nStudentas Nr." << k+1 << endl;
            cout << "Vardas:" << NAMES[k]<<endl;
            n=GRADES[k][0];cout<<"Pazymius:";
            if (n==0) {
               cout <<" nera\n";
            }else {
            for (int l = 1; l <= n; l++) {
                cout<<" "<<GRADES[k][l];
            }}
        }}}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void perzureti_konk_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
        char testi; int x=0; back:
            if (count==0) {
                cout << "---  Sarasas Tuscias  ---\n"; return;
            }
                cout<<"Studentas Nr. (1-"<<count<<")\n";
                cin>>n;
                if (n>count) {
                    cout << "Tokio studento nera";
                    goto back;}

                cout<<endl;
                n--;
                cout << "Vardas:" << NAMES[n]<<endl;
                x=GRADES[n][0];cout<<"Pazymius:";
                if (x==0) {
                    cout <<" nera\n";
                }else {
                    for (int l = 1; l <= x; l++) {
                        cout<<" "<<GRADES[n][l];
                    }}
            again:                  //galima dar pakartoti, ne iseidami is funkcijos
    cout << "\n\nAr norit dar pakartoti? (y/n)\n";
            cin>>testi;
            if (testi=='y') {
                goto back;
            } else if (testi!='y' && testi!='n'){
                cout <<"Tokios komandos nera\n"; goto again;}
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void atnaujinti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
    char testi; int x=0; back:
    if (count==0) {
        cout << "---  Sarasas Tuscias  ---\n"; return;
    }
        cout<<"Kam norit atnaujinti pazymius?\nStudentas Nr. (1-"<<count<<")\n";
        cin>>n; cout<<endl;
        if (n>count) {
            cout << "\n\nTokio studento nera\n";
            goto back;}
        n--;
        again1:      //klause jeigu bloga studentu numera buve ivestas
        cout <<"Tikrai norite atnaujinti "<< NAMES[n]<<" pazymius?\n (y/n)\n";
        cin>>testi;
        if (testi=='y') {
            cout << "Vardas:" << NAMES[n]<<endl;
            x=GRADES[n][0];cout<<"Pazymius:";
            if (x==0) {
                cout <<" nera\n";
            }else {
                for (int l = 1; l <= x; l++) {
                    cout<<" "<<GRADES[n][l];
                }}


            cout <<"\n\n---  Pazymius bus uzrasytos per naujos  ---\n";back_again:
            cout << "Pazymiu kiekis\n";
            cin>>x;
            if (x>grade_max_count) {
                cout << "-- Maximalus imanoma pazymiu kiekis yra "<<grade_max_count<<" --\n";
                goto back_again;
            }
            GRADES[n][0] = x; cout<<"Pazymai ( "<<min_grade<<" - "<<max_grade<<" )\n";
            for (int j = 1; j <= x; j++) {repeat:
                cin>>GRADES[n][j];
                if (GRADES[n][j]<min_grade || GRADES[n][j]>max_grade) {
                    cout << format("Pazymis turi buti tarp {0} ir {1}\n", min_grade, max_grade);
                    goto repeat;}}

                //rodo rezultata
            cout << "\n\nVardas:" << NAMES[n]<<endl;
            x=GRADES[n][0];cout<<"Pazymius:";
            if (x==0) {
                cout <<" nera\n";
            }else {
                for (int l = 1; l <= x; l++) {
                    cout<<" "<<GRADES[n][l];
                }}
        }else if (testi!='y' && testi!='n'){
            cout <<"Tokios komandos nera\n"; goto again1;}
     again:
cout << "\n\nAr norit dar pakartoti? (y/n)\n";
     cin>>testi;
     if (testi=='y') {
         goto back;
     } else if (testi!='y' && testi!='n'){
         cout <<"Tokios komandos nera\n"; goto again;}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void vidutinis_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
        char testi; int x=0; double average=0; back:
            if (count==0) {
                cout << "---  Sarasas Tuscias  ---\n"; return;
            } else{
                cout<<"Studentas Nr. (1-"<<count<<")\n";
                cin>>n; cout<<endl;
                if (n>count) {
                    cout << "\n\nTokio studento nera\n";
                    goto back;}
                n--;
                cout << "Vardas:" << NAMES[n]<<endl;
                x=GRADES[n][0];cout<<"Pazymius:";
                if (x==0) {
                    cout <<" nera\n";
                    cout<<"Pazymius vidurkis: nera\n";
                }else {
                    for (int l = 1; l <= x; l++) {
                        cout<<" "<<GRADES[n][l];
                    }cout<<endl;
                ;cout<<"Pazymius vidurkis:";
                for (int l = 1; l <= x; l++) {
                    average += GRADES[n][l];
                }
                cout <<setprecision(2)<<average/x<<endl;}
            }average=0;
    again:
cout << "\n\nAr norit dar pakartoti? (y/n)\n";
    cin>>testi;
    if (testi=='y') {
        goto back;
    } else if (testi!='y' && testi!='n'){
        cout <<"Tokios komandos nera\n"; goto again;
    }}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pasalinti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
        string Temp[stud_max];
        int TEMP[stud_max][grade_max_count+1]={0}, temp;
        char testi; back:
            if (count==0) {
                cout << "---  Sarasas Tuscias  ---\n"; return;
            }
                cout<<"Koki studento norite pasalinti?\nStudentas Nr. (1-"<<count<<")\n";
                cin>>n; cout<<endl;
                if (n>count) {
                    cout << "\n\nTokio studento nera\n";
                    goto back;}
                n--;again:
                cout <<"Tikrai norite pasalinti "<< NAMES[n]<<"?\n (y/n)\n";
        cin>>testi;
        if (testi=='y') {
            cout <<NAMES[n]<<"Pasalintas is sistemos\n";
            for (int k = n; k <= count; k++) {
                    Temp[k] = NAMES[k+1];
                NAMES[k] = Temp[k];
                temp=GRADES[k][0];
                GRADES[k][0]=0;//vietu pazymiu vel irasa 0, kad jeigu pasalintas mokinys turi daugiau nei kitas
                for (int j = 1; j <= temp; j++) {
                    GRADES[k][j]=0;
                }
                temp=GRADES[k+1][0];
                GRADES[k][0]=temp;
                for (int l = 1; l <= temp; l++) {
                    TEMP[k][l]=GRADES[k+1][l];
                    GRADES[k][l]=TEMP[k][l];

                }

         }count--;} else if (testi!='y' && testi!='n'){
            cout <<"Tokios komandos nera\n"; goto again;}


        again1:
cout << "\n\nAr norit dar pakartoti? (y/n)\n";
        cin>>testi;
        if (testi=='y') {
            goto back;
        } else if (testi!='y' && testi!='n'){
            cout <<"Tokios komandos nera\n"; goto again1;}
    }