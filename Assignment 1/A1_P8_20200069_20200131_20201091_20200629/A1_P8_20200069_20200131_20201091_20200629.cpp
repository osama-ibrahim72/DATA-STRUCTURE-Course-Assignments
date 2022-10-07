/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#include <iostream>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;


//recursive space complexity (log n)

int binarySearch(int key, int a[],int lb, int ub)
{
    if (ub <= lb)
    {
        if(key>a[lb])
        {
            return (lb+1);
        }
        else
        {
            return lb;
        }
    }

    int index = -1;
    int mid;
    mid = (ub + lb)/2;

    if (key < a[mid])
    {
        ub = mid - 1;
        return binarySearch(key,a,lb,ub);
    }
    else if (key > a[mid])
    {
        lb = mid + 1;
        return binarySearch(key,a,lb,ub);
    }
    else
    {
        return mid;
    }
}
/* best case O(1)
 average and worst caseS O(log n)
*/
void BinaryInsertionSort(int a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int j=i-1;

        int tmp = a[i];

        int position = binarySearch(tmp,a,0,j);

         for( ; j>=position; j--)
         {
             a[j+1]=a[j];
         }

        a[j+1]=tmp;
    }
}
/* best case O(nlog n)
worst and average O(n^2)
*/

void InsertionSort(int *arr, int siz) {
   int key, j;
   for(int i = 1; i<siz; i++) {
      key = arr[i];
      j = i;
      while(j > 0 && arr[j-1]>key) {
         arr[j] = arr[j-1];
         j--;
      }
      arr[j] = key;
   }
}
/* best case O(n)
 average and worst caseS O(N^2)
*/
int main()
{/*
    int n;
    cout<<"Please Enter The Size Of Your Array: "<<endl;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Please Enter Item ["<<i<<"]: ";
        cin>>a[i];
    }
    insertionSort(a, n);

    cout<<endl<<"Sorted array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< a[i] <<" ";
    }
*/


    for(int i=0;i<5;i++)
    {
        int*ptr;
        int x;
        auto f=[]()->int {return rand()%10000;};
        cin>>x;
        ptr=new int [x];
        generate(ptr,ptr+x,f);
        auto start=high_resolution_clock::now();
        BinaryInsertionSort(ptr,x);
        auto End=high_resolution_clock::now();
        auto duration=duration_cast<milliseconds>(End-start);
        cout<<duration.count()<<" msec "<<endl;
    }
    return 0;
}
