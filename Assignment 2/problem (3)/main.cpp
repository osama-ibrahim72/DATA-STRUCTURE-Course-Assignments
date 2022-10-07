/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>

using namespace std;

class QueueNode {
private:
public:
    int data;
    QueueNode* next;

    QueueNode()
    {
        data=NULL;
        next=NULL;
    }
    QueueNode(int d)
    {
        data=d;
        next=NULL;
    }
    ~QueueNode()
    {
        delete next;
    }
};

class Queue {
private:
    QueueNode* Nstart;
    QueueNode* Nend;
    int Qsize;
public:
    Queue()
    {
        Nstart=NULL;
        Nend=NULL;
        Qsize=0;
    }
    void EnQueue(int v)
    {
        QueueNode* temp = new QueueNode(v);
        if (Nstart == NULL) {
            Nstart = temp;
            Nend = temp;
            Qsize++;
        }
        else
        {
            Nend->next= temp;
            Nend = temp;
            Qsize++;
        }
    }
    int DeQueue()
    {
        if (Qsize==0)
            return NULL;
        QueueNode* temp = Nstart;
        Nstart = Nstart->next;
        Qsize--;
        if (Qsize==0)
            Nend = NULL;
        int d=temp->data;
        delete temp;
        return d;
    }
    int front ()
    {
        return Nstart->data;
    }
    int getsize ()
    {
        return Qsize;
    }
    ~Queue ()
    {
        while(Nend!=NULL&&Nstart!=NULL)
            DeQueue();
        delete Nend;
        delete Nstart;
    }
};

class P3_stack
 {
 private:
    Queue que;
 public:
     void push(int value)
     {
         int temp;
         que.EnQueue(value);
         for(int i=0;i<(que.getsize()-1);i++)
         {
             temp=que.DeQueue();
             que.EnQueue(temp);
         }
     }
     void pop ()
     {
         if(que.getsize()>0)
            que.DeQueue();
     }
     int top()
     {
         if(que.getsize()==0)
             return NULL;
         else
            return que.front();
     }
 };

int main()
{
    P3_stack stk1;
    stk1.push(1);
    stk1.push(2);
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    stk1.push(3);
    stk1.push(4);
    stk1.push(5);
    stk1.push(6);
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.push(7);
    cout<<stk1.top()<<endl;
    stk1.push(8);
    cout<<stk1.top()<<endl;
    stk1.push(9);
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    stk1.pop();
    cout<<stk1.top()<<endl;
    return 0;
}
