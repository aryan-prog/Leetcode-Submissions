class Solution {
public:
    string largestGoodInteger(string num) {
        int n =num.length();
        string s="";
        int k=0,max=INT_MIN;
        for(int i=0;i<n-2;i++)
        {
            k=0;
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                k=stoi(num.substr(i,3));
                cout<<num.substr(i,3)<<endl;
                if(max<k)
                {
                    max=k;
                    s=num.substr(i,3);
                }
            }
        }
        return s;
    }
};