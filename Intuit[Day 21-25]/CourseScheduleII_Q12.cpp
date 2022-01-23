class Solution {
public:
    /*
         Step 1: Make directed graph adjacency list
         Step 2: find topological sort
         Step 3 return sort if its size is == numCourses else return empty array
         
         TC: O(N+E)= O(N)
         
   */
    vector<int> topologicalSort( int N, vector<int> adj[])
    {
        
        vector<int> toposort;
        vector<int>indegree(N,0);
        queue<int>q;
        
        // finding indegrees of all nodes
        for(int i=0; i<N; i++)
            for(auto it: adj[i])
                indegree[it]++;
        
        // pushing all nodes with 0 indegree into queue
        for(int i=0; i<N; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto u= q.front();
            q.pop();
            toposort.push_back(u);
            
            for(auto it: adj[u])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            
        }
        
        if(toposort.size()==N)
            return toposort;
        else
            return {};
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int> adj[numCourses];
        
        for(auto x: prerequisites)
            adj[x[1]].push_back(x[0]);
        
        return topologicalSort(numCourses, adj);        
    }
};