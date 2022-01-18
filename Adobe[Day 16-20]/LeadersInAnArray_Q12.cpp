class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        stack<int> st;
        
        for(int i= n-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push(a[i]);
            }
            else
            {
                if(a[i]>=st.top())
                    st.push(a[i]);
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
       return ans; 
    }
};
