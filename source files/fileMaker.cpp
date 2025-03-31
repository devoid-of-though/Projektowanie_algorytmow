#include "fileMaker.h"
#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
using namespace std;

void tofile(int* x,int size,string type,int sample,double percent){
    string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/") +type+"/"+"not_sorted"+"/"+to_string(size)+"/"+to_string((int)(percent*1000))+"/"+ "array_" +to_string(size)+"_"+to_string(sample+1)+"_"+to_string((int)(percent*1000))+ ".txt";
    ofstream myfile (filename);
    for(int i = 0; i < size; i ++){
        myfile << x[i] << " " ;
    }
    myfile.close();
}
void resultstofile(long duration, int size,string type, int sample,double percent) {
    string filename =
        "/home/userbrigh/CLionProjects/Projektowanie_algorytmow/" + type + "/results"+"/"+to_string(size)+"/"+to_string((int)(percent*1000))+"/"+ "results_"+ to_string(size)+"_"   + to_string((int)(percent*1000)) + ".txt";
    ofstream logfile(filename, ios::app);
    if (logfile.is_open()) {
        logfile << duration << "\n";
        logfile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}
void sortedtofile(int* x,int size,string type,int sample,double percent){
    string filename = string("/home/userbrigh/CLionProjects/Projektowanie_algorytmow/") +type+"/"+"sorted"+"/"+to_string(size)+"/"+to_string((int)(percent*1000))+"/"+ "sorted_array_" +to_string(size)+"_"+ to_string(sample)+"_"+ to_string((int)(percent*1000))+ ".txt";
    ofstream myfile (filename);
    for(int i = 0; i < size; i ++){
        myfile << x[i] << " " ;
    }
    myfile.close();
}


int* createArray(int size) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 999999999);

    int* arr = new int[size];
    for(int i = 0; i < size; i++) {
        arr[i] = dist(rng);
    }
    return arr;
}