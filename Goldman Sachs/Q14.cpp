// Minimum Size Subarray Sum
// link: https://leetcode.com/problems/minimum-size-subarray-sum/

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i=0,j=0,ans=INT_MAX;
    long long sum=0;
    while(i<n&&j<n){
        sum+=nums[j];
        if(sum>=target){
            ans = min(ans,j-i+1);
            while(i<=j&&sum>=target)
                sum-=nums[i++];
            ans = min(ans,j-i+2);
        }
        j++;
    }
    if(ans==INT_MAX) return 0;
    return ans;
}