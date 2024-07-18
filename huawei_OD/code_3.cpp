#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(1 << M, INF));
    dp[0][0] = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int mask = 0; mask < (1 << M); ++mask) {
            if (dp[i][mask] == INF) continue;
            for (int j = 0; j < M; ++j) {
                if (!(mask & (1 << j))) {
                    int new_mask = mask | (1 << j);
                    vector<int> values;
                    for (int x = 0; x <= i; ++x) {
                        for (int y = 0; y < M; ++y) {
                            if (new_mask & (1 << y)) {
                                values.push_back(matrix[x][y]);
                            }
                        }
                    }
                    sort(values.begin(), values.end(), greater<int>());
                    dp[i + 1][new_mask] = min(dp[i + 1][new_mask], values[K - 1]);
                }
            }
        }
    }
    
    int result = INF;
    for (int mask = 0; mask < (1 << M); ++mask) {
        if (__builtin_popcount(mask) == N) {
            result = min(result, dp[N][mask]);
        }
    }
    
    cout << result << endl;
    
    return 0;
}