#include <iostream>

using namespace std;

void check(int* tab, int size) {
    for (int i =0; i <size-1; i++) {
        if (tab[i] <= tab[i+1]) {
            cout << "all good!\n";
        }
        else {
            cout << tab[i] << "not <=" << tab[i+1];
            break;
        }
    }
    cout << "ALL ALL good!";
}