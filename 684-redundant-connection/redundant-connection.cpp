class Solution {
public:
    int n = 1005;
    int parent[1005];
    int sz[1005];
    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[b]>sz[a]){
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        for(int i=1;i<=n;i++){
            make(i);
        }
        vector<vector<int>>ans;
        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            if(find(a) == find(b)){
                ans.push_back({a, b});
            }
            Union(a, b);
        }
        return ans.back();
    }
};