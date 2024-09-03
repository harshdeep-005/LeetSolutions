class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(arr[i][j] != '.'){
                    for(int x=0; x<9; x++){
                        if(j!=x){
                            if(arr[i][j] == arr[i][x]){
                                return false;
                            }
                        }
                        if(i!=x){
                            if(arr[i][j] == arr[x][j]){
                                return false;
                            }
                        }
                    }
                    
                    for(int m=3*(i/3); m<3*(i/3)+3; m++){
                        for(int n=3*(j/3); n<3*(j/3)+3; n++){
                            if(i!=m && j!=n){
                                if(arr[i][j] == arr[m][n]){
                                    return false;
                                }    
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
