#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	ifstream file;
	file.open(argv[1]);
	nlohmann::json jsonObject;
	if(file.is_open()){
		file >> jsonObject;
	}
	vector<string> name;
	for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
		name.push_back(itr.key());
	}
	
	nlohmann::json outObj;
	
	int i = 0;
	int prev=0;
	int current =0;
	size_t j = 0;
	int k=0;
	bool test = false;
	int ar_size=0;
	int diff=-1;
	int num_of_inv=0;
	int index = -1;
	while (j<name.size()-1){
		for (auto arrayItr = jsonObject[name[j]].begin();arrayItr !=jsonObject[name[j]].end();++arrayItr) {
			current = *arrayItr;
			//cout << current<<"wo"<<endl;
			if (i != 0){
				if (current < prev){
					vector<int> temp;
					temp.push_back(prev);
					temp.push_back(current);
					outObj[name[j]]["ConsecutiveInversions"][to_string(index)]=temp;
					k = k+ 1;
					test = true;
					if (j != diff){
						diff=j;
						num_of_inv=num_of_inv+1;
					}
					}
					
					
				}			
			else{
				i = i + 1;
			}
			ar_size++;	
			prev = *arrayItr;	
			index=index + 1;
		}
		if (test == true){
			outObj[name[j]]["sample"] = jsonObject[name[j]];
		}
		index=-1;
		prev=0;
		i=0;
		j=j+1;
	}
	
	//cout << jsonObject[name[j]]<<endl;

	//ar_size=ar_size/2;
	outObj[name[j]]=jsonObject[name[j]];
		//outObj[name[j]]["arraySize"] = ar_size;
	outObj[name[j]]["file"] = argv[1];
		//outObj[name[j]]["numSamples"] = k;
	outObj[name[j]]["samplesWithInversions"] = num_of_inv;
	ofstream outObjJson;
		// name the CSV file to write data to
	outObjJson.open("Output.json");
		// write to the file
	outObjJson << outObj;
		// close file writer
	outObjJson.close();
	cout << outObj<<endl;

return 0;
	
	
}
