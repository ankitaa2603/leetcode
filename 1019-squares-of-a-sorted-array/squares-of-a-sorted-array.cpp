class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s = nums.size();

        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < s; i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        int n = neg.size();
        int p = pos.size();

        if(n == 0){
            for(int i = 0; i < p; i++){
                pos[i] *= pos[i];
            }
            return pos;
        }

        if(p == 0){
            for(int i = 0; i < n; i++){
                neg[i] *= neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        for(int i = 0; i < n; i++){
            neg[i] *= neg[i];
        }
        reverse(neg.begin(), neg.end());

        for(int i = 0; i < p; i++){
            pos[i] *= pos[i];
        }

        int i = 0, j = 0, id = 0;
        vector<int> res(n + p);

        while(i < p && j < n){
            if(neg[j] <= pos[i]){
                res[id] = neg[j];
                id++;
                j++;
            }
            else{
                res[id] = pos[i];
                id++;
                i++;
            }
        }

        while(i < p){
            res[id] = pos[i];
            id++;
            i++;
        }

        while(j < n){
            res[id] = neg[j];
            id++;
            j++;
        }

        return res;
    }
};