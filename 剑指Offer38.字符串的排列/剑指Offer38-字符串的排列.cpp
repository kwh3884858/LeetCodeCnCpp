class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right= 0;
        unordered_map<char, int> need;
        unordered_map<char, int> result;
        int valid = 0;
        for(char c : s1) need[c]++;
        while(right < s2.size())
        {
            char cRight = s2[right];
            right++;
            if(need.count(cRight))
            {
                result[cRight]++;
                if(need[cRight] == result[cRight]) valid++;
            }

            while(valid == need.size())
            {
                if(right - left == s1.size()) return true;
                char cLeft = s2[left];
                left++;
                if(need.count(cLeft))
                {
                    if(need[cLeft] == result[cLeft]) valid--;
                    result[cLeft]--;
                }
            }
        }
        return false;
    }
};