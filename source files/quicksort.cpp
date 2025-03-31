#include "quicksort.h"
#include <iostream>
using namespace std;


void quicksort(int* tab, int leftIndex, int rightIndex) {
    if( leftIndex >= rightIndex) {
        return;
    }
    if (tab[leftIndex] > tab[rightIndex]) {
        swap(tab[leftIndex], tab[rightIndex]);
    }
    int startCounter = leftIndex +1;
    int Counter2 = leftIndex +1;
    int Counter3 = rightIndex -1;
    if ( tab[leftIndex]> tab[rightIndex]) {
        swap(tab[leftIndex], tab[rightIndex]);
    }
    while (Counter2 <= Counter3) {
        if (tab[Counter2] < tab[leftIndex]) {
            swap(tab[Counter2], tab[startCounter]);
            startCounter +=1;
        }
        else if (tab[Counter2]> tab[rightIndex]) {
            while (tab[Counter3] > tab[rightIndex] && Counter2 < Counter3) {
                Counter3 -=1;
            }
            swap(tab[Counter2], tab[Counter3]);
            Counter3 -=1;
            if (tab[Counter2] < tab[leftIndex]) {
                swap(tab[Counter2], tab[startCounter]);
                startCounter +=1;
            }
        }
        Counter2 +=1;

    }
    startCounter -=1;
    Counter3+=1;
    swap(tab[leftIndex],tab[startCounter]);
    swap(tab[rightIndex],tab[Counter3]);
    quicksort(tab, leftIndex, startCounter-1);
    quicksort(tab, startCounter+1, Counter3-1);
    quicksort(tab, Counter3+1, rightIndex);
}