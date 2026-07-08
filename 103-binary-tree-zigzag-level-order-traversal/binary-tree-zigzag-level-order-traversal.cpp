class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>result;
    bool leftToright = true;
    if(root==NULL){
        return result;
    }
    queue<TreeNode*>NodesQueue;
    NodesQueue.push(root);

    while(!NodesQueue.empty()){
        int size=NodesQueue.size();
        vector<int>row(size);
        
        for(int i=0; i<size;i++){
            TreeNode* node= NodesQueue.front();
            NodesQueue.pop();

            int index = (leftToright)? i:(size-1-i);

            row[index] = node->val;
            if(node->left){
                NodesQueue.push(node->left);
            }
            if(node->right){
                NodesQueue.push(node->right);
            }
        }
        leftToright =! leftToright;
        result.push_back(row);
    }
    return result;
    }
};