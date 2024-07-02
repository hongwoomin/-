#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int data[100];
	int tmp=0;
	for (int i=0; i<N; i++){
		cin >> data[i]; 
	}
	for (int j=0; j<N; j++){
		int count = 1;
		for (int k=j+1; k<N; k++){
			if (data[k-1]<=data[k]){
				count++;
			}
			else{
				break;
			}
		}
		if (count>tmp){
			tmp = count;
		}
	}
	cout << tmp;
	return 0;
}
