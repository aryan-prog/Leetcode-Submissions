class Solution {
public:
    int getBoardValue(vector<vector<int>>& board, int num) {
        int n = board.size();
        int r = (num - 1) / n;
        int x = n - 1 - r;
        int y = r % 2 == 0 ? num - 1 - r * n : n + r * n - num;
        return board[x][y];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        //int num=1;
        int moves=0;
        vector<bool> vis(n*n+1,false);
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                int num=q.front();
                q.pop();
                if(num==n*n)
                    return moves;
                if(vis[num])
                    continue;
                vis[num]=true;
                for (int i = 1; i <= 6 && num + i <= n * n; i++)
                {
                    int next = num + i;
                    int value = getBoardValue(board, next);
                    if (value > 0) 
                        next = value;
                    if (!vis[next]) 
                        q.push(next);
                }
            }
            moves++;
        }
        return -1;
    }
};