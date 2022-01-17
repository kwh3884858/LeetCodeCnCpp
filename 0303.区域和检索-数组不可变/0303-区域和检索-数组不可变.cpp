class NumArray {
public:
    NumArray(vector<int>& nums) {
        m_ref = &nums;
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left < 0 || left >= m_ref->size() || right < 0 || right >= m_ref->size() || left > right)
        {
            return 0; 
        }
        return (*m_ref)[right] - (left - 1 < 0 ? 0 : (*m_ref)[left - 1]);
    }

    vector<int>* m_ref;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */