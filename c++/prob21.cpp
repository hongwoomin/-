#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int data[101];
	int j = 0;
	int count =0;
	int t;
	for (int i=0; i<n; i++){
		cin >> t;
		if (i==0){
			data[j] = t;
			count ++;
		}
		else
			if(data[j]<=t){
				data[++j]=t;
				count++;
			}
	}
	cout <<count<<": ";
	for (int k=0; k<count; k++){
		cout << data[k]<<" ";
	}
	return 0;


	
}
