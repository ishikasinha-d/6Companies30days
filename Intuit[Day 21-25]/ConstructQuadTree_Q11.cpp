/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    bool isLeaf(int x, int y, int n, vector<vector<int>>& grid)
    {
        int val= grid[x][y];
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[x+i][y+j]!=val)
                    return false;
            }
        }

        return true;
    }
    
    Node* _constructQuadTree(int x, int y, int n, vector<vector<int>>& grid)
    {
        if(n==1)
            return new Node(grid[x][y], true);
        
        if(isLeaf(x,y,n,grid)==true)
            return new Node(grid[x][y], true);
        
        int leafSize= n/2;
        
        Node* topLeft = _constructQuadTree(x, y, leafSize, grid);
        Node* topRight = _constructQuadTree(x, y+leafSize, leafSize, grid);
        Node* bottomLeft = _constructQuadTree(x+leafSize, y, leafSize, grid);
        Node* bottomRight = _constructQuadTree(x+leafSize, y+leafSize, leafSize, grid);
        
        return new Node(grid[x][y], false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) 
    {
        return _constructQuadTree(0,0,grid.size(),grid);
    }
};