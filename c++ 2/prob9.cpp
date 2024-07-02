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

    // �ܾ���� �� �پ� ���Ϳ� ����
    while (getline(infile, line)) {
        words.push_back(line);
    }
    infile.close();

    sort(words.begin(), words.end()); // �ܾ���� ���������� ����

    vector<string> pure_words;
    vector<string> words_explain;
    for (auto c : words) {
        // �� ���ڸ� �������� ���� �ܾ�� ������ �����Ͽ� ����
        int pos = c.find('\t');
        pure_words.push_back(c.substr(0, pos));
        string explain = c.substr(pos + 1); // �� ������ �κи� ����
        words_explain.push_back(explain);
    }

    string word;
    cin >> word;

    auto i = find(pure_words.begin(), pure_words.end(), word);
    if (i != pure_words.end()) {
        // �Է���  �ܾ ������ ����� �Բ� ���
        cout << "Found:"<<endl;
        cout << word << ": " << words_explain[i - pure_words.begin()] << endl;
    } else {
        cout << "Not found" << endl;
        int j = 0;	  // �յ� �ܾ� ���
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

    // ���λ簡 ���� �ܾ� ���
    for (int k = 0; k < pure_words.size(); k++) {
        if (pure_words[k].substr(0, word.length()) == word) {
            cout << pure_words[k] << ": " << words_explain[k] << endl;
        }
    }

    return 0;
}

