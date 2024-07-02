#include <iostream>
using namespace std;

int main() {
    int count = 0;
    for (int x = 0; x <= 100; x++) {
        int min = (x + 2) / 3;
        int max = (2 * x) / 3;

        for (int y = min; y <= max; y++) {
            if (x * x + y * y <= 10000) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}

