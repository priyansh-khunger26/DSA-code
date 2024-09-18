int maxSubArray(vector<int>& nums) {
      int sum = 0;
      int max_sum = INT_MIN;

      int start =0, end=0;

      int tempStart = 0;

      for(int i = 0;i < nums.size();i++) {
          sum += nums[i];

          if(sum > max_sum) {
              max_sum = sum;
              end = i;
              start = tempStart;
          }

          if(sum < 0) {
              sum = 0;
              tempStart = i+1;
          }
      }

      cout << start << " " << end << endl;
      
      return max_sum;
  }
