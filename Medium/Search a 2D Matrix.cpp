//Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
//Topics: Array, Binary Search, Matrix

//Ist Appraoch(Brute Force(Linear Search))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  for(int i=0;i<matrix.size();i++)
  {
    for(int j=0;j<matrix[0].size();j++)
    {
      if(matrix[i][j]==target)
        return true;
    }
  }
  return false;
}

//TC : O(n^2)

//2nd Appraoch(Binary Search)
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0)
        {
            if(target<matrix[i][j])
                j--;
            else if(target>matrix[i][j])
                i++;
            else
                return true;
        }
        return false;
    }

//TC : O(nlogm)

//3rd Approach(Better Binary Search)
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int h=m*n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int t=matrix[mid/n][mid%n];
            if(t==target)
                return true;
            else if(t<target)
                l=mid+1;
            else
                h=mid-1;
        }
        return false;
    }

//TC: O(log(n*m))
//SC: O(1)
