class Solution
{
    public:
        int numIslands(vector<vector < char>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();

            vector<vector < int>> visited(grid.size(), vector<int> (grid[0].size(), 0));

           	//memset(visited,0,sizeof(visited));
            int count = 0;

            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == '1' && visited[i][j] == 0)
                    {
                        drawTreeforComponent(grid, i, j, visited);
                        count++;
                    }
                }
            }
            return count;
        }

    void drawTreeforComponent(vector<vector < char>> &arr, int i, int j, vector< vector< int>> &visited)
    {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
            return;

        if (visited[i][j] == 1)
            return;
        else
            visited[i][j] = 1;

        if (arr[i][j] == '0')
            return;

        drawTreeforComponent(arr, i + 1, j, visited);
        drawTreeforComponent(arr, i - 1, j, visited);
        drawTreeforComponent(arr, i, j + 1, visited);
        drawTreeforComponent(arr, i, j - 1, visited);
    }
};