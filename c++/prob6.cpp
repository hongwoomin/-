#include <iostream>
using namespace std;

int main(){
	
	int N;
	cin >> N;
	
	int max, min;
	int a;
	
	for (int i =0; i<N; i++){
		cin >> a;
		if (i==0){
			max=a;
			min= max;
		}
		if (a>max){
			max = a;
		}
		if (a<min){
			min = a;
		}
		cout << max-min<<" ";
	}
	
	
	
	return 0;
}
