#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    ifstream infile("table.txt");
    string line;
    vector<string> words;

    while (getline(infile, line)) {
        words.push_back(line);
    }
    infile.close();
	string str_columns = words[0].substr(2);
	int num_columns = stoi(str_columns); 

  	words.erase(words.begin()); //행과열 나타내는 첫라인 제거 
	 
    vector<string> pure_words;  
    for (auto c : words) {
        
        int i =0; // &기준으로 문자열 저장 
        for (i; i<c.length();){
        	int pos = c.find('&',i);
        	if (pos == -1){
        		pure_words.push_back(c.substr(i));
        		break;
			}
        	pure_words.push_back(c.substr(i, pos-i));
        	i = pos+1;
		}
	}

 // 열의 개수 설정
	vector<int> max_length(num_columns, 0); // 각 열의 최대 길이를 저장할 벡터

	int index;
	
	for (int k = 0; k < pure_words.size(); k++) {
		index = k % num_columns; // 현재 열의 인덱스 계산

		if (max_length[index] < pure_words[k].length()) {
			max_length[index] =  pure_words[k].length();
		}
	}

	for (int i = 0; i < pure_words.size(); i++) {
		if (i % num_columns == 0) {
			cout<<endl;
		}
		cout <<left<<setw(max_length[i % num_columns])<<pure_words[i];
	}
    return 0;
}

