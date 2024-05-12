class Solution {
public:
    
    int help(int i,int sum,int k,int n,vector<int>&a,vector<int>&dp)
    {
        //base case
        if(i>=n)
            return sum;
        if(dp[i]!=-1)
            return dp[i];
        
        int choice1=a[i] + help(i+k,0,k,n,a,dp);
        // int choice2=help(i+1,sum,k,n,a,dp);
        
        // int ans=max(choice1,choice2);
          return dp[i]=choice1;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n=energy.size();
        vector<int>dp(n,-1);
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, help(i,0,k,n,energy,dp));
        }
        for(auto i:dp)cout<<i<<endl;
        // return dp[n-1];
        return res;
    }
};