class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> candy;
        
        int type_count=0;
        for(int type : candyType){
            if(candy[type] == 0){
                type_count += 1;
                ++candy[type];
            } 
        }
        
        int len = candyType.size();
        len /= 2;
        
        return type_count > len ? len : type_count;
    }
};
