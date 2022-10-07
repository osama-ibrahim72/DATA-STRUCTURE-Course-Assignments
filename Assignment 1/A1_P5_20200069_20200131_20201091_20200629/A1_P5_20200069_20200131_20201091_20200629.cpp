/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */

#include <bits/stdc++.h>
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

class StudentName{
private:
    string name;
public:
    StudentName(s tmp);

    void print();
    bool check(int i,int j);
    int start(int tmp);
    int end(int tmp );
    void replace(int i,int j);
};
StudentName :: StudentName(s tmp){
        name=tmp;
        int cnt=0;
        for(int i=0;i<name.size()-1;i++){
            if(name[i]==' ' && name[i+1]!=' ')cnt++;
        }
        if(cnt==1){
            int i=name.size()-1;
            for (i;i>=0;i--){
                if(name[i]==' ')
                    break;
            }
            int n=name.size();
            name.push_back(' ');
            i++;
            for(i;i<n;i++){
                name.push_back(name[i]);
            }
        }
        else if (cnt==0){
            int n=name.size();
            name.push_back(' ');
            int i=0;
            for(i;i<n;i++){
                name.push_back(name[i]);
            }
            name.push_back(' ');
            i=0;
            for(i;i<n;i++){
                name.push_back(name[i]);
            }
        }

}

void StudentName :: print(){
        int cnt=1;
        cout<<1<<") "<<name[0];
        for(int i=1;i<name.size();i++){
            if(name[i]!=' ' && name[i-1]==' '){
                cout<<endl;
                ++cnt;
                cout<<cnt<<") "<<name[i];
            }else{
                cout<<name[i];
            }
        }
        cout<<endl;
    }

bool StudentName :: check(int i,int j){
        int cnt=1;
        for(int f=1;f<name.size();f++){
            if(name[f]!=' '&&name[f-1]==' ')cnt++;
        }
        return cnt>=max(i,j);
}
int StudentName :: start(int tmp){
        int cnt=1;
        int i=1;
        for(i=1;cnt<tmp;i++){
            if(name[i]!=' '&&name[i-1]==' '){cnt++;
                if(cnt==tmp)break;
            }
        }
        return (tmp==1)?0:i;
}

int StudentName :: end(int tmp ){
        int cnt=1;
        int i=1;
        for(i=1;i<name.size();i++){
            if(name[i]!=' '&&name[i-1]==' '){cnt++;
                if(cnt-tmp==1)break;
            }
        }
        return --i;
}

void StudentName :: replace(int i,int j){
        if(check(i,j)){
            cout<<"true"<<endl;
            int startI,endI,startJ,endJ,cnt=1;
            startI= start(i),endI= end(i),startJ= start(j),endJ=end(j);
            for(int k=0;k<name.size();k++){
                if(cnt==i){
                    for(int f=startJ;f<=endJ;f++){
                        cout<<name[f];
                        if (f==endJ && name[f]!=' ')cout<<' ';
                    }
                    k=endI;
                    cnt++;
                }
                else if(cnt==j){
                    for(int f=startI;f<=endI;f++){
                        cout<<name[f];
                        if(f==endI && name[f]!=' ')cout<<' ';
                    }
                    k=endJ;
                    cnt++;
                }else{
                    if(k>0)
                    if(name[k]==' '&&name[k-1]!=' '){
                        cnt++;
                    }
                    cout<<name[k];

                }
            }
            cout<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
}


void test1(){
    StudentName name("smsm");
    name.print();
    name.replace(5,3);
}
void test2(){
    StudentName name("osama ibrahim marzok eid ibrahim");
    name.print();
    name.replace(5,1);
}
void test3(){
    StudentName name("joeshowa george abo hagr malak");
    name.print();
    name.replace(3,6);
}
void test4(){
     StudentName name("osama ibrahim");
    name.print();
    name.replace(1,2);
}
void test5(){
     StudentName name("osama ibrahim marzok");
    name.print();
    name.replace(1,2);
}




int main () {
    //SMSM
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();

    return 0;
}
