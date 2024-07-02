#include <iostream>
using namespace std;

int main() {
    double bot = 1, sum = 0;
    int n;
    cin >> n;

    for (int j = 1; j <= n; j++) {
            bot *= j;
            sum += 1.0 / double(bot);
        }    
    cout << sum << endl;

    return 0;
}
