#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int>> table;
bool check(int i, int j, int color);

int main(){
    ifstream theFile("board.txt");
    int N;
    theFile >> N;

    int num;
    for (int i = 0; i < N; i++){
        vector<int> row;
        for (int j = 0; j < N; j++){
            theFile >> num;
            row.push_back(num);
        }
        table.push_back(row);
    }

    bool black = false;
    bool white = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if (table[i][j] != 0) {
                if (check(i, j, table[i][j])){
                    if (table[i][j] == 1){
                        black = true;
                    } else {
                        white = true;
                    }
                }
            }
        }
    }

 	if (black){
        cout << "Black";
    } 
	else if (white){
        cout << "White";
    } 
	else {
        cout << "Not Finished";
    }

    return 0;
}

bool check(int i, int j, int color) { // 바둑판을 읽는 순서는 위에서 밑으로 왼쪽에서 오른쪽으로
									// 읽기 떄문에 방향검사는 동,동남,남,남서 이렇게만 검사해도됨 
   	int dir[4][2] = {{1,0},{1,-1},{0,1},{-1,1}};
   	

    for (auto way: dir) {
        int count = 1;
        for (int k = 1; k <= 4; k++) {
            int x = i + k * way[0];
            int y = j + k * way[1];
            if (x < 0 || x >= table.size() || y < 0 || y >= table[0].size() || table[x][y] != color) {
                break;
            }
            count++;
        }
        if (count == 5) {
            return true;
        }
    }
    return false;
}

