#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int data[100];
    
	for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int j=n; j>0; j--){
    	for (int k=0; k<j-1; k++){
    		if (data[k]>data[k+1]){
    			int tmp = data[k];
    			data[k] = data[k+1];
    			data[k+1] = tmp;
			}
		}
	}
	int b = 0;
	for (int a=1; a<n; a++){
		if (data[a] != data[a-1]){
			data[++b] = data[a];
		}
	}
	cout << b+1 <<":";
    for (int i = 0; i < b+1; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
