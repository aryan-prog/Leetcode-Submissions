class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        
        queue<pair<int,int>> q;
        //q.push({entrance[0],entrance[1]});
        int steps=0;
        int x=entrance[0],y=entrance[1];
        maze[x][y]='+';
        if(possible(x+1,y,maze))
            q.push({x+1,y});
        if(possible(x,y+1,maze))
            q.push({x,y+1});
        if(possible(x-1,y,maze))
            q.push({x-1,y});
        if(possible(x,y-1,maze))
            q.push({x,y-1});
        while(!q.empty())
        {
            int l=q.size();
			//for every node in the queue visit all of it's adjacent nodes which are not visited yet
            for(int k=0;k<l;k++)
            {
            x=q.front().first;
            y=q.front().second;
            q.pop();
          //  cout<<x<<y<<endl;
            if(x==0 || y==0 || y==n-1 || x==m-1)
                return steps+1;
            
            
            if(possible(x+1,y,maze))
            {
                 // if(x+1==0 || y==0 || y==n-1 || x+1==m-1)
                 //    return steps+2;
                maze[x+1][y]='+';
                q.push({x+1,y});
                
                
            }
                
            if(possible(x,y+1,maze))
            {
                
                // if(x==0 || y+1==0 || y+1==n-1 || x==m-1)
                //     return steps+2;
                maze[x][y+1]='+';
                q.push({x,y+1});
            }
                
            if(possible(x-1,y,maze))
            {
                
                 // if(x-1==0 || y==0 || y==n-1 || x-1==m-1)
                 //    return steps+2;
                maze[x-1][y]='+';
                q.push({x-1,y});
                
            }
                
            if(possible(x,y-1,maze))
            {
                
                 // if(x==0 || y-1==0 || y-1==n-1 || x==m-1)
                 //    return steps+2;
                maze[x][y-1]='+';
                q.push({x,y-1});
                
                
            }
                
            
           // maze[x][y]='+';
           
            }
             steps++;
            
            
        }
        return -1;
    }
    bool possible(int x,int y,vector<vector<char>>& maze)
    {
        if( x<0 || y<0 || x>=maze.size() || y>= maze[0].size()|| maze[x][y]=='+')
            return false;
        
        return true;
    }
};