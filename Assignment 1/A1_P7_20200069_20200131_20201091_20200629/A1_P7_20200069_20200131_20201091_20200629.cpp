/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */

#include <iostream>
#include <vector>
using namespace std;
void BiasedSort (vector<string>& songs)
{
    int LU = -1;
    for(int i=1;i<songs.size();i++)
    {
        string C = songs[i];
        if(C=="Untitled")
        {
            for(int x=i;x>LU+1;x--)
            {
                songs[x]=songs[x-1];
            }
            songs[++LU]=C;
        }
        else
        {
            if(C < songs[i-1]&&songs[i-1]!="Untitled")
            {
                int x=i-1;
                for(;x>LU&&x>0&&C<songs[x];x--)
                {
                    songs[x+1]=songs[x];
                }
                songs[x+1]=C;
            }
            else
            {

            }
        }
    }
}


int main() {
    cout<<"Enter the number of Songs"<<endl;
    int n;
    cin>>n;
    cout<<"Enter Songs"<<endl;
    vector<string>vec(n);
    for(auto &i:vec)cin>>i;
    cout<<"------"<<endl;
    BiasedSort(vec);
    for(auto i:vec){
        cout<<i<<endl;
    }
    return 0;
}
