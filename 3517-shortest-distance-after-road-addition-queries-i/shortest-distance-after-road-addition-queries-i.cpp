
class Solution {
public:

    void bfs(vector<vector<int>>& adj,
             vector<int>& dist,
             queue<int>& q) {

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto child : adj[node]) {

                if(dist[node] + 1 < dist[child]) {

                    dist[child] = dist[node] + 1;

                    q.push(child);
                }
            }
        }
    }

    vector<int> shortestDistanceAfterQueries(
        int n, vector<vector<int>>& queries
    ) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> dist(n);

        for(int i = 0; i < n; i++) {
            dist[i] = i;
        }

        vector<int> ans;

        for(auto query : queries) {

            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);

            queue<int> q;

            if(dist[u] + 1 < dist[v]) {

                dist[v] = dist[u] + 1;

                q.push(v);

                bfs(adj, dist, q);
            }

            ans.push_back(dist[n - 1]);
        }

        return ans;
    }
};
