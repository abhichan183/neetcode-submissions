class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int top=0;
        int bot=r-1;
        int rm=matrix.size()-1;
        while(top<=bot){
            int row=(top+bot)/2;
            if(target>matrix[row][c-1]) top=row+1;
            else if(target<matrix[row][0]) bot=row-1;
            else break;
        }
        if(!(top<=bot)) return false;
        int row=(top+bot)/2;
        int left=0;
        int right=c-1;
        while(left<=right){
            int m=(left+right)/2;
            if(target>matrix[row][m]) left=m+1;
            else if(target<matrix[row][m]) right=m-1;
            else return true;
        }
        return false;
    }
};
