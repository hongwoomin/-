#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	int data[100];

	for (int i =0; i<N; i++){
		cin >> data[i];
	}


	int max = 0;
	for (int m =0; m<N; m++){
		int count_one= 0;
		int count_zero = 0;
		int tmp=0;  // 처음 인덱스부터 기준을 잡기
		for (int k = m; k<N; k++){

			if (data[k]==1){  //1과 2의 개수를 셀려줌
				count_one++;
			}
			if (data[k]==0){
				count_zero ++;
			}

			if (count_zero>1){ //0개수가 2개가 될떄
				break;
			}

			tmp = count_one +count_zero ;
			if (tmp >max){
				max = tmp;
			}
		}
	}
	cout << max;
	return 0;
}

