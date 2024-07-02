#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int data[n];
    
	for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < n - 1; i++) {
    	
        int max = 0;
        for (int j = 1; j < n - i; j++) {
            if (data[j] > data[max]) {
                max = j;
            }
        }
        int tmp = data[n - i - 1]; 
        data[n - i - 1] = data[max];
        data[max] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}

