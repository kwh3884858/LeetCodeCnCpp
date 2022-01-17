class Solution {
public:
    // struct Node
    // {
    //     int m_value = 0;
    //     Node* m_left = nullptr;
    //     Node* m_right = nullptr;
    // }

    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> maps;
        maps[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (maps.find(sum - k) != maps.end()) {
                count += maps[sum - k];
            }
            maps[ sum ]++;
        }
        return count;
    }
};