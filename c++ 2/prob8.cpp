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
	string result =""; //����� ���λ� ���� 
	for (int i=0; i<n; i++){
		cin>>word;
		words.push_back(word);
	}
	bool check = true;
	for (int j=0; j<words[0].length(); j++){  //���� ù��° ���� ���� 
		
		for (int i =1; i<n; i++){  // ���� ù��° ������ char �ϳ��� �� 
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
