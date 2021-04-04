class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size()-1;
        int n = num2.size()-1;
        
        string s = "";
        int carry = 0;
        while(m >= 0 or n >= 0 or carry > 0){
            int number1 = m >= 0 ? num1[m]-'0' : 0;
            int number2 = n >= 0 ? num2[n]-'0' : 0;            
            int sum = number1 + number2 + carry;
            cout << sum << "\n";
            
            carry = sum / 10;
            sum %= 10;
            s.push_back(sum + '0');
            m--;
            n--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
