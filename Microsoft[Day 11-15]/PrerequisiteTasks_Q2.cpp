class Solution {
public:
    
    bool isCycle( int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis )
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it: adj[node])
        {
            if(vis[it]==0 && isCycle(it,adj,vis,dfsVis))
                return true;
            else if(vis[it]==1 && dfsVis[it]==1)
                return true;
        }
        
        dfsVis[node]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    /*
	        N=4 tasks from 0 to 3
	        preq is basically a directed graph 0-->1-->2-->3
	        
	        N=2 from 0 to 1
	        preq= 0-->1 and 1--->0 so there is a cycle 
	        
	        So we can use 2 methods 
	        1. DFS to detect cycle in a directed graph
	        2. BFS to detect cycle using Kahn's Algorithm
	        
	        
	    */
	    
	    vector<int> adj[N];
	    
	    // storing edges of directed graph in adjacency list 
	   for(auto u: prerequisites)
	        adj[u.second].push_back(u.first);
	        
	    vector<int> vis(N,0);
	    vector<int> dfsVis(N,0);
	    
	    for(int i=0; i<N; i++)
	    {
	        if(vis[i]==0)
	            if(isCycle(i,adj,vis,dfsVis))
	                return false;
	    }
	    return true;
	    
	}
};