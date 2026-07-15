class Solution {
public:
    bool isPossible(const vector<int>& piles, int h, int mid) {
        long long total_hours = 0; 
        
        for (int pile : piles) {

            total_hours += (pile + mid - 1) / mid;
            if (total_hours > h) return false;
        }
        
        return total_hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int hi = 0;
        for (int pile : piles) {
            hi = max(hi, pile);
        }
        
        int ans = hi;
        
        
        while (l <= hi) {
            int mid = l + (hi - l) / 2;
            
            if (isPossible(piles, h, mid)) {
                ans = mid;     
                hi = mid - 1;
            } else {
                l = mid + 1;      
            }
        }
        
        return ans;
    }
};