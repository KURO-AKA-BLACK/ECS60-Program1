#include <ctime>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include <string>
//#include "insertionsort.h"
//#include "mergesort.h"
//#include "quicksort.h"

using namespace std;


int main(int argc, char** argv) {
    string output;
    ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if(file.is_open()){
        file >> jsonObject;
    }
    vector<string> name;
    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
        name.push_back(itr.key());
    }
    
    
    ofstream outCsv;
    outCsv.open("Example.csv");
    outCsv << "Sample,insertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess\n";
    cout <<"Sample,insertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess\n";
    for (size_t i =0; i<name.size()-1;i++){
        vector<int>* temp = new vector<int>();
        vector<int>* temp2 = new vector<int>();
        vector<int>* temp3 = new vector<int>();
        vector<int> check;
        int size = jsonObject[name[i]].size();
        for (int j=0; j < size; j++){
            temp->push_back(jsonObject[name[i]][j]);
            temp2->push_back(jsonObject[name[i]][j]);
            temp3->push_back(jsonObject[name[i]][j]);
        }
        
        int ISM=0;
        int ISC=0;
        clock_t start_ins,end_ins;
        start_ins=clock();
        InsertionSort(temp,&ISM,&ISC);
        end_ins=clock();
        //double diff_ins = (end_ins - start_ins)/CLOCKS_PER_SEC;
        outCsv << name[i]<<','<<fixed<<((double)end_ins-start_ins)/CLOCKS_PER_SEC;
        outCsv <<','<<ISC<<','<< ISM;
        cout << name[i]<<','<<fixed<<((double)end_ins-start_ins)/CLOCKS_PER_SEC;
        cout <<','<<ISC<<','<< ISM;
        
        int MSM=0;
        int MSC=0;
        clock_t start_mer,end_mer;
        start_mer = clock();
        MergeSort(temp2,&MSM,&MSC);
        end_mer = clock();
        //double diff_mer = (end_mer - start_mer)/CLOCKS_PER_SEC;
        outCsv <<',' << fixed<< ((double)end_mer-start_mer)/CLOCKS_PER_SEC <<','<<MSC<<','<<MSM;
        cout <<',' << fixed<<((double)end_mer-start_mer)/CLOCKS_PER_SEC<<','<<MSC<<','<<MSM;
        
        int QSM=0;
        int QSC=0;
        clock_t start_qk,end_qk;
        start_qk=clock();
        QuickSort(temp3,&QSM,&QSC);
        end_qk=clock();
        //double diff_qk = (end_qk - start_qk)/CLOCKS_PER_SEC;
        outCsv <<','<<fixed<<((double)end_qk-start_qk)/CLOCKS_PER_SEC<<','<<QSC<<','<<QSM<<endl;
        cout <<','<<fixed<<((double)end_qk-start_qk)/CLOCKS_PER_SEC<<','<<QSC<<','<<QSM<<endl;
    }
    outCsv.close();
    return 0;
}
