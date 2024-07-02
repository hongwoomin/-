#include <iostream>
using namespace std;

int main(){
	
	int N;
	int data[100]= {0,};
	cin >> N;
	while (N>0){
		data[N%10]++;
		N/=10;
	}
	for (int i=0; i<10; i++) {
		if (i==9){
			cout << data[i] << endl;	
		}
		else
		cout << data[i]<<", ";
	}
	return 0;


	
}
