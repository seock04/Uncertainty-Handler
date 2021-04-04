class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int cn = n-1;
        int cm = 0;
        
        while(cn >= 0 and cm < m){
            if(matrix[cn][cm] == target){
                return true;
            }
            else if(matrix[cn][cm] < target){
                cm += 1;
            }
            else{
                cn -= 1;
            }
        }
        
        return false;
    }
};
