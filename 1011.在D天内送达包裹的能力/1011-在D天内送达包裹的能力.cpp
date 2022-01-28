class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1, right = 25000000;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int day = GetDay(weights, mid);
            if(day == days) right = mid - 1;
            else if(day < days) right = mid -1;
            else left = mid + 1;
        }
        if(left > 25000000 || GetDay(weights, left) > days) return -1;
        return left;
    }
    
    int GetDay(vector<int>& weights, int capacity)
    {
        int day = 0;
        int tmp = 0;
        for(auto i : weights)
        {
            if(i > capacity) return INT_MAX;
            tmp += i;
            if(tmp > capacity)
            {
                tmp = i;
                day++;
            }
        }
        return ++day;
    }
};