#include <iostream>
#include <vector>

using namespace std;

const int EMPTY = 0;
const int BLACK = 1;
const int WHITE = 2;

vector<vector<int>> board(8, vector<int>(8, 0));
void printBoard(vector<vector<int>> board);
bool checkBoard(vector<vector<int>> board);
int countStoneToCapture(int x, int y, int color);
void makeMove(int x, int y, int color);

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { 0, -1, 1, -1, 1, -1, 0, 1 };

int main() {
    // 초기 보드 설정
    board[3][3] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
    board[4][4] = WHITE;

    printBoard(board);

    while (true) {
        if (!checkBoard(board)) {
            // 게임 종료 조건
            int blackCount = 0, whiteCount = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (board[i][j] == BLACK) blackCount++;
                    else if (board[i][j] == WHITE) whiteCount++;
                }
            }
            if (blackCount > whiteCount) {
                cout << "You win" << endl;
            } else if (blackCount < whiteCount) {
                cout << "You lose" << endl;
            } else {
                cout << "Draw" << endl;
            }
            break;
        }

        // 검은돌 턴
        while(true){
            int x, y;
            cout << "당신 차례입니다 좌표를 입력하세요:  ";
            cin >> x >> y;

            // 입력한 위치에 돌을 놓을 수 있는지 확인
            if (board[y][x] != EMPTY) {
                cout << "여기에 돌을 둘수없습니다." << endl;
                continue;
            }

            // 입력한 위치에 돌을 놓아도 상대편 돌을 잡을 수 있는지 확인
            if (countStoneToCapture(y, x, BLACK) == 0) {
                cout << "여기에 돌을 둘수없습니다" << endl;
                continue;
            }

            // 돌을 놓고 상대편 돌을 잡음
            makeMove(y, x, BLACK);
            printBoard(board);
            cout << endl;
            break;
        }

        // 흰돌 턴  
        int maxCaptures = -1;
        int bestX = -1, bestY = -1;

        // 모든 빈 칸을 탐색하여 가장 많은 돌을 잡을 수 있는 위치 찾기
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == EMPTY) {
                    int captures = countStoneToCapture(i, j, WHITE);
                    if (captures > maxCaptures) {
                        maxCaptures = captures;
                        bestX = i;
                        bestY = j;
                    }
                }
            }
        }

        if (maxCaptures == 0) {
            cout << "둘곳이 없습니다 상대턴으로 넘깁니다." << endl;
            continue;
        }

        // 흰돌을 놓고 상대편 돌을 잡음
        makeMove(bestX, bestY, WHITE);
        cout << "컴퓨터 차례:" << endl;
        printBoard(board);
        cout << endl;
    }

    return 0;
}

void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkBoard(vector<vector<int>> board) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

int countStoneToCapture(int x, int y, int color) {
    int opponentColor = (color == BLACK) ? WHITE : BLACK;
    int captures = 0;

    // 상대 돌의 방향
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 보드 범위를 벗어나는 경우 건너뜀
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] != opponentColor) {
            continue;
        }

        // 상대 돌을 만나면 계속 진행하며 잡을 수 있는지 확인
        while (true) {
            nx += dx[dir]; 
            ny += dy[dir];

            // 보드 범위를 벗어나거나 빈 칸이 나오면 종료
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] == EMPTY) {
                break;
            }

            // 나의 돌을 만나면 잡을 수 있는 상대 돌의 개수를 증가하고 종료
            if (board[nx][ny] == color) {
                captures++;
                break;
            }
        }
    }

    return captures;
}

void makeMove(int x, int y, int color) {
    int opponentColor = (color == BLACK) ? WHITE : BLACK;

    // 입력한 위치에 돌을 놓음
    board[x][y] = color;

    // 상대편 돌을 모든 방향으로 확인하여 내 돌로 바꿈
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 상대편 돌을 찾으면서 내 돌로 바꿈
        bool foundOpponent = false;
        while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            if (board[nx][ny] == opponentColor) {
                foundOpponent = true;
            } 
            else if (board[nx][ny] == color) {
                // 같은 돌 사이에 있는 상대편 돌을 내 돌로 바꿈
                if (foundOpponent) {
                    while (board[nx -= dx[dir]][ny -= dy[dir]] == opponentColor) {
                        board[nx][ny] = color;
                    }
                }
                break;
            } 
            else {
                break;
            }
            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

