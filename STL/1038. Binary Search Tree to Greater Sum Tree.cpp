// Just want to use Prefix sum.. there are better answers.

class Solution {
public:
    
    void Calc_Nods(TreeNode* root,  vector<int> &sfx)
    {
        if(root == NULL)    return;
        
        sfx.push_back(root->val);
        
        Calc_Nods(root->left, sfx);
        Calc_Nods(root->right, sfx);
    }
    
    void Traverse(TreeNode* root, vector<int> &frq)
    {
        if(root == NULL)    return;
        
        root->val = frq[root->val];
        
        Traverse(root->left, frq);
        Traverse(root->right, frq);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> sfx;
        
        Calc_Nods(root, sfx);
        sort(sfx.begin(), sfx.end());
      
        int back = 0;
        vector<int> frq(*max_element(sfx.begin(), sfx.end()) + 1);
        
        for(int i = sfx.size() - 1 ; ~i ; i--) {
            frq[sfx[i]] = sfx[i] + back;
            back = frq[sfx[i]];
        }
       
        Traverse(root,  frq);
        return root;
    }
};


// Answer Using Recursion..


class Solution {
public:
    void Traverse(TreeNode* root, int &sum)
    {
        if(root == NULL)    return;
        
        Traverse(root->right, sum);
        
        sum += root->val;
        root->val = sum;
        
        Traverse(root->left, sum);
            
    }
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;
        Traverse(root, sum);
        
        return root;
    }
};
