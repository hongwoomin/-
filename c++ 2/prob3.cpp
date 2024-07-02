#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    
	ifstream infile("input3.txt");
    string str;
    string words[101];
    int count[100]={0};
    
    int n=0;
    while(infile >> str){
    	for (int i=0; i<str.length(); i++){ //�Ҥ̤��� ��ȯ 
    		str[i] = tolower(str[i]); 
		}
		
		int j=0; //��Ͽ� �ִ��� �˻� 
		for (; j<n; j++){
			if(words[j]==str){
				break;
			}
		}
		if (j<n){    //��Ͽ� ������ Ƚ���� ���� 
			count[j]++;
		}
		else{ //��Ͽ������� �迭���� �߰��ϰ� Ƚ�� ���� 
			words[n] = str;
			count[n++] =1;
		}
	}
    infile.close();
    for(int i = 0; i<n; i++){
    	for(int j=n-1; j>i; j--){
    		if(count[j]>count[j-1]){
    			swap(count[j],count[j-1]);
    			swap(words[j],words[j-1]);
			}
			if (count[j]==count[j-1] && words[j]<words[j-1]){
				swap(words[j],words[j-1]);
			}
		}
	}    	
	for (int i=0; i<n; i++){
		cout<<words[i]<<":"<<count[i]<<endl;
	}
	
    return 0;
}

