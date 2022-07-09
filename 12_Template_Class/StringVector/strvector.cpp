#include "strvector.h"
#include<stdexcept>

StrVector::StrVector() : 
    logicalSize(0), allocatedSize(kInitialSize)
{
    elems = new std::string[allocatedSize];
}

StrVector::~StrVector() {
    delete[] elems;
}

// 逻辑大小为数组的大小，分配大小为真实分配的空间的大小
StrVector::StrVector(size_type n, const std::string& val) :
    logicalSize(n), allocatedSize(2 * n)
{
    elems = new std::string[allocatedSize];
    // 将数组全部用val的值填充
    std::fill(begin(), end(), val);
}

StrVector::iterator StrVector::begin() {
    return elems;
}

StrVector::iterator StrVector::end() {
    return elems + size();
}

StrVector::size_type StrVector::size() const {
    return logicalSize;
}

bool StrVector::empty() const {
    return size() == 0;
}

std::string& StrVector::operator[] (size_type index) {
    return *(begin() + index);
}

std::string& StrVector::at(size_type index) {
    if(index >= size()) {
        throw std::out_of_range("Out of bounds access of vector");
    }
    return *(begin() + index);
}

StrVector::iterator StrVector::insert(iterator pos, const std::string& elem) {
    size_type index = pos - begin();
    if(size() == allocatedSize) {
        grow();
    }
    pos = begin() + index;
    // 将从pos开始到end的数据拷贝到end后面1位的位置
    // 因为拷贝的话是从最后一位开始的，因此指定的位置是拷贝结束的位置
    std::copy_backward(pos, end(), end()+1);
    *pos = elem;
    ++logicalSize;
    return pos;
}

void StrVector::grow() {
    iterator new_elems = new std::string[2 * allocatedSize];
    // 在空间不够的情况下，将原有的数据复制到新空间
    std::copy(begin(), end(), new_elems);
    delete elems;
    allocatedSize *= 2;
    elems = new_elems;
}

void StrVector::push_back(const std::string& elem) {
    // 调用前面定义的insert函数
    insert(end(), elem);
}