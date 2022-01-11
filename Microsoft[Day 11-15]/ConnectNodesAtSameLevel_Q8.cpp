/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        /*
            We can do set our nextRight pointers to the correct node 
            while doing level order traversal using a previous pointer 
            
            TC: O(N)
            SC: O(N)
        */
        
        queue<Node*> q;
        q.push(root);
        Node *prev;
        
        while(!q.empty())
        {
            int size= q.size();
            prev= NULL;
            
            while(size--)
            {
                Node* node= q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                if(prev!=NULL)
                    prev->nextRight= node;
                prev= node;
            }
            prev->nextRight= NULL;
        }
    }    
      
};
