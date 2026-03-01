#pragma once

class Vector{
    int len = 0;
    int* vector = nullptr;

public:
    Vector(){}
    Vector(int n, int q = 0);
    Vector(int len, int* vec);

    Vector(const Vector& vec);
    Vector(Vector&& vec) noexcept;

    int Len() const {return len;}
    int Dim() const {return len;}

    void Print();


    int& operator[] (int i);
    const int& operator[] (int i) const;

    bool operator = (const Vector& vec);

    ~Vector(){delete[] vector;}
};
