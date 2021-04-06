class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        
        if(n%2 == 0){
            for(int i = n/2-1; i >=0; --i){
                res += ((2*i) + 1);
                cout << "even " << res << "\n";
            }
        }
        else{
            int mid = n/2;
            int mid_val = (2*mid) + 1;
            for(int i = 0; i < mid; ++i){
                res += mid_val - ((2*i)+1);
                cout << "odd " << res << "\n";
            }
        }
        
        return res;
    }
};
