/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/

#include <iostream>
#define ll long long 
using namespace std;

//create node that has value & two pointers one for left ande other to right 
class BST  {
    public:
    BST* left= NULL, * right = NULL;
    string value ;
    // defaulte constructor 
	BST(string value)
	{
        this->value = value ;
	}
    int conversion(string arr) ;
    int evaluateSubTrees( BST* root) ;
};

//function that convert from string to integer & check if there is negative value or not 
int BST :: conversion(string arr){
    long number = 0;
    if(arr[0]!='-')
        for (int i=0; i<arr.size(); i++)
            number = number*10 + (long(arr[i])-48);
    else
    {
        for (int i=1; i<arr.size(); i++)
            number = number*10 + (long(arr[i])-48);
        number = number*-1;
    }
    return number;
}

// functions for evaluate every operation with its number 
//all the integer values would appear at the leaf nodes, while the interior nodes represent the operators.
int BST :: evaluateSubTrees(BST* root){
    // root is empty
    if (!root) return 0;

    // in case root have left & right child then it can evaluate the sub expression 
    if (!root->left && !root->right)
        return conversion(root->value);


    long leftNode = evaluateSubTrees(root->left);
    long rightNode = evaluateSubTrees(root->right);

    if (root->value=="/")
        return leftNode / rightNode ;

    if (root->value=="*")
        return leftNode * rightNode ;

    if (root->value=="+")
        return leftNode + rightNode ;
    
    else 
        return leftNode - rightNode ;
}
int main(){ 

    BST *r1 = new BST("+");
    r1->left = new BST("*");
    r1->left->left = new BST("5");
    r1->left->right = new BST("-4");
    r1->right = new BST("-");
    r1->right->left = new BST("100");
    r1->right->right = new BST("20");
    cout << r1->evaluateSubTrees(r1) << endl; // output must be 60

    BST* r2= new BST("+");
    r2->left = new BST("*");
    r2->left->left = new BST("5");
    r2->left->right = new BST("4");
    r2->right = new BST("-");
    r2->right->left = new BST("100");
    r2->right->right = new BST("/");
    r2->right->right->left = new BST("20");
    r2->right->right->right = new BST("2");
    cout << r2->evaluateSubTrees(r2) << endl; // output must be 110

    BST* r3 = new BST("*");
    r3->left = new BST("+");
    r3->left->left = new BST("6");
    r3->left->right = new BST("9");
    r3->right = new BST("-");
    r3->right->left = new BST("3");
    r3->right->right = new BST("1");
    cout << r3->evaluateSubTrees(r3) << endl; // output must be 30

    BST* r5 = new BST("+");
    r5->left = new BST("*");
    r5->left->left = new BST("5");
    r5->left->right = new BST("4");
    r5->right = new BST("-");
    r5->right->left = new BST("100");
    r5->right->right = new BST("/");
    r5->right->right->left = new BST("20");
    r5->right->right->right = new BST("2");
    cout << r5->evaluateSubTrees(r5) << endl; // output must be 110
    
    BST* r4 = new BST("-");
    r4->left = new BST("+");
    r4->left->left = new BST("8");
    r4->left->right = new BST("/");
    r4->right = new BST("6");
    r4->right->left = new BST("3");
    r4->right->right = new BST("2");
    cout << r4->evaluateSubTrees(r4) << endl; // output must be 6


}