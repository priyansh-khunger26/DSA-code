#include <bits/stdc++.h>

int linearSearch(vector<int> &ans, int target) {
  for(int i = 0;i < ans.size();i++) {
    if(ans[i] == target) {
      return i;
    }
  }

  return -1;
}
