     #include <iostream>
    #include <fstream>
    //#include <iomanip>
    #include <string>
    #include <format>

    using namespace std;
    const int stud_max=100; const int grade_max_count=10;
    //const int min_grade=1; const int max_grade=10;

    void irasiti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n);

    int main() {
        int count=0, n=0, meniu=0, testi=0;
        //int students, grade; //Students - studentu kiekis; Grades - studentu pazymiu kiekis
        string NAMES[stud_max]={};
        int GRADES[stud_max][grade_max_count+1]={0};


        again:
        cout << "\n-----  MENIU -----\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        beggining:
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
                cout<<"-  Perziurėti visu mokiniu pazymius  -"<<endl;

                break;
            case 3:
                cout<<"-  Peržiūrėti konkretaus mokinio pažymius  -"<<endl;

                break;
            case 4:
                cout<<"-  Atnaujinti pazymį  -"<<endl;

                break;
            case 5:
                cout<<"-  Apskaiciuoti mokinio vidurkii  -"<<endl;

                break;
            case 6:
                cout<<"-  Pasalinti mokini  -"<<endl;

                break;
            case 0:
                cout<<"Aciu kad naudojates musu paslaugus"<<endl;
                return 0;
            default:
                cout<<"-  Tokios funkcijos nera  -"<<endl;
                goto beggining;}

        again1:
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
            goto again1;
        }



         return 0;
    }



void irasiti_Function (string NAMES[], int GRADES[][grade_max_count+1], int &count, int &n) {
        int add_stud;
back:
        if (count==0) {
            cout << "Studentu kiekis?\n";
        }else {
            cout << "Kiek dar studentu dateti?\n";}


        cin >> add_stud;
        count += add_stud;
        if (count >= stud_max) {
            cout << "Laiskas yra pilnas (" << stud_max << ").\n";
            count -= add_stud; goto back;
        } else if (count <= 0) {
            cout << "Laiskas yra tuscias.\n";
            count=0; goto back;
        }

        for (int i = 0; i < count; i++) {

            cout << "\nStudent " << i+1 << endl;
            cout << "Vardas: \n";
            cin>>ws;
            getline(cin, NAMES[i]);

                    cout << "Pazymiu kiekis\n";
                    cin>>n;
                GRADES[i][0] = n;
                for (int j = 1; j <= n; j++) {
                    cout<<"Pazymai\n";
                cin>>GRADES[i][j];
            }}
        for (int k = 0; k < count; k++) {

            cout << "\nStudent " << k+1 << endl;
            cout << "Vardas:" << NAMES[k]<<endl;
            GRADES[k][0] = n;cout<<"Pazymius\n";
            for (int l = 0; l < n; l++) {
                cout<<GRADES[k][l]<<endl;
            }

      }
    }