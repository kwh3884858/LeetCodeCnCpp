class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> result;
        int validCount = 0;
        int start = 0, length = INT_MAX;
        for(char c : t) need[c]++;
        while(right < s.size())
        {
            char cRight = s[right];
            right++;

            if(need.count(cRight))
            {
                result[ cRight ]++;
                if(result[ cRight ] == need[ cRight ]) validCount++;
            }

            while(validCount == need.size())
            {
                if(right - left < length)
                {
                    start = left;
                    length = right - left;
                }
                char cLeft = s[left];
                left++;
                if(need.count(cLeft))
                {
                    result[cLeft]--;
                    if(result[ cLeft ] < need[ cLeft ]) validCount--;
                }
            }
        }
        return length ==  INT_MAX ? string() : string(s, start, length);
    }
};