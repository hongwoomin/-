#include <iostream>
#include <vector>
using namespace std;
void compute_set(vector<int> &A, vector<int> &B){
	auto it = A.begin();
    for (int i = 0; i < B.size(); i++) {	
        bool duplicate = false;
        it = A.begin();
        while(it!=A.end() && B[i]>=*it){
        	if (B[i] == *it) {
                duplicate = true;
                it = A.erase(it);
            }
            else{
            	it++;
			}
           	
		}	
        if (!duplicate) {
            A.insert(it, B[i]);
        }
    }
}

int main() {
	 int m, n, k;
	 vector<int> first, second;
	 cin >> m;
	 // m개의 정수가 오름차순으로 정렬되어 입력된다.
	 for (int i=0; i<m; i++) {
		 cin >> k;
		 first.push_back(k);
	 }
	 cin >> n;
	 // n개의 정수가 오름차순으로 정렬되어 입력된다.
	 for (int i=0; i<n; i++) {
		 cin >> k;
		 second.push_back(k);
	 }
	 compute_set(first, second);
	 for (auto item: first)
	 	cout << item << " ";
	 cout << endl;
	 return 0;
}
