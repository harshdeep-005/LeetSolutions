class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0; i<operations.size(); i++){
            string c=operations[i];
            if(c[1]=='+')x++;
            else x--;
        }
        return x;
    }
};
