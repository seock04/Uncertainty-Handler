class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int length = nums.size() - 1;
        
        int result = 0;
        int min = INT_MAX;
        for(int i = 0; i <= length - 2; i++){
            if(i == 0 || (nums[i] != nums[i-1])){
                int left = i+1;
                int right = length;
                
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right];
                    if( sum == target){
                        return sum;
                    }
                    else if( sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                    
                    if(min > abs(sum-target)){
                        result = sum;
                        min = abs(sum-target);
                    }
                }
            }             
        }
        return result;
    }
};
