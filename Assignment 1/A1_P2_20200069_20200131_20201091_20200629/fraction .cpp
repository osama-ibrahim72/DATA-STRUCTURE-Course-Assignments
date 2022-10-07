/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#include "fraction .h"
#include <iostream>
using namespace std;

fraction ::fraction ()
{
    //ctor
}

fraction::fraction(int x,int y)
{
    nume=x;
    deno=y;
    this->reduce();
}

fraction::fraction(const fraction&obj)
{
    nume=obj.nume;
    deno=obj.deno;
      this->reduce();

}
int fraction::GCD(int num1,int num2)
{
    if(num2==0)
        return num1;
    else
        return GCD(num2,num1%num2);
}

void fraction ::reduce()
{
    int gcd=GCD(nume,deno);
    nume/=gcd;
    deno/=gcd;

}
bool fraction::operator>(const fraction& obj)
{
    float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1>res2)
      return 1;
     return 0;
}
bool fraction::operator<(const fraction& obj)
{
      float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1<res2)
      return 1;
     return 0;
}
bool fraction::operator>=(const fraction& obj)
{
    float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1>=res2)
        return 1;
     return 0;
}
bool fraction::operator<=(const fraction& obj)
{
     float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1<=res2)
      return 1;
     return 0;
}
bool fraction::operator==(const fraction& obj)
{
    float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1==res2)
        return 1;
    return 0;
}
bool fraction ::operator!=(const fraction &obj )
{
    float res1=static_cast<float>(nume)/deno;
    float res2=static_cast<float>(obj.nume)/obj.deno;

    if ( res1!=res2)
        return 1;
    return 0;
}
fraction fraction:: operator+(const fraction&obj)
{
    fraction frac;
    frac.deno=deno*obj.deno;
    frac.nume=nume*obj.deno+obj.nume*deno;
    frac.reduce();
    return frac;
}
fraction fraction ::operator-(const fraction&  obj)
{
    fraction frac;
    frac.deno = deno*obj.deno;
    frac.nume = nume*obj.deno-obj.nume*deno;
    frac.reduce();
    return frac;
}
fraction fraction ::operator*(const fraction &obj)
{
    fraction frac;
    frac.deno = deno*obj.deno;
    frac.nume = nume*obj.nume;
    frac.reduce();
    return frac;
}
fraction fraction::operator /(const fraction&obj)
{
    fraction frac;
    frac.deno=deno*obj.nume;
    frac.nume=nume*obj.deno;
    frac.reduce();
    return frac;
}

istream & operator >> (istream & is , fraction & obj)
{
    char x;
    is>>obj.nume>>x>>obj.deno;
    obj.reduce();
    return is;
}

ostream & operator << (ostream & os , fraction  obj)
{
   if (obj.deno==0)
        os<<"it can't be divided by 0"<<endl;
   else if (obj.nume==0)
        os<<0<<endl;
    else if (obj.nume==obj.deno)
        os<<1<<endl;
    else
        os<<obj.nume<<'/'<<obj.deno;
    return os;
}

fraction ::~fraction ()
{
    //dtor
}

