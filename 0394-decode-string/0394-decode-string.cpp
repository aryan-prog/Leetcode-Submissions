class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string curr = "";
                
                while(st.top() != '['){
                    curr = st.top() + curr ;
                    st.pop();
                }
                st.pop(); //for '['
                
                string num="";
                
                while(!st.empty() && isdigit(st.top()))
                {
                    num=st.top()+num;
                    st.pop();
                }
                int k_time=stoi(num);
                
                while(k_time--)
                {
                    for(int p=0;p<curr.length();p++)
                        st.push(curr[p]);
                }
            }
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
        
    }
};