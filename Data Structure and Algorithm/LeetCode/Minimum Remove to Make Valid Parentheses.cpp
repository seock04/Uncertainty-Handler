class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int open = 0;
        string t;
        for(char c : s){
            if(c == '('){
                open++;
            }
            else if(c == ')'){
                if(open == 0) continue;
                open--;
            }
            
            t += c;
        }
        
        string result;
        for(int i = t.length() -1; i >= 0; i--){
            if(t[i] == '(' && open-- > 0) continue;
            
            result += t[i];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
