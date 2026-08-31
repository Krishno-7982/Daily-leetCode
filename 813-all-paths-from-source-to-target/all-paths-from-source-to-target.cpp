class Solution {
public:

    void dfs(int source, int dest,
             vector<vector<int>>& graph,
             vector<int>& path,
             vector<vector<int>>& ans) {

        path.push_back(source);

        
        if(source == dest) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        
        for(auto child : graph[source]) {
            dfs(child, dest, graph, path, ans);
        }

       
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(
        vector<vector<int>>& graph) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, graph.size() - 1, graph, path, ans);

        return ans;
    }
};