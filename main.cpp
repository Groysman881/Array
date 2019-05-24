#include <iostream>
#include"array.h"
using namespace std;

int main(int argc, char *argv[])
{
    Array<int> arr;
    arr.push_back(12);
    arr.push_back(14);
    arr.push_back(15);
    arr.insert(10,0);
    arr.push_back(156);
    Array<float> arr2;
    arr2.push_back(12.3);
    arr.print();
    Array<int> arr1(arr);
    arr1.print();
    cout<<"Check"<<arr[0]<<endl;
    arr1.erase(0);
    arr1.erase(0);
    arr1.erase(0);
    cout<<"PRINT"<<endl;
    arr1.print();
    cout<<"Check"<<arr1[0]<<endl;
    cout<<"CHECK"<<endl;
    Array<int>::Iterator iter1(arr.begin());
    ++iter1;
    cout<<*iter1<<endl;
    arr.print();
    return 0;
}
