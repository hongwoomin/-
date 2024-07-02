#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	int n;
	int data[101];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> data[i];
	}
	int k;
	cin >> k;
	int tmp,num;
	tmp = abs(data[0]-k);
	num = data[0];
	for (int j=1; j<n; j++){
		if (tmp>abs(data[j]-k)){
			tmp = abs(data[j]-k);
			num = data[j];
		}		
	}
	cout << num;
	return 0;


	
}
