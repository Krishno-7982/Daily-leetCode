
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        set<pair<long long,int>> st;

        dist[0] = 0;
        ways[0] = 1;

        st.insert({0, 0});

        while(!st.empty()) {

            auto node = *st.begin();
            st.erase(st.begin());

            long long d = node.first;
            int v = node.second;

            if(d > dist[v]) continue;

            for(auto child : adj[v]) {

                int child_v = child.first;
                int wt = child.second;

                long long newDis = d + wt;

                if(newDis < dist[child_v]) {

                    dist[child_v] = newDis;
                    ways[child_v] = ways[v];

                    st.insert({newDis, child_v});
                }

                else if(newDis == dist[child_v]) {

                    ways[child_v] =
                        (ways[child_v] + ways[v]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
