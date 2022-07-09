#ifndef STRVECTOR
#define STRVECTOR

#include<string>
#include<algorithm>

class StrVector {
public:
    using iterator = std::string*;
    using size_type = size_t;
    const size_type kInitialSize = 2;
    StrVector();
    // 构造函数重载
    StrVector(size_type n, const std::string& val);
    ~StrVector();

    iterator begin();
    iterator end();

    size_type size() const;
    bool empty() const;

    std::string& operator[] (size_type index);
    std::string& at(size_type index);

    iterator insert(iterator pos, const std::string& elem);
    void push_back(const std::string& elem);

private:
    size_type logicalSize;
    size_type allocatedSize;
    std::string* elems;
    void grow();
};

#endif