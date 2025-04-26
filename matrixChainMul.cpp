#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int dims[], int n) {
    int dp[n][n];
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int dims[] = {1, 2, 3, 4};
    int n = sizeof(dims) / sizeof(dims[0]);
    cout << matrixChainOrder(dims, n) << endl;
    return 0;
}
