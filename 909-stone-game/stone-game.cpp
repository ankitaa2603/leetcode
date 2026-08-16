class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int i = 0; 
        int j = nums.size()-1;
        int sum = 0; 
        int flag = 0 ;  
        while(i<j){
             if(flag==0){
                if(nums[i]>nums[j]){
                    sum = sum+max(nums[i],nums[j]); 
                    i++; 
                    flag = 1; 
                }
                else if(nums[i]<=nums[j]){
                    sum = sum+max(nums[i],nums[j]);
                     j--;
                    flag=1; 
                }
             }
             if(flag==1){
                if(nums[i]>nums[j]){
                    j--; 
                    flag = 0; 
                }
                else if(nums[i]<=nums[j]){
                    i++; 
                    
                    flag=0; 
                }
             }
        }
        int total = 0; 
        for(int i = 0; i<nums.size(); i++){
            total = nums[i]+total; 
        }
        if(total-sum<=sum){
            return true; 
        }
        return false; 
    }
};