/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */

#include <bits/stdc++.h>

using namespace std;

#define SMSM cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define endl '\n' ;
#define fo(n) for(int i=0 ; i<n ; i++)
#define w(n) while(n--)
#define sortall(v) sort(v.begin(),v.end())
typedef long long ll;
typedef unsigned long long ull;
typedef double d;
typedef float f;
typedef string s;

const ll llmin = -1e18;
const ll llmax = 1e18;
const int imin = -1e9;
const int imax = 1e9;
class Sorter {
private:
public:
    virtual void sort(vector<int> &arr,int n)=0;
    virtual ll getoper()=0;
};

class SelectionSorter : public Sorter {
private:
    ll oper=0;
    ll lastoper=0;
public:
    SelectionSorter(){}
    void sort (vector<int> &arr,int n){
        oper++;
        for (int i=0;i<n;i++){
            oper+=2;
            int temp = arr[i];oper++;
            int idx=i;oper++;
            oper++;
            for (int j=i+1;j<n;j++){
                oper+=2;
                if (arr[j]<temp){
                    temp=arr[j];
                    idx=j;
                    oper+=2;
                }
                oper++;
            }
            arr[idx]=arr[i];oper++;
            arr[i]=temp;oper++;
        }
        oper++;
        lastoper=oper;
        oper=0;
    }
    ll getoper()
    {
        return lastoper;
    }
};

class QuickSorter : public Sorter {
private:
    ll oper=0;
    ll lastoper=0;
    int i=0,j=0,p;
    int Partition(vector<int> &arr, int left,int right)
    {
        int x =arr[left];
        i = left;
        oper+=3;//x,i,j
        for(j=left+1;j<=right;j++)
        {
            oper++;//if
            if(arr[j]<x)
            {
                i++;
                swap(arr[i],arr[j]);//swap = 3oper
                oper+=4;//i++ , swap
            }
        }
        swap(arr[i],arr[left]);//swap= 3oper
        oper+=3;//swap
        return i;
    }
public:
    QuickSorter(){}
    void sort (vector<int> &arr, int left,int right)
    {
        int middle;
        if (left>=right)
        {
            oper++;//if
            return;
        }
        else
        {
            oper++;//if
            middle= Partition(arr,left,right);
            oper++;//middle
            sort(arr,left,middle-1);
            sort(arr,middle+1,right);
        }

    }
    ll getoper()
    {
        return lastoper;
    }
};

class Test_Bed {
public :
    vector<int> GenrateRandomList(int min, ll max, int size) {
        vector<int> list(size);
        for (auto &i:list) {
            i = (rand() % max);
            if (i < min)i + min;
        }
        return list;
    }

    vector<int> GenrateReviceOrderedList(int min, ll max, int size) {
        vector<int> list = GenrateRandomList(min, max, size);
        sort(list.rbegin(), list.rend());
        return list;
    }

    ll RunOnce(Sorter* s,vector<int> &data,int size)
    {
        s->sort(data,size);
        return s->getoper();
    }

    ll RunAndAverage(Sorter* s,int type,int min, ll max, int size,int sets_num)
{
    ll total=0;
    for(int i=0;i<sets_num;i++)
    {
        vector<int> data;
        if(type==0)
            data=GenrateRandomList(min,max,size);
        else if(type==1)
            data=GenrateReviceOrderedList(min,max,size);
        s->sort(data,size);
        total+=s->getoper();
    }
    return total/sets_num;
}
vector<pair<int,ll>> RunExperient (Sorter* s,int type,int min, ll max,int min_val,int max_val,int sets_num,int step)
{
    vector<pair<int,ll>> Rec;
    ll time=0;
    int size=min_val;
    int v_size=0;
    while(size<=max_val)
        {
            time=RunAndAverage(s,type,min,max,size,sets_num);
            size+=step;
            Rec.push_back(pair<int,ll>(size,time));
            v_size++;
        }
        cout<<"size   time";
        for(int i=0;i<v_size;i++)
        {
            cout<<Rec[i].first<<"  "<<Rec[i].second<<endl;
        }
        return Rec;

}
};

int main() {
    SMSM

    Test_Bed t ;
    //QuickSorter q;
    SelectionSorter s;

    vector<pair<int,ll>> vec = t.RunExperient(s,1,100,1000,5,78920,1,2);
    for(auto [k,v]:vec){
        cout<<k<<' '<<v<<endl;
    }


    return 0;
}
