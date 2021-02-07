class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> pos;
        
        for(int i = 0; i< s.length; ++i){
            if(s[i] == c){
                pos.push_back(i);
            }                
        }
        
        vector<int> ret(s.length, 0);
        
        for(int i = 0; i<ret.size(); ++i){
            if(s[i] != c){
                int dist = 10001;
                for(int j = 0; j < pos.size(); ++j){
                    dist = min(dist, abs(i - pos[j]));
                }
                
                ret[i] = dist;
            }
        }
        
        return ret;
    }
};