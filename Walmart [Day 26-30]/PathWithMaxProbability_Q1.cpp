class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        //creating undirected weighted graph
        vector<unordered_map<int, double>> adj(n);
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]][edges[i][1]]= succProb[i];
            adj[edges[i][1]][edges[i][0]]= succProb[i]; 
        }
        
        //probability of reaching each node
        vector<double> p(n, 0.0);
      
        p[start] = 1.0; 
        
        // BFS
        queue<double> q;
        q.push(start);
        
        while(!q.empty())
        {
            double node= q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                double adj_node= it.first;
                double probab= it.second;
                
                if(p[node]*probab>p[adj_node])
                {
                    q.push(adj_node);
                    p[adj_node]= p[node]*probab;
                }
            }
        }
        
        return p[end];
    }
};