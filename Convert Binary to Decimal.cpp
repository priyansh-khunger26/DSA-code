#include <bits/stdc++.h>
using namespace std;

// Assuming Binary Number is stored in a vector or an array
// It can be modified even if the number is given in different formats

int func(vector<int> &input) {
  int ans = 0;
  for(int i = 0;i < input.size();i++) {
    ans = ans * 2 + input[i];
  }

  return ans;
}
