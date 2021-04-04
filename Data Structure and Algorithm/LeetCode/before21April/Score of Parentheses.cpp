class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<char> s;
        int score = 0;
        for(char c : S){
            if(c == '('){
                s.push_back(score);
                score = 0;
            }
            else{
                score = s.back() + max(score*2, 1);
                s.pop_back();
            }
        }
        
        cout << score;
        
        return score;
    }
};
