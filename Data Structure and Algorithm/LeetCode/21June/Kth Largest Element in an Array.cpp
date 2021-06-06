// using quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        for(auto v : nums){
            cout << v;
        }
        cout << "\n";
        return nums[k-1];
    }
    
    void quickSort(vector<int>& nums, int left, int right)
    {
        if(left >= right) return;
        
        int l = left;
        int r = right;
        int pivot = left;
        
        while(l < r){
            while(nums[l] >= nums[pivot] and l < right) l++;
            while(nums[r] < nums[pivot]) r--;
            if(l < r) swap(nums[l], nums[r]);
        }
        swap(nums[pivot], nums[r]);
        quickSort(nums, left, r-1);
        quickSort(nums, r+1, right);
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        priority_queue<int> maxheap;
        for(auto i : nums){
            maxheap.push(i);
        }
        for(int i = 1; i<k;++i)maxheap.pop();
        
        return maxheap.top();
        //*/
        
        /*min heap solution*/
        ///*
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto i : nums){
            minheap.push(i);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        return minheap.top();
        
        //*/
        
    }
    
    
};

