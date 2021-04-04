class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums){
      int n = nums.size();
      vector<vector<int>> result;
      
      for(int mask = 0; mask < (1 << n); mask++){
          vector<int> subset;
          for(int i = 0; i < n; i++){
              if(mask & (1 << i)) subset.push_back(nums[i]);
          }
          results.push_back(subset);
      }
      
      return result;
  }
}
