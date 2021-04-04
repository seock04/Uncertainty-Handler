class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>stack;
        int result = 0;
        
        stack.push_back(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stack.push_back(i);
            }
            
            if(s[i] == ')'){
                stack.pop_back();
                if(!stack.empty()){
                    int temp = i - stack.back();
                    result = max(result, temp);
                }
                else{
                    stack.push_back(i);
                }
            }
        }
        
        return result;
    }
};
