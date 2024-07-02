#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sorted_merge(vector<string> &first, vector<string> &second) {
	for (int i=0; i<second.size(); i++){
		auto it = first.begin();
		for (it; it<first.end(); it++){
			if (*it>=second[i]){
				first.insert(it,second[i]);
				break;
			}
		}
		if (it == first.end()){
			first.push_back(second[i]);
		}
	}
}
int main() {
	 int m, n;
	 string str;
	 vector<string> first, second;
	 cin >> m;
	 // m개의 영문자열이 사전식 순서로 정렬되어 입력된다.
	 for (int i=0; i<m; i++) {
		 cin >> str;
		 first.push_back(str);
	 }
	 cin >> n;
	 // n개의 영문자열이 사전식 순서로 정렬되어 입력된다.
	 for (int i=0; i<n; i++) {
		 cin >> str;
		 second.push_back(str);
	 }
	 sorted_merge(first, second);
	 // m+n개의 문자열이 사전식 순서로 정렬되어 출력되어야 한다.
	 for (auto item: first)
	 	cout << item << " ";
	 cout << endl;
	 return 0;
}
