
#include <iostream>
using namespace std;

int main() {
    double add = 1,sum = 1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        add *= double(-0.5);
        sum += add;
    }
    cout << sum << endl;

    return 0;
}

