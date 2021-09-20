//Problem link: https://leetcode.com/problems/subsets/
//Topics: Array, Backtracking,Bit Manupulation

//Ist Approach(Bit Masking)
    vector<vector<int>> res;
    void solve(vector<int>& nums)
    {
        int n=nums.size();
        int subset_ct=(1<<n);
        for(int masks=0;masks<subset_ct;masks++)
        {
            vector<int> subset;
            for(int i=0;i<n;i++)
            {
                if((masks&(1<<i))!=0)
                    subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) { 
        solve(nums);
        return res;
    }
};

//TC: O(n*(2^n))

//IInd Approach(Using Recursion)
 vector<vector<int>> res;
    void solve(vector<int> nums,vector<int> op)
    {
        if(nums.size()==0)
        {
            res.push_back(op);
            return;
        }
        vector<int> op1;
        vector<int> op2;
        op1=op;
        op2=op;
        op1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,op1);
        solve(nums,op2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums,op);
        return res;
    }

//TC: O(2^n)
