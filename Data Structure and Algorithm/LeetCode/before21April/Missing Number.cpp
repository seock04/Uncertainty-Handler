class Solution {
public:
    int missingNumber(vector<int>& nums) {
// 0 solution that I used
// counting sort with O(N) space but below are better solution      
      
 // 1st approach, using sum of all number logic sum of 0~n is same as n(m-1)/2, and if there is any missing number, then we can find it by substract it from all sum
 /*       
        int sum = 0;
        int ref = nums.size();
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ref += i;
        }
        
        cout << sum << " " << ref;
        return ref - sum;
*/
      
// 2nd approach, using xor logic
        int result = nums.size(); // init with the last number of nums
        for(int i = 0; i < nums.size(); i++){
            result = result ^ nums[i] ^ i;
        }
       
        return result;
    }
};
