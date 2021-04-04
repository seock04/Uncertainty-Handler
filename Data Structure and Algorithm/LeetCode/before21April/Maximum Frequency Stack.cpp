//Hard

class FreqStack {
public:
    
    unordered_map<int, int> freq_map;
    unordered_map<int, vector<int>> group;
    int max_freq;
    
    FreqStack() {
        max_freq = 0;        
    }
    
    void push(int x) {
        ++freq_map[x];
        if(freq_map[x] > max_freq){
            max_freq = freq_map[x];
        }
        group[freq_map[x]].push_back(x);
    }
    
    int pop() {    
        auto x = group[max_freq].back(); group[max_freq].pop_back();
        if(group[max_freq].empty()){
            group.erase(max_freq);
            --max_freq;
        }
        
        --freq_map[x];
        
        if(freq_map[x] == 0){
            freq_map.erase(x);
        }
        
        return x;
    }
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
