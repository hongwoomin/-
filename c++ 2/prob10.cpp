#include <iostream>
#include <string>
#include <vector>
using namespace std;
void sorted_merge(vector<string> &first, vector<string> &second) {
 	int i=0, j=0;
	while(i<first.size() && j<second.size()){
		if(first[i]>=second[j]){
			first.insert(first.begin()+i,second[j]);
			i++;
			j++;
		}
		else{
			i++;
		}
	}
	while (j<second.size()){
		first.push_back(second[j]);
		j++;
	}
}
int main() {
	 int m, n;
	 string str;
	 vector<string> first, second;
	 cin >> m;
	 
	 for (int i=0; i<m; i++) {
	 cin >> str;
	 first.push_back(str);
	 }
	 cin >> n;

	 for (int i=0; i<n; i++) {
	 cin >> str;
	 second.push_back(str);
	 }
	 sorted_merge(first, second);
	 
	 for (auto item: first)
	 cout << item << " ";
	 cout << endl;
 return 0;
}
