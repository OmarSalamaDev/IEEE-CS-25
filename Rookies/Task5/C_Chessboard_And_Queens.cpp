

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll N = 8;
vector<string> board;
ll result = 0;


bool isSafe(
    vector<ll>& column,
    vector<ll>& diag1,
    vector<ll>& diag2,
    ll row,
    ll col
){
    return 
        column[col] == 0 &&
        diag1[row - col + N - 1] == 0 &&
        diag2[row + col] == 0;
}

void solve(
    ll row,
    vector<ll>& column,
    vector<ll>& diag1,
    vector<ll>& diag2
){

    if (row == N) {
        result++;
        return;
    }

    for (ll col = 0; col < N; col++) {

        if (board[row][col] == '*' || !isSafe(column, diag1, diag2, row, col)) continue;

        column[col] = diag1[row - col + N - 1] = diag2[row + col] = 1;

        solve(row + 1, column, diag1, diag2);

        column[col] = diag1[row - col + N - 1] = diag2[row + col] = 0;
    }
}

int main() {

    board.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> board[i];
    }

    vector<ll> column(N, 0), diag1(2 * N - 1, 0), diag2(2 * N - 1, 0);
    solve(0, column, diag1, diag2);

    cout << result << endl;
}
