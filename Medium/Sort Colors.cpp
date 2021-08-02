//Problem Link: https://leetcode.com/problems/sort-colors/
//Topics: Array, Two pointer, Sorting

//1st Apprach(Brute Force)
void sortColors(vector<int>& nums) {
  sort(nums.begin(),nums.end());
}
//TC:O(nlogn)
//SC: O(1)


//2nd Approach(Counting Sort)
 void sortColors(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        int k=0;
        for(auto i: m)
        {
            int freq=i.second;
            while(freq--)
            {
                nums[k++]=i.first;
            }
        }
    }
//TC: O(2n)

//3rd Approach(Dutch National Flag Algorithm)
  void sortColors(vector<int>& nums) {
      int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
           else if(nums[mid]==1)
                mid++;
           else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
//TC: O(n)

