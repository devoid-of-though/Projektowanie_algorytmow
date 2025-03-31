#include "heapsort.h"
#include "introsort.h"
#include <cmath>
using namespace std;

void insertion(int* tab, int leftIndex, int rightIndex) {
    for (int i = leftIndex+1; i <= rightIndex; i++) {
        int  hold = tab[i];
        int j = i - 1;
        while (j >= leftIndex && tab[j] > hold) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = hold;
    }

}
int partition(int* tab,int leftIndex, int rightIndex) {
    int pivot = tab[leftIndex];
    int i = leftIndex;
    int j = rightIndex;
    while(true) {
        while(tab[i]<=pivot) {
            i+=1;
        }
        while(tab[j]>pivot) {
            j-=1;
        }
        if (i>=j) {
            return j;
        }
        swap(tab[i],tab[j]);
    }


}
void intro(int* tab, int leftIndex, int rightIndex, int maxdepth) {
    int size = rightIndex - leftIndex + 1;
    if (size < 16) {
        insertion(tab, leftIndex, rightIndex);
    } else if (maxdepth == 0) {
        heapsort(tab , leftIndex, size-1);
    } else {
        int p = partition(tab, leftIndex, rightIndex);
        intro(tab, leftIndex, p, maxdepth - 1);
        intro(tab, p + 1, rightIndex, maxdepth - 1);
    }
}

void introsort(int* tab, int leftIndex, int rightIndex) {
    int size = rightIndex+1;
    if (size <= 0) return;
    int maxdepth = 2 * log2(size);
    intro(tab, 0, size - 1, maxdepth);
}