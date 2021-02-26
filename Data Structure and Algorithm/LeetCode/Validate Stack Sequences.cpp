class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int ppush = 0, ppop = 0;
        
        vector<int> stack;
       
        for(int i = 0;i < pushed.size(); i++){
            stack.push_back(pushed[ppush++]);    
            
            while(!stack.empty() and stack.back() == popped[ppop]){
                stack.pop_back();
                ppop++;
            }
        }
        
        return ppop == popped.size();
    }
};
