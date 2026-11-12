#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_GRADES   = 10;
const int MIN_GRADE    = 1;
const int MAX_GRADE    = 10;

// Nuskaito sveiką skaičių ir apsaugo nuo neteisingo (pvz., raidžių) įvedimo
bool readInt(int &value) {
    if (cin >> value) {
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}

int main() {
    string names[MAX_STUDENTS];               // vienmatis masyvas vardams
    int grades[MAX_STUDENTS][MAX_GRADES];     // dvimatis masyvas pažymiams
    int gradeCount[MAX_STUDENTS] = {0};       // kiek pažymių turi kiekvienas mokinys
    int studentCount = 0;                     // kiek mokinių yra sąraše

    char addMore = 't';

    while (addMore == 't' || addMore == 'T') {
        if (studentCount >= MAX_STUDENTS) {
            cout << "Pasiektas maksimalus mokinių skaičius (" << MAX_STUDENTS << ")." << endl;
            break;
        }

        // Vardo įvedimas
        cout << "\nMokinys Nr. " << studentCount + 1 << endl;
        cout << "Įveskite vardą: ";
        cin >> ws;
        getline(cin, names[studentCount]);

        // Pažymių skaičiaus įvedimas
        int n;
        while (true) {
            cout << "Kiek pažymių įvesite (0-" << MAX_GRADES << ")? ";
            if (readInt(n) && n >= 0 && n <= MAX_GRADES) {
                break;
            }
            cout << "Klaida: įveskite skaičių nuo 0 iki " << MAX_GRADES << "." << endl;
        }

        // Pažymių įvedimas su patikra
        for (int j = 0; j < n; j++) {
            int g;
            while (true) {
                cout << "Įveskite " << j + 1 << "-ą pažymį (" << MIN_GRADE << "-" << MAX_GRADE << "): ";
                if (readInt(g) && g >= MIN_GRADE && g <= MAX_GRADE) {
                    break;
                }
                cout << "Klaida: pažymys turi būti sveikasis skaičius nuo "
                     << MIN_GRADE << " iki " << MAX_GRADE << ". Bandykite dar kartą." << endl;
            }
            grades[studentCount][j] = g;
        }

        gradeCount[studentCount] = n;
        studentCount++;

        cout << "Ar norite įvesti dar vieną mokinį? (t/n): ";
        cin >> addMore;
    }

    // Duomenų išvedimas
    cout << "\n===== MOKINIŲ SĄRAŠAS =====" << endl;
    cout << "Mokinių skaičius: " << studentCount << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << i + 1 << ". " << names[i] << " (pažymių: " << gradeCount[i] << "): ";
        if (gradeCount[i] == 0) {
            cout << "pažymių nėra";
        } else {
            for (int j = 0; j < gradeCount[i]; j++) {
                cout << grades[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}