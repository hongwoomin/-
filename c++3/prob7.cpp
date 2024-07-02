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
    // �ʱ� ���� ����
    board[3][3] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
    board[4][4] = WHITE;

    printBoard(board);

    while (true) {
        if (!checkBoard(board)) {
            // ���� ���� ����
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

        // ������ ��
        while(true){
            int x, y;
            cout << "��� �����Դϴ� ��ǥ�� �Է��ϼ���:  ";
            cin >> x >> y;

            // �Է��� ��ġ�� ���� ���� �� �ִ��� Ȯ��
            if (board[y][x] != EMPTY) {
                cout << "���⿡ ���� �Ѽ������ϴ�." << endl;
                continue;
            }

            // �Է��� ��ġ�� ���� ���Ƶ� ����� ���� ���� �� �ִ��� Ȯ��
            if (countStoneToCapture(y, x, BLACK) == 0) {
                cout << "���⿡ ���� �Ѽ������ϴ�" << endl;
                continue;
            }

            // ���� ���� ����� ���� ����
            makeMove(y, x, BLACK);
            printBoard(board);
            cout << endl;
            break;
        }

        // �� ��  
        int maxCaptures = -1;
        int bestX = -1, bestY = -1;

        // ��� �� ĭ�� Ž���Ͽ� ���� ���� ���� ���� �� �ִ� ��ġ ã��
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
            cout << "�Ѱ��� �����ϴ� ��������� �ѱ�ϴ�." << endl;
            continue;
        }

        // ���� ���� ����� ���� ����
        makeMove(bestX, bestY, WHITE);
        cout << "��ǻ�� ����:" << endl;
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

    // ��� ���� ����
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // ���� ������ ����� ��� �ǳʶ�
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] != opponentColor) {
            continue;
        }

        // ��� ���� ������ ��� �����ϸ� ���� �� �ִ��� Ȯ��
        while (true) {
            nx += dx[dir]; 
            ny += dy[dir];

            // ���� ������ ����ų� �� ĭ�� ������ ����
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] == EMPTY) {
                break;
            }

            // ���� ���� ������ ���� �� �ִ� ��� ���� ������ �����ϰ� ����
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

    // �Է��� ��ġ�� ���� ����
    board[x][y] = color;

    // ����� ���� ��� �������� Ȯ���Ͽ� �� ���� �ٲ�
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // ����� ���� ã���鼭 �� ���� �ٲ�
        bool foundOpponent = false;
        while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            if (board[nx][ny] == opponentColor) {
                foundOpponent = true;
            } 
            else if (board[nx][ny] == color) {
                // ���� �� ���̿� �ִ� ����� ���� �� ���� �ٲ�
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

