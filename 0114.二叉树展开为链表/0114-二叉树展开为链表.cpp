/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        loop(root);
    }

    void loop(TreeNode* node)
    {
        if(!node)return;
        if(node->left == nullptr && node->right == nullptr) return;
        if(node->left) loop(node->left);
        if(node->right) loop(node->right);


        if(node->left)  
        {
            TreeNode* tmp = node->right;
            node->right = node->left;
            TreeNode* end = FindEnd(node->right);
            end->right = tmp;
            node->left = nullptr;
        }
    }

    TreeNode* FindEnd(TreeNode* node)
    {
        if(node->right == nullptr) return node;
        else return FindEnd(node->right);
    }  
};