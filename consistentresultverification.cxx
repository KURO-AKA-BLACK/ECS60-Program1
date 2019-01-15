#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
using namespace std;

int main(int argc, char** argv) {
	ifstream file;
	file.open(argv[1]);
	nlohmann::json json1;
	if(file.is_open()){
		file >> json1;
	}
	
	ifstream file2;
	file2.open(argv[2]);
	nlohmann::json json2;
	if(file2.is_open()){
		file2 >> json2;
	}
	
	nlohmann::json outOb;
	
	vector<string> name1;
	for (auto itr = json1.begin(); itr != json1.end(); ++itr){
		name1.push_back(itr.key());
	}
	vector<string> name2;
	for (auto itr = json2.begin(); itr != json2.end(); ++itr){
		name2.push_back(itr.key());
	}
	
	int ar_size = json1[name1[name1.size()-1]]["arraySize"];
	bool is_diff = false;
	int cnt=0;
	for(size_t i=0; i < name1.size()-1;i++){
		if (json1[name1[i]] != json2[name2[i]]){
			for (int j=0;j<ar_size;j++){
				if (json1[name1[i]][j] != json2[name2[i]][j]){
					outOb[name1[i]]["Mismatches"][to_string(j)][0] = json1[name1[i]][j];
					outOb[name1[i]]["Mismatches"][to_string(j)][1] = json2[name2[i]][j];
					is_diff = true;
					outOb[name1[i]]["sample1"] = json1[name1[i]];
					outOb[name1[i]]["sample2"] = json2[name2[i]];
				}
			}
			cnt = cnt + 1;
		}
	}
	outOb["sample1"]["metadata"] = json1[name1[name1.size()-1]];
	outOb["sample2"]["metadata"] = json2[name2[name2.size()-1]];
	outOb["sample1"]["metadata"]["file"] = argv[1];
	outOb["sample2"]["metadata"]["file"] = argv[2];
	outOb[name1[name1.size()-1]]["samplesWithConflictingResults"] = cnt;
	cout << outOb;
	ofstream outObjJson;
	outObjJson.open("output.json");
	outObjJson << outOb;
	outObjJson.close();
}