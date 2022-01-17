class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result;
        result.resize(length + 1, 0);
        for(int i = 0; i < updates.size(); i++)
        {
            result[updates[i][0]] += updates[i][2];
            result[updates[i][1] + 1] += -updates[i][2];
        }

        for(int i = 1; i < length; i++)
        {
            result[i] += result[i - 1];
        }
        result.resize(length);
        return result;
    }
};