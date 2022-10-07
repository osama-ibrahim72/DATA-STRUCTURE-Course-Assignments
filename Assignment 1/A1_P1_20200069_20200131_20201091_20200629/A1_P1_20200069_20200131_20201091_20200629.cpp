/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */


#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

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

class BigInt{

private:
    string number;
    bool cary,sign=0;
    int size;

public:
    BigInt();
    BigInt(BigInt&);
    BigInt(string);
    BigInt(ll);

    int get_size();
    void swap ();

    BigInt comp(BigInt&);

    void operator=(const BigInt&);
    void operator=(const string);
    void operator=(ll);

    bool compare (BigInt&);//bigger than or equal

    BigInt operator+( BigInt&);
    BigInt operator-(const BigInt&);


    friend istream& operator >>(istream & , BigInt&);
    friend ostream& operator << (ostream &,const BigInt &);
};

BigInt::BigInt() {}

BigInt::BigInt( string num) {
    for (int i=0;i<num.size();i++){
        if (i == 0) {
            if (num[i] == '-')sign = 1;
            else {
                number.push_back(num[i]);
            }
        }
        else{
            if (num[i]<='9' && num[i]>='0'){
                this->number.push_back(num[i]);
            }
            else{
                number.clear();
                cout<<"Invaild number";
                break;
            }
        }
    }
    this->size=number.size();
}

BigInt::BigInt(ll num) {
    if(num<0){
        sign=1;
    }
    while(num>0){
        this->number.push_back(num%10+'0');
        num/=10;
    }
    this->swap();
    this->size+=number.size();
}

BigInt::BigInt(BigInt &obj) {
    this->sign = obj.sign;
    this->number=obj.number;
    this->cary=obj.cary;
}
void BigInt::operator=( ll num) {
    if(num<0){
        sign=1;
    }
    while(num>0){
        this->number.push_back(num%10+'0');
        num/=10;
    }
    this->swap();
    this->size+=number.size();
}
void BigInt::operator=(const string num) {
    for (int i=0;i<num.size();i++){
        if(i==0) {
            if (num[i] == '-') {
                sign = 1;
                continue;
            }
        }
            if (num[i]<='9' && num[i]>='0'){
                this->number.push_back(num[i]);
            }
            else{
                number.clear();
                cout<<"Invaild number";
                break;
            }

    }
    this->size=number.size();
}

void BigInt::operator=(const BigInt & obj) {
    this->sign = obj.sign;
    this->number=obj.number;
    this->cary=obj.cary;
}

void BigInt::swap() {
    while(this->number.back()=='0'){
        number.pop_back();
    }
    for(int i=0;i< this->number.size()/2;i++){
        char tmp=this->number[this->number.size()-1-i];
        this->number[this->number.size()-1-i]=this->number[i];
        this->number[i]=tmp;
    }
    if(this->number.size()==0){
        this->number.push_back('0');
    }
    this->size=this->number.size();
}

BigInt BigInt::operator+( BigInt &obj) {
    BigInt tmp;
    tmp.number=this->number;
    tmp.size=this->size;
    tmp.sign=0;

    BigInt result;
    string s1 =this->number;
    string s2 = obj.number;
    cary= false;
    if (this->sign && obj.sign){
        result.sign=1;
    }
    else if (this->sign){
        result = obj-tmp;
        return result;
    }else if (obj.sign){
        BigInt tmp2;
        tmp2.number=obj.number;
        tmp2.size=obj.size;
        tmp2.sign=0;
        result = tmp-tmp2;
        return result;
    }
    while(!s1.empty() ||!s2.empty()){
        int temp=0;
        if (cary){
            temp++;
            cary=0;
        }
        if(!s1.empty()) {
            temp += s1.back() - '0';
            s1.pop_back();
        }
        if(!s2.empty()) {
            temp += s2.back() - '0';
            s2.pop_back();
        }
        if (temp>9){
            cary=1;
            temp-=10;
        }
        result.number.push_back(temp+'0');
    }
    result.swap();
    return result;
}

bool BigInt::compare(BigInt &obj) {
    if(this->size>obj.size){
        return true;
    }else if(this->size<obj.size){
        return false;
    }
    else{
        for(int i=0;i< this->size;i++){
            if(this->number[i]>obj.number[i]){
                return true;
            }
            else if(this->number[i]<obj.number[i]){
                return false;
            }
        }
    }
    return true;
}

BigInt BigInt::operator-( const BigInt &obj) {
    BigInt result, obj2;
    obj2.number=obj.number;
    obj2.sign=obj.sign;
    obj2.size=obj.size;
    obj2.sign^=1;
    string s1,s2;
    bool res_sign;
    if(this->compare(obj2)){
        s1= this->number;
        s2=obj2.number;
        res_sign=this->sign;
    }
    else{
        s2= this->number;
        s1=obj2.number;
        res_sign=obj2.sign;
    }
    if(this->sign == obj2.sign){
        BigInt tmp;
        tmp.number=this->number;
        result=tmp+obj2;
        result.sign=res_sign;
        return result;
    }
    else{
        cary= false;
        while(!s1.empty() ||!s2.empty()){
            int temp=0;
            if (cary){
                if(!s1.empty())
                s1.back()--;
                cary=0;
            }
            if(!s1.empty()) {
                temp += s1.back() - '0';
                s1.pop_back();
            }
            if(!s2.empty()) {
                temp -= s2.back() - '0';
                s2.pop_back();
            }
            if (temp<0){
                cary=1;
                temp+=10;
            }
            result.number.push_back(temp+'0');
        }
    }
    result.sign=res_sign;
    result.swap();
    return result;

}

istream & operator >> (istream & is , BigInt & obj)
{
    string num;
    is>>num;
    for (int i=0;i<num.size();i++){
        if(i==0){if(num[i]=='-')obj.sign=1;}
        else{
            if (num[i]<='9' && num[i]>='0'){
                obj.number.push_back(num[i]);
            }
            else{
                obj.number.clear();
                cout<<"Invaild number";
                break;
            }
        }
    }
    obj.size=obj.number.size();
    return is;
}

ostream & operator << (ostream & os , const BigInt & obj){
    if(obj.sign){
        cout<<'-';
    }
    os<<obj.number;
    return os;
}


void test1(){
    BigInt x,y;
    x="123456789";
    y="123456789";
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"x+y : "<<x+y<<endl;
    cout<<"x-y : "<<x-y<<endl;
}
void test2(){
    BigInt x,y;
    x=123456789;
    y="-123456789";
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"x+y : "<<x+y<<endl;
    cout<<"x-y : "<<x-y<<endl;
}
void test3(){
    BigInt x("5555555555"),y("-123456789"),w,z;
   w=x+y;
   z=x-y;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"x+y : "<<w<<endl;
    cout<<"x-y : "<<z<<endl;
}
void test4(){
    BigInt x,y;
    x="-310000000";
    y="-45555555";
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"x+y : "<<x+y<<endl;
    cout<<"x-y : "<<x-y<<endl;
}
void test5(){
    BigInt x,y;
    x="310556789";
    y="455987";
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"x+y : "<<x+y<<endl;
    cout<<"x-y : "<<x-y<<endl;
}



int main () {
    SMSM
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();

    return 0;
}
