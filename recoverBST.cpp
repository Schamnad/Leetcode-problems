// 99. Recover Binary Search Tree
//
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, TreeNode* &first,TreeNode* &second,TreeNode* &prev ){
        if(root == NULL)
            return;

        traverse(root->left,first,second,prev);

        if(first == NULL && prev->val >= root->val){
            first = prev;
        }
        if(first != NULL && prev->val >= root->val){
            second = root;
        }
        prev = root;

        traverse(root->right,first,second,prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode * first = NULL;
        TreeNode * second = NULL;
        TreeNode * prev = new TreeNode(INT_MIN);

        traverse(root,first,second,prev);

        //if(first && second){
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        //}
    }
};
