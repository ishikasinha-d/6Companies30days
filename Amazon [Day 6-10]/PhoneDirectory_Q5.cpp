class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string str)
    {
        /*
            LOGIC:
            For string s, we need to get all prefixes i.e if
            s= geeips
            prefixes= {g, ge, gee, geei, geeip, geeips}
            So if we find a list v matching prefix g
            then for ge we need to match from list v and not from the original contact array
            because any string which has ge as prefix will definitely have g too as its prefix
            and to sort lexicographically, we can use set
            
            TC: O(|s|*n*max|contact[i]|)
            SC: O(n * max|contact[i]|)
        */
        
        vector<vector<string>> ans;
        set<string> s;
        vector<string>v;
        string prefix="";
        
        // initializing v with all contacts 
        for(int i=0; i<n; i++)
            v.push_back(contact[i]);
        
        // for each prefix from index 0 to i, we'll search the phone directory
        for(int i=0; i<str.length(); i++)
        {
            prefix+= str[i];
            
            // for prefix from index 0 to i, we'll search in list v which
            // already contains contacts matching prefix from index 0 to i-1
            // inserting in set to sort in lexicographical manner
            for(auto x: v)
            {
                if(x.substr(0,i+1)==prefix)
                    s.insert(x);
            }
            
            if(s.empty())
                s.insert("0");
            
            // adding matching contacts to the 2D ans array 
            v.clear();
            v.insert(v.begin(), s.begin(), s.end());
            s.clear();
            ans.push_back(v);
        }
        
        return ans;
    }
};