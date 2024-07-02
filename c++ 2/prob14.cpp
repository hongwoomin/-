#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){

	ifstream infile("harry.txt");
	string str;
	vector <string> words;
	while(infile >> str){ //중복 가려서 벡터에 저장 
	
		if (find(words.begin(),words.end(),str)==words.end()){
			words.push_back(str);
		}
		else{
			continue;
		}
	}
	sort(words.begin(),words.end());
	string word;
	cin >> word;
	int count = 0;
	cout << endl;
	for (int i=0; i<words.size(); i++){
		string pre = words[i].substr(0,word.length());
		if (pre==word){
			cout << words[i] <<endl;
			count ++;
		}
	}
	cout << count << endl;
	return 0;
}
