#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int data[100];
	int count = 0;
	for (int i=0; i<N; i++){
		cin >> data[i]; 
	}
	for (int j=0; j<N; j++){
		for (int k=j+1; k<N; k++){
			if (data[j]>data[k]){
				count++;
			}	
		}
	}
	cout << count;
	return 0;
}
