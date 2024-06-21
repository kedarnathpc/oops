#include <bits/stdc++.h>
using namespace std;

// pure virtual function 
// -> a do nothing function is pure virtual function (no definition)
// -> a class which has a do nothing function, object cannot be created 
// -> to use such class we have to create a child class and we have to override the function 
// -> or create a child class and declare the function as virtual again

// a class in which there is atleast one pure virtual function, is called an abstract class
// and object cannot be created of such class 
// why abstrict class ?
// suppose a student class, faculty class 
// common class -> person class (abstract class) (generalisation)

class Person {
public:
    virtual void fun () = 0; // pure virtual function : do nothing function
};

class Student {
public:
    virtual void fun () = 0;
};
int main () {
    return 0;
}