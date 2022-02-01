class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end)
        {
            if(nums[start] == val)
            {
                nums[start] = nums[end];
                end--;
            }
            else
            {
                start++;
            }
        }
        return start;
    }
};