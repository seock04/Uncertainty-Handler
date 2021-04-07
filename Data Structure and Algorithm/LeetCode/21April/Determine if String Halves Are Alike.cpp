class Solution {
public:
    bool halvesAreAlike(string s) {
        int A[52] = {0};
        int B[52] = {0};
        int half = s.size()/2;
        
        for(int i = 0; i < s.size(); ++i){
            if(i < half and s[i] >= 'a' and s[i] <= 'z'){
                A[s[i] - 'a'] += 1;
            }
            else if(i < half and s[i] >= 'A' and s[i] <= 'Z'){
                A[s[i] - 'A' + 26] += 1;
            }
            else if(i >= half and s[i] >= 'a' and s[i] <= 'z'){
                B[s[i] - 'a'] += 1;
            }
            else if(i >= half and s[i] >= 'A' and s[i] <= 'Z'){
                B[s[i] - 'A' + 26] += 1;
            }
        }
        
        int countA = A['a' - 'a'] + A['e' - 'a'] + A['i' - 'a'] + A['o' - 'a'] + A['u' - 'a'] + A['A' - 'A'+26] + A['E'- 'A'+26] + A['I'- 'A'+26] + A['O'- 'A'+26] + A['U'- 'A'+26];
        int countB = B['a' - 'a'] + B['e' - 'a'] + B['i' - 'a'] + B['o' - 'a'] + B['u' - 'a'] + B['A' - 'A'+26] + B['E'- 'A'+26] + B['I'- 'A'+26] + B['O'- 'A'+26] + B['U'- 'A'+26];
        cout << countA << " " << countB;
        return countA == countB;
    }
};
