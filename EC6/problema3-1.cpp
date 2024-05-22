//Definition for a binary tree node.
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        return buildBST(preorder, 0, preorder.size() - 1);
    }
    
private:
    TreeNode* buildBST(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[start]);
        int i;
        for (i = start; i <= end; ++i) {
            if (preorder[i] > root->val) {
                break;
            }
        }
        
        root->left = buildBST(preorder, start + 1, i - 1);
        root->right = buildBST(preorder, i, end);
        
        return root;
    }
};

void printPreorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    vector<int> preorder = {8,5,1,7,10,12};
    Solution solution;
    TreeNode* result = solution.bstFromPreorder(preorder);
    printPreorder(result);
    return 0;
}
