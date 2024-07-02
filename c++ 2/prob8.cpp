#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


int main(){
	vector<string> words;
	int n;
	cin >>n;
	string word;
	string result =""; //출력할 접두사 정의 
	for (int i=0; i<n; i++){
		cin>>word;
		words.push_back(word);
	}
	bool check = true;
	for (int j=0; j<words[0].length(); j++){  //벡터 첫번째 원소 기준 
		
		for (int i =1; i<n; i++){  // 벡터 첫번째 원소의 char 하나씩 비교 
			int found = words[i].find(words[0][j]);
			if (found ==j){
				check  = true;
			}
			else{
				check = false;
				break;
			}		
		}
		if(check){
			result += words[0][j];
		}
		else{
			break;
		}
	}
	if(result!=""){
		cout << result <<endl;
	}
	else{
		cout <<"nothing" << endl;
	}
	return 0;
}
