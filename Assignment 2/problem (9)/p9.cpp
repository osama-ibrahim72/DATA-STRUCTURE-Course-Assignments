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
bool areMirror(TreeNode* p ,TreeNode* q)
{
        if (p==nullptr && q==nullptr)
            return 1;
        else if (p==nullptr|| q==nullptr)
            return 0;
        else
            return (areMirror(p->left , q->right) && areMirror(p->right , q->left)) ;
}
bool isFoldable (TreeNode* root)
{
    if (root == nullptr)
        return 1;
    return(areMirror(root->left,root->right)) ;
}

int main()
{
    /*
    t1:           t2:          t3:           t4:                t5:
        1      |       1     |      1      |       1          |   1
       / \     |     /   \   |    /   \    |     /   \        |    \
      2   2    |    2     2  |   2     2   |    4     8       |     8
     /     \   |    \     /  |  / \     \  |   / \   / \      |      \
    3       3  |     3   3   | 4   3     3 |  4   3 12   3    |       13
                                           | /            \   |        \
                                           |9             13  |         24
    */
    //t0 declaration
    TreeNode *t[5];
    t[0] = new TreeNode(1);
    t[0]->left = new TreeNode(2);
    t[0]->right = new TreeNode(2);
    t[0]->left->left = new TreeNode(3);
    t[0]->right->right = new TreeNode(3);

    //t1 declaration
    t[1]=new TreeNode(1) ;
    t[1]->left = new TreeNode(2);
    t[1]->right = new TreeNode(2);
    t[1]->left->right = new TreeNode(3);
    t[1]->right->left = new TreeNode(3);

    // t2 declaration
    t[2]=new TreeNode(1) ;
    t[2]->left = new TreeNode(2);
    t[2]->right = new TreeNode(2);
    t[2]->left->right = new TreeNode(3);
    t[2]->left->left = new TreeNode(4);
    t[2]->right->right = new TreeNode(3);

   // t3 declaration
    t[3]=new TreeNode(1) ;
    t[3]->left = new TreeNode(4);
    t[3]->right = new TreeNode(8);
    t[3]->left->left = new TreeNode(4);
    t[3]->left->right = new TreeNode(3);
    t[3]->left->left->left = new TreeNode(9);
    t[3]->right->right = new TreeNode(3);
    t[3]->right->left = new TreeNode(12);
    t[3]->right->right->right = new TreeNode(13);

    // t4 declaration
    t[4]=new TreeNode(1) ;
    t[4]->right =new TreeNode(8);
    t[4]->right->right =new TreeNode(13);
    t[4]->right->right->right =new TreeNode(24);

    for (int i=0 ; i<5 ; i++)
        if (isFoldable(t[i]))
            cout << 't'<< i << " is foldable " << endl;
        else
            cout << 't'<< i << " is not foldable " << endl;

    return 0;
}
