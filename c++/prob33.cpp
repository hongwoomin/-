#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
	srand(time(0));
    int N;
    cin >> N;

    int data[N][N]={0,};
    int a,b;
  	
	int count = 0;
	
	for (int i = 0; i < 10000; i++) {
		int a = N /2; //처음 위치 초기화 
		int b = N/2;
		data[a][b] = 1;
		int moves = 0;
		
		while(1){
			int dir = rand() % 4;
			
			if (dir ==0 && b<N-1 && data[a][b + 1] == 0 ){ //동
				b++;
			}
			else if(dir ==1 && a< N-1 && data[a + 1][b] == 0){ //남 
				a++; 
			}
			else if(dir ==2  && b>0 &&data[a][b - 1] == 0){ //서 
				b--; 
			} 
			else if(dir ==3 && a>0 && data[a - 1][b] == 0){ // 북 
				a--; 
			}
			
			data[a][b] = 1;
			
			
			if((a==0) || (b==0) || a==N-1 || b==N-1){
				count++;
				break;
			}	
			
			moves ++;
			
			if (moves>=N*N){
				break;
			}	 	
		}
		// 방문한 길 초기화 
		for (int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				data[j][k] = 0;
			}
		}					
	}
	
	cout << double(count)/10000;
    
    return 0;
}


