class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length() == 0) return 0;
        if(isPalindrome(s)) return 1;
        
        return 2;
    }
    
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length()-1;
        
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};
