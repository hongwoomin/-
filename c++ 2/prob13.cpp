#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n;
	cin >>n;
	vector<string> words;
	string word;
	for (int i=0; i<n; i++){
		cin >> word;
		words.push_back(word);
	}
	for (int j=words.size()-1; j>0; j--){
		for (int k=0; k<j; k++){
			if(words[k].length() > words[k+1].length()){
				words[k].swap(words[k+1]);
			}
			if (words[k].length() == words[k+1].length()
			&& words[k]>words[k+1]){
				words[k].swap(words[k+1]);
			}
		}
	}
	cout << endl;
	for(int i=0; i<words.size(); i++){
		cout << words[i] << endl;
	}
	cout <<endl;
	return 0;
}

