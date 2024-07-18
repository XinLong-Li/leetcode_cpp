#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findKthLargestInCombination(vector<int>& combination, int K) {
    // 找出组合中第K大的数
    sort(combination.begin(), combination.end(), greater<int>());
    return combination[K-1];
}

void findCombinations(const vector<vector<int>>& matrix, int N, int M, int K, int row, vector<bool>& usedCols, vector<int>& currentCombination, int& minKthLargest) {
    if (row == N) {
        // 找到一种组合，计算其中第K大的数
        int KthLargest = findKthLargestInCombination(currentCombination, K);
        minKthLargest = min(minKthLargest, KthLargest);
        return;
    }
    
    for (int col = 0; col < M; ++col) {
        if (!usedCols[col]) {
            usedCols[col] = true;
            currentCombination.push_back(matrix[row][col]);
            
            findCombinations(matrix, N, M, K, row + 1, usedCols, currentCombination, minKthLargest);
            
            usedCols[col] = false;
            currentCombination.pop_back();
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    vector<bool> usedCols(M, false);
    vector<int> currentCombination;
    int minKthLargest = INT_MAX;
    
    findCombinations(matrix, N, M, K, 0, usedCols, currentCombination, minKthLargest);
    
    cout << minKthLargest << endl;
    
    return 0;
}