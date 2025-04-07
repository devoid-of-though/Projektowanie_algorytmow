#include "heapsort.h"
#include "introsort.h"
#include <cmath>
using namespace std;

//sortowanie przez wstawianie
void insertion(int* tab, int leftIndex, int rightIndex) {
    for (int i = leftIndex+1; i <= rightIndex; i++) {
        int temp = tab[i];
        int j = i - 1;
        while (j >= leftIndex && tab[j] > temp) {
            tab[j + 1] = tab[j];
            j -= 1;
        }
        tab[j + 1] = temp;
    }

}
//metoda partycji hoarego
int partition(int* tab, int leftIndex, int rightIndex) {
    int pivot = tab[leftIndex];
    //iicjalizacja indeksów z początkiem poza zakresami
    int i = leftIndex - 1;
    int j = rightIndex + 1;
    while (true) {
        //szukanie elementu mniejszego od pivot po lewej stronie tablicy
        do {
            i++;
        } while (tab[i] < pivot);
        //szukanie elementu większego od pivot po prawej stronie tablicy
        do {
            j--;
        } while (tab[j] > pivot);
        //kiedy lewy i prawy się spotkają to zwracamy j, które będzie naszym pivotem
        if (i >= j) {
            return j;
        }
        swap(tab[i], tab[j]);
    }
}
//algorytm introsort
void intro(int* tab, int leftIndex, int rightIndex, int maxdepth) {
    int size = rightIndex - leftIndex;
    //jeżeli rozmiar tablicy jest mniejszy od 16 to sortujemy przez wstawianie
    if (size < 16) {
        insertion(tab, leftIndex, rightIndex);
    //jeżeli ilość elementów przekroczy recursion depth
    } else if (maxdepth == 0) {
        heapsort(tab+leftIndex , 0, size -1);
    //wracamy ro introsorta
    } else {
        int p = partition(tab, leftIndex, rightIndex);
        intro(tab, leftIndex, p, maxdepth - 1);
        intro(tab, p + 1, rightIndex, maxdepth - 1);
    }
}
//inicjalizacja algorytmu
void introsort(int* tab, int leftIndex,int rightIndex) {
    int size = rightIndex +1;
    if (size <= 0) return;
    int maxdepth = 2 * log2(size);
    intro(tab, 0, size, maxdepth);
}