class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int n)
    {
        vector<string> ans;  
        map<int, string>mp= { {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        
        if(n==0) return ans;
        
        for(int i=0; i< mp[digits[0]].length(); i++)
        {
            char x= mp[digits[0]][i];
            string xx= "";
            xx+= x;
            ans.push_back(xx);
        }
        
        if(n==1)
            return ans;
        
        for(int p=1; p<n; p++)
        {
            char d= digits[p];
            vector<string> v;
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<mp[d].length(); j++)
                {
                    v.push_back(ans[i]+mp[d][j]);
                }
            }
            ans=v;
            v.clear();
        }
       
        return ans;
    }
};


