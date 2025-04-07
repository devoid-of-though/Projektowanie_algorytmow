#ifndef FILEMAKER_H
#define FILEMAKER_H
#include <string>
void tofile(int* x,int size,int sample,double percent);
void resultstofile(long long duration, int size, std::string type,double percent);
void sortedtofile(int* x,int size,std::string type,int sample, double percent);
int* createArray(int size);
void tocsv(std::string type,int* sizes,int sizes_len, double* percentages, int percentages_len);
#endif
