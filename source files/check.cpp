#include <iostream>

using namespace std;

bool check(int* arr, int size) {
    if (size <= 1) return true;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::cout << "Unsorted elements at positions " << i
                      << " (" << arr[i] << ") and " << i+1
                      << " (" << arr[i+1] << ")\n";
            return false;
        }
    }
    return true;
}