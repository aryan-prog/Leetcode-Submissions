class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        
        if(x==0 && y==0 && t==1)
            return false;
        
        if(t>=max(x,y))
            return true;
        
        return false;
    }
};