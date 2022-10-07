/* 
Name: Lilian Astfanous Younan            ID : 20200404     Lab :15-16
Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
Name: Mostafa Mohamed Ali                ID : 20200544     Lab : 13
Name :abdalla emad abdelhamid            ID: 20200323      Lab:13
*/
#include <iostream>

using namespace std;

template <class T>
struct node
{
    T data ;
    node<T>*next ;
};

template <class T>
class stack
{
    node<T>*head ;
    int cnt;
public:
    stack():cnt(0)
    {
        head=NULL;
    }
    ~stack()
    {
        node<T>*cur;
        while (head!=NULL)
        {
            cur = head;
            head=head->next ;
            delete cur;
        }
    }
    void push(T value)
    {
         node<T>*N= new node<T>;
         N->data=value ;
         N->next=head ;
         head=N ;
         cnt++ ;
    }
    void pop()
    {
        if (cnt>0)
        {
            cnt--;
            node<T>*N= head;
            head=head->next ;
            delete N;
        }
    }
    T top()
    {
        return head->data ;
    }
    bool empty()
    {
        return (cnt==0) ;
    }
    int size ()
    {
        return cnt ;
    }
};
string simplify(string str)
{
    stack<string> stk , ans ;
    unsigned int i=0 ;
    while(i<str.length())
    {
        string tmp="" ;
        while (str[i] == '/')
            i++  ;
        while (str[i] != '/' &&i<str.length())
        {
            tmp+=str[i++];
        }
        if (tmp ==".")
            continue ;
        else if (tmp=="..")
        {
            if (!stk.empty())
                stk.pop();
        }
        else
            stk.push(tmp);
        i++;
    }
    while (!stk.empty())
    {
        ans.push("/"+stk.top()) ;
        stk.pop() ;
    }
    string path="";
    while (!ans.empty())
    {
        path+=ans.top() ;
        ans.pop() ;
    }
    return path ;
}
int main()
{
    char choice;
    do
    {
        cout << "please Enter the absolute path: " ;
        string str;   cin >> str ;
        string ans =simplify(str);
        cout << "the simplified path: "+ans+"\n";
        cout << "do you want to enter another path ? (y/n) ";
        cin >> choice ;
    }while(choice == 'y' || choice == 'Y') ;
    return 0;
}
