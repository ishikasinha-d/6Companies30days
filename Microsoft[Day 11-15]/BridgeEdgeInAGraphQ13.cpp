class Solution
{
	public:
	
	bool isPathDFS(int c, int d, vector<int> adj[], vector<int> &vis)
	{
	    //base case
	    if(c==d)
	        return true;
	       
	    vis[c]=1;
	    
	    for(auto it: adj[c])
	        if(!vis[it])
	            if(isPathDFS(it, d, adj, vis))
	                return true;
	   return false;
	    
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
       /*
            1. remove edge c-d
            2. if there is still a path between c and d , return 0 else return 1
    
            to find whether there is a path between c and d, using DFS
            
            TC: O(V+E)
            SC: O(V)
       */
       
       vector<int> vis(V,0);
       
       //removing edge 
       
       for(auto it= adj[c].begin(); it!=adj[c].end(); )
            {
                if(*it==d)
                {
                    adj[c].erase(it);
                    break;
                }
                else
                    it++;
            }
        
       for(auto it= adj[d].begin(); it!=adj[d].end();)
            {
                if(*it==c)
                {
                    adj[d].erase(it);
                    break;
                }
                else
                    it++;
            }
       
       if(isPathDFS(c,d,adj,vis))
            return 0;
        
        return 1;
    }
};