//  Array Pair Sum Divisibility Problem
// link: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

bool canPair(vector<int> nums, int k) {
    // Code here.
    vector<int> cnt(k+1,0);
    int n = nums.size();
    long long sum=0;
    for(int i:nums){
        cnt[i%k]++;
        sum+=i;
    }
    if(sum%k||n&1) return false;
    if(cnt[0]&1) return false;
    for(int i=1;i<k;i++)
        if(cnt[i]!=cnt[k-i]) return false;
    
    return true;
}