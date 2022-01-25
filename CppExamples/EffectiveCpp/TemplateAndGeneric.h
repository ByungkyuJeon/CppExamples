#pragma once

// Templates and Generic Example
//
// 1. typename's two different meanings
//
// when declaring template parameter, 'class' and 'typename' are same meaning.
// but when identifying nested dependent type name, typename must be used.
//
// wrong example
template <typename T>   
void print2nd(const T& container)
{
    if (container.size() >= 2) 
    {
        // compiler doesn't know what T::const_iterator is.
        // compiler doesn't treat this type as a type.
        T::const_iterator iter(container.begin());

        ++iter;
        int value = *iter;
        std::cout << value;
    }
}

// right example
//
// let the compiler to know what T::const_iterator is, using typename keyword
// T::const_iterator is a nested dependent type name
template<typename T>
void print2nd(const T& container, typename T::const_iterator iter) {}


// 2. Avoiding template code duplication
//
//
// example class bellow is going to duplicated depend on the template parameter, size.
// this is a inefficient code and there are several ways to fix this.
template<typename T, size_t size>
class TemplateAndGenericSquareMatrix
{
public:
    void invert() {}
};

// fixed example
//
// when type T is same, now they are sharing base class code
// so code duplication reduces
template<typename T>
class TemplateAndGenericSquareMatrix_Fixed_1_Base
{
public:
    TemplateAndGenericSquareMatrix_Fixed_1_Base(size_t sz, T* data) : size{ sz }, pData{ data }{}

    void invert(size_t sz) {}

private: 
    size_t size;
    T* pData;
};

template<typename T, size_t size>
class TemplateAndGenericSquareMatrix_Fixed_1_Derived : private TemplateAndGenericSquareMatrix_Fixed_1_Base
{
public:
    TemplateAndGenericSquareMatrix_Fixed_1_Derived() : TemplateAndGenericSquareMatrix_Fixed_1_Base<T>(size, data) {}

    void invert()
    {
        this->invert(size);
    }
    
private:
    T data[size * size];
};


// Receiving compatable types with member template
//
// if there are some compatable types with a class
// member template can be a good choice to use
template<typename T>
class TemplateAndGenericPlayer
{
public:
    // complie error occur when types are not implicitly castable
    template<typename U>
    void TemplateAndGenericPlayer(const TemplateAndGenericPlayer<U>& other) : pData{ other.get() } {}

    T* get() const
    {
        return pData;
    }

private:
    T* pData;
};