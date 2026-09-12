class Solution {
public:
    int N = 510;
    int parent[510];
    int sz[510];
    void make(int v){
        parent[v] = v;
        sz[v] = 1;

    }

    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a  = find(a);
        b = find(b);
        if(a==b) return;
        if(sz[b] > sz[a]){
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }

    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,int>mp;
        int num = 1;
        for(auto equation : equations){
            if(mp.count(equation[0])==0){
                mp[equation[0]] = num++;
            }
            if(mp.count(equation[3]) == 0){
                mp[equation[3]] = num++;
            }
        }
        
        for(int i=1;i<num;i++){
            make(i);
        }
        //union all equalities
        for(auto e : equations){
            if(e[1]=='='){
                Union(mp[e[0]], mp[e[3]]);
            }
        }
        //check for all inequatlities
        for(auto e : equations){
            if(e[1] == '!'){
                if(find(mp[e[0]])==find(mp[e[3]])){
                    return false;
                }
            }
        }
        return true;
       
    }
};