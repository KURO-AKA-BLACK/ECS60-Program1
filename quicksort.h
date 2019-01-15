// Quicksort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void QuickSort(std::vector<int>* numbers, int* QSM, int* QSC);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int* QSM, int* QSC);
int Partition(std::vector<int>* numbers, int i, int k, int* QSM, int* QSC);
