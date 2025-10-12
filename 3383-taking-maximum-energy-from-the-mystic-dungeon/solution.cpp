class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        reverse(energy.begin(),energy.end());
        int maxi=-1000, n=energy.size();
        for(int i=0; i<k&&i<n; i++){
            int sum=0, z=i;
            while(i<n){
                sum+=energy[i];
                maxi=max(maxi,sum);
                i+=k;
            }
            i=z;
        }
        return maxi;
    }
};
