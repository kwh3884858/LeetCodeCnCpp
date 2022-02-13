class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int count = GetCount(piles, mid);
            if(count == h) right = mid - 1;
            else if(count > h) left = mid + 1;
            else right = mid - 1;
        }
        if(left > 1000000000 || GetCount(piles, left) > h) return -1;
        return left;
    }
        
    int GetCount(vector<int>& piles, int time)
    {
        int amount = 0;
        for(int i: piles)
        {
            amount += i / time;
            amount += i % time != 0 ? 1 : 0;
        }
        return amount;
    }
};