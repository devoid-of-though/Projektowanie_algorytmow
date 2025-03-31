#include <iostream>
#include <chrono>
#include <algorithm>
#include "fileMaker.h"
#include "heapsort.h"
#include "check.h"
#include "quicksort.h"
#include "introsort.h"


using namespace std;

void test_algorithm(void (*funcptr)(int*, int, int), int* tab, int size, string type, double percent, int sample) {
    int part = static_cast<int>(size * std::clamp(percent, 0.0, 1.0));
    sort(tab, tab + part);
    auto start = chrono::high_resolution_clock::now();
    funcptr(tab, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    resultstofile(duration.count(), size, type, sample, percent);
    cout <<to_string(sample) + " out of 100 " <<type + " " <<to_string(size) + " " <<to_string((int)(percent*1000))+ " " << "Duration: " << duration.count() << " ns, Is Sorted: "  << to_string(check(tab, size)) << endl;;
}


double percentages[] = {0.0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1.0};
int sizes[] = {1000, 10000, 50000, 100000, 500000, 1000000};

int main() {
    for (int s: sizes) {
            for (double p: percentages) {
                        int *tab = createArray(s);
                        int *tab1 = new int[s];
                        copy(tab, tab + s, tab1);
                        test_algorithm(quicksort, tab1, s, "quicksort", p, 1);
                        delete[] tab1;
                        int *tab2 = new int[s];
                        copy(tab, tab + s, tab2);
                        test_algorithm(heapsort, tab2, s, "heapsort", p, 1);
                        delete[] tab2;
                        int *tab3 = new int[s];
                        copy(tab, tab + s, tab3);
                        test_algorithm(introsort, tab3, s, "introsort", p, 1    );
                        delete[] tab3;
                        delete[] tab;
                    }
            }


    return 0;
}
