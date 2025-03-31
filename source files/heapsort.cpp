#include "heapsort.h"
#include <cmath>

using namespace std;



int leftChild(int i){
    return 2*i + 1;
}
int rightChild(int i){
    return 2*i + 2;
}
int parent(int i) {
    return floor((i-1)/2);
}

void heapsort(int* tab, int leftIndex, int rightIndex) {
    int start = (rightIndex+1) / 2;
    int end = rightIndex;
    while (end > 1) {
        if (start > 0) {
            start -=1;
        } else {
            end -=1;
            swap(tab[end], tab[0]);
        }
        int root = start;
        while (leftChild(root) < end) {
            int child = leftChild(root);
            if (child + 1 < end && tab[child] < tab[child + 1]) {
                child +=1;
            }
            if (tab[root] < tab[child]) {
                swap(tab[root], tab[child]);
                root = child;
            } else {
                break;
            }
        }
    }
}



