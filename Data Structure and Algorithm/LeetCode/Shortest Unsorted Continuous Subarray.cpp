
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int len = nums.size();

        bool sorted = true;
        int left = INT_MAX;
        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                sorted = false;
            }

            if (sorted == false) {
                left = min(left, nums[i]);
            }
        }

        sorted = true;
        int right = INT_MIN;
        for (int i = len-2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                sorted = false;
            }

            if (sorted == false) {
                right = max(right, nums[i]);
            }
        }
        if (left == INT_MAX and right == INT_MIN) return 0;
        cout << left << " " << right << "\n";

        int left_boundary = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] > left) {
                left_boundary = i;
                cout << nums[i] << "\n";
                break;
            }
        }

        int right_boundary = len;
        for (int i = len-1; i >= 0; --i) {
            if (nums[i] < right) {
                right_boundary = i;
                cout << nums[i] << "\n";
                break;
            }
        }

        return right_boundary - left_boundary < 0 ? 0 : right_boundary-left_boundary+1;
    }
};
