#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array
{
public:
    T* ptr;
    size_t size;
    size_t capacity;

    class Iterator
    {

    };

    Array(){
        std::cout<<"Check"<<std::endl;
        ptr = new T [1];
        size = 1;
        capacity = 1;
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
                new(ptr + i) T *(arr.ptr + i);
            }
            size = arr.size;
            capacity = arr.capacity;
        }
    }

    T operator[](size_t index){
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
    void operator=(const Array<T> &arr){

    }
    void insert(T element);
    void erase(T element);
    void push_back(T element){
        if(size == capacity){
            if(size == 0){
                ptr = new T(1);
                std::cout<<"Check"<<std::endl;
                capacity = 1;
            }
            else{
                capacity = 2 * capacity;
                T* buf = new T(capacity);
                for(int i = 0;i < size;i++){
                    new(buf + i) T *(ptr + i);
                }
                delete(ptr);
                ptr = buf;
            }
        }
        size++;
        *(ptr + size - 1) = element;
    }
};

#endif // ARRAY_H
