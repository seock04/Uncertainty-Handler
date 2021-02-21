class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        if( X >= Y) return X-Y;
        
        int result = 0;
        while(Y > X){
            if(Y%2 == 0) Y = Y/2;
            else
                Y = Y+1;
            result++;
        }
     
        return result + X-Y;       
    }  
};
