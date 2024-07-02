#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int data[100][100];
    
    for (int j=0; j<n; j++){
    	 for (int i=0; i<2; i++){
    	 	cin >> data[j][i];
		 }		
	}
     
    for (int k=n; k>0; k--){
    	for (int p=0; p<k-1; p++){
    		if (data[p][0]>data[p+1][0]){
    			int tmp = data[p][0];
    			int tmp1 = data[p][1];
    			data[p][1] = data[p+1][1];
    			data[p+1][1] = tmp1;
    			data[p][0] = data[p+1][0];
    			data[p+1][0] = tmp;
			}
			
			if (data[p][0]==data[p+1][0]){
				if (data[p][1]>data[p+1][1]){
					int tmp3 = data[p][1];
    				data[p][1] = data[p+1][1];
    				data[p+1][1] = tmp3;
				}
					
			}
		}
	}
	cout<<endl;
	for (int m=0; m<n; m++){
		cout<< data[m][0] << " "<< data[m][1]<<endl;
	}
    return 0;
}
