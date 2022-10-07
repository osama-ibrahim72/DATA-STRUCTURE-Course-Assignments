/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include<ctime>
#include<chrono>
#include <iomanip>
/*
ABFGC
FBGAC
*/
using namespace std;

class Node {
public:
  char data;
  Node *left, *right;

  Node(char data)
  {
    this->data = data;
    left = right = NULL;
  }
  ~Node()
  {
      delete left;
      delete right;
  }
};

// A utility function to search x in in
int search(string in, char ch)
{
	for (int i = 0; i < in.size(); i++)
		if (in[i] == ch)
			return i;
	return -1;
}

// Prints postorder traversal from given inorder and preorder traversals
Node* constructTree(string pre ,string in)
{
    // meaning no subtree
    if(pre.size() == 0) {
        return NULL ;
    }

    Node* node = new Node(pre[0]);

    if(pre.size() == 1) {
        return node;
    }
    // we reached leaf
	int index = search(in, pre[0]);

    node->left = constructTree(pre.substr(1, index), in.substr(0, index));
    node->right = constructTree(pre.substr(index + 1),in.substr(index +1));

    return node;
}
void postorderTraversal( Node* node2) {
  if (node2 == NULL)
    return ;

  postorderTraversal(node2->left);
  postorderTraversal(node2->right);
  cout << node2->data;
}
void printPostOrder(string pre ,string in)
{

    Node *node1 = constructTree(pre ,in);
    postorderTraversal(node1);
}

// Driver program to test above functions
int main()
{
	//string in ,pre; cin>>pre>>in;
	cout << "Postorder traversal " << endl;
	//printPostOrder(pre, in);
	printPostOrder("ABFGC","FBGAC");    //FGBCA
	cout<<endl;
    printPostOrder("12453","42513");    //4 5 2 3 1
    cout<<endl;
    printPostOrder("124795368","794251368"); //974528631
    cout<<endl;
    printPostOrder("1245367","4251637");//4526731
    cout<<endl;
    printPostOrder("273681594","378612549");//381674952
    cout<<endl;

	return 0;
}
