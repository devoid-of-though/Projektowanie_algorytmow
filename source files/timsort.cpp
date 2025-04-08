    #include "introsort.h"
    #include <algorithm>

    using namespace std;


    //inicjalizacja
    const int run = 32;
    //mergesort
    void merge(int* tab, int leftIndex, int middleIndex, int rightIndex) {
        //tworzenie zmiennych pomocniczych
        int x,y,i=0,j=0,k =leftIndex ;
        //tworzenie tablic pomocniczych
        int len1 = middleIndex  - leftIndex+1;
        int len2 = rightIndex - middleIndex;
        int* leftArray = new int[len1];
        int* rightArray = new int[len2];
        //przypisanie wartości do tablic pomocniczych
        for(x=0; x<len1; x++) {
            leftArray[x] = tab[leftIndex + x];
        }
        for(y=0; y<len2; y++) {
            rightArray[y] = tab[middleIndex + 1 + y];
        }
        //łączenie tablic
        while(i<len1 && j<len2) {
            if (leftArray[i] <= rightArray[j]) {
                tab[k] = leftArray[i];
                i+=1;
            } else {
                tab[k] = rightArray[j];
                j+=1;
            }
            k+=1;
        }
        //skopiowanie pozostałych elementów
        while (i<len1) {
            tab[k] = leftArray[i];
            k+=1;
            i+=1;
        }
        while(j<len2) {
            tab[k] = rightArray[j];
            k+=1;
            j+=1;

        }
        //zwolnienie miejsca w pamięci
        delete[] leftArray;
        delete[] rightArray;
    }
    //timsort
    void timsort(int* tab, int leftIndex, int rightIndex) {
        int size = rightIndex +1;
        //podzielenie tablic na mniejsze subtablice o rozmiarze run
        for (int i=0; i<size; i+=run) {
            int temp = min(i+run-1,size-1);
            //posortowanie subtablicy za pomocą insertion sorta
            insertion(tab,i,temp);
        }
        //łączenie subtablic
        for (int might = run; might < size; might*=2) {
            for (int leftIndex = 0; leftIndex < size; leftIndex += 2*might) {
                int mid = leftIndex +might-1;
                int rightIndex = min(leftIndex + 2 * might - 1, size - 1);
                if (mid < rightIndex) {
                    //użycie mergesorta do połączenia i posotorowania subtablic
                    merge(tab, leftIndex, mid, rightIndex);
                }
            }
        }
    }

