#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
vector<string> text;
int findWord(string keyword);
vector<string> make_pure_words(vector<string> &tokens);
vector<string> split_line(string line, char delimiter);


int main() {
    string command;
    while(true)		{
        cout << "$ ";
        cin >> command;
        if (command == "read")	{
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "exit")
            break;
        else if (command == "find")	{
            string keyword;
            cin >> keyword;
            for (int i=0; i<keyword.size(); i++){
            	keyword[i] = tolower(keyword[i]);
			}
            handle_find(keyword);
        }
    }
    return 0;
}

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while(getline(theFile, line)) {
        text.push_back(line);
        vector<string> tokens = split_line(line, ' ');
        for (auto s : make_pure_words(tokens))
            if (s.length()>3)
                addWord(s, lineNum);
        lineNum++;
    }
   
    lineNums.resize(words.size());
    theFile.close();
}

vector<string> split_line(string line, char delimiter) {
    vector<string> split_word;
    stringstream sstream(line);
    string str;

    while(getline(sstream, str, delimiter)){
        if (!str.empty()) {
            split_word.push_back(str);
        }
    }
    return split_word;
}

vector<string> make_pure_words(vector<string> &tokens){
    vector<string> pure_words;
    for (auto i: tokens){
        int first_index = 0, last_index = i.length()-1;
        while(!isalpha(i[first_index]) && first_index<i.length()){
            first_index++;
        }
        while(last_index>=0 && !isalpha(i[last_index])){
            last_index--;
        }
        if (first_index <= last_index){
            string pure_word = i.substr(first_index, last_index-first_index+1);
            for (int j=0; j<pure_word.length(); j++){
                pure_word[j] = tolower(pure_word[j]);
            }
            bool found = false;
            for (int k=0; k<pure_words.size(); k++){
                if(pure_words[k] == pure_word){
                    found = true;
                    break;
                }
            }
            if(!found){
                pure_words.push_back(pure_word);
            }
        }  
    }
    return pure_words;
}

void addWord(string word, int lineNum) {    
    int index = findWord(word);
    if (index > -1)
        lineNums[index].push_back(lineNum);
    else {
        words.push_back(word);
        vector<int> tmp = {lineNum};
        lineNums.push_back(tmp);
    }
}

int findWord(string keyword) {
    for (int i=0; i<words.size(); i++)
        if (words[i] == keyword)
            return i;
    return -1;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index != -1)  {
        cout << "The word " << keyword << " appears " <<
             lineNums[index].size()  << " times in lines: "<<endl;
     
        vector<bool> printed(text.size(), false);
        for (auto v : lineNums[index]) {
            if (!printed[v]) {
                cout << v << ": " << text[v] << endl;
                printed[v] = true;
            }
        }
    }
    else
        cout << "The word " << keyword << " doesn¡¯t appear." << endl;
}







