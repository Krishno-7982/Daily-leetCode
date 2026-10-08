class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, pair<int, int>>> v;
        for(auto &x : costs){
            v.push_back({x[0]-x[1], {x[0], x[1]}});
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int n = costs.size();
        for(int i=0;i<n;i++){
            if(i>=(n/2)){
                sum += v[i].second.second;
            }else{
                sum += v[i].second.first;
            }
        }
        return sum;
    }
};