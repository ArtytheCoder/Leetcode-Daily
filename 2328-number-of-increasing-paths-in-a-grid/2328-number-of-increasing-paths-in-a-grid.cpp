class Solution {
public:
int mod=1e9+7;
int isValid(int r,int c,vector<vector<int>>& grid){
    if(r<0||c<0||r>=grid.size()||c>=grid[0].size()) return 0;
    return 1;
    
}
int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &dp){
    
    if(dp[r][c]!=-1) return dp[r][c];

    int ans=1;
    if(isValid(r+1,c,grid)&&grid[r+1][c]>grid[r][c])
    ans+=dfs(r+1,c,grid,dp);
    ans=ans%mod;
     if(isValid(r,c+1,grid)&&grid[r][c+1]>grid[r][c])
    ans+=dfs(r,c+1,grid,dp);
    ans=ans%mod;
     if(isValid(r-1,c,grid)&&grid[r-1][c]>grid[r][c])
    ans+=dfs(r-1,c,grid,dp);
    ans=ans%mod;
     if(isValid(r,c-1,grid)&&grid[r][c-1]>grid[r][c])
    ans+=dfs(r,c-1,grid,dp);
    ans=ans%mod;

    return dp[r][c]=ans%mod;

}
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(dp[i][j]==-1){
                    ans+=dfs(i,j,grid,dp);
                    ans=ans%mod;
                }
                else
                ans+=dp[i][j];

                ans=ans%mod;
            }
        }

        return ans%mod;
    }
};