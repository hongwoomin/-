#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("shuffled_dict.txt");
    string line;
    vector<string> words;

    // 단어들을 한 줄씩 벡터에 저장
    while (getline(infile, line)) {
        words.push_back(line);
    }
    infile.close();

    sort(words.begin(), words.end()); // 단어들을 사전순으로 정렬

    vector<string> pure_words;
    vector<string> words_explain;
    for (auto c : words) {
        // 탭 문자를 기준으로 순수 단어와 설명을 추출하여 저장
        int pos = c.find('\t');
        pure_words.push_back(c.substr(0, pos));
        string explain = c.substr(pos + 1); // 탭 이후의 부분만 저장
        words_explain.push_back(explain);
    }

    string word;
    cin >> word;

    auto i = find(pure_words.begin(), pure_words.end(), word);
    if (i != pure_words.end()) {
        // 입력한  단어가 있으면 설명과 함께 출력
        cout << "Found:"<<endl;
        cout << word << ": " << words_explain[i - pure_words.begin()] << endl;
    } else {
        cout << "Not found" << endl;
        int j = 0;	  // 앞뒤 단어 출력
	    while (j < pure_words.size() && word > pure_words[j]) {
	        j++;
	    }
	    if (j > 0) {
	        cout << "-" << pure_words[j - 1] << ": " << words_explain[j - 1] << endl;
	    }
	    if (j < pure_words.size()) {
	        cout << "+" << pure_words[j] << ": " << words_explain[j] << endl;
	    }
    }

    cout << endl;
    cout << "Results of prefix search:" << endl;

    // 접두사가 같은 단어 출력
    for (int k = 0; k < pure_words.size(); k++) {
        if (pure_words[k].substr(0, word.length()) == word) {
            cout << pure_words[k] << ": " << words_explain[k] << endl;
        }
    }

    return 0;
}

