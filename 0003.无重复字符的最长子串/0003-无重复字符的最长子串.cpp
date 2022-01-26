class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int min = 0;
        unordered_map<char, int> freqence;
        while(right < s.size())
        {
            char cRight = s[right];
            freqence[cRight]++;
            right ++;
            while(freqence[cRight] > 1)
            {
                char cLeft = s[left];
                freqence[cLeft]--;
                left++;
            }
            if(right - left > min) min = right - left;
        }
        return min;
    }
};