#include <iostream>
using namespace std;


int p(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int count = 0;
    for (int i = 2; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = j + 1; k <= 100; k++) {
                if (p(i, j) == 1 && p(i, k) == 1 && p(j, k) == 1) {
                    count++;
                }
            }
        }
    }
    cout << count;

    return 0;
}


