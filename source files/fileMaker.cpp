#include "fileMaker.h"
#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <numeric>
using namespace std;


//wgrywanie tablicy do pliku
void tofile(int* x,int size,int sample,double percent){
    string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/")+"wyniki"+"/"+"not_sorted"+"/"+to_string(size)+"/"+to_string((int)(percent*1000))+"/"+ "array_" +to_string(size)+"_"+to_string(sample+1)+"_"+to_string((int)(percent*1000))+ ".txt";
    ofstream myfile (filename);
    for(int i = 0; i < size; i ++){
        myfile << x[i] << " " ;
    }
    myfile.close();
}
//zapisywanie wyników do pliku
void resultstofile(long long duration, int size,string type,double percent) {
    string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/")+"wyniki/" + type + "/results"+"/"+ "results_"+type+"_"+ to_string(size)+"_"   + to_string((int)(percent*1000)) + ".txt";
    ofstream logfile(filename, ios::app);
    if (logfile.is_open()) {
        logfile << duration << "\n";
        logfile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}
//zapisywanie posortowanej tablicy do pliku
void sortedtofile(int* x,int size,string type,int sample,double percent){
    string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/") +"wyniki/"+type+"/"+"sorted"+"/"+to_string(size)+"/"+to_string((int)(percent*1000))+"/"+ "sorted_array_" +to_string(size)+"_"+ to_string(sample)+"_"+ to_string((int)(percent*1000))+ ".txt";
    ofstream myfile (filename);
    for(int i = 0; i < size; i ++){
        myfile << x[i] << " " ;
    }
    myfile.close();
}

//tworzenie tablicy o danym rozmiarze i wypełnienie jej losowymi liczbami
int* createArray(int size) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);

    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = dist(rng);
    }
    return arr;
}

#include <numeric> // Include this header for std::accumulate

void tocsv(string type, int* sizes, int sizes_len, double* percentages, int percentages_len) {
    ofstream outfile(string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/") + "wynik" + type + ".csv");
    outfile << "size,0.0,0.25,0.5,0.75,0.95,0.99,0.997,1.0,-1.0"<<endl;

    for (int i = 0; i < sizes_len; i++) {
        int size = sizes[i];
        outfile << size << ",";
        for (int j = 0; j < percentages_len; j++) {
            double p = percentages[j];
            string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/") + "wyniki/" + type + "/results" + "/" + "results_" + type + "_" + to_string(size) + "_" + to_string((int)(p * 1000)) + ".txt";
            ifstream infile(filename);
            long long data = 0;
            int num;
            int k = 0;
            while (infile >> num) {
                data += num;
                k++;
            }
            cout << to_string(data) + " " + to_string(k) + " " + to_string(size) + " " + to_string(p) << endl;
            int mean = (int)(data / 100);
            outfile << mean << ",";
        }
        outfile << "\n";
    }

    outfile.close();
    cout << "Results saved to wynik" << type << ".csv" << endl;
}