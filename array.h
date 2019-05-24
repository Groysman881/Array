#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>



template<typename T>
class Array
{
public:
    struct Iterator{
        T* mas;
        Iterator():mas(nullptr){}
        Iterator(const Iterator &iter1):mas(iter1.mas){}
        Iterator(T* _begin):mas(_begin){}
        T& operator*(){return *mas;}
        T& operator++(){mas++;return *mas;}
        T& operator--(){mas--;return *mas;}
        bool operator!=(const Iterator &iter1){return mas != iter1.mas;}
    };

    Array():ptr(nullptr),size(0),capacity(0){}
    ~Array(){
        delete(ptr);
    }
    Array(const Array<T> &arr){
        if(arr.ptr == nullptr){
            ptr = nullptr;
            size = 0;
            capacity = 0;
        }
        else{
            ptr = new T [arr.capacity];
            for(int i = 0;i < arr.size;i++){
                new (ptr + i) T (*(arr.ptr + i));
            }
            size = arr.size;
            capacity = arr.capacity;
        }
    }

    T& operator[](size_t index){
        try
        {
            if(index < size){
                return *(ptr + index);
            }
            throw 1;
        }
        catch(int a)
        {
            std::cout<<"Out of bounds"<<std::endl;
            exit(0);
        }
    }

    void insert(T element,size_t pos){
        if(pos < size){
            if(size == capacity){
                capacity*=2;
                std::cout<<capacity<<std::endl;
                T* buf = new T [capacity];
                for (size_t i = 0;i < pos - 1;i++){
                    new (buf + i) T (*(ptr + i));
                }
                new (buf + pos) T (element);
                for(size_t i = pos + 1;i < size;i++){
                    new (buf + i) T (*(ptr + pos - 1))  ;
                }
                delete(ptr);
                ptr = buf;
            }
            else{
                for(int i = size;i >= pos + 1;i--){
                    new (ptr + i) T (*(ptr + i - 1));
                }
                new (ptr + pos) T (element);
            }
        }
        else{
            std::cout<<"Out of Bounds!"<<std::endl;
            return;
        }
        size++;
    }
    void erase(size_t pos){
        if(pos < size && size != 0){
            for(size_t i = pos;i < size - 1;i++){
                new (ptr + i) T (*(ptr + i + 1));
            }
            size--;
            while(size < capacity/2){
                std::cout<<"?????"<<std::endl;
                capacity/=2;
                T* buf = new T[capacity];
                for(size_t i = 0;i < size;i++){
                    new (buf + i) T (*(ptr + i));
                }
                delete(ptr);
                ptr = buf;
            }
        }
        else if(size != 0){
            std::cout<<"Out of bounds"<<std::endl;
            return;
        }
        else{
            std::cout<<"Array is empty"<<std::endl;
            return;
        }
    }
    void push_back(T element){
        if(size == capacity){
            if(size == 0){
                ptr = new T[1];
                capacity = 1;
            }
            else{
                capacity*=2;
                T* buf = new T[capacity];
                for(int i = 0;i < size;i++){
                    new (buf + i) T (*(ptr + i));
                }
                delete(ptr);
                ptr = buf;
            }
        }
        size++;
        new (ptr + size - 1) T (element);
    }
    size_t getSize(){return size;}
    Iterator begin(){
        Array<T>::Iterator _begin(ptr);
        return _begin;
    }
    Iterator end(){
        Array<T>::Iterator _end(ptr + size);      
        return _end;
    }
    void print(){
        for(auto i : *this){
            std::cout<<i;
        }
        std::cout<<std::endl;
    }
private:
    T* ptr;
    size_t size;
    size_t capacity;
};
#endif // ARRAY_H
