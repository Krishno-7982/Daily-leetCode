
class Solution {
public:
    int parent[200005];
    int sz[200005];

    void make(int i) {
        parent[i] = i;
        sz[i] = 1;
    }

    int find(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]) {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        for(int i = 0; i < n; i++) {
            make(i);
        }

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            Union(u, v);
        }

        return find(source) == find(destination);
    }
};
