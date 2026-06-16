class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int maxi=0, n=h.size(),temp=0;
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=0; i<n;i++){
            while(!st.empty()&& h[st.top()]>=h[i])st.pop();
            if(!st.empty())ans[i]=i-st.top()-1;
            else ans[i]=i;
            st.push(i);
        }
        st={};
        for(int i=n-1; i>=0; i--){
            while(!st.empty()&& h[st.top()]>=h[i])st.pop();
            if(!st.empty())temp=(st.top()-i+ans[i])*h[i];
            else temp=h[i]*(n-i+ans[i]);
            maxi=max(maxi,temp);
            st.push(i);

        }
        return maxi;
    }
};
