
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{   

    int before = 1, after = 1, sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i <= n-2; i++) {
        sum = before + after;
        before = after;
        after = sum;  
    }
    cout << sum << endl;
    return 0;
 

  
} 

