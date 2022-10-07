/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#include <iostream>
using namespace std;

template <class T>
 class node
{
    public:
    T info;
    node<T>*next;
    node<T>*prev;
};
template <class T>
class doublylist
{
private:
    node<T>*head;
    node<T>*tail;
    node<T>*dummy;
    int cnt;
public:
    bool IsEmpty()
    {
        return(head==NULL);
    }
    doublylist()
    {
        head=NULL;
        tail=NULL;
        cnt=0;
        dummy=new node<T>;
    }
    doublylist(T value, int initial_size)
    {
        for(int i=0; i<initial_size; i++)
        {
            node  <T> * newnode = new node <T>;
            if(IsEmpty())
            {
                head = newnode;
                tail= newnode;
                head->info = value;
                head->next=NULL;
                head->prev=NULL;
                cnt++;
            }
            else
            {
                tail->next = newnode;
                newnode->prev=tail;
                tail=newnode;
                tail->info = value;
                tail->next=NULL;
                cnt++;
            }
        }
    }
    class Iterator{
    private:
        node <T>*newnode;
        friend class doublylist;
    public:

        bool operator==(Iterator itr ){
            if(this->newnode == itr.newnode)
            {
                return true;
            }
            return false;
        }
        void operator--(int)
        {
            if(newnode->prev==NULL)
            {
                cout <<"Out of Range"<<endl;
            }
            else
            {
                Iterator itr =*this;
                this->newnode = this->newnode->prev;
            }

        }
        void operator++(int)
        {
            if (newnode->next == NULL )
            {
                cout <<"Out of Range"<<endl;
                return;
            }
            else
            {
                Iterator itr  = *this;
              this->newnode = this->newnode->next;
            }
        }
        T &operator *()
        {
            return this->newnode->info;
        }
        bool operator!=(Iterator itr)
        {
            if(this->newnode != itr.newnode)
            {
                return true;
            }
            return false;
        }
    };
    int siz()
    {
        return cnt;
    }
    void insertAt(T value,Iterator &pos)
    {
       node <T> * temp = new node <T>;
       temp->info = value;
       Iterator itr  = this->Begin();
       Iterator itr2 = this->End();
       if(head==NULL)
        {
            head = tail = temp;
            head->prev = NULL;
            head->next = NULL;
            cnt ++;
            pos.newnode=head;
            return;
        }
        if(pos==itr)
        {
         temp->next = head;
         head->prev = temp;
         temp->prev= NULL;
         head = temp;
         pos.newnode = head;
         cnt++;
         return;
       }
       if(pos.newnode==tail){
           tail->prev->next = temp;
           temp->prev = tail->prev;
           temp->next = tail;
           tail->prev = temp;
            cnt++;
            pos.newnode = tail->prev;
            return;
       }
       itr++;
       while(itr!=itr2){
        if(itr==pos){
           itr.newnode->prev->next = temp;
           temp->prev = itr.newnode->prev;
           temp->next = itr.newnode;
           itr.newnode->prev = temp;
           cnt++;
           pos.newnode = temp;
           return;
        }
        itr++;
       }
       cout<<"This Position isn't found."<<endl;
    }
    Iterator Begin()
    {
        Iterator itr ;
        itr.newnode = head;
        return itr;
    }
    Iterator End()
    {
        if(head==NULL)
        {
           Iterator itr ;
           itr.newnode = tail;
           return itr;
        }
        Iterator itr ;
        tail->next = dummy;
        dummy->prev = tail;
        dummy->next = NULL;
        itr.newnode = dummy;
        return itr;
    }
    Iterator erase(Iterator pos)
    {
        if(pos.newnode==head &&  siz()==1)
        {
            head = tail = NULL;
            cnt--;
            pos.newnode = NULL;
            return pos;
        }

        if(pos.newnode==head)
        {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            cnt--;
            pos.newnode = NULL;
            return pos;
        }

        if(pos.newnode==tail)
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            pos.newnode = tail;
            cnt--;
            return pos;
        }

        node <T>*temp = head;

        while(temp!=tail->next)
        {
           if(temp==pos.newnode)
           {
               temp->prev->next = temp->next;
               temp->next->prev = temp->prev;
               pos.newnode = temp->prev;
               delete temp;
               cnt--;
               return pos;
           }
          temp = temp->next;
        }

        cout <<"This position is not found."<<endl;
    }
    void display()
    {
      node <T>*temp = head;
      Iterator itr  = this->End();
      while(temp!=itr.newnode){
        cout <<temp->info<<"   ";
        temp=temp->next;
      }
      cout<<endl;
    }
    doublylist &operator=(doublylist<T> lst)
    {
        Iterator Start = lst.Begin();
        Iterator Finish = lst.End();
        while(Start!=Finish)
        {
             push_back(Start.newnode->info);
             Start++;
        }
        return *this;
    }
    void pushBack(int inf)
    {
         node <T> *temp = new node <T>;
         temp->info = inf;
         temp->prev = temp->next = NULL;
         if(head==NULL){
               head = tail = temp;
               cnt++;
         }
         else
         {
            tail->next = temp;
             temp->prev = tail;
             tail = temp;
             cnt++;
         }

    }
    ~doublylist()
    {
       node  <T> * current = head;
       node  <T> * tailcurrent = tail;
       while(current!=tailcurrent)
        {
            node<T> * temp = new node <T>;
            temp = current;
            delete temp;
            current = current->next;
       }
       delete tailcurrent;
       delete tail->next;
    }
};

int main()
{
    doublylist <int> lst;
    lst.pushBack(5);
    lst.pushBack(9);
    lst.display();

    doublylist <int>::Iterator itr;
    itr = lst.Begin();
    lst.insertAt(3,itr);
    lst.display();

    lst.erase(itr);
    lst.display();

    cout<<lst.siz()<<endl;

    itr=lst.End();
    itr--;
    lst.insertAt(2,itr);
    lst.display();


    return 0;
}
