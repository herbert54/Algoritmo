#include <iostream>
using namespace std;
/*Como saber si un arbol esta dentro de otro*/
 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool esIdentico(TreeNode* root,TreeNode* subroot){
    if(root==nullptr && subroot==nullptr)
        return true;
    if(root==nullptr || subroot==nullptr)
        return false;
    return (root->val==root->val) && 
            esIdentico(root->left,root->left) && 
            esIdentico(root->right,root->right);

}
 
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr)
            return false;
        if  (subRoot==nullptr)
            return true;
        return esIdentico(root,subRoot)||isSubtree(root->left,subRoot)
                ||isSubtree(root->right,subRoot);
        
    }
};

int main(){
    TreeNode* tree=new TreeNode(3);
    tree->right=new TreeNode(5);
    tree->left=new TreeNode(4);
    tree->left->right=new TreeNode(2);
    tree->left->left=new TreeNode(1);

    TreeNode* subtree=new TreeNode(4);
    subtree->right=new TreeNode(2);
    subtree->left=new TreeNode(1);

    Solution sol;

    bool solution=sol.isSubtree(tree,subtree);
    if(solution==true) cout<<"Es un subarbol"<<endl;
    else cout<<"No es un sub arbol"<<endl;
}