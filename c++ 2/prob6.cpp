#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string pure_word(string str){ //단어와 숫자를 순수하게 추출 
		string result;
		for(auto c : str){
			if (isalnum(c)){
				result += tolower(c);
			}
		}
		return result;	
	}
	
int main(){
	ifstream infile("sample.txt");
	vector<string > words;
	string str;
	int n =0;
	while(infile >> str){
		string comp_word = pure_word(str);
		bool found = false;   //중복 찾기 
		for(int i=0; i<words.size(); i++){
			if(words[i]==comp_word){
				found = true;
				break;
			}
		}
		if(!found){
			words.push_back(comp_word);
		}
	}
	infile.close();
	
	sort(words.begin(),words.end());
	
	for(auto c: words){
		cout << c << " ";
	}
	return 0;
}
