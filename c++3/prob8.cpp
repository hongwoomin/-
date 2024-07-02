#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
vector<vector<string>> alpha;
vector<vector<string>> dict;
vector<string> result;
void find_word(string a);
void dir_check(int i,int j);
void north(int i,int j);
void north_east(int i,int j);
void east(int i,int j);
void south_east(int i,int j);
void south(int i,int j);
void south_west(int i,int j);
void west(int i,int j);
void north_west(int i,int j);
int num;
int main(){
    ifstream theFile("dictionary.txt");
    string word,first_word;
    theFile >> first_word;
    vector<string> first_same = {first_word};
    while(theFile>>word){   // 첫문자가 같은 단어끼리 그룹화 
    	if (string(1,word[0])!= first_word){
			dict.push_back(first_same);
			first_same.clear();
			first_word = word[0];
		}
		first_same.push_back(word);
	}
	dict.push_back(first_same); //마지막 동일그룹들 벡터추가 
	theFile.close();
	
	ifstream thefile("puzzle.txt");
	string str;
	thefile >> num;
	for (int j=0; j<num; j++){
		vector<string> row;
		for(int i=0; i<num; i++){
			thefile>>str;
			row.push_back(str);
		}
		alpha.push_back(row);
	}	
	for (int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			dir_check(i,j);
		}

	}
	sort(result.begin(), result.end());

    result.erase(unique(result.begin(), result.end()), result.end());
	for (int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}

void dir_check(int i,int j){
	find_word(alpha[i][j]);
	north(i,j);
	north_east(i,j);
	east(i,j);
	south_east(i,j);
	south(i,j);
	south_west(i,j);
	west(i,j);
	north_west(i,j);
}
void find_word(string a) {
    for (int i = 0; i < dict.size(); i++) { // 단어 그룹 인덱스 확인
        if (dict[i][0][0] == a[0]) {
            auto it = find(dict[i].begin(), dict[i].end(), a);

            if (it != dict[i].end()) {
                result.push_back(a);
                break; // 단어를 찾았으면 탐색 중지
            }
        }
    }
}

void north(int i,int j){
	string a = alpha[i][j];
	while(i>0){
		i--;
		a +=alpha[i][j];
		find_word(a);
	}
}
void north_east(int i,int j){
	string a = alpha[i][j];
	while(i>0&&j<num-1){
		i--;
		j++;
		a +=alpha[i][j];
		find_word(a);
	}
}
void east(int i,int j){
	string a = alpha[i][j];
	while(j<num-1){
		j++;
		a +=alpha[i][j];
		find_word(a);
	}
}
void south_east(int i,int j){
	string a = alpha[i][j];
	while(j<num-1&&i<num-1){
		i++;
		j++;
		a +=alpha[i][j];
		find_word(a);
	}
}
void south(int i,int j){
	string a = alpha[i][j];
	while(i<num-1){
		i++;
		a +=alpha[i][j];
		find_word(a);
	}
}
void south_west(int i,int j){
	string a = alpha[i][j];
	while(j>0&&i<num-1){
		j--;
		i++;
		a +=alpha[i][j];
		find_word(a);
	}
}
void west(int i,int j){
	string a = alpha[i][j];
	while(j>0){
		j--;
		a +=alpha[i][j];
		find_word(a);
	}
}
void north_west(int i,int j){
	string a = alpha[i][j];
	while(j>0&&i>0){
		j--;
		i--;
		a +=alpha[i][j];
		find_word(a);
	}
}	
