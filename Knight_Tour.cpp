class Solution {
public:
bool valid(int size,int row,int col){
    if(row>=0 && row<size && col>=0 && col<size){
        return true;
    }
    return false;
}
vector<int> validpos(vector<vector<int>>grid,int row,int col,int val){
    vector<int>res;
    if(valid(grid.size(),row-2,col+1) && grid[row-2][col+1]==val){
        res.push_back(row-2);
        res.push_back(col+1);
    }
    else if(valid(grid.size(),row-2,col-1) && grid[row-2][col-1]==val){
        res.push_back(row-2);
        res.push_back(col-1);
    }
    else if(valid(grid.size(),row-1,col-2) && grid[row-1][col-2]==val){
        res.push_back(row-1);
        res.push_back(col-2);
    }
    else if(valid(grid.size(),row-1,col+2) && grid[row-1][col+2]==val){
        res.push_back(row-1);
        res.push_back(col+2);
    }
    else if(valid(grid.size(),row+1,col+2) && grid[row+1][col+2]==val){
        res.push_back(row+1);
        res.push_back(col+2);
    }
    else if(valid(grid.size(),row+1,col-2) && grid[row+1][col-2]==val){
        res.push_back(row+1);
        res.push_back(col-2);
    }
    else if(valid(grid.size(),row+2,col+1) && grid[row+2][col+1]==val){
        res.push_back(row+2);
        res.push_back(col+1);
    }
    else if(valid(grid.size(),row+2,col-1) && grid[row+2][col-1]==val){
        res.push_back(row+2);
        res.push_back(col-1);
    }
    return res;
}
void helper(vector<vector<int>>grid,vector<vector<int>>h,int row,int col,int curr){
    if(grid[row][col]==grid.size()*grid.size()-1|| row<0 || col<0 || row>=grid.size() || col>=grid.size() || curr==grid.size()*grid.size()){
        return;
    }
    if(h[row][col]==1){
        result=false;
        return;
    }
    h[row][col]=1;
    vector<int>r=validpos(grid,row,col,curr+1);
    if(r.size()==0){
        result=false;
        return;
    }
    if(r.size()>0){
        helper(grid,h,r[0],r[1],curr+1);
    }
}
bool result=true;
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        vector<vector<int>>arr(grid.size(),vector<int>(grid.size()));
        helper(grid,arr,0,0,0);
        return result;
    }
};
