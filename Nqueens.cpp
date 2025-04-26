#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1) return false;
        if (col + (row - i) < N && board[i][col + (row - i)] == 1) return false;
    }
    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "Q " : "x ");
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, N);
            board[row][col] = 0;
        }
    }
}

int main() {
    int N = 4;
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueens(board, 0, N);
    return 0;
}
