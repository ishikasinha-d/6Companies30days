class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        // LOGIC: 
        // After sorting each anagram, the order of letters will be same
        // Unordered map can be used to store all anagrams hashed to the sorted string
        // TC: O(N*SlogS)  where N is for traversing string_list and SlogS is for sorting each string
        
        vector<vector<string>>anagrams;
        unordered_map<string, vector<string>>mp;
        
        for(auto str: string_list)
        {
            string sorted_str= str;
            sort(sorted_str.begin(), sorted_str.end());
            
            mp[sorted_str].push_back(str);
        }
        
        for(auto x: mp)
        {
            anagrams.push_back(x.second);
        }
        
        return anagrams;
    }
};
