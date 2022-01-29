class Solution {
public:
    bool winnerOfGame(string colors) {
        
        colors+="$";
        int count=0, moves_A=0, moves_B=0;
        
        // moves by alice
        for(int i=0; i<colors.length(); i++)
        {
            if(colors[i]=='A')
                count++;
            else
            {
                if(count>2)
                    moves_A+= count-2;
                count=0;
            }
        }
        
        // moves by bob
        count=0;
        for(int i=0; i<colors.length(); i++)
        {
            if(colors[i]=='B')
                count++;
            else
            {
                if(count>2)
                    moves_B+= count-2;
                count=0;
            }
        }
          
        return moves_A>moves_B;
    }
};