class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        if(dividend == INT_MIN and divisor == 1) return INT_MIN;
        
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        cout << dividend << " " << divisor << "\n";
        int quotient = 0;
        /*while (dividend <= divisor){
            dividend -= divisor;
            quotient++;
        }*/
        
        while(dividend <= divisor){
            int i = 1, accum = divisor;
            while(accum > INT_MIN >> 1 and dividend <= accum + accum){
                i += i;
                accum += accum;
            }
            
            dividend -= accum;
            quotient += i;
        }
        
        return negative ? -quotient : quotient;
    }
};
