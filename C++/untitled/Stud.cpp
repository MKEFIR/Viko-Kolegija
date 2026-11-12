// Created by markk on 10/1/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <format>

using namespace std;

int main() {
    const int Studentu_kiekis = 10,
    maziasia = 1,
    didziausia = 10;
    int pazymai[Studentu_kiekis]={},
        kiekis[11]={0};


    for (int i = 0; i < 5; i++) {
        cout << "Iveskite studentu pazymis - " << pazymai[i] << endl;

        kiekis[pazymai[i]]++;
    }
for (int i = 1; i <= 10; i++) {
    cout <<i<< " Pazymiu yra - " <<kiekis[i]<< endl;
}

return 0;
}