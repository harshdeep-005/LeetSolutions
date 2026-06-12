class Solution {
public:
    int sum(vector<int>& s){int total=0;
    for(int p : s){
    total+=p;}
    return total;
    }
    bool foo(vector<int>& s, int days, int res){
        int val=1, total=0;
        for(int p : s){
            if(total+p<=res){
            total+=p;
            }
            else{
                val++;
                total=p;
                if(val>days)return false;
            }
        }
            return true;
    }
    int shipWithinDays(vector<int>& s, int days) {
        int l=*max_element(s.begin(),s.end()), r=sum(s);
        while(l<=r){
            int mid=l+(r-l)/2;
            if(foo(s,days,mid))r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
