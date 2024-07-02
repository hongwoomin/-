#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 

    int count1 = 0; 
    int count2 = 0; 
    
    for (int i = 0; i < 1000000; i++) {
        int temp1 = 0;
        int temp2 = 0;

        for (int j = 0; j < 6; j++) {
            int result = rand() % 6 + 1; 
            if (result == 1) {
                temp1++;
            }
        }
        if (temp1 >= 1){
            count1++;
        }

        for (int j = 0; j < 12; j++) {
            int result = rand() % 6 + 1; 
            if (result == 1) {
                temp2++;
            }
        }
        if (temp2 >= 2) {
            count2++;
        }
    }

    cout << "6�� ������ ��� 1�� ������ ��: " <<count1 << endl;
    cout <<"12�� ������ ��� �ι� 1�� ������ ��: "<< count2;

    return 0;
}

