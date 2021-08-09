//Problem Link: https://leetcode.com/problems/powx-n/submissions/
//Topics: Math, Recursion

//1st Appraoch(Using STL function)
 double myPow(double x, int n) {
        double res=pow(x,n);
        return res;
    }

//2nd Appraoch
   double myPow(double x, int n) {
        double res=1.0;
        long long nn=n;//here we take nn to prevent out of bound error.
        if(nn<0)
            nn=-1*nn;
        while(nn>0)
        {
            if(nn%2==0)
            {
                x=x*x;
                nn=nn/2;
            }
            else
            {
                res=res*x;
                nn=nn-1;
            }
        }
        if(n<0)
            return (double)(1)/(double)res;
        return res;
    }

//TC: O(logn)
