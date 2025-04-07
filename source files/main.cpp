#include <iostream>
#include <chrono>
#include <algorithm>
#include "fileMaker.h"
#include "heapsort.h"
#include "check.h"
#include "introsort.h"
#include "timsort.h"
#include "quicksort.h"

using namespace std;

//funkcja do testowania szybkości algorytmu, przyjmująca wskaźnik do funkcji sortującej, tablicę do posortowania, rozmiar tablicy, typ algorytmu, procent posortowanej tablicy oraz numer próbki
void test_algorithm(void (*funcptr)(int*, int,int), int* tab, int size, string type, double percent, int sample) {
    //obliczenie jaki procent tablicy ma być posortowany
    int part = static_cast<int>(size * percent);
    //wyznaczenie startowych indexów
    int leftIndex = 0;
    int rightIndex = size-1;
    //posortowanie danej części tablicy
    sort(tab, tab + part);
    //start zegara mierzącego czas
    auto start = chrono::high_resolution_clock::now();
    //wywołanie funkcji sortującej
    funcptr(tab,leftIndex,rightIndex);
    //koniec zegara i wyznaczenie czasu po czym przesłanie wyniku do pliku
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    resultstofile(duration.count(), size, type, percent);
    //wyświetlenie w jakim czasie tablica została posortowana i czy została posortowana
    cout <<to_string(sample) + " out of 100 " <<type + " " <<to_string(size) + " " <<to_string((int)(percent*1000))+ " " << "Duration: " << duration.count() << " ns, Is Sorted: "  << to_string(check(tab, size)) << endl;;

}
void test_algorithm_reverse(void (*funcptr)(int*, int,int), int* tab, int size, string type, double percent, int sample) {
    //posortowanie tablicy w odwrotnej kolejności
    sort(tab, tab + size, greater<int>());
    //wyznaczenie początkowych indeksów
    int leftIndex = 0;
    int rightIndex = size-1;
    //start zegara mierzącego czas
    auto start = chrono::high_resolution_clock::now();
    //wywołanie funkcji sortującej
    funcptr(tab,leftIndex,rightIndex);
    //koniec zegara i wyznaczenie czasu po czym przesłanie wyniku do pliku
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    resultstofile(duration.count(), size, type, -1);
    //wyświetlenie w jakim czasie tablica została posortowana i czy została posortowana
    cout <<to_string(sample) + " out of 100 " <<type + " " <<to_string(size) + " -" <<to_string((int)(percent*1000))+ " " << "Duration: " << duration.count() << " ns, Is Sorted: "  << to_string(check(tab, size)) << endl;;

}

//inicjalizacja tablicy z procentami posortowań i rozmiarami tablic
double percentages[] = {0.0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1.0,-1.0};
int sizes[] = {1000, 10000, 50000, 100000, 500000, 1000000};

int main() {
    //stworzenie 100 próbek tablicy dla każdego rozmiaru i procentu posortowania
    for (int s: sizes) {
        for (double p: percentages) {
            if (p>=0) {
                for (int i=0; i<100; i++) {
                    //stworzenie tablicy o danym rozmiarze i wypełnienie jej losowymi liczbami
                    int *tab = createArray(s);
                    //zapisanie tablicy do pliku
                    tofile(tab,s,i,p);
                    //skopiowanie tablicy do trzech nowych tablic
                    int *tab1 = new int[s];
                    copy(tab, tab + s, tab1);
                    //testowanie algorytmu introsort
                    test_algorithm(introsort, tab1, s, "introsort", p, i);
                    //usunięcie tablicy by nie zajmowała miejsca w pamięci
                    delete[] tab1;
                    int *tab2 = new int[s];
                    copy(tab, tab + s, tab2);
                    //testowanie algorytmu heapsort
                    test_algorithm(heapsort, tab2, s, "heapsort", p, i);
                    //usunięcie tablicy by nie zajmowała miejsca w pamięci

                    delete[] tab2;
                    int *tab3 = new int[s];
                    copy(tab, tab + s, tab3);
                    //testowanie algorytmu timsort
                    test_algorithm(timsort, tab3, s, "timsort", p, i);
                    //usunięcie tablic by nie zajmowała miejsca w pamięci
                    delete[] tab3;
                    delete[] tab;
                }
            }
        }
    }
    //dla każdego rozmiaru wygenerowanie tablicy posortowaniem w odwrotnej kolejności
    for (int s: sizes) {
            for (int i=0; i<100; i++) {
                //stworzenie tablicy o danym rozmiarze i wypełnienie jej losowymi liczbami
                int *tab = createArray(s);
                //zapisanie tablicy do pliku
                tofile(tab,s,i,-1000);
                //skopiowanie tablicy do trzech nowych tablic
                int *tab1 = new int[s];
                copy(tab, tab + s, tab1);
                //testowanie algorytmu introsort dla odwrotnie posortowanej tablicy
                test_algorithm_reverse(introsort, tab1, s, "introsort", 1, i);
                //usunięcie tablic by nie zajmowała miejsca w pamięci
                delete[] tab1;
                int *tab2 = new int[s];
                copy(tab, tab + s, tab2);
                //testowanie algorytmu introsort dla odwrotnie posortowanej tablicy
                test_algorithm_reverse(heapsort, tab2, s, "heapsort", 1, i);
                //usunięcie tablic by nie zajmowała miejsca w pamięci
                delete[] tab2;
                int *tab3 = new int[s];
                copy(tab, tab + s, tab3);
                //testowanie algorytmu introsort dla odwrotnie posortowanej tablicy
                test_algorithm_reverse(timsort, tab3, s, "timsort", 1, i);
                //usunięcie tablic by nie zajmowała miejsca w pamięci
                delete[] tab3;
                delete[] tab;
            }
        }

    tocsv("introsort", sizes,6,percentages,9);
    tocsv("heapsort", sizes,6,percentages,9);
    tocsv(  "timsort", sizes,6,percentages,9);
    return 0;
}
