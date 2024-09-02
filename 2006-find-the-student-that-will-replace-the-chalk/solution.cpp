class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0, n=chalk.size() ;
        long long s=0;
        while(i<n){
            s+=chalk[i];
            i++;
        }
        k=k%s;
        i=0;
        while(k>=0){
            if(k<chalk[i]){
                return i;
            }
            k=k-chalk[i];
            i++;
        }
        return -1;
    }    
};
