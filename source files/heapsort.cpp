#include "heapsort.h"
#include <cmath>

using namespace std;


//funkcje pomocnicze do wyznaczania indeksów
int leftChild(int i){
    return 2*i + 1;
}
int rightChild(int i){
    return 2*i + 2;
}
int parent(int i) {
    return floor((i-1)/2);
}

//sortowanie przez kopcowanie
void heapsort(int* tab, int leftIndex,int rightIndex) {
    int size = rightIndex +1;
    int start = (size+1) / 2;
    int end = size+1;
    while (end > 0) {
        //budowa kopca
        if (start > 0) {
            start -=1;
        } else {
            //wyjmowanie elementów z kopca
            end -=1;
            swap(tab[end], tab[0]);
        }
        int root = start;
        while (leftChild(root) < end) {
            int child = leftChild(root);
            //jeżeli prawy potomek jest większy od lewego i istnieje to przypisanie do zmiennej child
            if (child + 1 < end && tab[child] < tab[child + 1]) {
                child +=1;
            }
            //jeżeli rodzic jest mniejszy od potomka to zamiana miejscami
            if (tab[root] < tab[child]) {
                swap(tab[root], tab[child]);
                root = child;
            } else {
                break;
            }
        }
    }
}



