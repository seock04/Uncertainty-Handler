class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int>sequence(26, 0);
        
        for(int i = 0; i < order.length(); ++i){
            sequence[order[i] - 'a'] = i;
        }
        for(int i = 1; i < words.size(); ++i){
            int sizei = words[i].size();
            int sizemi = words[i-1].size();
            
            bool iisbigger = false;
            for(int j = 0; j < sizei; ++j){
                if(sizemi > j and sequence[words[i][j] - 'a'] < sequence[words[i-1][j] - 'a']){
                    return false;
                }
                else if(sizemi <= j or (sizemi > j and sequence[words[i][j] - 'a'] > sequence[words[i-1][j] - 'a'])){
                    cout << "bigger: " << words[i][j] << " " << words[i-1][j] << "\n";
                    iisbigger = true;
                    break;
                }
                cout << "same: " << words[i][j] << " " << words[i-1][j] << "\n";
            }
            if(iisbigger == false and sizei < sizemi){
                return false;
            }
        }       

        
        return true;
    }
};
