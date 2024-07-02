#include <iostream>
using namespace std;

int main(){
	
	int n;
	int data[101];
	int result_data[101]={0,};
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> data[i];
	}
	int k;
	cin >> k;
	int move_index;
	move_index = k;
	for (int j=0; j<n; j++){
		if (j+move_index > n-1){
			result_data[(move_index+j)%(n)] = data[j];
		}
		else{
			result_data[j+move_index] = data[j];
		}
	}
	for (int a=0; a<n; a++){
		cout << result_data[a]<< " ";
	} 
	return 0;


	
}
