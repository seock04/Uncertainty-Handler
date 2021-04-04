class Solution {
public:
    int N;
    vector<string> generateParenthesis(int n) {
        N = n;
        string p = "";
        vector<string> result;
        
        solve(0, 0, p, result);
        
        return result;
    }
    
    void solve(int open, int close, string p, vector<string>& res)
    {
        if(open == N and close == N){
            res.push_back(p);
            cout << p << "\n";
            return;
        }
        
        if(open < N){
            solve(open+1, close, p + '(', res);
        }
        
        if(open <= N and open > close){
            solve(open, close+1, p + ')', res);
        }
    }
};
