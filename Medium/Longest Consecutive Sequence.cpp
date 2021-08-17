//Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
//Topics: Array, HashTable, Union Find

//1st Approach
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int len=1;
        int mx=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1==nums[i])
            {
                len++;
                mx=max(len,mx);
            }
            else if(nums[i-1]==nums[i])
                continue;
            else
                len=1;
        }
        return mx;
    }

//TC: O(nlogn)
//SC: O(1)

//2nd Approach
 int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int mx=1;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int len=1;
                int curr=nums[i];
                while(s.find(curr+1)!=s.end())
                {
                    curr=curr+1;
                    len++;
                }
                mx=max(mx,len);
            }
        }
        return mx;
    }

//TC: O(3n)
//SC: O(n)
