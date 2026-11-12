#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

const int stud_max = 100;
const int grade_max_count = 10;
const int min_grade = 1;
const int max_grade = 10;

void irasiti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);
void perzureti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);
void perzureti_konk_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);
void atnaujinti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);
void vidutinis_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);
void pasalinti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n);

////////////////////////////////////////////////////////////////////////////////

int readInt(int min, int max) {
    string line;
    while (true) {
        if (!getline(cin, line)) exit(0);

        try {
            size_t pos;
            int value = stoi(line, &pos);
            while (pos < line.size() && isspace(static_cast<unsigned char>(line[pos]))) pos++;

            if (pos == line.size() && value >= min && value <= max) {
                return value;
            }
        } catch (...) {}

        cout << "Iveskite sveika skaiciu nuo " << min << " iki " << max << ":\n";
    }
}

char readYesNo() {
    string line;
    while (true) {
        if (!getline(cin, line)) exit(0);
        if (line == "y" || line == "n") return line[0];
        cout << "Tokios komandos nera. Iveskite y arba n:\n";
    }
}

////////////////////////////////////////////////////////////////////////////////

int main() {
    int count = 0, n = 0, meniu = 0;
    string NAMES[stud_max] = {};
    int GRADES[stud_max][grade_max_count + 1] = {0};

    while (true) {
        cout << "\n-----  MENIU -----\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "\nPasirinkite funkcija:\n";

        meniu = readInt(0, 6);
        cout << endl;

        switch (meniu) {
            case 1:
                cout << "-  Ivesti mokini ir jo pazymius  -" << endl << endl;
                irasiti_Function(NAMES, GRADES, count, n);
                break;
            case 2:
                cout << "-  Perziureti visu mokinio pazymius  -" << endl;
                perzureti_Function(NAMES, GRADES, count, n);
                break;
            case 3:
                cout << "-  Perziureti konkretaus mokinio pazymius  -" << endl;
                perzureti_konk_Function(NAMES, GRADES, count, n);
                break;
            case 4:
                cout << "-  Atnaujinti pazymi  -" << endl;
                atnaujinti_Function(NAMES, GRADES, count, n);
                break;
            case 5:
                cout << "-  Apskaiciuoti mokinio vidurki  -" << endl;
                vidutinis_Function(NAMES, GRADES, count, n);
                break;
            case 6:
                cout << "-  Pasalinti mokini  -" << endl;
                pasalinti_Function(NAMES, GRADES, count, n);
                break;
            case 0:
                cout << "Aciu kad naudojates musu paslaugus" << endl;
                return 0;
        }
        cout << endl << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////
void irasiti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    if (count >= stud_max) {
        cout << "Studentu kiekis virs limito. Limitas - " << stud_max << endl;
        return;
    }int now = count;
    repeat:
    if (count == 0) {
        cout << "Studentu kiekis? (1-" << stud_max << ")\n";
    } else {
        cout << "Kiek dar studentu dateti? (1-" << stud_max - count << ")\n";
    }

                              // kiek studentu buvo pries pridedant
    int add_stud = readInt(1, stud_max - count);
    count += add_stud;
    if (count>stud_max) {
        cout<<"Studentu kiekis virs limito. Limitas - "<<stud_max<<endl;
        count=now;    //griztem pries virsat limita
        goto repeat;
    }

    for (int i = now; i < count; i++) {
        cout << "\nStudentas " << i + 1 << endl;
        cout << "Vardas: \n";
        getline(cin, NAMES[i]);

        cout << "Pazymiu kiekis (0-" << grade_max_count << ")\n";
        n = readInt(0, grade_max_count);
        GRADES[i][0] = n;

        if (n > 0) cout << "Pazymiai ( " << min_grade << " - " << max_grade << " )\n";
        for (int j = 1; j <= n; j++) {
            GRADES[i][j] = readInt(min_grade, max_grade);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void perzureti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    if (count == 0) {
        cout << "---  Sarasas Tuscias  ---\n";
        return;
    }

    for (int k = 0; k < count; k++) {
        cout << endl << "\nStudentas Nr." << k + 1 << endl;
        cout << "Vardas: " << NAMES[k] << endl;
        n = GRADES[k][0];
        cout << "Pazymius:";
        if (n == 0) {
            cout << " nera\n";
        } else {
            for (int l = 1; l <= n; l++) {
                cout << " " << GRADES[k][l];
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void perzureti_konk_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    char testi;
    int x = 0;

    if (count == 0) {
        cout << "---  Sarasas Tuscias  ---\n";
        return;
    }

    do {
        cout << "Studentas Nr. (1-" << count << ")\n";
        n = readInt(1, count);
        n--;

        cout << endl;
        cout << "Vardas: " << NAMES[n] << endl;
        x = GRADES[n][0];
        cout << "Pazymius:";
        if (x == 0) {
            cout << " nera\n";
        } else {
            for (int l = 1; l <= x; l++) {
                cout << " " << GRADES[n][l];
            }
        }

        cout << "\n\nAr norit dar perzureti? (y/n)\n";
        testi = readYesNo();
    } while (testi == 'y');
}

////////////////////////////////////////////////////////////////////////////////
void atnaujinti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    char testi;
    int x = 0;

    if (count == 0) {
        cout << "---  Sarasas Tuscias  ---\n";
        return;
    }

    do {
        cout << "Kam norit atnaujinti pazymius?\nStudentas Nr. (1-" << count << ")\n";
        n = readInt(1, count);
        cout << endl;
        n--;

        cout << "Vardas: " << NAMES[n] << endl;
        x = GRADES[n][0];
        cout << "Pazymius:";
        if (x == 0) {
            cout << " nera\n";
        } else {
            for (int l = 1; l <= x; l++) {
                cout << " " << GRADES[n][l];
            }
        }

        cout << "\n\n---  Pazymius bus uzrasytos per naujos  ---\n";
        cout << "Pazymiu kiekis (0-" << grade_max_count << ")\n";
        x = readInt(0, grade_max_count);

        // isvalome senus pazymius
        for (int j = 0; j <= grade_max_count; j++) GRADES[n][j] = 0;

        GRADES[n][0] = x;
        if (x > 0) cout << "Pazymiai ( " << min_grade << " - " << max_grade << " )\n";
        for (int j = 1; j <= x; j++) {
            GRADES[n][j] = readInt(min_grade, max_grade);
        }

        cout << "\n\nVardas: " << NAMES[n] << endl;
        cout << "Pazymius:";
        if (x == 0) {
            cout << " nera\n";
        } else {
            for (int l = 1; l <= x; l++) {
                cout << " " << GRADES[n][l];
            }
        }

        cout << "\n\nAr norit dar atnaujinti? (y/n)\n";
        testi = readYesNo();
    } while (testi == 'y');
}

////////////////////////////////////////////////////////////////////////////////
void vidutinis_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    char testi;
    int x = 0;

    if (count == 0) {
        cout << "---  Sarasas Tuscias  ---\n";
        return;
    }

    do {
        double average = 0;

        cout << "Studentas Nr. (1-" << count << ")\n";
        n = readInt(1, count);
        cout << endl;
        n--;

        cout << "Vardas: " << NAMES[n] << endl;
        x = GRADES[n][0];
        cout << "Pazymius:";
        if (x == 0) {
            cout << " nera\n";
            cout << "Pazymiu vidurkis: nera\n";
        } else {
            for (int l = 1; l <= x; l++) {
                cout << " " << GRADES[n][l];
                average += GRADES[n][l];
            }
            cout << endl;
            cout << "Pazymiu vidurkis: " << fixed << setprecision(2) << average / x << endl;
        }

        cout << "\n\nAr norit dar pakartoti? (y/n)\n";
        testi = readYesNo();
    } while (testi == 'y');
}

////////////////////////////////////////////////////////////////////////////////
void pasalinti_Function(string NAMES[], int GRADES[][grade_max_count + 1], int &count, int &n) {
    char testi;
        if (count == 0) {
            cout << "---  Sarasas Tuscias  ---\n";
            return;
        }
    do {
        cout << "Koki studenta norite pasalinti?\nStudentas Nr. (1-" << count << ")\n";
        n = readInt(1, count);
        cout << endl;
        n--;

        cout << "Tikrai norite pasalinti " << NAMES[n] << "? (y/n)\n";
        testi = readYesNo();

        if (testi == 'y') {
            cout << NAMES[n] << " pasalintas is sistemos\n";

            // pastumiame visus studentus po pasalinto viena vieta i prieki
            for (int k = n; k < count - 1; k++) {
                NAMES[k] = NAMES[k + 1];
                for (int j = 0; j <= grade_max_count; j++) {
                    GRADES[k][j] = GRADES[k + 1][j];
                }
            }

            // isvalome paskutini (dabar nebenaudojama) irasa
            NAMES[count - 1] = "";
            for (int j = 0; j <= grade_max_count; j++) {
                GRADES[count - 1][j] = 0;
            }
            count--;
        }

        if (count == 0) {
            cout << "\n---  Sarasas Tuscias  ---\n";
            return;
        }

        cout << "\n\nAr norit dar pakartoti? (y/n)\n";
        testi = readYesNo();
    } while (testi == 'y');
}