class Solution {

public:

     /*
            x,y coordinates are given for n points on a plane
            we need to find 3 points i, j, k such that dist(i,j)==dist(i,k) 
            
            also i,j,k and i,k,j will be counted diff as the order of tuples matter
            
            if we have 2 pts equidistant to ith point, we'll get 2 boomerang combinations i,a,b and i,b,a
            if we have 3 such pts a b c, then we'll get 
            i,a,b ; i,b,a
            i,b,c ; i,c,b
            i,a,c ; i,c,a
            i.e 6 boomerang
            
            so we can be observe that whenever a new equidistant point and we had already x combinations , 
            then it will make exactly x more combinations with all the the other equidistant points
            
            TC:O(n^2)
            SC:O(n)
        */
    
    int getDistance(vector<int> a, vector<int> b)
    {
        return ((a[0]-b[0])*(a[0]-b[0]))+((a[1]-b[1])*(a[1]-b[1]));
    }
 
    int numberOfBoomerangs(vector<vector<int>>& points) {
    
        int n= points.size(), boomerangs=0;
        
        // getting distance between all pairs 
        for(int i=0; i<n; i++)
        {
            // fixing ith point and finding all the points equidistant with i which can form a boomerang
            unordered_map<int, int> dist;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    int d= getDistance(points[i], points[j]);
                    
                    // found a boomerang
                    if(dist.find(d)!=dist.end())
                        boomerangs+= dist[d];
                    
                    dist[d]++;
                }
            }
        }
        return boomerangs*2;            
    }
};