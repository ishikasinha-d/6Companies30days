
vector<int> maxTenNumbers( vector<int> &arr, int n) 
{
    /*
        Since we have 1 million entries and only max 10 are required
        we can keep a minheap of size 10 at all times 
        such that top which would be minimum could be replaced by a greater value 
        TC: O(nlog10)= O(n)  SC:O(10)=O(1)
    */
    vector<int> maxTen;
    
    // declaring a minheap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // storing first 10 elements in minheap
    for(int i=0; i<10; i++)
        pq.push(arr[i]);
    
    // traversing the rest of the elements to get 10 maximum ones in the minheap
    for(int i=10; i<n; i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    while(!pq.empty())
    {
        maxTen.push_back(pq.top());
        pq.pop();
    }
  return maxTen;
}
