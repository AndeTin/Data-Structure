#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<vector<int>>& arr, int NumOfCol, int col) {
    for (int i = 1; i < NumOfCol; i++) {
        int j = i - 1;
        vector<int> temp = arr[i];
        while(j >= 0 && arr[j][col] > temp[col]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        InsertionSort(score, score.size(), k);
        return score;
    }
};
int main() {
    vector<vector<int>> score = {{2, 9, 3}, {4, 8, 2}, {7, 6, 5}};
    Solution s;
    s.sortTheStudents(score, 2);
    cout << "Sorted Score:" << endl;
    for (const auto& row : score) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}