#include <iostream>
#include <fstream>
#include <string>
#include<format>

using namespace std;

int main() {
int a, f, l; //f - first, l - last

cout << "Iveskite skaiciu: " << endl;
    cin >> a;

    idf (a >= 10 && a <= 99) {
     f=a/10 ;
     l=a-f*10;

cout<<f+l<<endl;
    }
else
{cout << "Pasirink dvi zenklius skaicius";}


    return 0;
}
