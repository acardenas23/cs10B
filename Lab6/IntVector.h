#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector{
    public:
        IntVector();
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector();
        unsigned size() const; 
        unsigned capacity() const;
        bool empty() const;
        const int& at(unsigned index) const;
        void insert(unsigned index, int value);
        void erase(unsigned index);
        const int& front() const;
        int& front();//finish
        const int& back() const;
        int& back();//finish
        void assign(unsigned n, int value);//finish
        void push_back(int value);//finish
        void pop_back();
        void clear();
        void resize(unsigned size, int value);
        void reserve(unsigned n);

        //void expand();
        //void expand(unsigned amount);
        void print();
        

    private:
        unsigned _size;
        unsigned _capacity;
        int *data; //point to the index 0 of the IntVector
        void expand();
        void expand(unsigned amount);

};

#endif