/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#include <iostream>
using namespace std;

string first, last, phone;

class Node
{
private:
    string firstName, lastName, PhoneNumber;
public:
    Node *link;
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    string getPhoneNumber(){return PhoneNumber;}

    void setFirstName(string fir){firstName=fir;}
    void setLastName(string las){lastName=las;}
    void setPhoneNumber(string n){PhoneNumber= n;}
};


class PhoneDirectory
{
public:
    Node *head=NULL, *current, *tail, *sorted=NULL;
    int siz=0;
    bool IsEmpty()
    {
        return(head == NULL);
    }
    string AddNumber()
    {
        cout<<"Please Enter The First Name."<<endl;
        cin>>first;
        cout<<"Please Enter The Last Name."<<endl;
        cin>>last;
        cout<<"Please Enter The Phone Number."<<endl;
        cin>>phone;
        Node * newnode= new Node;
        if(IsEmpty())
        {
            head = newnode;
            tail= newnode;
            head->setFirstName(first);
            head->setLastName(last);
            head->setPhoneNumber(phone);
            head->link=NULL;
        }
        else
        {
            tail->link = newnode;
            tail=newnode;
            tail->setFirstName(first);
            tail->setLastName(last);
            tail->setPhoneNumber(phone);
            tail->link=NULL;
        }
        siz++;
        return "The Number Was Added SuccessFully";
    }
    /*Three Sorting Techniques*/
    /*Insertion Sort*/
    void insertSorted(Node * newnode)
    {
        if (sorted == NULL || sorted->getFirstName()[0] >= newnode->getFirstName()[0])
        {
            newnode->link = sorted;
            sorted = newnode;
        }
        else
        {
            Node* current = sorted;

            while (current->link != NULL&& current->link->getFirstName()[0] < newnode->getFirstName()[0])
            {
                current = current->link;
            }

            newnode->link = current->link;
            current->link = newnode;
        }
    }
    void InsertionSort()
    {
        current = head;

        while (current != NULL)
        {
            Node * next = current->link;

            insertSorted(current);

            current = next;
        }

        head = sorted;
    }
    /*Merge Sort*/
    void DivideList(Node* Lst, Node** Begin, Node** End)
    {
        Node* ptr = Lst->link;
        Node* ptr2= Lst;

        while (ptr != NULL)
        {
            ptr = ptr->link;
            if (ptr != NULL)
            {
                ptr2 = ptr2->link;
                ptr = ptr->link;
            }
        }
        *Begin = Lst;
        *End = ptr2->link;
         ptr2->link = NULL;
    }
    Node* MergeSortedList(Node* firstList, Node* secondList)
    {
        Node *result = NULL;

        if (firstList == NULL)
        {
            return (secondList);
        }

        if (secondList == NULL)
        {
            return (firstList);
        }

        if (firstList->getFirstName()[0] <= secondList->getFirstName()[0])
        {
            result = firstList;
            result->link = MergeSortedList(firstList->link,secondList);
        }
        else
        {
            result = secondList;
            result->link = MergeSortedList(firstList, secondList->link);
        }
        return result;
    }
    void MergeSort(Node** thead)
    {
        Node* head = *thead;
        Node* ptr;
        Node* ptr2;

        if ((head == NULL) || (head->link == NULL))
        {
            return;
        }

        DivideList(head, &ptr, &ptr2);

        MergeSort(&ptr);
        MergeSort(&ptr2);

        *thead = MergeSortedList(ptr, ptr2);
    }
    /*Bubble Sort*/
    void Swap (Node *node, Node *node2)
    {
        string firstTemp = node->getFirstName();
        string lastTemp = node->getLastName();
        string phoneTemp = node->getPhoneNumber();

        node->setFirstName(node2->getFirstName());
        node2->setFirstName(firstTemp);


        node->setLastName(node2->getLastName());
        node2->setLastName(lastTemp);


        node->setPhoneNumber(node2->getPhoneNumber());
        node2->setPhoneNumber(phoneTemp);
    }
    void BubbleSort(Node *head)
    {
        int swapped;

        Node *leftPtr;
        Node *rightPtr = NULL;
        do
        {
            swapped = 0;
            leftPtr = head;
            while(leftPtr->link != rightPtr)
            {
                if (leftPtr->getFirstName() > leftPtr->link->getFirstName())
                {
                    Swap(leftPtr, leftPtr->link);
                    swapped = 1;
                }
                leftPtr = leftPtr->link;
            }
            rightPtr = leftPtr;
        }
        while(swapped);
    }
    /*Lookup an entry by Phone number*/
    string LookPhone()
    {
        if (IsEmpty())
        {
            return "The List Is Empty. You Cannot Search In An Empty List.";
        }
        else
        {
            cout<<"Please Enter The Phone Number You Want To Search."<<endl;
            cin>>phone;
            current = head;
            while(current!=NULL)
            {
                if(current->getPhoneNumber()==phone)
                {
                   return current->getFirstName() + " " + current->getLastName();
                }
                current=current->link;
            }
            return "The Number was not found.";
        }

    }
    /*Delete an entry by first name*/
    string del()
    {
        InsertionSort();
        if (IsEmpty())
        {
            return "The List Is Empty, You Cannot Delete From An Empty List";
        }
        else
        {
            cout<<"Please Enter The Name You Want To Delete."<<endl;
            cin>>first;
            current = head;
            if (head->getFirstName()==first)
            {
                head=head->link;
                return "The Number Was Deleted Successfully.";
            }

            else
            {
                current = head;
                while(current->link->getFirstName()!=first)
                {
                    current=current->link;
                    if(current->link==NULL)
                    {
                        return "The Number was not found.";
                    }
                }
                current->link=current->link->link;
                return "The Number Was Deleted Successfully.";
            }
        }
    }
    /*Lookup an entry by first name*/
    string LookName()
    {
      if (IsEmpty())
        {
            return "The List Is Empty. You Cannot Search In An Empty List.";
        }
        else
        {
            cout<<"Please Enter Name You Want To Search."<<endl;
            cin>>first;
            current = head;
            while(current!=NULL)
            {
                if(current->getFirstName()==first)
                {
                    return "Name: " + current->getFirstName() + " " + current->getLastName() + '\n' + "Phone Number: " + current->getPhoneNumber();
                }
                current=current->link;
            }
            return "The Number was not found.";
        }

    }
    /*List the directory in alphabetical order by first name*/
    void display()
    {
        BubbleSort(head);
        MergeSort(&head);
        if(IsEmpty())
        {
            cout<<"The List Is Empty."<<endl;
        }
        else
        {
            current=head;
            while(current!=NULL)
            {
                cout<<"Name: "<<current->getFirstName() <<" "<<current->getLastName()<<endl;
                cout<<"Phone Number: "<<current->getPhoneNumber()<<endl;
                current=current->link;
                cout<<endl;
            }
        }
    }
};

int main()
{
    PhoneDirectory directory;
    int choice;

    do
    {
        string first, last,phone;
        switch(choice)
        {
            case 1:
                cout<<directory.AddNumber()<<endl;
                break;

             case 2:
                cout<<directory.LookPhone()<<endl;
                break;

             case 3:
                cout<<directory.LookName()<<endl;
                break;

             case 4:
                cout<<directory.del()<<endl;
                break;

             case 5:
                directory.display();
                break;
        }

        cout<<endl<<endl;
        cout<<"Please choose a function to perform: "<<endl;
        cout<<"1. Add an entry to the directory."<<endl;
        cout<<"2. Look up a phone number."<<endl;
        cout<<"3. Look up by first name."<<endl;
        cout<<"4. Delete an entry from the directory."<<endl;
        cout<<"5. List All entries in phone directory."<<endl;
        cout<<"6. Exit form this program."<<endl;
        cin>>choice;
        cout<<endl<<endl;
    }
    while(choice!=6);


    return 0;
}
