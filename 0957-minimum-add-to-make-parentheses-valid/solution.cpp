class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans=0;
        for(auto c:s){
            if(c=='(')st.push('(');
            else if(!st.empty() && st.top()=='(')st.pop();
                 else ans++;
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};
