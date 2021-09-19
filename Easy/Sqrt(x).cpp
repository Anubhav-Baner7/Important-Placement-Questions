//Problem link: https://leetcode.com/problems/sqrtx/
//Topic: Binary search

    double eps=1e-1;
    int mySqrt(int x) {
        double l=1,h=x,mid;
        while(h-l>eps)
        {
            mid=(l+h)/2;
            if(mid*mid<x)
            {
               l=mid;   
            }  
            else
            {
              h=mid;  
            }
        }
        int res=h;
        return h;
    }

//TC: O(logn)
