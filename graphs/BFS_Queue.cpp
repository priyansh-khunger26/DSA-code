#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printHelper(vector<vector<int>> &edges, int n, int startIndex, vector<bool> &visited) {
    queue<int> q;
    q.push(startIndex);
    visited[startIndex] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        cout << front << " ";
        for (int i = 0; i < n; i++) {
            if (edges[front][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print(vector<vector<int>> &edges, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printHelper(edges, n, i, visited);
        }
    }
    cout << endl; // Print a newline after traversal
}

int main() {
    int n, e;
    cin >> n >> e;

    if (n == 0) {
        return 0;
    }

    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;

        // Ensure the indices are within the valid range
        if (first >= 0 && first < n && second >= 0 && second < n) {
            edges[first][second] = 1;
            edges[second][first] = 1;
        } else {
            cout << "Invalid edge input: (" << first << ", " << second << ")" << endl;
            return 1; // Exit if there is an invalid edge input
        }
    }

    print(edges, n);
    return 0;
}
