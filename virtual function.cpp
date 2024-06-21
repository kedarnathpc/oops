#include <bits/stdc++.h>
using namespace std;

// base class pointer
// -> base class pointer can point to the object of any of its descendant class 
// -> but its converse is not true

class A {
public:
    virtual void f1 () {} // to make late binding of this function
};

class B : public A {
public:
    void f1 () {}
};

// virtual function working concept
// -> if for any class there is atleast one virtual function
//    then the compiler will declare a variable in the class by itself (*_vptr)
// -> if the class is inherited to the child class, then it will also inherit the vptr pointer (only 1 vptr exists) 
// vtable : a static array of virtual funtion pointers
//          each class will have its own vtable
// vptr : pointer pointing to the starting address of this vtable 
// when compiler does early binding it considers the pointer type
// but in runtime late binding pointer considers the content it pointes to (vptr-> vtable)

class C {
public:
    void f1() {}    
    virtual void f2 () {}
    virtual void f3 () {}
    virtual void f4 () {}

    // vtable pointers : f2, f3, f4 
};

class D : public C {
public:
    void f1 () {}
    void f2 () {}
    void f4 (int x) {}

    // vtable pointers : f2, f3, f4 
};

int main () {
    A *p, o1;
    B o2;
    p = &o1; // or p = &o2
    p->f1(); // while binding the function to the pointer, we are saying to the compiler that 
             // don't look at the type of pointer, look at the content of the object
             // so f1() from B will be called

            // if f1() is not declared as virtual, then compiler will look at the type of the pointer 
            // and will bind the funtion to the A class, so f1() from A will be called 
    
    return 0;
}