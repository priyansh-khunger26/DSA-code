#include <bits/stdc++.h>

vector<int> sortArray(vector<int>& nums) {
      if(nums.size() == 0) {
          return nums;
      }

      auto minItr = min_element(nums.begin(), nums.end());
      auto maxItr = max_element(nums.begin(), nums.end());

      int mini = *minItr, maxi = *maxItr;
      vector<int> helper(maxi-mini+1, 0);

      for(int i = 0;i < nums.size();i++) {
          helper[nums[i]-mini]++;
      }

      int index= 0;
      for(int i = 0;i < helper.size();i++) {
          while(helper[i]>0) {
              nums[index++] = i+mini;
              helper[i]--;
          }
      }

      return nums;
  }
