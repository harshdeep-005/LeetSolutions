class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        stack<char> st;
        for(auto s: word)st.push(s);
        m=board.size(),n=board[0].size();
        vector<vector<bool>> arr(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==st.top()){
                    char temp=st.top();
                    st.pop();
                    arr[i][j]=true;
                    if(foo(board,st, i, j, arr)) return true;
                    st.push(temp);
                    arr[i][j]=false;
                }
            }
        }
        return false;
    }
    bool foo(vector<vector<char>>& board, stack<char> &st, int i,int j, vector<vector<bool>> &arr){
        if(st.size()==0)return true;
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k],nc=j+dc[k];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&(!arr[nr][nc])&&board[nr][nc]==st.top()){
                char temp=st.top();
                st.pop();
                arr[nr][nc]=true;
                if(foo(board,st, nr, nc, arr)) return true;
                st.push(temp);
                arr[nr][nc]=false;
            }  
        }
        return false;
    }
};
