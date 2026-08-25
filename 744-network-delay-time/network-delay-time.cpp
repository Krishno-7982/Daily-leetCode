class Solution {
public:

    const int INF = 1e9;

    int dijkstra(int source, int n, vector<vector<pair<int,int>>>& g) {

        vector<int> vis(n + 1, 0);
        vector<int> dis(n + 1, INF);

        set<pair<int,int>> st;

        st.insert({0, source});
        dis[source] = 0;

        while(!st.empty()) {

            auto node = *st.begin();

            int distance = node.first;
            int v = node.second;

            st.erase(st.begin());

            if(vis[v]) continue;

            vis[v] = 1;

            for(auto child : g[v]) {

                int child_v = child.first;
                int wt = child.second;

                if(dis[v] + wt < dis[child_v]) {

                    dis[child_v] = dis[v] + wt;

                    st.insert({dis[child_v], child_v});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dis[i] == INF)
                return -1;

            ans = max(ans, dis[i]);
        }

        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> g(n + 1);

        for(auto vec : times) {

            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            g[u].push_back({v, wt});
        }

        return dijkstra(k, n, g);
    }
};