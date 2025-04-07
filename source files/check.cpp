#include <iostream>

using namespace std;
//funckja sprawdzająca posortowanie tablicy
bool check(int* arr, int size) {
    //przejście po tablicy i sprawdzenie czy elementy są posortowane
    for (int i = 0; i < size - 1; i++) {
        //jeżeli element o mniejszym indeksie jest większy od następnego zwrócenie false
        if (arr[i] > arr[i + 1]) {
            std::cout << "NOT SORTED "<< i << ": " <<  arr[i] <<"  is greater than " << i+1 << ": " << arr[i+1] << endl;
            return false;
        }
    }
    //jeżeli tablica jest posortowana zwrócenie true
    return true;
}