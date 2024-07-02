#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main() {
    ifstream infile("sample_lines.txt");
    string line;
    string lines[1000];
    int word_count[1000]={0};
    int n = 0;

    while (getline(infile, line)){
        
        if (line.empty()){  //공백줄이면 넘어가기 
        	continue;
		}
		//줄에서 제일 앞에 있는 공백 제거 
        while (line.front() == ' ')
            line.erase(0, 1);
        
        bool prev_space = false;
        for (int i = 1; i < line.length(); i++){
        	if (line[i]==' '){
        		prev_space =true;
			}
            if (line[i] == ' ' && line[i-1] == ' '){ // 공백이 두개이상인거 한개로 만들어줌 
                line.erase(i, 1);
                i--;
            }
            if (prev_space ==true && line[i]!=' '){
            	word_count[n]++;    //공백 기준으로 단어 나눔 
            	prev_space = false;
			}
        }
        lines[n] = line;
        n++;
    }
    infile.close();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (word_count[i] < word_count[j]) {
                swap(word_count[i], word_count[j]);
                swap(lines[i], lines[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << lines[i] << ": " << word_count[i]+1<< endl;
    }

    return 0;
}

