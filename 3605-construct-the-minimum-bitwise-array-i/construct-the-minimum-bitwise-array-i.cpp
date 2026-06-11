class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
     vector<int>ans;
     for(int num:nums){
        if(num%2==0){
            ans.push_back(-1);
            continue;
        }
        int x=num;
        int bit=1;
        while(num&bit){
            bit<<=1;
        }
         bit >>= 1;
            x = x ^ bit;
            ans.push_back(x);
    }
    return ans;
    }

};