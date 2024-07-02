#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int squares = 0;
	int num;
	 
    for (int i = 0; i < n; i++) {
       
        cin >> num;
        sum += num;
        squares += num * num;
    }

    double ave = double(sum) / n;

    double a = double(squares) / n - pow(ave, 2);
    double result = sqrt(a);

    // 결과 출력
    cout << ave <<" "<< result;

    return 0;
}

