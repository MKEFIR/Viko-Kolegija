#include <iostream>
#include <fstream>
#include <string>
#include<format>

using namespace std;

int main() {
int M[5]={};
    double a;
 cout << "Iveskite 5 skaiciu: " << endl;
    for(int i=0;i<5;i++) {
    cin >> M[i];
        a = a + M[i];
    }

    cout << "Vidutinis - " << a/5 << endl;

    return 0;
}
