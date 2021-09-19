//Problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/
//Topics: Array, Binary search

//Ist Approach(using XOR)
int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x^=nums[i];
        }
        return x;
    }
//TC: O(n)

// IInd Approach(binary search)
  int singleNonDuplicate(vector<int>& nums) {
       int l=0,h=nums.size()-2,mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(nums[mid]==nums[mid^1])
                l=mid+1;
            else
                h=mid-1;
        }
        return nums[l];
    }
//TC:O(logn)
