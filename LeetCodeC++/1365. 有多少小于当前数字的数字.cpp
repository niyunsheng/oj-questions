class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int A[105]={0},B[105]={0};
        for(int i=0;i<nums.size();i++)
            A[nums[i]]++;
        for(int i=1;i<105;i++)B[i] = B[i-1]+A[i-1];
        for(int i=0;i<nums.size();i++)
            nums[i] = B[nums[i]];
        return nums;
    }
};