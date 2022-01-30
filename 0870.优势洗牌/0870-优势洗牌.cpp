class Solution {
public:
    struct Pair
    {
        int index;
        int value;
    };
    static bool LessThan (const Pair& i, const Pair& j) { return (i.value < j.value); }
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp1(nums1);
        sort(tmp1.begin(), tmp1.begin() + tmp1.size());

        vector<int> result(tmp1.size(), 0);
        
        vector<Pair> tmp2;
        for(int i = 0; i< nums1.size(); i++)
        {
            Pair pair;
            pair.index = i;
            pair.value = nums2[i];
            tmp2.push_back(pair);
        }
        sort(tmp2.begin(), tmp2.end(), LessThan);
        int left =  0, right = tmp1.size() - 1;

        for(int i = tmp2.size() - 1; i >= 0; i--)
        {
            if(tmp1[right] <= tmp2[i].value)
            {
                result[ tmp2[i].index ] = tmp1[left];
                left++;
            }
            else
            {
                result[ tmp2[i].index ] = tmp1[right];
                right--;
            }

        }
        return result;
    }
};