#include "MyVector.h"

template <class T>
class Matrix : public Vector<Vector<T>>
{
public:
    Matrix() : Vector<Vector<T>>() {};
    Matrix(int _r) : Vector<Vector<T>>(_r)
    {
        if (_r < 0)
            throw length_error("incorrect size");
        for (int i = 0; i < _r; i++)
            this->x[i].Init(_r - i);
    };

    Matrix(const Matrix& _m)
    {
        this->length = _m.length;
        this->x = new Vector<T>[this->length];
        for (int i = 0; i < this->length; i++)
            this->x[i] = _m.x[i];
    };
    Matrix(const Vector<Vector<T>>& _m) : Vector<Vector<T>>(_m)
    {
        for (int i = 0; i < this->Length(); i++)
        {
            Vector<T> result(_m.x[i]);
            this->x[i] = result;
        }
    };
    
    Matrix(int _r, T a) : Matrix<T>(_r)
    {
        for (int i = 0; i < _r; i++)
            for (int j = 0; j < _r - i; j++)
                this->x[i][j] = a;
    };

    int get_rows()
    {
        return this->Length();
    };

    Matrix<T>& operator =(Matrix<T>& _m)
    {
        if (this == &_m)
            return *this;

        for (int i = 0; i < this->length; i++)
            this->x[i].~Vector();
        delete[] this->x;

        this->length = _m.Length();

        this->x = new Vector<T>[this->length];

        for (int i = 0; i < this->length; i++)
            this->x[i] = _m[i];
    };

    Vector<T>& operator [](const int i)
    {
        if (i > this->length || i < 0)
            throw length_error("Incorrect index");
        return this->x[i];
    };
    Matrix<T> operator +(Matrix<T>& _m)
    {
        if (this->length != _m.Length())
            throw "Matrices' sizes aren't equal";

        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] + _m[i];

        return result;
    };
    Matrix<T> operator -(Matrix<T>& _m)
    {
        if (this->length != _m.Length())
            throw "Matrices' sizes aren't equal";

        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] - _m[i];

        return result;
    };
    bool operator ==(const Matrix<T>& _m) const
    {
        if (this->length != _m.Length())
            return false;
        else
            for (int i = 0; i < this->length; i++)
                if (this->x[i] != _m.x[i])
                    return false;
        return true;
    };
    bool operator !=(const Matrix<T>& _m) const
    {
        return !((*this) == _m);
    };
    Matrix<T> operator *(Matrix<T>& _m)
    {
        if (this->length != _m.Length())
            throw "Can't multiply";

        Matrix<T> result(this->length);
        T t;
        for (int i = 0; i < this->length; i++)
            for (int j = 0; j < this->length - i; j++)
            {
                t = 0; // i = 1; j = 1;
                for (int k = i; k < j + i + 1; k++)
                    t += x[i][k - i] * _m[k][j - k + i];
                result[i][j] = t;
            }

        return result;
    }
    Matrix<T> operator *(T n)
    {
        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] * n;

        return result;
    };

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const Matrix<T1>& A)
    {
        for (int i = 0; i < A.Length(); i++)
        {
            for (int k = 0; k < i; k++)
                ostr << "0 ";
            for (int j = 0; j < A.x[i].Length(); j++)
                ostr << A.x[i][j] << " ";


            ostr << endl;
        }

        return ostr;
    };
    template <class T1>
    friend istream& operator >> (istream& istr, Matrix<T1>& A)
    {
        for (int i = 0; i < A.Length(); i++)
            istr >> A.x[i];
        return istr;
    };

};


/*template <class T>
class Matrix
{
protected:
	Vector<T>* m;
	int rows;
public:
    Matrix() : rows(0), m(0) {};
    Matrix(int _r);
    Matrix(const Matrix& _m);
    Matrix(int _r, int a);

    virtual ~Matrix() {};

    int get_rows() const { return rows; }

    Matrix<T>& operator =(Matrix<T>& _m);

    Vector<T>& operator [](const int i);
    Matrix<T> operator +(Matrix<T>& _m);
    Matrix<T> operator -(Matrix<T>& _m);
    bool operator ==(const Matrix<T>& _m) const;
    bool operator !=(const Matrix<T>& _m) const;
    Matrix<T> operator *(Matrix<T>& _m);
    Matrix<T> operator *(T n);
    //Matrix<T> operator /(Matrix<T>& _m);
    
    template <class T1>
    friend ostream& operator<< (ostream& ostr, const Matrix<T1>& A);
    template <class T1>
    friend istream& operator >> (istream& istr, Matrix<T1>& A);
    
};


template<class T>
Matrix<T>::Matrix(int _r)
{
    if (_r < 0)
        throw length_error("incorrect size");
    m = new Vector<T>[_r];
    for (int i = 0; i < _r; i++)
        m[i] = Vector<T>(_r - i);
    rows = _r;
}

template<class T>
inline Matrix<T>::Matrix(const Matrix& _m)
{
    rows = _m.get_rows();
    m = new Vector<T>[rows];
    for (int i = 0; i < rows; i++)
        m[i] = _m.m[i];
}

template<class T>
inline Matrix<T>::Matrix(int _r, int a)
{
    if (_r < 0)
        throw length_error("incorrect size");
        m = new Vector<T>[_r];
    for (int i = 0; i < _r; i++)
    {
        m[i] = Vector<T>(_r - i);
        for (int j = 0; j < _r - i; j++)
            m[i][j] = a;
    }
    rows = _r;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>& _m)
{
    if (this == &_m)
        return *this;

    for (int i = 0; i < rows; i++)
        m[i].~Vector();
    delete[] m;

    rows = _m.get_rows();

    m = new Vector<T>[rows];

    for (int i = 0; i < rows; i++)
        m[i] = _m[i];
}

template<class T>
Vector<T>& Matrix<T>::operator[](const int i)
{
    if (i > rows || i < 0)
        throw length_error("Incorrect index");
    return m[i];
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& _m)
{
    if (rows != _m.get_rows())
        throw "Matrices' sizes aren't equal";

    Matrix<T> result(rows);
    for (int i = 0; i < rows; i++)
        result[i] = m[i] + _m[i];

    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& _m)
{
    if (rows != _m.get_rows())
        throw "Matrices' sizes aren't equal";

    Matrix<T> result(rows);
    for (int i = 0; i < rows; i++)
        result[i] = m[i] - _m[i];

    return result;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T>& _m) const
{
    if (rows != _m.get_rows())
        return false;
    else
        for (int i = 0; i < rows; i++)
            if (m[i] != _m.m[i])
                return false;
    return true;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& _m) const
{
    return !((*this) == _m);
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& _m)
{
    if (rows != _m.get_rows())
        throw "Can't multiply";

    Matrix<T> result(rows);
    T t;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows - i; j++)
        {
            t = 0; // i = 1; j = 1;
            for (int k = i; k < j + i + 1; k++)
                t += m[i][k - i] * _m[k][j - k + i];
            result[i][j] = t;
        }

    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T n)
{
    return Matrix<T>();
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const Matrix<T1>& A)
{
    for (int i = 0; i < A.get_rows(); i++)
    {
        for (int k = 0; k < i; k++)
            ostr << "0 ";
        for (int j = 0; j < A.m[i].Length(); j++)
            ostr << A.m[i][j] << " ";

            
        ostr << endl;
    }

    return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, Matrix<T1>& A)
{
    for (int i = 0; i < A.get_rows(); i++)
        istr >> A.m[i];
    return istr;
}*/