#include <iostream>
#include <string>
//#include <>


using namespace std;
int main() {
    int salary = 75, savings = 100, m = 0;
    const int target = 500;

    while (target >= savings) {
        savings = savings + salary;
        m++;

    }


    cout << "Tikslas pasektes per " << m << "menesiu";

    return 0;
}
