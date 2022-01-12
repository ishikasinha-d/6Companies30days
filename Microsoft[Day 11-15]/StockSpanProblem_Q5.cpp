public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       /*
            [100,80,60,70,60,75,85]
            
            span: maximum number of consecutive days (starting from today and going backward) for which the stock price                     was less than or equal to today's price.
            in other words, traversing from right to left, we need to find next greater element for each array element
            
            TC: O(N)
            SC: O(N)
        */
    
        stack< pair<int,int>> st;
        // stack<int>st;
        vector<int> ans;
        reverse(price, price+n);
//         100 80 60 70 60 75 85

// Your Output: 
// -1 100 80 80 70 80 100 
        
        int pos=0;
        for(int i=n-1; i>=0; i--)
        {
            int t=-1;
            while(!st.empty() && price[i]>=st.top().first)
                {
                    t= st.top().second;
                    st.pop();
                }
            
            
            if(!st.empty())
            ans.push_back(pos-st.top().second);
            else
            ans.push_back(pos-t);
            //     ans.push_back(st.top().second-i);
            // else 
            //     ans.push_back(t);
                
            st.push({price[i],pos++});
            // pos++;
            // st.push(price[i]);
        }
        return ans;
    }
};