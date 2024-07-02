#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> words;
    string str;
    while (true) {
        cin >> str;
        
        if (str == "exit") {
            break;
        }
        // 중복확인 
        auto check = find(words.begin(), words.end(), str);
        if(check != words.end()){
        	cout << "duplicate" << endl;
        	continue;
		}
  		auto it = words.begin();
  		while (it!= words.end() && *it <str){
  			it++;	
		}
    	if (it ==words.end()){ // 사전식 순으로 제일 뒤에 있으면 
    		words.push_back(str);
		}
		else{
			words.insert(it,str);
		}
		for(auto s : words){
			cout << s << " ";
		}
		cout << endl;
	}
    return 0;
}

