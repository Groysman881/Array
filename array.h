#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>

/*template<typename T>
class Iterator{
private:
    T* mas;
public:
    Iterator(){mas = nullptr;}
    Iterator(T* arr): mas(arr){};
    T operator*(){return (*mas);}
    Iterator<T>& operator++(){mas++;return *this;}
    bool operator!=(const Iterator<T> &iter1){return mas != iter1.mas;}
};*/

template<typename T>
class Array
{
public:
    class Iterator;
    T* ptr;   
    size_t size;
    size_t capacity;

    Array(){
        std::cout<<"Check"<<std::endl;
        ptr = nullptr;
        size = 0;
        capacity = 0;
    }
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
            for(int i = 0;i < size;i++){
                ptr = new (arr.ptr) T [size];
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
        if(pos <= size){
            if(size == capacity){
                capacity<<1;
                T* buf = new T [capacity];
                for (int i = 0;i < pos;i++){
                    new (buf + i) T (*(ptr + i));
                }
                new (buf + pos - 1) T (element);
                for(int i = pos;i < size;i++){
                    new (buf + i) T (*(ptr + pos - 1))  ;
                }
                delete(ptr);
                ptr = buf;
            }
            else if(size < capacity){
                for(int i = pos;i < size;i++){
                    new (ptr + pos + i) T (*(ptr + pos + i - 1));
                }
                new (ptr + pos - 1) T (element);
            }
        }
        else{
            std::cout<<"Out of Bounds!"<<std::endl;
            exit(0);
        }
        size++;
    }
    void erase(size_t pos){
        if(pos <= size){

        }
    }
    void push_back(T element){
        if(size == capacity){
            if(size == 0){
                ptr = new T[1];
                std::cout<<"Check"<<std::endl;
                capacity = 1;
            }
            else{
                capacity = 2 * capacity;
                T* buf = new T[capacity];
                for(int i = 0;i < size;i++){
                    new (buf + i) T (*(ptr + i));
                }
                std::cout<<buf[0]<<std::endl;
                delete(ptr);
                ptr = buf;
                std::cout<<ptr[0]<<std::endl;
            }
        }
        size++;
        *(ptr + size - 1) = element;
    }
    size_t getSize(){return size;}
    Iterator begin(){return ptr;}
    Iterator end(){return ptr + size;}

    class Iterator{
    private:
        T* mas;
    public:
        Iterator(T* _begin): mas(_begin){};
        T& operator*(){return (*mas);}
        Iterator& operator++(){mas++;return *this;}
        Iterator& operator--(){mas--;return *this;}
        bool operator!=(const Iterator &iter1){return mas != iter1.mas;}
    };

};



#endif // ARRAY_H
