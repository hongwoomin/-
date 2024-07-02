#include <iostream>
using namespace std;

int main() {

    int data[101];
    int count = 0;
	
    while (1) {
        int num;
        cin >> num;

        if (num == -1){
        	break;
		}
		int duplicate = 0;
        for (int i = 0; i < count; i++) {
        	if(data[i]==num){
        		duplicate = 1;
        		cout << "duplicate" << endl;
                break;	
			}    
        }
        if (!duplicate) {  // 중복체크 다하고 중복아니라면  
            int j = count - 1;
            while (j >= 0 && data[j] > num) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = num;
            count++;


            for (int m = 0; m < count; m++) {
                cout << data[m] << " ";
            }
            cout<< endl; 
        }
    }

    return 0;
}

