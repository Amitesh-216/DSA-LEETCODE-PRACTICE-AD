class Solution {
public:
int f(int ind, int T,vector<int>&coins,vector<vector<int>>&dp){
    if(ind == 0){
        if(T%coins[0] == 0) return T/coins[0];
        return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
     int nottake =  0+f(ind-1,T,coins,dp);
     int take = INT_MAX;
    if(coins[ind]<=T){
         take = 1+f(ind,T-coins[ind],coins,dp);
    }
    return dp[ind][T] = min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int T = 0;T<=amount;T++){
            if(T%coins[0] == 0){
                prev[T] = T/coins[0];
            }
            else{
               prev[T] = 1e9;
            }
        } //basecase

        for(int ind = 1;ind<n;ind++){
            for(int T = 0;T<=amount;T++){
                int nottake =  0+prev[T];
                int take = INT_MAX;
                if(coins[ind]<=T){
                take = 1+curr[T-coins[ind]];
              }
              curr[T] = min(take,nottake);

            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans>=1e9) return -1;
        return ans;

        
    }
};

