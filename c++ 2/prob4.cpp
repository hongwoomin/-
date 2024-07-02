#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int sum = 0;
    int num = 0;
    char sign = '+'; 
    for(auto c : s){
        if (isdigit(c)){
            num = num * 10 + (c - '0');
        } 
		else if (c == '+' || c == '-') {

            if (sign == '+') { //숫자앞에 있는 부호에 따라 계산
								//4 앞에는 + 라고 치니깐  
                sum += num;
            } 
			else {
                sum -= num;
            }
            num = 0;  // 부호가 나오면 다음에는 숫자가 나오므로 자릿수 
					//  계산하는 숫자 초기화 
            sign = c; 
        }
    } 
    if (sign == '+') {     //마지막 숫자 계산 
        sum += num;
    } 
	else {
        sum -= num;
    }
    cout << sum << endl; 	
    return 0;
}

