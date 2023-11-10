class Solution {
public:
    
    void dfs(unordered_map<int, vector<int>>& adj,int a,unordered_map<int, bool>& vis,vector<int>& ans)
    {
        vis[a] = true;
        
        for(int i=0;i<adj[a].size();i++){
            if(vis[adj[a][i]]==false)
            {
                ans.push_back(adj[a][i]);
                dfs(adj,adj[a][i],vis,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int start=-1;
        int n=0;
        unordered_map<int, vector<int>> adj;
        for (auto &p : adjacentPairs) 
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
            n=max(n,max(p[0],p[1]));
        }
        for (auto &p : adjacentPairs) 
        {
            if(adj[p[0]].size()==1)
            {
                start=p[0];
                break;
            }
            if(adj[p[1]].size()==1)
            {
                start=p[1];
                break;
            }
        }
        
        unordered_map<int, bool> vis;
        vector<int> ans;
        ans.push_back(start);
        dfs(adj,start,vis,ans);
        
        return ans;
    }
};