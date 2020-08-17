/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

bool high(struct TreeNode* root, int h, int *min, int *max)
{
    h++;

    if (!root->left || !root->right)
    {
        if (*min == 0)
            *min = h;
        *min = min(h, *min);
        *max = max(h, *max);
        if (*max - *min > 1)
            return false;
    }

    if (root->left)
    {
        if (!high(root->left, h, min, max))
            return false;
    }
    
    if (root->right)
    {
        if (!high(root->right, h, min, max))
            return false;
    }

    return true;
}

bool isBalanced(struct TreeNode* root){
    bool ret = true;
    int min = 0;
    int max = 0;
    int h = 0;

    if (root)
        ret = high(root, h, &min, &max);

    return ret;
}