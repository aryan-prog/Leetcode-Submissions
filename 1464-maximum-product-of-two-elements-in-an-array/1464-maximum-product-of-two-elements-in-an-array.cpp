class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=0,max2=0;
        int ind=-1;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(max1<nums[i])
            {
                max1=nums[i];
                ind=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(i!=ind)
                max2=max(max2,nums[i]);
        }
        
        int ans=(max1-1)*(max2-1);
        
        return ans;

    }
};