class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>G(numCourses);
        vector<int>inDegree(numCourses, 0);

        for(auto prerequisite : prerequisites){
            G[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for(auto child : G[node]){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    q.push(child);
                }
            }
        }
        if(topo.size() != numCourses){
            return {};
        }
        return topo;
        
    }
};