class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        
        set<string> bc;
        
        for(int i = 0; i <= s.length()-k; i++){
            
            bc.insert(s.substr(i, k));
            //cout << s.substr(i, k) <<"\n";
        }
        
        return bc.size() == pow(2, k);
    }
};
