class Solution {
    
    /*
        LOGIC:
        When we start burning the tree from a node, we need to go to adjacent nodes upwards and downwards
        i.e a node will burn its parent and both the children each second, thus we have to use BFS, can't use DFS 
        We have pointers to go in downward direction but not to go in upward direction
        So we'll first do a level order traversal to store parents of all the nodes in a hashmap
        Also, we are given integer value of target so we'll need to find node whose node->data= target 
        Then we'll traverse the tree starting from Target Node, and burn adjacent nodes in all direction each second
        
        Step 1: create a fnc to find parents of all nodes, and find target node using BFS
        Step 2: Apply BFS again to burn parent, left child and right child if they exist and haven't been visited before
        TC: O(N)+O(N)= O(N)  SC:O(N)
    */
  public:
    int BFStoBurnTree(Node* target, map<Node*, Node*> &parents)
    {
        map< Node*, int> vis;
        queue<Node*>q;
        q.push(target);
        vis[target]=1;
        int timer=-1;
        
        while(!q.empty())
        { 
            int size= q.size();
            timer++;
            
            while(size--)
            {
                 Node *node= q.front();
                 q.pop();
                 
                 //burning parent if parent exists and hasn't been visited yet
                 if(parents[node] && !vis[parents[node]])
                 { 
                     q.push(parents[node]);
                     vis[parents[node]]=1;
                 }
                 
                 //burning left child if it exists and hasn't been visited yet
                 if(node->left && !vis[node->left])
                 { 
                     q.push(node->left);
                     vis[node->left]=1;
                 }
                 
                 //burning right child if it exists and hasn't been visited yet
                 if(node->right && !vis[node->right])
                 { 
                     q.push(node->right);
                     vis[node->right]=1;
                 }
            }
            
        }
        return timer;
        
    }
    
    void BFStoMapParents(Node* root, map<Node*, Node*> &parents, int x, Node* &target)
    {
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* node= q.front();
            q.pop();
            
            if(node->data==x) 
                target= node;
            
            if(node->left)
                {
                    parents[node->left]= node;
                    q.push(node->left);
                }
            if(node->right)
                {
                    parents[node->right]= node;
                    q.push(node->right);
                }
        }

    }
    
    int minTime(Node* root, int tar) 
    {
        if(root==NULL)
            return 0;
        
        map<Node*, Node*> parents;
        Node* target= NULL;
        BFStoMapParents(root, parents, tar, target);
        
        int min_time=0;
        if(target!=NULL)
            min_time= BFStoBurnTree(target, parents);
        
        return min_time;
    }
};