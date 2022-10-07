/*
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include<bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
using namespace std;

#define SMSM cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define endl '\n' ;
#define fo(n) for(int i=0 ; i<n ; i++)
#define w(n) while(n--)
#define sortall(v) sort(v.begin(),v.end())
#define test    int t;cin>>t; w(t)
typedef long long ll;
typedef unsigned long long ull ;
typedef double d;
typedef float f;
typedef string s;

const ll   llmin  = -1e18 ;
const ll   llmax  =  1e18 ;
const int  imin   = -1e9  ;
const int  imax   =  1e9  ;



template<class t>
class BSTNode {
public:
    int key;
    BSTNode<t> *left;
    BSTNode<t> *right;
    int height;//get height to balance the tree
    bool vis=0;
};


template<class t>
int get_height(BSTNode<t> *tmp) {
    if (tmp == NULL)
        return 0;
    return tmp->height;
}

template<class t>
BSTNode<t> *newNode(t tmp) {
    BSTNode<t> *node = new BSTNode<t>;
    node->height = 1;
    node->key = tmp;
    node->left = NULL;
    node->right = NULL;
    return node;
}


template<class t>
BSTNode<t> *rightRotate(BSTNode<t> *tmp) {
    BSTNode<t> *finalnode = tmp->left;
    BSTNode<t> *Tmpnode = finalnode->right;
    BSTNode<t>* tt = tmp->right;
    finalnode->right = tmp;
    tmp->left = Tmpnode;
    tt=tmp->left;
    tmp->height = max(get_height(tmp->left),get_height(tmp->right)) + 1;
    finalnode->height = max(get_height(finalnode->left),get_height(finalnode->right)) + 1;
    delete(tmp,tt);
    return finalnode;
}

template<class t>
BSTNode<t> *leftRotate(BSTNode<t> *tmp) {
    BSTNode<t> *finalnode = tmp->right;
    BSTNode<t> *tmpnode = finalnode->left;
    BSTNode<t> *tt= tmp->right;
    finalnode->left = tmp;
    tmp->right = tmpnode;
    tt=tmp->left;
    tmp->height = max(get_height(tmp->left),get_height(tmp->right)) + 1;
    finalnode->height = max(get_height(finalnode->left),get_height(finalnode->right)) + 1;
    delete(tmp,tt);
    return finalnode;
}


template<class t>
int getBalance(BSTNode<t> *tmp) {
    if (tmp == NULL)
        return 0;
    return get_height(tmp->left) - get_height(tmp->right);
}


template<class t>
BSTNode<t> *insert(BSTNode<t> *node, t key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(get_height(node->left),get_height(node->right));


    int balance = getBalance(node);


    //ll
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    //rr
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);


    //rl
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //lr
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
}


template<class t>
class BSTFCI {
private:
    BSTNode<t> *root;
    vector<t>sol;
public:

    BSTFCI(BSTNode<t> *node) {
        root = node;
    }

    bool dfs(BSTNode<t>*ro1,BSTNode<t>*ro2) {
        if(ro2==NULL && ro1==NULL){
            return 1;
        }
        if((ro1==NULL  && ro2 !=NULL)||(ro2==NULL  && ro1 !=NULL)){
            return 0;
        }
        if (ro2->key!=ro1->key){
            return 0;
        }
        return dfs(ro1->right,ro2->right) && dfs(ro1->left,ro2->left);
    }

    bool isSubTree(BSTNode<t>*ro1,BSTNode<t>*ro2) {
        if (ro1==NULL){
            return 0;
        }
        if (ro1->key==ro2->key){
            if(dfs(ro1,ro2))
                return 1;
        }
        return isSubTree(ro1->left,ro2)||
        isSubTree(ro1->right,ro2);

    }
    void dfs2(BSTNode<t>*ro,t low,t high){
        if(ro==NULL || ro->vis )
            return;
        ro->vis=1;
        if((ro->key<= max(low,high)) && (ro->key>=min(low,high))){
            sol.push_back(ro->key);
        }
        dfs2(ro->left,low,high);
        dfs2(ro->right,low,high);
        return;
    }
    void printRange(t low, t hegih) {
        sol.clear();
        dfs2(root,low,hegih);
        sort(sol.begin(),sol.end());
        for (auto i:sol){
            cout<<i<<' ';
        }
        if(sol.empty()){
            cout<<"NO Numbers in Range";
        }

    }
};

void test1(){
    BSTNode<int>*tree1=NULL;
    BSTNode<int>*tree2=NULL;
    tree1 = insert(tree1,5);
    tree1 = insert(tree1,7);
    tree1 = insert(tree1,3);
    tree1 = insert(tree1,2);
    tree1 = insert(tree1,4);
    tree1 = insert(tree1,1);
    tree1 = insert(tree1,9);
    tree1 = insert(tree1,8);
    tree1 = insert(tree1,10);

    tree2 = insert(tree2,9);
    tree2 = insert(tree2,8);
    tree2 = insert(tree2,10);
    BSTFCI<int>bs(tree1);
    cout<<bs.isSubTree(tree1,tree2);
    cout<<endl;
    bs.printRange(90,100);
    cout<<endl;
    delete(tree1,tree2);

}
void test2(){
    BSTNode<int>*tree1=NULL;
    BSTNode<int>*tree2=NULL;
    tree1 = insert(tree1,5);
    tree1 = insert(tree1,7);
    tree1 = insert(tree1,3);
    tree1 = insert(tree1,2);
    tree1 = insert(tree1,4);
    tree1 = insert(tree1,1);
    tree1 = insert(tree1,9);
    tree1 = insert(tree1,8);
    tree1 = insert(tree1,10);

    tree2 = insert(tree2,2);
    tree2 = insert(tree2,3);
    tree2 = insert(tree2,1);
    tree2 = insert(tree2,4);
    BSTFCI<int>bs(tree1);
    cout<<bs.isSubTree(tree1,tree2);
    cout<<endl;
    bs.printRange(4,100);
    cout<<endl;
    delete(tree1,tree2);
}
void test3(){
    BSTNode<int>*tree1=NULL;
    BSTNode<int>*tree2=NULL;
    tree1 = insert(tree1,5);
    tree1 = insert(tree1,7);
    tree1 = insert(tree1,3);
    tree1 = insert(tree1,2);
    tree1 = insert(tree1,4);
    tree1 = insert(tree1,1);
    tree1 = insert(tree1,9);
    tree1 = insert(tree1,8);
    tree1 = insert(tree1,10);

    tree2 = insert(tree2,99);
    tree2 = insert(tree2,3);
    tree2 = insert(tree2,1);
    tree2 = insert(tree2,4);
    BSTFCI<int>bs(tree1);
    cout<<bs.isSubTree(tree1,tree2);
    cout<<endl;
    bs.printRange(-4,11);
    cout<<endl;
    delete(tree1,tree2);
}
void test4(){
    BSTNode<char>*tree1=NULL;
    BSTNode<char>*tree2=NULL;
    tree1 = insert(tree1,'b');
    tree1 = insert(tree1,'a');
    tree1 = insert(tree1,'c');
    tree1 = insert(tree1,'d');
    tree1 = insert(tree1,'e');
    tree1 = insert(tree1,'f');
    tree1 = insert(tree1,'n');
    tree1 = insert(tree1,'x');
    tree1 = insert(tree1,'y');


    tree2 = insert(tree2,'b');
    tree2 = insert(tree2,'d');
    tree2 = insert(tree2,'l');
    tree2 = insert(tree2,'a');
    BSTFCI<char>bs(tree1);
    cout<<bs.isSubTree(tree1,tree2);
    cout<<endl;
    bs.printRange('b','g');
    cout<<endl;
    delete(tree1,tree2);
}
void test5(){
    BSTNode<char>*tree1=NULL;
    BSTNode<char>*tree2=NULL;
    tree1 = insert(tree1,'b');
    tree1 = insert(tree1,'c');
    tree1 = insert(tree1,'d');
    tree1 = insert(tree1,'e');
    tree1 = insert(tree1,'f');
    tree1 = insert(tree1,'n');
    tree1 = insert(tree1,'x');
    tree1 = insert(tree1,'y');


    tree2 = insert(tree2,'b');
    tree2 = insert(tree2,'c');
    tree2 = insert(tree2,'d');
    tree2 = insert(tree2,'e');
    tree2 = insert(tree2,'f');
    tree2 = insert(tree2,'n');
    tree2 = insert(tree2,'x');
    tree2 = insert(tree2,'y');
    BSTFCI<char>bs(tree1);
    cout<<bs.isSubTree(tree1,tree2);
    cout<<endl;
    bs.printRange('0','z');
    cout<<endl;
    delete(tree1,tree2);
}
int main() {
    SMSM
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();


    return 0;
}


