// Quicksort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "quicksort.h"


void QuickSort(std::vector<int>* numbers, int* QSM, int* QSC) {
   QuickSortRecurse(numbers, 0, numbers->size() - 1,QSM,QSC);
}

void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int* QSM, int* QSC) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k,QSM,QSC);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   QuickSortRecurse(numbers, i, j,QSM,QSC);
   QuickSortRecurse(numbers, j + 1, k,QSM,QSC);
   
   return;
}

int Partition(std::vector<int>* numbers, int i, int k ,int* QSM, int* QSC) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = (*numbers)[midpoint];
    *QSM=*QSM+1;
   
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while ((*numbers)[l] < pivot) {
         ++l;
          //if((*numbers)[l]<pivot){
              *QSM=*QSM+1;
              *QSC=*QSC+1;
          //}
      }
       *QSM=*QSM+1;
       *QSC=*QSC+1;
      
      /* Decrement h while pivot < numbers[h] */
      while (pivot < (*numbers)[h]) {
         --h;
          *QSM=*QSM+1;
          *QSC=*QSC+1;
          
      }
       *QSM=*QSM+1;
       *QSC=*QSC+1;
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = (*numbers)[l];
          *QSM=*QSM+1;
         (*numbers)[l] = (*numbers)[h];
          *QSM=*QSM+2;
         (*numbers)[h] = temp;
          *QSM=*QSM+1;
         
         ++l;
         --h;
      }
   }
   
   return h;
}
