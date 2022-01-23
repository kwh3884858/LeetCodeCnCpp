class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            bool result = calculate(mid, piles, h);
            if(result) right = mid ;
            else left = mid + 1;
        }
        return left;
    }

    bool calculate(int count, const vector<int>& piles, int h)
    {
        int hour = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            hour += piles[i] / count;
            hour += piles[i] % count == 0? 0 : 1;
        }
        if(hour <= h)return true;
        else return false;
    }
};