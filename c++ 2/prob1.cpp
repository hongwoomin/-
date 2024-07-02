#include <iostream>
using namespace std;

int find_digit(int a, int b) {
    int count_a = 0, count_b = 0;
    while (a > 0) {   // 각 정수 자릿수 알아내기
        a /= 10;
        count_a++;
    }
    while (b > 0) {
        b /= 10;
        count_b++;
    }
    return count_a - count_b;
}

int comp(int a, int b) { // 각 정수 자릿수 맞춰서 비교하기
    int digit = find_digit(a, b);
    if (digit > 0) {
        for (int i = 0; i < digit; i++) {
            b *= 10;
        }
    } 
	else if (digit < 0) {
        for (int i = 0; i < -digit; i++) {
            a *= 10;
        }
    }
    if (a - b > 0) {
        return 1;
    } else if (a - b < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;

    int num[100];

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    for (int j = 0; j < n - 1; j++) {
        for (int k = 0; k < n - j - 1; k++) {  // 오름차순 정렬
            if (comp(num[k], num[k + 1]) == 1) {
                swap(num[k], num[k + 1]);
            }
            else if(comp(num[k], num[k + 1]) == 0 && num[k]>num[k+1]){
            	swap(num[k], num[k + 1]);
			}
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }

    return 0;
}

