//Problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//Topics: Arrays, Hash

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> m;
    int sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==0)
        res=i+1;
        if(m.find(sum)==m.end())
        m[sum]=i;
        if(m.find(sum)!=m.end())
        res=max(res,i-m[sum]);
    }
    return res;
}

//TC: O(nlogn)
//SC: O(n)
