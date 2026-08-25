class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> left;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> right;

        int n = costs.size();

        int l = 0;
        int r = n - 1;

        
        for(int i = 0; i < candidates && l <= r; i++) {
            left.push({costs[l], l});
            l++;
        }

        
        for(int i = 0; i < candidates && l <= r; i++) {
            right.push({costs[r], r});
            r--;
        }

        long long total_cost = 0;

        while(k--) {

            if(right.empty() || 
              (!left.empty() && left.top() <= right.top())) {

                auto [cost, idx] = left.top();
                left.pop();

                total_cost += cost;

                
                if(l <= r) {
                    left.push({costs[l], l});
                    l++;
                }

            } else {

                auto [cost, idx] = right.top();
                right.pop();

                total_cost += cost;

                
                if(l <= r) {
                    right.push({costs[r], r});
                    r--;
                }
            }
        }

        return total_cost;
    }
};