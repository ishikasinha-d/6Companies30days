class Solution{
public:
    int isValid(vector<vector<int>> mat){
        /*
            We know rules of Soduku are
            1. each row contains 0-9 digits without repetition 
            2. each column contains 0-9 digits without repetition
            3. the 9x9 grid is divided into nine 3x3 sub-grids each of which also 
               contains 0-9 digits without any repetition
            
            When we pick a number from the grid, it will be part of some row, column as well as a 3x3 grid
            and to make sure the soduku is valid, it is non repeated in each 
            
            So I'll be using a set of strings where I'll store  strings containing info about row, col and grid
            if any of these strings will already exist in the set, that would mean there is repetition i.e invalid soduku
        */
        
        unordered_set<string> s;
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                int num= mat[i][j];
                
                if( num!=0 )
                {    
                    // storing information of number w.r.t row, col and 3x3 grid
                    string row= to_string(num) + "in row"+ to_string(i);
                    string col= to_string(num) + "in cloumn" + to_string(j);
                    string grid= to_string(num) + "in (x,y)=" + to_string(i/3) + " " + to_string(j/3);
                    
                    if( s.find(row)!=s.end() || s.find(col)!=s.end() || s.find(grid)!=s.end())
                            return 0;
                    
                    s.insert(row);
                    s.insert(col);
                    s.insert(grid);
                }
            }
        }
        return 1;
    }
};