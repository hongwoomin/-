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

            if (sign == '+') { //���ھտ� �ִ� ��ȣ�� ���� ���
								//4 �տ��� + ��� ġ�ϱ�  
                sum += num;
            } 
			else {
                sum -= num;
            }
            num = 0;  // ��ȣ�� ������ �������� ���ڰ� �����Ƿ� �ڸ��� 
					//  ����ϴ� ���� �ʱ�ȭ 
            sign = c; 
        }
    } 
    if (sign == '+') {     //������ ���� ��� 
        sum += num;
    } 
	else {
        sum -= num;
    }
    cout << sum << endl; 	
    return 0;
}

