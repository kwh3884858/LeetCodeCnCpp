class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> result;
        int valid = 0;
        vector<int> saved;
        for(char c : p) need[c]++;
        while(right < s.size())
        {
            char cRight = s[right];
            right++;
            if(need.count(cRight))
            {
                result[cRight]++;
                if(result[cRight] == need[cRight]) valid++;
            }

            while(right - left >= p.size())
            {
                if(valid == need.size())
                {
                    saved.push_back(left);
                }
                char cLeft = s[left];
                left++;
                if(need.count(cLeft))
                {
                    if(result[cLeft] == need[cLeft]) valid--;
                    result[cLeft]--;
                }
            }
        }
        return saved;
    }
};