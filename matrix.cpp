#include<iostream>

using namespace std;


int main()
{
    int mat1[4][2];
    int mat2[2][3];
    int res;
    int sum[4][4];
    int mult[4][4] = {0};

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 2; j++)
            cin>>mat1[i][j];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
        {
            cin>>mat2[i][j];
            // sum[i][j] = mat1[i][j] + mat2[i][j];
        }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
        
        
    // for(int i = 0; i < 4; i++)
    // {
    //     for(int j = 0; j < 4; j++)
    //         cout<<sum[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
            cout<<mult[i][j]<<" ";
        cout<<endl;
    }
        

    




    return 0;
}