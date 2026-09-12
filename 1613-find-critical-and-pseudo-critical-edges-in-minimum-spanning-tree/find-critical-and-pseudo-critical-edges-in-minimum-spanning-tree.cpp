class Solution {
public:
    int parent[110];
    int sz[110];

    void make(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v) {
        if(v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[b] > sz[a]) {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }

    void DSU(int n) {
        for(int i = 0; i < n; i++) {
            make(i);
        }
    }

    int Kruskal(int n, vector<vector<int>>& edges, int skip, int force) {

        DSU(n);

        int weight = 0;
        int count = 0;

        // Force edge
        if(force != -1) {

            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            Union(u, v);

            weight += w;
            count++;
        }

        // Normal Kruskal
        for(int i = 0; i < edges.size(); i++) {

            if(i == skip) continue;
            if(i == force) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if(find(u) != find(v)) {

                Union(u, v);

                weight += w;
                count++;
            }
        }

        if(count != n - 1) {
            return INT_MAX;
        }

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges
    ) {

        // Store original index
        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Sort according to weight
        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            }
        );

        // Find normal MST weight
        int original = Kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> p_critical;

        for(int i = 0; i < edges.size(); i++) {

            // Remove edge
            int without = Kruskal(n, edges, i, -1);

            if(without > original) {

                // Critical
                critical.push_back(edges[i][3]);

            }
            else {

                // Force edge
                int with = Kruskal(n, edges, -1, i);

                if(with == original) {

                    // Pseudo-critical
                    p_critical.push_back(edges[i][3]);
                }
            }
        }

        return {critical, p_critical};
    }
};