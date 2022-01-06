// 845. Longest Mountain in Array
// link: https://leetcode.com/problems/longest-mountain-in-array/

int longestMountain(vector<int>& arr) {
    int lv=-1,n=arr.size(),ans=0;
        
    if(n<3) return 0;
        
    if(arr[0]<arr[1]) lv = 0;
       
    for(int i=1;i<n-1;i++){
        if(arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
            if(lv!=-1) ans = max(ans,i-lv+1);
            lv = i;
        }
          
        if(arr[i-1]!=arr[i]&&arr[i]==arr[i+1]){
            if(arr[i]>arr[i-1]) lv = -1;
            else if(arr[i]<arr[i-1]){
                if(lv!=-1) ans = max(ans,i-lv+1);
                lv = -1;
            }
        }
            
        if(arr[i-1]==arr[i]&&arr[i]!=arr[i+1]){
            if(arr[i]<arr[i+1]) lv = i;
            else if(arr[i]>arr[i+1]){
                lv = -1;
            }
        }
    }
       
    if(arr[n-2]>arr[n-1]&&lv!=-1) ans = max(ans,n-lv);
      
    return ans;
}