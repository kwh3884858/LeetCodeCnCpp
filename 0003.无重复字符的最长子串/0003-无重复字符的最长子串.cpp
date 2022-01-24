class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> result;
        int min = 0;
        while(right < s.size())
        {
            char cRight = s[right];
            right++;
            result[cRight]++;
            while(result[cRight] > 1)
            {
                char cLeft = s[left];
                left++;
                result[cLeft]--;
            }
            min = max(min, right - left);
        }
        return min;
    }
};