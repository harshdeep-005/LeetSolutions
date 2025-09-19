class Spreadsheet {
    vector<vector<int>>arr;
public:
    Spreadsheet(int rows) {
        arr=vector<vector<int>>(rows, vector<int>(26,0));
    }
    vector<string> split(string s, char op){
        vector<string>res;
        string temp="";
        for(char c:s){
            if(c==op){
                res.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        res.push_back(temp);
        return res;
    }
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1));
        arr[row-1][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1));
        arr[row-1][col]=0;
    }
    
    int getValue(string formula) {
        string temp=formula.substr(1);
        auto parts=split(temp, '+');
        int sum=0;
        for(auto part:parts){
            if(isalpha(part[0])){
                int col=part[0]-'A';
                int row=stoi(part.substr(1));
                sum+=arr[row-1][col];
            }else{
                sum+=stoi(part);
            }
        }
        return sum;
    }
};
