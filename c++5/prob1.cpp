#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
    int capacity = 0, size_ = 0;
    int* arr = nullptr;

    void resize() {
        if (size_ >= capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }
            int* temp = new int[capacity];
            for (int i = 0; i < size_; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
    }

    int find_index(int val) {
        for (int i = 0; i < size_; i++) {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }
public:
    OrderedVecInt() = default;

    void insert(int val) {
        resize();
        int i = size_ - 1;
        while (i >= 0 && arr[i] > val) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
        size_++;
    }

    bool remove_by_val(int val) {
        int index = find_index(val);
        if (index != -1) {
            for (int i = index; i < size_ - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size_--;
            return true;
        }
        return false;
    }

    bool remove_by_index(int index) {
        if (index >= 0 && index < size_) {
            for (int i = index; i < size_ - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size_--;
            return true;
        }
        return false;
    }

    int& operator[](int index) {
        return arr[index];
    }

    int size() {
        return size_;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    int n, k;
    OrderedVecInt vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k = rand() % 1000;
        vec.insert(k);
    }
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    if (vec.remove_by_val(vec[2]))
        cout << "Remove done" << endl;
    else
        cout << "Remove failed" << endl;
    if (vec.remove_by_index(4))
        cout << "RemoveIndex done" << endl;
    else
        cout << "RemoveIndex failed" << endl;
    for (int i = 0; i < vec.size(); i++)
        vec[i] -= 10;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
