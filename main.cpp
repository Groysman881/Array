#include <iostream>
#include"array.h"
using namespace std;

int main(int argc, char *argv[])
{
    Array<int> arr;
    arr.push_back(12);
    arr.push_back(14);
    arr.push_back(15);
    arr.insert(10,1);
    Array<int> arr1(arr);
    cout<<"Check"<<arr[0]<<endl;
    return 0;
}
