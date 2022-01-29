class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        
        stack<int> st;
        bool flag= false;
        
        for(int i= N-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
                
            st.push(arr[i]);
            
            if(st.size()==3)
                {
                    flag= true;
                    break;
                }
        }
        
        vector<int>ans;
        
        if(flag)
        {
            ans.push_back(st.top()); st.pop();
            ans.push_back(st.top()); st.pop();
            ans.push_back(st.top()); 
        }
        
        return ans;
    }
};