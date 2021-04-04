class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0") return "0";
        
        int m = num1.length();
        int n = num2.length();
        
        vector <int> v(m+n, 0);
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                v[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                v[i+j] += v[i+j+1] / 10;
                v[i+j+1] %= 10;
            }
        }
        
        int i = 0;
        while(i < m+n and v[i] == 0) ++i;
        
        string s = "";
        while(i < m+n){
            s.push_back(v[i++]+'0');    
        }            
        
        return s;
    }
};
