class Solution {
public:
 bool dfs(vector<int> &ans, int target, int i) 
    {
        if (i == ans.size()) 
            return target == 0;

        int n = ans[i];
        // if we don't invert this number
        if (dfs(ans, target, i + 1)) 
            return true; 

        ans[i] = -n;
        // if we invert this number
        if (dfs(ans, target - n, i + 1)) 
            return true; 
            
        ans[i] = n;
        return false;
    }
    
    vector<int> recoverArray(int n, vector<int>& A) 
    {
        int mn = *min_element(begin(A), end(A)); // `mn` must be the sum of all the negative numbers in `A`.
        
        // offset all the numbers by -mn, so that all the numbers in `A` are non-negative.
        for (int &n : A) 
            n += -mn; 
        
        multiset<int> s(begin(A), end(A)), tmp;
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) 
        {
            tmp.clear();
            int num = *next(s.begin()); // the 2nd number in the sorted subset sums must be a number in the answer
            ans.push_back(num);
            
            while (s.size()) 
            {
                int first = *s.begin(); // `first` is a subset sum without `num`. We leave it for the next round.
                tmp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first + num)); // `first + num` is a subset sum with `num` which should be ignored going forward.
            }
            swap(s, tmp);
        }
        
        dfs(ans, -mn, 0); // Find a subset in `ans` whose sum is `-mn`. Invert all the numbers in this subset.
        return ans;
    }
};