//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& m) {
    if(ps > pe || is > ie) return NULL;
    TreeNode* root = new TreeNode(preorder[ps]);
    int inRoot = m[root->val];
    int numLeft = inRoot - is;
    root->left = buildTree(preorder, ps + 1, ps + numLeft, inorder, is, inRoot - 1, m);
    root->right = buildTree(preorder, ps + numLeft + 1, pe, inorder, inRoot + 1, ie, m);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> m;
    for(int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
}
};
/*
inorder=[40,20,50,10,60,30] left,root,right
preorder=[10,20,40,50,30,60] root,left,right

                          10->root
     inorder     40,20,50           60,30
     preorder    20,40,50           30,60
                20->r                 30->r
              40     50             60   null

in=[9,3,15,20,7]
    0 1  2  3 4
    is         ie
       inRoot->3
pr=[3,9,20,15,7]
    ps        pe

9-0
3-1
15-2
20-3
7-4

*/
