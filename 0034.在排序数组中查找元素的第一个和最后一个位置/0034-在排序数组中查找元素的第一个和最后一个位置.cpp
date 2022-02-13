class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result;
        if(nums.size() == 0) return vector<int>{ -1, -1};
        while(left <= right)
        {
            int mid = left + ( right - left ) / 2;
            int value = nums[mid];
            if(value < target) left = mid + 1;
            else if(value > target) right = mid - 1;
            else right = mid - 1;
        }
        if(left >= nums.size() || nums[left] != target) result.push_back(-1);
        else result.push_back(left);

        left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ( right - left ) / 2;
            int value = nums[mid];
            if(value < target) left = mid + 1;
            else if(value > target) right = mid - 1;
            else left = mid + 1;
        }
        if(right < 0 || nums[right] != target) result.push_back(-1);
        else result.push_back(right);

        return result;
    }
};