/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */
#include <bits/stdc++.h>
using namespace std;

void RecPermute(string soFar, string rest)

{
    vector<string>vec;
    if (rest == "") // No more characters
        cout << soFar << endl; // Print the word
    else // Still more chars
        // For each remaining char

        for (int i = 0; i < rest.length(); i++) {

            string next = soFar + rest[i]; // Glue next char

            string remaining = rest.substr(0, i)+ rest.substr(i+1);

            int size=vec.size();
            vec.push_back(next);
            sort(vec.begin(), vec.end());
            for(int i=0;i<vec.size();i++){
                if(vec[i]==vec[i+1])
                {
                    vec.pop_back();
                }
                else
                    continue;
            }
            if(vec.size()>size)
            RecPermute(next, remaining);
        }
}

void ListPermutations(string s) {
    RecPermute("", s);
}

int main()
{

    ListPermutations("abc");
    cout<<endl;
    ListPermutations("MAKKA");
	return 0;
}

