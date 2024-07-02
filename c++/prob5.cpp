#include <iostream>
using namespace std;

int main() {
    int N;
    int result = -1; 
    int a;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        
        if (a >= 0) {
            if (result == -1 || a < result) {
                result = a;
            }
        }
    }
  
    cout << result; 
   

    return 0;
}


