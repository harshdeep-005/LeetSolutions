class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi=0;
        for(auto c:s){
            if(c=='(')st.push(1);
            if(c==')') st.pop();
            // cout<<st.size();
            maxi=max(maxi,(int)st.size());
        }
        return maxi;
    }
};
