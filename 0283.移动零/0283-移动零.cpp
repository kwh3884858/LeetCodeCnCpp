class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2) return;
        int fast = 0;
        int slow = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for(int i = slow; i < fast; i++) nums[i] = 0;
    }
};