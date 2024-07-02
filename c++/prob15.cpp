#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 0) {
                count++;
            }
            num /= 10;
        }
    }
    cout << count;

    return 0;
}

