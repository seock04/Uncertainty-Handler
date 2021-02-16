
///////////////////using bit operation ////////////////////////
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int count_alpha = 0;
        for(char c : S){
            count_alpha += (isalpha(c) > 0);
        }
        
        vector<string> result;
        
        for(int mask=0; mask < (1<<count_alpha); mask++){
            string s;            
            int i = 0;
            for(char c : S){
                if(isalpha(c) == 0){
                    s.push_back(c);
                }
                else{
                    s.push_back((mask & (1 << i))? toupper(c) : tolower(c));
                    i++;
                }
            }
            result.push_back(s);
        }
        return result;
    }
};


////////////// using backtracking ///////////////////////////

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
       vector<string> result;
       string s; 
       permute(S, 0, s, result);
       return result;
    }
    
    void permute(string S, int index, string & s, vector<string> & res)
    {
        if(index >= S.length()){
            res.push_back(s);
            return;
        }
        
        char c = S[index];
        if(isalpha(c)){
            char cl = tolower(c);
            string lower = s + cl;
            
            char cu = toupper(c);
            string upper = s + cu;
            
            permute(S, index+1, lower, res);
            permute(S, index+1, upper, res);
        }
        else{
            s+=c;
            permute(S, index + 1, s, res);
        }
    }
};
