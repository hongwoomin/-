#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int back; 
    int attention; 
    int next; 

    cin >> back; 
    cin >> attention; 

    if (back <= attention){
        count++;
    }
    while (1) {
        cin >> next; 
        if (next == -1){
            break;
        }
        if (attention <= back && attention <= next){
            count++;
        }
        back = attention;
        attention = next;
    }
    if (attention <= back) {
        count++;
    }
    cout << count;
    return 0;
}

