#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H //personal note - prevents double inclusion of header file

#include<stdexcept>//personal note - for std::out_of_range
#include<cstdlib>//personal note - for malloc and free

template<typename T>
class DynamicArray {
    T* data; 
    size_t capacity;  //personal note - size_t is a data type for sizes, typically an unsigned integer;
    size_t size;

    void grow(){
        size_t newcap = capacity ? capacity*2:4;//personal note - good practice to not change used variable before the changes are done without errors
        T* newdata = static_cast<T*>(std::malloc(newcap*sizeof(T)));
        if(!newdata) throw std::bad_alloc();

        try{
            for(size_t i=0;i<size;i++){
                new(&newdata[i]) T(std::move(data[i]));//personal note - 'new' other syntax used when you want to specify the memory location 
                data[i].~T();
            }
        }catch(...){
            std::free(newdata);
            throw;
        }
        T* olddata = data;
        data = newdata;
        capacity = newcap;
        std::free(olddata);
    }
    public:
    DynamicArray():data(nullptr),capacity(0),size(0){}
    ~DynamicArray(){
        for(size_t i=0;i<size;i++){
            data[i].~T();
        }
        std::free(data);
    }
    void push_back(const T& val){
        if(size==capacity) grow();
        new(&data[size]) T(val);
        size++;
    }
    
    size_t Size() const {return size;}
    
    T& operator[](size_t at){
        if(at>=size) throw std::out_of_range("DynamicArray::operator[]");
        return data[at];
    }

    const T& operator[](size_t at) const {
        if(at>=size) throw std::out_of_range("DynamicArray::operator[]");
        return data[at];
    }

};

#endif