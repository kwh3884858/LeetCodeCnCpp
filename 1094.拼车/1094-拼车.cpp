class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> result(1001);
        for(int i = 0; i < trips.size(); i++)
        {
            result[ trips[i][1] ] +=  trips[i][0];
            result[ trips[i][2] ] -=  trips[i][0];
        }

        for(int i = 1; i < result.size(); i++)
        {
            result[i] += result[i - 1];
            if(result[i - 1] > capacity) return false;
        }
        return true;
    }
};