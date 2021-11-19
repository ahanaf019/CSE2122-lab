#include<iostream>
#include<cmath>

using namespace std;

int SIZE = 10;
const int MAX_SIZE = 20;

int max(int arr[], int size);
int min(int arr[], int size);
double avg(int arr[], int size);
int total(int arr[], int size);
void insert_to_pos(int* arr,int size, int item, int pos);
void insert_to_sorted(int* arr, int size, int item);
void delete_item_at_index(int *arr, int size, int pos);
void delete_by_item(int *arr, int size, int item);
int linear_search(int *arr, int size, int item);
void bubble_sort(int *arr, int size);
int binary_search(int *arr, int size, int item);

int main()
{
    int arr[MAX_SIZE];
    int arr_sorted[MAX_SIZE];
    int str_arr[MAX_SIZE];
    int str_arr_sorted[MAX_SIZE];

//  Input section
    for(int i = 0; i<SIZE; i++)
        std::cin>>arr[i];
    for(int i = 0; i<SIZE; i++)
        std::cin>>arr_sorted[i];
    for(int i = 0; i<SIZE; i++)
        std::cin>>str_arr[i];
    for(int i = 0; i<SIZE; i++)
        std::cin>>str_arr_sorted[i];

    std::cout<<max(arr,SIZE)<<std::endl;
    std::cout<<min(arr,SIZE)<<std::endl;
    std::cout<<avg(arr,SIZE)<<std::endl;
    std::cout<<total(arr,SIZE)<<std::endl;
    // insert_to_pos(arr,SIZE, 150, 6);

    // insert_to_sorted(arr_sorted,SIZE,54);
    for(int i = 0; i<SIZE; i++)
        std::cout<<arr_sorted[i]<<" ";
    std::cout<<"\n";

    std::cout<<binary_search(arr_sorted, SIZE, 87)<<std::endl;

    // for(int i = 0; i<SIZE; i++)
    //     std::cout<<arr[i]<<" ";

    return 0;
}


int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]<min)
            min = arr[i];
    }
    return min;
}

double avg(int arr[], int size)
{
    int sum = total(arr,size);
    return double(sum)/double(size);
}

int total(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void insert_to_pos(int* arr,int size, int item, int pos)
{
    for(int i = size; i >= pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = item;
    SIZE += 1;
}

void insert_to_sorted(int* arr, int size, int item)
{
    int pos;

    for(int i = 0; i < size; i++)
    {
        if(arr[i]>=item)
        {
            pos = i+1;
            break;
        }
    }
    insert_to_pos(arr, size, item, pos);
}

void delete_item_at_index(int *arr, int size, int pos)
{
    for(int i = pos - 1; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    SIZE-=1;
}

void delete_by_item(int *arr, int size, int item)
{
    int pos = linear_search(arr, size, item);

    if(pos == -1)
    {
        std::cout<<"ITEM NOT FOUND"<<std::endl;
        return;
    }
    delete_item_at_index(arr, size, pos);
}

int linear_search(int *arr, int size, int item)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == item)
        {
            return (i+1);
        }
    }
    return -1;
}

void bubble_sort(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        int temp;
        for (int j = 0; j < i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } 
    }
}

int binary_search(int *arr, int size, int item)
{
    int mid;
    int beg = 0;
    int end = size;

    while(beg<=end)
    {
        int mid = (beg+end)/2;
        if(item == arr[mid])
            return mid+1;
        else if(item > arr[mid])
            beg = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}