#include <iostream>
#include <vector>
using namespace std;

void printHelper(vector<vector<int> > &edges, int n, int startIndex, vector<bool> &visited) {
    cout << startIndex << endl;
    visited[startIndex] = true;

    for(int i = 0;i < n;i++) {
        if(i == startIndex) {
            continue;
        }

        if(edges[startIndex][i] == 1) {
            if(!visited[i]) {
                printHelper(edges, n, i, visited);
            }
        }
    }
}

void print(vector<vector<int> > &edges, int n, int startIndex) {
    vector<bool> visited(n, false);
    printHelper(edges, n, startIndex, visited);
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

    print(edges, n, 0);
}
