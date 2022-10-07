/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    bool vis ;
    TreeNode()
    {
        val=0;
        left=NULL;
        right=NULL;
        vis=0;
    }
    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
        vis=0;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val=x;
        left=left;
        right=right;
        vis=0;
    }
};

class Solution
{
public:
    void dfs(TreeNode* node){
        if (node== NULL || node->vis)
            return;
        TreeNode* tmp = node->left;
        node->left=node->right;
        node->right = tmp;
        dfs(node->left);
        dfs(node->right);
        return;
    }
};

void test1(){
    Solution s;

    TreeNode* E1n7=new TreeNode(3);
    TreeNode* E1n6=new TreeNode(4);
    TreeNode* E1n5=new TreeNode(9);
    TreeNode* E1n4=new TreeNode(7);
    TreeNode* E1n3=new TreeNode(2);
    TreeNode* E1n2=new TreeNode(6);
    TreeNode* E1n1=new TreeNode(1);

    E1n1->left=E1n2;
    E1n1->right=E1n3;

    E1n2->left=E1n4;
    E1n2->right=E1n5;

    E1n3->left=E1n6;
    E1n3->right=E1n7;
    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;
    s.dfs(E1n1);

    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;

    delete E1n1,E1n2,E1n3,E1n4,E1n5,E1n6,E1n7;
}
void test2(){
    Solution s;

    TreeNode* E1n7=new TreeNode(30);
    TreeNode* E1n6=new TreeNode(45);
    TreeNode* E1n5=new TreeNode(9);
    TreeNode* E1n4=new TreeNode(77);
    TreeNode* E1n3=new TreeNode(26);
    TreeNode* E1n2=new TreeNode(62);
    TreeNode* E1n1=new TreeNode(10);

    E1n1->left=E1n2;
    E1n1->right=E1n3;

    E1n2->left=E1n4;
    E1n2->right=E1n5;

    E1n3->left=E1n6;
    E1n3->right=E1n7;
    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;
    s.dfs(E1n1);

    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;

    delete E1n1,E1n2,E1n3,E1n4,E1n5,E1n6,E1n7;
}
void test3(){
    Solution s;

    TreeNode* E1n7=new TreeNode(32);
    TreeNode* E1n6=new TreeNode(4);
    TreeNode* E1n5=new TreeNode(9);
    TreeNode* E1n4=new TreeNode(72);
    TreeNode* E1n3=new TreeNode(92);
    TreeNode* E1n2=new TreeNode(6);
    TreeNode* E1n1=new TreeNode(10);

    E1n1->left=E1n2;
    E1n1->right=E1n3;

    E1n2->left=E1n4;
    E1n2->right=E1n5;

    E1n3->left=E1n6;
    E1n3->right=E1n7;
    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;
    s.dfs(E1n1);

    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;

    delete E1n1,E1n2,E1n3,E1n4,E1n5,E1n6,E1n7;
}
void test4(){
    Solution s;


    TreeNode* E1n7=new TreeNode(32);
    TreeNode* E1n6=new TreeNode(774);
    TreeNode* E1n5=new TreeNode(-6);
    TreeNode* E1n4=new TreeNode(7277);
    TreeNode* E1n3=new TreeNode(9277);
    TreeNode* E1n2=new TreeNode(6);
    TreeNode* E1n1=new TreeNode(1077);

    E1n1->left=E1n2;
    E1n1->right=E1n3;

    E1n2->left=E1n4;
    E1n2->right=E1n5;

    E1n3->left=E1n6;
    E1n3->right=E1n7;
    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;
    s.dfs(E1n1);

    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;

    delete E1n1,E1n2,E1n3,E1n4,E1n5,E1n6,E1n7;
}
void test5(){
    Solution s;

    TreeNode* E1n7=new TreeNode(-3);
    TreeNode* E1n6=new TreeNode(4);
    TreeNode* E1n5=new TreeNode(-9);
    TreeNode* E1n4=new TreeNode(7);
    TreeNode* E1n3=new TreeNode(-2);
    TreeNode* E1n2=new TreeNode(6);
    TreeNode* E1n1=new TreeNode(-1);

    E1n1->left=E1n2;
    E1n1->right=E1n3;

    E1n2->left=E1n4;
    E1n2->right=E1n5;

    E1n3->left=E1n6;
    E1n3->right=E1n7;
    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;
    s.dfs(E1n1);

    cout<<E1n1->val<<' ' << E1n1->right->val<<' '<<E1n1->left->val<<' '<<E1n1->right->right->val<<' '<<E1n1->right->left->val<<' '<<E1n1->left->right->val<<' '<<E1n1->left->left->val<<endl;

    delete E1n1,E1n2,E1n3,E1n4,E1n5,E1n6,E1n7;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
