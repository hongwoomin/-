#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);


    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }


    sort(num.begin(), num.end());

    vector<int> result;
    auto it = num.begin();
    result.push_back(*it);
    it++; //Ã³À½ ¼ö Çª½Ã 
    for (it; it != num.end(); it++) {
        if (*it != *(it - 1)) {
            result.push_back(*it);
        }
    }


    cout << result.size() << ": ";
    for (auto c : result) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

