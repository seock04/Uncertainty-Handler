
/// below are very naive solution, but it works.. it's O(N) solution
class Solution {
public:
    
    int romanToInt(string s) {
        
        int len = s.size();
        
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'V') result += 5;
            else if(s[i] == 'L') result += 50;
            else if(s[i] == 'D') result += 500;
            else if(s[i] == 'M') result += 1000;
            else if(s[i] == 'I') {
                if(s[i+1] == 'V') {result += 4;i++;}
                else if(s[i+1] == 'X') {result += 9;i++;}
                else{
                    result += 1;
                }
            }
            else if(s[i] == 'X') {
                if(s[i+1] == 'L') {result += 40;i++;}
                else if(s[i+1] == 'C') {result += 90;i++;}
                else{
                    result += 10;
                }
            }
            else if(s[i] == 'C') {
                if(s[i+1] == 'D') {result += 400;i++;}
                else if(s[i+1] == 'M') {result += 900;i++;}
                else{
                    result += 100;
                }
            }
            
        }
        return result;
    }
};


//////////////////below are the simpler solution that use one idea ////////////
//////////// if cur value is smaller than prev, then subtract the value and if the cur value is bigger than prev, then add the value
class Solution {
public:
    
    int romanToInt(string s) {
        
        int len = s.size();
        
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        
        int result = 0;
        int prev = -1;
        int cur;
        
        for( int i = len-1; i >= 0; --i){
            cur = m[s[i]];
            if(cur < prev){
                result -= cur;
            }
            else{
                result += cur;
            }
            prev = cur;
        }
        
        return result;
    }
};
