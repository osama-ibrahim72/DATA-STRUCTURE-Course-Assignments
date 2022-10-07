/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>
#include <vector>

using namespace std;

class BSTNode
{
public:
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode ()
    {
        left=nullptr;
        right=nullptr;
    }
    BSTNode (int el)
    {
        key=el;
        left=nullptr;
        right=nullptr;
    }
    BSTNode (int el, BSTNode* l, BSTNode* r)
    {
        key = el;
        left = l;
        right = r;
    }
    void distroy(BSTNode* n)
    {
        if(n->left!=nullptr)
            distroy(n->left);
        if(n->right!=nullptr)
            distroy(n->right);
        delete n;
    }
};

class BST
{
private:
    BSTNode* root = new BSTNode();
    int c=1;
    vector<int> t;
public:
    BST (int x) {root->key=x;}
    void clear() {root = nullptr;}
    bool isEmpty() {return root == 0;}
    BSTNode* getroot() {return root;}
    void PushNodeInorder(BSTNode* n)
    {
        if (n == nullptr)
        {
            return;
        }
        PushNodeInorder(n->left);
        t.push_back(n->key);
        PushNodeInorder(n->right);
    }
    BSTNode* addNode(BSTNode* n, int v)
    {
        if (n == nullptr)
        {
            return new BSTNode(v);
        }
        if (v < n->key)
        {
            n->left = addNode(n->left, v);
        }
        else
        {
            n->right = addNode(n->right, v);
        }
        t.clear();
        return n;
    }
    int search (int el)
    {
        BSTNode* p = root;
        while (p != 0)
        {
            if (el == p->key)
                return p->key;
            else if (el < p->key)
                p = p->left;
            else
                p = p->right;
            return 0;
        }
    }
    void Solution(BSTNode* n,int k)
    {
        PushNodeInorder(n);
        cout<<k<<"th smallest number in tree is equal "<<t[k-1]<<endl;
        int sum =0;
        for(int i=0;i<k;i++)
        {
            sum+=t[i];
        }
        cout<<"Sum of first "<<k<<" smallest number in tree is equal "<<sum<<endl;
    }
    ~BST()
    {
        root->distroy(root);
        delete root;
    }
};
void test1(){
    BST* t=new BST(54);


    t->addNode(t->getroot(),51);

    t->addNode(t->getroot(),49);

    t->addNode(t->getroot(),52);

    t->addNode(t->getroot(),75);

    t->addNode(t->getroot(),74);

    t->addNode(t->getroot(),85);


    t->Solution(t->getroot(),3);
}
void test2(){
    BST* t=new BST(98);


    t->addNode(t->getroot(),122);

    t->addNode(t->getroot(),65);

    t->addNode(t->getroot(),32);

    t->addNode(t->getroot(),96);

    t->addNode(t->getroot(),22);

    t->addNode(t->getroot(),90);


    t->Solution(t->getroot(),3);
}
void test3(){
    BST* t=new BST(54);


    t->addNode(t->getroot(),51);

    t->addNode(t->getroot(),49);

    t->addNode(t->getroot(),52);

    t->addNode(t->getroot(),75);

    t->addNode(t->getroot(),74);

    t->addNode(t->getroot(),85);


    t->Solution(t->getroot(),4);
}
void test4(){
    BST* t=new BST(54);


    t->addNode(t->getroot(),51);

    t->addNode(t->getroot(),49);

    t->addNode(t->getroot(),52);

    t->addNode(t->getroot(),75);

    t->addNode(t->getroot(),74);

    t->addNode(t->getroot(),85);


    t->Solution(t->getroot(),2);
}
void test5(){
    BST* t=new BST(98);


    t->addNode(t->getroot(),122);

    t->addNode(t->getroot(),65);

    t->addNode(t->getroot(),32);

    t->addNode(t->getroot(),96);

    t->addNode(t->getroot(),22);

    t->addNode(t->getroot(),90);


    t->Solution(t->getroot(),4);
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
