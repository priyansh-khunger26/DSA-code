#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printHelper(vector<vector<int> > &edges, int n, int startIndex, vector<bool> &visited) {
    stack<int> s;
    s.push(startIndex);
    visited[startIndex] = true;

    while(!s.empty()) {
        int front = s.top();
        s.pop();

        cout << front << endl;
        // visited[front] = 1;
        for(int i = 0;i < n;i++) {
            if(i == front) {
                continue;
            }

            if(edges[front][i] == 1) {
                if(!visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void print(vector<vector<int> > &edges, int n) {
    vector<bool> visited(n, false);
    for(int i = 0;i < n;i++) {
        if(!visited[i]) {
            printHelper(edges, n, i, visited);
        }
    }
}

int main() {
	int n, e;
    cin >> n >> e;

    vector<vector<int> > edges(n, vector<int>(n, 0));
    for(int i = 0;i < e;i++) {
        int first, second;
        cin >> first >> second;

        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    print(edges, n);
}
