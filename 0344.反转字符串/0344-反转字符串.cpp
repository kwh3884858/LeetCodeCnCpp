class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size() - 1;
        for(int i = 0;i <= length / 2; i++)
        {
            char t = s[i];
            s[i] = s[length - i];
            s[length - i] = t;
        }
    }
};