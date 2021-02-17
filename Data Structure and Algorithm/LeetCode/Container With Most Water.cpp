class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        cout << left << " " << right << "\n";
        int result = 0;

        while(left < right){
            
            int h = 0, w = 0;
            int container_size = 0; 
            
            h = min(height[left], height[right]);
            w = right - left;
            container_size = h * w;
            cout << " container size: " << container_size << "\n";
            result = max(result, container_size);            
            cout << " result: " << result << "\n";            
            
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        
        return result;
        
    }
};
