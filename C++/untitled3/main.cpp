#include <iostream>
#include <string>

using namespace std;

const int stud_max = 100;
const int grade_max_count = 10;
const int min_grade = 1;
const int max_grade = 10;

// Writes name and grades of ONE student into row 'students', then increases the counter
void WriteStudent(string NAMES[], int GRADES[][grade_max_count + 1], int &students) {
    if (students >= stud_max) {
        cout << "List is full (" << stud_max << ").\n";
        return;
    } else if (students <= 0) {
        cout << "List is empty.\n";
        return;

    int i = students;                        // index of the new student

    // name -> NAMES[i]
    cout << "Name: ";
    cin >> ws;                               // skip leftover newline
    getline(cin, NAMES[i]);

    // number of grades -> GRADES[i][0]
    int n;
    do {
        cout << "How many grades (0-" << grade_max_count << ")? ";
        cin >> n;
    } while (n < 0 || n > grade_max_count);
    GRADES[i][0] = n;

    // grades -> GRADES[i][1..n]
    for (int j = 1; j <= n; j++) {
        int g;
        do {
            cout << "Grade " << j << " (" << min_grade << "-" << max_grade << "): ";
            cin >> g;
            if (g < min_grade || g > max_grade)
                cout << "Wrong grade, try again.\n";
        } while (g < min_grade || g > max_grade);
        GRADES[i][j] = g;
    }

    students++;                              // only now the student is counted
}

// Prints all students: name + grades
void PrintStudents(const string NAMES[], const int GRADES[][grade_max_count + 1], int students) {
    cout << "\nStudents: " << students << endl;
    for (int i = 0; i < students; i++) {
        cout << i + 1 << ". " << NAMES[i] << ": ";
        if (GRADES[i][0] == 0)
            cout << "no grades";
        for (int j = 1; j <= GRADES[i][0]; j++)
            cout << GRADES[i][j] << " ";
        cout << endl;
    }
}

int main() {
    string NAMES[stud_max] = {};
    int GRADES[stud_max][grade_max_count + 1] = {0};
    int students = 0, stud_amount= 0;                        // MUST start from 0

    cout << "Studentu kiekis?\n";
    cin >> students;

    // test: enter 2 students
    for (int k = 0; k < students; k++) {
        cout << "\nStudent " << k + 1 << endl;
        WriteStudent(NAMES, GRADES, students);
    }

    PrintStudents(NAMES, GRADES, students);
    return 0;
}