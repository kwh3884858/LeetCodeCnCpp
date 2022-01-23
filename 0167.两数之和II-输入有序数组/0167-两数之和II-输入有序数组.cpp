class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right)
        {
            int mid = numbers[left] + numbers[right] ;
            if(mid == target) { return vector<int> { left + 1, right + 1 }; }
            else if (mid > target) { right--; }
            else { left++; }
        }
        return vector<int> { -1, -1 };;
    }
};