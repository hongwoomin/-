#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int tmp = 0;
	int data[100];
	for (int i=0; i<N; i++){
		cin >> data[i]; 
	}
	int K;
	cin >> K;
	
	for (int j=0; j<N; j++){
		int count = 0;
		int sum = 0;
		for (int k=j; k<N; k++){
			sum+=data[k];
			if (sum>K){
				break;
			}
			else{
				count ++;
			}
		}
		if (count>tmp){
			tmp = count;
		}
	}
	cout << tmp;
	return 0;
}

