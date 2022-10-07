#include "FractionCalculator.h"
#include "fraction .cpp"
#include <iostream>
using namespace std;


FractionCalculator::FractionCalculator()
{
    fraction f1,f2,f3;

   cout<<"Welcome to our fraction calculator"<<endl;
   cout<<endl;
   cout<<"please enter the first fraction: "<<endl;
   cin>>f1;
   cout<<"please enter the second fraction:"<<endl;
   cin>>f2;
   int choice;

    while(true){
            cout<< endl;
            cout<<"1-Add '+'"<<endl;
            cout<< "2-subtract '-'"<<endl;
            cout<<"3-multiply '*'"<<endl;
            cout <<"4-divide'/'"<<endl;
            cout <<"5-reduce the fractions"<<endl;
            cout <<"6-exit"<<endl;
            cout<<endl;
            cin>>choice;

            cout<<endl;

          if(choice==1){
                fraction f3(f1+f2);
                cout<<f1<<" + "<<f2<<" = "<<f3<<endl;
                cout<<"----------------------------------"<<endl;




        }
        else if(choice==2){

                fraction f3(f1-f2);
                cout<<f1<<" - "<<f2<<" = "<<f3<<endl;
                cout<<"----------------------------------"<<endl;




        }
        else if(choice==3){
                fraction f3(f1*f2);

            cout<<f1<<" * "<<f2<<" = "<<f3<<endl;
            cout<<"----------------------------------"<<endl;




        }
         else if(choice==4){
                fraction f3(f1/f2);
            cout<<f1<<" / "<<f2<<" = "<<f3<<endl;
            cout<<"----------------------------------"<<endl;




       }
         else if(choice==5)
        {
              cout<<"reduction of first fraction :"<<f1<<endl;
              cout<<"----------------------------------"<<endl;
              cout<<"reduction of second fraction :"<<f2<<endl;
              cout<<"----------------------------------"<<endl;


        }


        else if(choice==6)
        {
              cout<<"the program is terminated"<<endl;
              cout<<"----------------------------------"<<endl;
                break;

        }
    }
}



FractionCalculator::~FractionCalculator()
{
    //dtor
}

