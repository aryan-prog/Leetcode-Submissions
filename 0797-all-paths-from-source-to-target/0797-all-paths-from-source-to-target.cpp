class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n,0);
        
        // for(int i=0;i<n)
        dfs(graph,0,ans,temp,vis);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph,int node,vector<vector<int>>& ans,vector<int>& temp,vector<int>& vis)
    {
        vis[node]=1;
        temp.push_back(node);
        if(node==graph.size()-1)
            ans.push_back(temp);
            
        for(int i=0;i<graph[node].size();i++)
        {
            if(vis[graph[node][i]]==0)
            dfs(graph,graph[node][i],ans,temp,vis);
        }
        vis[node]=0;
        temp.pop_back();

    }
};