#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    
    while (true) {
        getline(cin, text);
        
        if (text == "exit") {
            break;
        }
  		
  		for (int i=0; i<text.length(); i++){ //첫시작이 공백이 아닌지점 찾기 
  			if (isspace(text[i])==0){
  				text = text.substr(i);
				break;
			}
		}

		string result_text;
        bool prev_space = false; 
        
        for (auto c : text) {
            if (c != ' ') {
                result_text.push_back(c); 
                prev_space = false;
            } else if (!prev_space) {
                result_text.push_back(c);
                prev_space = true;
            } 
        }

        cout << result_text << ": " << result_text.length() << endl;
    }
    
    return 0;
}

