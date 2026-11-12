#include <iostream>
#include <string>
//#include <>


using namespace std;
int main() {
    string password;

    do {
        cout<<"Sukurkite slaptazodi, bet astoni symbolai";
        cin >> password;
        if (password.length()< 8)
        {    cout << "Slaptazodis per trumpas" << endl;}
    }while (password.length()>=8); {

        cout <<"Slaptazodis priimtas"<<endl;
    }









    //for (int i = 0; i < 8; i++) {}

    return 0;
}
