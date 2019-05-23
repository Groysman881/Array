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
    Array<int> arr1(arr);
    cout<<"Check"<<arr[0]<<endl;
    arr1.erase(0);
    cout<<"Check"<<arr1[0]<<endl;
    cout<<"CHECK"<<endl;
    Array<int>::Iterator iter(arr.begin());
    int a = *iter;
    cout<<a;
    //for(auto i: arr){
    //    cout<<i;
    //}
    return 0;
}
