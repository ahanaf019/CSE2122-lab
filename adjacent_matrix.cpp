#include<iostream>

using namespace std;

struct adj_matrix{
    int dim;
    int data[10][10] = {0};
};

adj_matrix multiply(adj_matrix mat1, adj_matrix mat2);
void print_matrix(adj_matrix mat);
adj_matrix add(adj_matrix mat1, adj_matrix mat2);
adj_matrix make_path_matrix(adj_matrix mat);
int min(int a, int b);
adj_matrix warshall(adj_matrix mat);

int main()
{
    adj_matrix mat;
    cin>>mat.dim;
    for(int i = 0; i < mat.dim; i++)
    {
        for(int j = 0; j < mat.dim; j++)
        {
            cin>>mat.data[i][j];
        }
    }
    cout<<endl;
    // adj_matrix mat2 = multiply(mat, mat);
    // print_matrix(mat2);

    // adj_matrix mat3 = multiply(mat2, mat);
    // print_matrix(mat3);
    
    // adj_matrix mat4 = multiply(mat3, mat);
    // print_matrix(mat4);

    // adj_matrix Bn = add(mat, mat2);
    // Bn = add(Bn, mat3);
    // Bn = add(Bn, mat4);
    // print_matrix(Bn);

    // adj_matrix path_matrix = make_path_matrix(Bn);
    // print_matrix(path_matrix);

    adj_matrix Q1 = warshall(mat);
    print_matrix(Q1);
    

    return 0;
}

adj_matrix multiply(adj_matrix mat1, adj_matrix mat2)
{
    adj_matrix result;
    result.dim = mat1.dim;
    
    for(int i = 0; i < mat1.dim; i++)
    {
        for(int j = 0; j < mat1.dim; j++)
        {
            for(int k = 0; k < mat1.dim; k++)
            {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}

void print_matrix(adj_matrix mat)
{
    for(int i = 0; i < mat.dim; i++)
    {
        for(int j = 0; j < mat.dim; j++)
        {
            cout<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

adj_matrix add(adj_matrix mat1, adj_matrix mat2)
{
    adj_matrix result;
    result.dim = mat1.dim;

    for(int i = 0; i < mat1.dim; i++)
    {
        for(int j = 0; j < mat1.dim; j++)
        {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

adj_matrix make_path_matrix(adj_matrix mat)
{
    adj_matrix result;
    result.dim = mat.dim;
    for(int i = 0; i < mat.dim; i++)
    {
        for(int j = 0; j < mat.dim; j++)
        {
            if(mat.data[i][j] != 0)
            {
                result.data[i][j] = 1;
            }
        }
    }
    return result;
}

adj_matrix warshall(adj_matrix mat)
{
    adj_matrix result;
    result.dim = mat.dim;

    for(int i = 0; i < mat.dim; i++)
    {
        for(int j = 0; j < mat.dim; j++)
        {
            if(mat.data[i][j] == 0)
            {
                mat.data[i][j] = 999999;
            }
        }
    }

    for(int k = 0; k < mat.dim; k++)
    {
        for(int i = 0; i < mat.dim; i++)
        {
            for(int j = 0; j < mat.dim; j++)
            {
                // cout<<i+1<<" "<<k+1<<" "<<k+1<<" "<<j+1<<endl;
                mat.data[i][j] = min(mat.data[i][j],(mat.data[i][k] + mat.data[k][j]));
            }
        }
    }
    return mat;
}

int min(int a, int b)
{
    return a < b ? a : b;
}
