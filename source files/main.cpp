#include <iostream>
#include <chrono>
#include <algorithm>
#include "fileMaker.h"
#include "heapsort.h"
#include "check.h"
#include "quicksort.h"
#include "introsort.h"


using namespace std;

void test_algorithm(void (*funcptr)(int*, int, int),int size, string type, double percent) {
    for (int i = 0; i < 100; i++) {
        int* tab = createArray(size);
        int part = size*percent;
        sort(tab,tab+part);
        tofile( tab, size, type, i, percent);
        auto start = chrono::high_resolution_clock::now();
        funcptr(tab, 0, size-1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        resultstofile(duration.count(), size, type,i, percent);
        sortedtofile(tab, size, type, i, percent);
        delete tab;
    }
}

double percentages[] = {0.0,0.25,0.5,0.75,0.95,0.99,0.997,1.0};
int sizes[] = {1000,10000,50000,100000,500000,1000000};
int main () {
    for (int s: sizes) {
        for (double p:percentages) {
            test_algorithm(quicksort, s, "quicksort", p);
            test_algorithm( heapsort, s, "heapsort", p);
            test_algorithm(introsort, s, "introsort", p);
        }
    }
    return 0;

}