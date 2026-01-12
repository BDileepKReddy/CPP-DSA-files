#include <iostream>
#include <vector>
using namespace std;

bool dfs(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    int n = maze.size();

    // Out of bounds
    if(x < 0 || y < 0 || x >= n || y >= n)
        return false;

    // Blocked cell
    if(maze[x][y] == 0)
        return false;

    // Already visited
    if(visited[x][y])
        return false;

    // Mark visited
    visited[x][y] = true;
    cout << "Visiting (" << x << ", " << y << ")\n";

    // Destination reached
    if(x == n - 1 && y == n - 1) {
        cout << "Reached destination!\n";
        return true;
    }

    // Move in 4 directions
    // (right, down, left, up)
    if(dfs(x, y + 1, maze, visited)) return true;
    if(dfs(x + 1, y, maze, visited)) return true;
    if(dfs(x, y - 1, maze, visited)) return true;
    if(dfs(x - 1, y, maze, visited)) return true;

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    cout << "Trying to find a path...\n\n";

    bool possible = dfs(0, 0, maze, visited);

    cout << "\nFinal Answer: ";
    if(possible) cout << "Path Exists!" << endl;
    else cout << "No Path!" << endl;

    return 0;
}
