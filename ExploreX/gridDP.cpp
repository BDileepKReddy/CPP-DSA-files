#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<vector<int>> &maze) {
    int n = maze.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // If starting cell is blocked
    if(maze[0][0] == 0) {
        cout << "Start is blocked!" << endl;
        return false;
    }

    dp[0][0] = true;
    cout << "dp[0][0] = true (start)\n";

    // Fill DP table
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(maze[i][j] == 0) {
                cout << "dp[" << i << "][" << j << "] = false (blocked)\n";
                continue;
            }

            // skip starting cell
            if(i == 0 && j == 0) continue;

            bool fromTop = (i > 0) ? dp[i-1][j] : false;
            bool fromLeft = (j > 0) ? dp[i][j-1] : false;

            dp[i][j] = fromTop || fromLeft;

            cout << "dp[" << i << "][" << j << "] = "
                 << (dp[i][j] ? "true" : "false")
                 << " (from ";
            if(i > 0) cout << "top=" << fromTop << " ";
            if(j > 0) cout << "left=" << fromLeft;
            cout << ")\n";
        }
    }

    return dp[n-1][n-1];
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    bool possible = canReach(maze);

    cout << "\nFinal Answer: ";
    if(possible) cout << "Path Exists!" << endl;
    else cout << "No Path!" << endl;

    return 0;
}
