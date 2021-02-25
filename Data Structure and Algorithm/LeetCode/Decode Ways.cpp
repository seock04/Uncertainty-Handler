class Solution {
public:
    int numDecodings(string s) {
   
        if(s.length() == 0 or s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int prevtoprev = 1, prev = 1;
        for(int i = 1; i<s.length(); i++){
            int d = s[i] - '0';
            int dd = (s[i-1] - '0') * 10 + s[i] - '0';
            
            int count = 0;
            if(d > 0) count +=  prev;
            if(dd >= 10 and dd <= 26) count += prevtoprev;
            
            prevtoprev = prev;
            prev = count;
        }
        return prev;
    }
};
