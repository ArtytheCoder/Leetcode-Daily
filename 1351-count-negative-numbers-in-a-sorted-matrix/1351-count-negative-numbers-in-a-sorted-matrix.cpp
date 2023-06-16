class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int count =0, row= grid.size()-1 , col=0;
       int t_col= grid[0].size();
       while( row >=0 and col< t_col){
           if(grid[row][col] < 0){
               count = count+ t_col -col;
               row--;
           }
           else {
               col++;
           }
       }
       return count;
    } 
};