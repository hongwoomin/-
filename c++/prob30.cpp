#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int data[100][2];
	for (int i=0; i<N; i++){
		for (int j =0; j<2; j++){
			cin >> data[i][j]; 
		}
	}
	
	int len = 0;
	int first_itv_s  = 0;
	int first_itv_e  = 0;
	int second_itv_s  = 0;
	int second_itv_e  = 0;
	int tmp;
	for (int k=0; k<N; k++){
		for (int m=k+1; m<N; m++){
			if(data[k][0]<=data[m][0] && data[k][1]>=data[m][1]){
				tmp = data[m][1] - data[m][0];
			}
			else if(data[m][1]<=data[k][1] && data[m][1]>=data[k][0]){
				tmp = data[m][1] - data[k][0];
			}
			else if(data[m][0]>=data[k][0] && data[k][1]>=data[m][0]){
				tmp = data[k][1] - data[m][0];
			}
			else if(data[k][0]>=data[m][0] && data[m][1]>=data[k][1]){
				tmp = data[k][1] - data[k][0];
			}
			if (tmp > len){
				len = tmp;
				first_itv_s  = data[k][0];
				first_itv_e  = data[k][1];
				second_itv_s  = data[m][0];
				second_itv_e  = data[m][1];
			}
		}
	}
	cout <<"["<<first_itv_s<<", "<<first_itv_e<<"]"<<endl;
	cout <<"["<<second_itv_s<<", "<<second_itv_e<<"]"<<endl;
	return 0;
}

