#include <iostream>
using namespace std;

int main() {
	
    int prices[101];
    int price;
	int days = 0;

    while (1) {
        cin >> price;
        if (price == -1 || days >= 101){
        	break;	
		} 
        prices[days++] = price;
    }

    int max_profit = 0;
    for (int i = 1; i < days; i++) {
        int profit = prices[i] - prices[i - 1]; 
        if (profit > 0) {
            max_profit += profit; 
        }
    }

   	cout << max_profit;

    return 0;
}

