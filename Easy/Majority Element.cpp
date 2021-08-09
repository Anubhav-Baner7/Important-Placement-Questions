//Problem Link : https://leetcode.com/problems/majority-element/submissions/
//Topics: Array, HashTable, Divide and Conquer, Sorting

//1st Approach(Using HashMap)
int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int maj;
        for(auto i: m)
        {
            if(i.second>nums.size()/2)
            {
              maj=i.first;
                break;
            }
        }
        return maj; 
    }

//TC: O(2n)
//SC: O(n)

//2nd Appraoch(Moore Voting Algorithm)
   int majorityElement(vector<int>& nums) {
        int cnt=0;
        int maj=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
                maj=nums[i];
            if(maj==nums[i])
                cnt++;
            else
                cnt--;
        }
        return maj;
    }

//TC: O(n)
//SC: O(1)
