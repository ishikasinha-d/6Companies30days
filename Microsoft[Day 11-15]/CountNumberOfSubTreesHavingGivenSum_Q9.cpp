//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
int utiltityForCount( Node* root, int x, int &count)
{
    if( root == NULL )
	    return 0;
	    
	//left subtree
	int ls= utiltityForCount( root->left, x, count);
	
	//right subtree
	int rs= utiltityForCount( root->right, x, count);
	
	//if subtree sum is x
	int sum= ls+rs+root->data;
	
	if(sum==x) count++;
	
	return sum;
}
//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int x)
{
	if( root == NULL )
	    return 0;
	    
	int count= 0;
	int bt= utiltityForCount( root, x, count);

	 return count;
}