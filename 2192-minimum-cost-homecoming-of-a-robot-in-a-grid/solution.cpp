class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int is=startPos[0], js=startPos[1], ih=homePos[0], jh=homePos[1], cost=0;
        if(is>ih){
            for(int i=ih; i<is; i++)cost+=rowCosts[i];
        }
        else{
            for(int i=is+1; i<=ih; i++)cost+=rowCosts[i];
        }
        if(js>jh){
            for(int i=jh; i<js; i++)cost+=colCosts[i];
        }
        else{
            for(int i=js+1; i<=jh; i++)cost+=colCosts[i];
        }
        return cost;
    }
};
