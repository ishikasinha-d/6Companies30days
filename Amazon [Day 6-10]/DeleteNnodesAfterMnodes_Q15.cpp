class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        // base case
        if(head==NULL)
            return;
        
        Node* curr= head;
        
        while(curr)  
        {
            // Reaching Mth node
            int count=1;
            while(curr!=NULL && count<M)
            {
                curr= curr->next;
                count++;
            }
            
             // if we have reached the end, we'll return
            if(curr==NULL)
                return;
            
            // Starting from (M+1)th node and deleting N nodes
            Node* temp= curr->next;
            count= 0;
            
            while( temp!=NULL && count<N)
            {
                Node *node= temp;
                temp= temp->next;
                free(node);
                count++;
            }
            
            // linking tail of Mth node to (M+N+1)th node 
            curr->next= temp;
            
            // setting current node for next iteration
            curr= curr->next;
            
        }
    }
};
