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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
class Solution {
public:
    static bool isSymmetric(TreeNode* root)
    {
        return areMirror(root->left , root->right) ;
    }
    static bool areMirror (TreeNode* p ,TreeNode* q)
    {
        if (p==nullptr && q==nullptr)
            return 1;
        else if (p==nullptr|| q==nullptr)
            return 0;
        else
            return ( p->val==q->val && areMirror(p->left , q->right) && areMirror(p->right , q->left)) ;
    }
};

int main()
{
     /*
    root0:        root1:        root2:        root3:            |
         1       |       1     |      1      |       1          |
       /   \     |     /   \   |    /   \    |     /   \        |
      2     2    |    2     2  |   2     2   |    4     8       |
     / \   / \   |    \     /  |    \     \  |   / \   / \      |
    3   4 4   3  |     3   3   |     3     3 |  4   3 12   3    |
                                             | /            \   |
                                             |9             13  |
    */
    TreeNode *root[4] ;
    root[0] = new TreeNode(1);
    root[0]->left = new TreeNode(2);
    root[0]->right = new TreeNode(2);
    root[0]->left->left = new TreeNode(3);
    root[0]->left->right = new TreeNode(4);
    root[0]->right->left = new TreeNode(4);
    root[0]->right->right = new TreeNode(3);

    //t2 declaration
    root[1]=new TreeNode(1) ;
    root[1]->left = new TreeNode(2);
    root[1]->right = new TreeNode(2);
    root[1]->left->right = new TreeNode(3);
    root[1]->right->left = new TreeNode(3);

    // t4 declaration
    root[2] = new TreeNode(1);
    root[2]->left = new TreeNode(2);
    root[2]->right = new TreeNode(2);
    root[2]->left->right = new TreeNode(3);
    root[2]->right->right = new TreeNode(3);

    // t4 declaration
    root[3]=new TreeNode(1) ;
    root[3]->left = new TreeNode(4);
    root[3]->right = new TreeNode(8);
    root[3]->left->left = new TreeNode(4);
    root[3]->left->right = new TreeNode(3);
    root[3]->left->left->left = new TreeNode(9);
    root[3]->right->left = new TreeNode(12);
    root[3]->right->right = new TreeNode(3);
    root[3]->right->right->right = new TreeNode(13);

    for (int i=0 ; i<4 ; i++)
        if(Solution::isSymmetric(root[i]))
            cout << "root #" << i << " is symmetric" << endl;
        else
            cout << "root #" << i << " is not symmetric" << endl;


    return 0;
}
