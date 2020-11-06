#pragma once

#include <iostream>

using namespace std;

template <class T>
class Vector
{
protected:
  int length;
  T* x;
public:
  //Vector<T>* vec;
  Vector();
  Vector(int rowsCount);
  Vector(int rowsCount, T* _v);
  Vector(int rowsCount, T _v);
  Vector(Vector<T>& _v);
  ~Vector();

  Vector<T> operator +(Vector<T>& _v);
  Vector<T> operator -(Vector<T>& _v);
  //Vector<T> operator *(Vector<T>& _v);
  //Vector<T> operator /(Vector<T>& _v);
  Vector<T>& operator =(Vector<T>& _v);
  T& operator[] (const int index);

  bool operator==(const Vector& _v)const; 
  bool operator!=(const Vector& _v) const; 

  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vector<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vector<T1> &A);

  int Length() const;
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
  length = 0;
  x = 0;
}
template <class T>
Vector<T>::Vector(int rowsCount)
{
    if (rowsCount < 0)
        throw length_error("incorrect index");
    length = rowsCount;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = 0;
}
template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
    if (rowsCount < 0)
        throw length_error("incorrect index");
  length = rowsCount;

  ///x = _v;

  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v[i];
}
template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
    if (rowsCount < 0)
        throw length_error("incorrect index");
  length = rowsCount;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v;
}
template <class T>
Vector<T>::Vector(Vector<T>& _v)
{
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
Vector<T>::~Vector()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}
template <class T>
Vector<T> Vector<T>::operator +(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
/*template <class T>
Vector<T> Vector<T>::operator *(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] * _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)

{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}*/
template <class T>
Vector<T>& Vector<T>::operator =(Vector<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}
template <class T>
T& Vector<T>::operator[] (const int index)
{
    if ((index < 0) || (index >= length))
        throw length_error("incorrect index");
    return x[index];

  /*if ((index >= 0) && (index < length))
    return x[index];
  return x[0];*/
}

template<class T>
inline bool Vector<T>::operator==(const Vector& _v) const
{
    if (((*this).Length() == _v.Length()))
    {
        for (int i = 0; i < _v.Length(); i++)
        {
            if ((*this).x[i] != _v.x[i])
                return false;
        }
        return true;
    }
    return false;
}

template<class T>
inline bool Vector<T>::operator!=(const Vector& _v) const
{
    return!(_v == (*this));
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template <class T>
int Vector<T>::Length() const
{
  return length;
}

