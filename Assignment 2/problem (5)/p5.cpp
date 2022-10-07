/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *L, TreeNode *R) : val(x), left(L),right(R) {}
};
class Solution {
public:
    static bool isSameTree(TreeNode* p, TreeNode* q) {
    if ((p == nullptr && q == nullptr) || p==q) // if they are empty trees or if the are the same tree
        return 1;
    else if (p != nullptr && q != nullptr) // if they both are non-empty trees
    {
        return
        (
            p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)
        );
    }
    else
        return 0;  // if one is empty, one is not
    }
};
int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);
    q->left->right = new TreeNode(5);
    if (Solution::isSameTree(p,q))
        cout << "p&q are the same tree" << endl;
    else
        cout << "p&q are the not same tree" << endl;

    return 0;
}
