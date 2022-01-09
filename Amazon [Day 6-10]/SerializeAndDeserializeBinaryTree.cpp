class Solution
{
    /*
        Serialization is the process of converting a data structure or object into a sequence of bits
        so that it can be stored in a file or memory buffer, or transmitted across a network connection link 
        to be reconstructed later in the same or another computer environment.
        
        Here, we have to use some traversal to convert out tree into an vector and
        then reconstruct the original tree from that array
        
        Serialization:
        We can use recurive preorder traversal (root left right) using a helper function
        a. if node is null, we can push int(NULL) or -1 in our list and return
        b. else push node in list, recur for left then recur for right
        TC: O(n) SC: O(n)
        
        Deserialization:
        just as we used recursion to serialize, we'll reverse the process here
        preorder traversal= root left right i.e first we need to grab root 
        and then point its left pointer to the left subtree and right pointer to the right subtree
        and we'll get out left and right subtrees by recurring for the element next to current node
        a. We'll call a helper function passing index=0 as reference
        b. if index>N , return NULL
        c. if arr[index]== int(NULL), we'll increment index and return NULL
        d. create node of arr[index] and increment index
        e. node's left-> recur for left subtree and node's right-> recur for right subtree
        TC: O(N) SC: O(1)
        
        
    */
    public:
    void serializeHelper(Node* root, vector<int> &preorder)
    {
        if(root==NULL)
            {
                preorder.push_back(int(NULL));
                return;
            }
        
        preorder.push_back(root->data);
        serializeHelper(root->left, preorder);
        serializeHelper(root->right, preorder);
        
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> preorder;
        serializeHelper( root, preorder);
        return preorder;
        
    }
    
    Node* deserializeHelper(vector<int> &A, int &i)
    {
        // if i has gone out of array
        if(i==A.size())
            return NULL;
            
        //null node
        if(A[i]==int(NULL))
        {
            i++; 
            return NULL;
        }
        
        Node* root= new Node(A[i]);
        i++;
        root->left= deserializeHelper(A,i);
        root->right= deserializeHelper(A,i);
        
        return root;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       int i=0;
       return deserializeHelper(A,i);
    }

};