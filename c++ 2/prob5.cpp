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
        
        if (line.empty()){  //�������̸� �Ѿ�� 
        	continue;
		}
		//�ٿ��� ���� �տ� �ִ� ���� ���� 
        while (line.front() == ' ')
            line.erase(0, 1);
        
        bool prev_space = false;
        for (int i = 1; i < line.length(); i++){
        	if (line[i]==' '){
        		prev_space =true;
			}
            if (line[i] == ' ' && line[i-1] == ' '){ // ������ �ΰ��̻��ΰ� �Ѱ��� ������� 
                line.erase(i, 1);
                i--;
            }
            if (prev_space ==true && line[i]!=' '){
            	word_count[n]++;    //���� �������� �ܾ� ���� 
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

