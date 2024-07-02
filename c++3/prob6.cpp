#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> path;

bool intersect(pair<int, int> current, pair<int, int> new_pos) {
    for (int i = 1; i < path.size(); ++i) {
        pair<int, int> p1 = path[i - 1];
        pair<int, int> p2 = path[i];

        // 선분의 방향을 통일하여 교차 여부 확인
        // 선분의 방향을 통일하여 교차 여부 확인
		if (p1.first == p2.first) { // 수직 선분
		    if (p1.second < p2.second)
		        swap(p1, p2);
		    if (current.first == new_pos.first && p1.first == current.first && p1.second <= current.second && current.second <= p2.second)
		        return true;
		    if (current.first < p1.first && new_pos.first >= p1.first && min(p1.second, p2.second) <= current.second && current.second <= max(p1.second, p2.second))
	        	return true;

		} else if (p1.second == p2.second) { // 수평 선분
		    if (p1.first > p2.first)
		        swap(p1, p2);
		    if (current.second == new_pos.second && p1.second == current.second && p1.first <= current.first && current.first <= p2.first) //입력도 수평인경우 
		        return true;
		    if (p1.first <= current.first && p2.first >= current.first && p1.second >= new_pos.second && p1.second < current.second) //
		        return true;
		    if (p1.first<=current.first && p2.first>= current.first && current.second<p1.second && new_pos.second>=p1.second){
		    	return true;
			}
		}
	}
    return false;
}

int main() {
    pair<int, int> current = {0, 0};
    pair<int, int> new_pos;
    path.push_back(current);

    int dir, dis;
    while (true) {
        cin >> dir >> dis;
        if (dir == -1 && dis == -1) {
            break;
        }

        
        if (dir == 0) { // y 좌표 증가
            new_pos = {current.first, current.second + dis};
        } else if (dir == 1) { // x 좌표 증가
            new_pos = {current.first + dis, current.second};
        } else if (dir == 2) { // y 좌표 감소
            new_pos = {current.first, current.second - dis};
        } else if (dir == 3) { // x 좌표 감소
            new_pos = {current.first - dis, current.second};
        }

        bool invalid = false;
        // 선분 교차 확인
        if (intersect(current, new_pos)) {
            invalid = true;
        }

        if (invalid) {
            cout << "invalid move" << endl;
        } else {
            path.push_back(new_pos);
            current = new_pos;
            cout << current.first << " " << current.second << endl;
        }
        
    }

    return 0;
}

