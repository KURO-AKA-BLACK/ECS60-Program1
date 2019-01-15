// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"

void InsertionSort(std::vector<int>* numbers,int* ISM, int* ISC) {
    int i = 0;
    int j = 0;
    int temp = 0;  // Temporary variable for swap
    for (i = 1; i < numbers->size(); ++i) {
        j = i;
        *ISC=*ISC+1;
        *ISM = *ISM + 2;
        // Insert numbers[i] into sorted part
        // stopping once numbers[i] in correct position
        while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
            *ISC = *ISC + 1;
            *ISM = *ISM + 2;
            // Swap numbers[j] and numbers[j - 1]
            temp = (*numbers)[j];
            *ISM = *ISM + 1;
            (*numbers)[j] = (*numbers)[j - 1];
            *ISM = *ISM + 2;
            (*numbers)[j - 1] = temp;
            *ISM = *ISM + 1;
            --j;
        }
    }
    return ;
}
