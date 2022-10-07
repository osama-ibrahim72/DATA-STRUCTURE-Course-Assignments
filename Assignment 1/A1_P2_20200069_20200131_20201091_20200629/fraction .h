/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#ifndef FRACTION _H
#define FRACTION _H
#include <iostream>
using namespace std;

class fraction
{
    public:
        fraction ();
        fraction (int x,int y);
        fraction(const fraction&obj);
        int GCD(int num1,int num2);
        void reduce();

        bool operator >(const fraction& obj);
        bool operator <(const fraction &obj);
        bool operator <=(const fraction& obj);
        bool operator >=(const fraction& obj);
        bool operator==(const fraction & obj);
        bool operator !=(const fraction& obj);

        fraction operator + (const fraction & obj);
        fraction operator - (const fraction & obj);
        fraction operator * (const fraction & obj);
        fraction operator / (const fraction & obj);


        friend istream &operator>>(istream&is,fraction&obj);
        friend ostream &operator<<(ostream&os,const fraction obj);


        virtual ~fraction ();

    protected:
        int nume,deno;
};

#endif // FRACTION _H
