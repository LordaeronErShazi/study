#include<iostream>
using namespace std;
template<class T>
class SqList
{
private:
    T *data;
    int capacity,n;
    bool realloc();
public:
    SqList(int cap = 100)
    {
        data = new T[cap];
        capacity = cap;
        n = 0;
    }
    bool _insert(int i,T e);
    bool _remove(int i);
    bool _push_back(T e);
    bool _insert_front(T e);
    bool _get(int i,T &e);
    bool _set(int i,T e);
    bool _remove_front();
    bool _pop_back();
    int _size()
    {
        return n;
    }
};
template<class T>
bool SqList<T>::_insert(int i,T e)
{
    if(i < 1||i > n+1)
        return false;
    if(n >= capacity)
    {
        if(!realloc())
            return false;
    }
    for(int j = n;j > i;j--)
    {
        data[j] = data[j-1];
    }
    data[i-1] = e;
    n++;
}
template<class T>
bool SqList<T>::_remove(int i)
{
    if(i < 1||i > n)
        return false;
    T *p,*q;
    p = &(data[i]);
    q = data + n - 1;
    for(;p <= q;++p)
        *(p - 1) = *p;
    n--;
    return true;
}
template<class T>
bool SqList<T>::_push_back(T e)
{
    if(n > capacity)
        if(!realloc()) return false;
    data[n] = e;
    n++;
    return true;
}
template<class T>
bool SqList<T>::_insert_front(T e)
{
    if(n > capacity)
        if(!realloc()) return false;
    for(int j = n+1;j >= 1;j++)
    {
        data[j] = data[j-1];
    }
    data[0] = e;
    n++;
    return true;
}
template<class>
bool SqList<T>::_get(int i,T &e)
{
    if(i < 1||i > n)
        return false;
    e = data[i-1];
    return true;
}
template<class T>
bool SqList<T>::_set(int i,T e)
{
    if(i < 1||i > n)
        return false;
    data[i-1] = e;
    return true;
}
template<class T>
bool SqList<T>::realloc()
{
    T *p = new T[2*capacity];
    if(!p) return false;
    for(int i = 0;i < capacity;i++)
    {
        p[i] = data[i];
    }
    capacity *= 2;
    delete[] data;
    data = p;
    return true;
}
template<class T>
bool SqList<T>::_remove_front()
{
    if(n==0)
        return false;
    for(int j=0;j < n-1;j++)
    {
        data[j] = data[j+1];
    }
    n--;
    return true;
}
template<class T>
bool SqList<T>::_pop_back()
{
    if(n==0)
        return false;
    n--;
    return true;
}
