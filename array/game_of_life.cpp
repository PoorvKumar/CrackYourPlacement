class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> newBoard(m,vector<int>(n));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cnt=0;
                for(int x=-1; x<=1; x++)
                {
                    for(int y=-1; y<=1; y++)
                    {
                        if(x==0 && y==0) continue;
                        if(i+x>=0 && i+x<m && j+y>=0 && j+y<n) cnt+=board[i+x][j+y];
                    }
                }

                if(board[i][j])
                {
                    if(cnt<2 || cnt>3) newBoard[i][j]=0;
                    else newBoard[i][j]=board[i][j];
                }
                else if(cnt==3) newBoard[i][j]=1;
            }
        }

        board=newBoard;
        return;
    }
};

// Rules -> 
/*
    1 -> 0 (<2)
    1 -> 1 (==2 || ==3)
    1 -> 0 (>3)
    0 -> 1 (==3)

    // simultaneously to every cell in current state, birth and death simultaneously
    // return next state
*/

// Approach -> 
/*
    we can try to find all the neighbours of current cell and change it based on rule in the new grid so that it 
    doesnot affect current state neighbours -> O(2n^2) for original + new
*/