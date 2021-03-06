class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map <string, string> word_map;
        
        for(string s : words){
            word_map[s] = s;
        }
        
        for(string s : words){
            for(int i = 1; i<s.length(); ++i){
                if(word_map.find(s.substr(i)) != word_map.end()){
                    word_map.erase(s.substr(i));
                }
            }            
        }
        
        int res=0;
        for(auto v : word_map){
            cout << v.second << '\n';
            res += v.second.length() + 1;
        }
        
        return res;
    }
    
};
