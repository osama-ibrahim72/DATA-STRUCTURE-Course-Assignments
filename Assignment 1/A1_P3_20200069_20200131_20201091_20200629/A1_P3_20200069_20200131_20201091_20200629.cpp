/*
 Name : Osama Ibrahim Marzok              ID : 20200069     lab : 25-26
 Name : Joeshwoa George Abo Hager Melek   ID : 20200131     Lab : 25-26
 Name : Silvana Yacoub GabAllah           ID : 20201091     Lab : 25-26
 Name : Yara Muhammad Saad                ID : 20200629     Lab : 25-26
 */

#include <iostream>
using namespace std;
template <class t>
class matrix
{
private:
    t ** mat;
    int Dx,Dy;
public:
    matrix(int x, int y)
    {
        if(x<0||y<0)
        {
            x=0;
            y=0;
        }
        Dx=x;
        Dy=y;
        mat = new t * [Dx];
        for(int i=0; i<Dx; i++)
        {
            mat [i] = new t [Dy];
        }
    }
    ~matrix()
    {
        for(int i=0; i<Dx; i++)
        {
            delete [] mat [i];
        }
        delete [] mat ;
    }
    friend ostream& operator<<(ostream& os,const matrix& m)
    {
        for(int x=0; x<m.Dx; x++)
        {
            for(int y=0; y<m.Dy; y++)
            {
                os<<m.mat[x][y]<<' ';
            }
            os<<endl;
        }
    }
    friend istream& operator>>(istream& is,matrix& m)
    {
        for(int x=0; x<m.Dx; x++)
        {
            cout<<"Enter ROW "<<x+1<<endl;
            for(int y=0; y<m.Dy; y++)
            {
                cin>>m.mat[x][y];
            }
            cout<<endl;
        }
    }
    t& operator()(int x,int y){
        if(x>=Dx || y>=Dy)
            cout<<"ERROR!!!!! it's out of matrix";
        else
            return mat [x][y] ;
    }
    matrix& operator= (const matrix& RM)
    {
        if(Dx!=RM.Dx || Dy!=RM.Dy)
            cout<<"ERROR!!!!!order of 2 matrix are not equal";
        else
        {
            for(int x=0; x<Dx; x++)
            {
                for(int y=0; y<Dy; y++)
                {
                    mat[x][y]=RM.mat[x][y];
                }
            }
        }
    }
    matrix operator+ (const matrix& RM)
    {
        if(Dx!=RM.Dx || Dy!=RM.Dy)
            cout<<"ERROR!!!!!order of 2 matrix are not equal";
        else
        {
            matrix res(Dx,Dy);
            for(int x=0; x<Dx; x++)
            {
                for(int y=0; y<Dy; y++)
                {
                    res.mat[x][y]=mat[x][y]+RM.mat[x][y];
                }
            }
            return res;
        }
    }
    matrix operator- (const matrix& RM)
    {
        if(Dx!=RM.Dx || Dy!=RM.Dy)
            cout<<"ERROR!!!!!order of 2 matrix are not equal";
        else
        {
            matrix res(Dx,Dy);
            for(int x=0; x<Dx; x++)
            {
                for(int y=0; y<Dy; y++)
                {
                    res.mat[x][y]=mat[x][y]-RM.mat[x][y];
                }
            }
            return res;
        }
    }
    matrix operator* (const matrix& RM)
    {
        if(Dy!=RM.Dx)
            cout<<"ERROR!!!!! can not multiply there 2 matrix";
        else
        {
            matrix res(Dx,RM.Dy);
            for(int x=0;x<Dx;x++)
            {
                for(int y=0;y<RM.Dy;y++)
                {
                    int R=0;
                    for(int i=0;i<Dx;i++)
                        R+=mat[x][i]*RM.mat[i][y];
                    res.mat[x][y]=R;
                }
            }
            return res;
        }
    }
    matrix transpose()
    {
        matrix trans(Dx,Dy);
        for(int x=0;x<Dx;x++)
        {
            for(int y=0;y<Dy;y++)
            {
                trans.mat[x][y]=mat[y][x];
            }
        }
        return trans;
    }
};
int main()
{

    cout<<"1- Perform Matrix Addition"<<endl;
    cout<<"2 Perform Matrix Subtraction"<<endl;
    cout<<"3- Perform Matrix Multiplication"<<endl;
    cout<<"4- Matrix Transpose"<<endl;
    cout<<"5- Exit"<<endl;
    while (true ){
        int ch;
        cin>>ch;
        switch(ch){
            case 1:{
                int n ,m;
                cout<<"enter number of rows and columns of matrix 1"<<endl;
                cin>>n>>m;
                matrix <int>m1(2,2);
                cin>>m1;
                cout<<"enter number of rows and columns of matrix 2"<<endl;
                cin>>n>>m;
                matrix <int>m2(2,2);
                cin>>m2;
                matrix <int>m3(2,m);
                m3 = m1 + m2;
                cout<<m3;
            }
            case 2 : {
                int n ,m;
                cout<<"enter number of rows and columns of matrix 1"<<endl;
                cin>>n>>m;
                matrix <int>m1(n,m);
                cin>>m1;
                cout<<"enter number of rows and columns of matrix 2"<<endl;
                cin>>n>>m;
                matrix <int>m2(n,m);
                cin>>m2;
                matrix <int>m3(n,m);
                m3 = m1 - m2;
                cout<<m3;
            }
            case 3 : {
                int n ,m,x,y;
                cout<<"enter number of rows and columns of matrix 1"<<endl;
                cin>>n>>m;
                matrix <int>m1(n,m);
                cin>>m1;
                cout<<"enter number of rows and columns of matrix 2"<<endl;
                cin>>x>>y;
                matrix <int>m2(x,y);
                cin>>m2;
                matrix <int>m3(m,x);
                m3 = m1 * m2;
                cout<<m3;
            }
            case 4 : {
                int n ,m;
                cout<<"enter number of rows and columns of matrix"<<endl;
                cin>>n>>m;
                matrix <int>m1(n,m);
                cin>>m1;
                cout<<m1.transpose();

            }
            case 5: {
                return 0 ;
            }
            default : {
            cout<<"invaild choice"<<endl;
            }
        }
        cout<<"1- Perform Matrix Addition"<<endl;
        cout<<"2 Perform Matrix Subtraction"<<endl;
        cout<<"3- Perform Matrix Multiplication"<<endl;
        cout<<"4- Matrix Transpose"<<endl;
        cout<<"5- Exit"<<endl;
    }
    return 0;
}
