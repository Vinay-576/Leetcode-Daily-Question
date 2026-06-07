class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];
            
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }
            
            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            
            children.insert(childVal);
        }
        
        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            if (children.find(desc[0]) == children.end()) {
                root = nodes[desc[0]];
                break;
            }
        }
        
        return root;
    }
};
