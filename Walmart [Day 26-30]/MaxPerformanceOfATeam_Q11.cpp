class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        // efficiency is directy proportional to speed
        vector<pair<int,int>> eng(n);
        priority_queue<int, vector<int>, greater<int>> pq;  //minheap
        long sum=0, res=0;
        
        for(int i=0; i<n; i++)
        {
            eng[i]= {efficiency[i], speed[i]};
        }
        
        sort(rbegin(eng),rend(eng));
        
        for(auto x: eng)
        {
            int eff= x.first;
            int sp= x.second;
            
            pq.push(sp);
            sum+= sp;
            
            if(pq.size()>k)
            {
                sum-= pq.top();
                pq.pop();
            }
            res= max(res, sum*eff);
        }
        
        return res % (int)(1e9+7);
        
    }
};