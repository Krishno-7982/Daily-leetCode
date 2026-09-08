class Solution {
public:
    vector<int>parent, sz;
    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a, b);
            }
            parent[b] = a;
            sz[a]+=sz[b];
        }


    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        sz.resize(n);
        vector<pair<int, pair<int, int>>>edges;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        for(int i=0;i<n;i++){
            make(i);
        }
        sort(edges.begin(), edges.end());
        
        long long min_cost = 0;
        for(auto &edge : edges){
            int wt = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;
            if(find(x)==find(y)) continue;
            Union(x,y);
            min_cost += wt;
        }
        return min_cost;
    }
};