#include <bits/stdc++.h>

void selectionSort(vector<int> &ans) {
    for(int i = 0;i < ans.size();i++) {
        auto itr = min_element(ans.begin() + i, ans.end());
        int index = itr - ans.begin();

        swap(ans[i], ans[index]);
    }
}
