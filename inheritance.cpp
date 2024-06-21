#include <bits/stdc++.h>
using namespace std;

// inheritance
// -> class is used to describe properties and behaviour of an object
// -> property has names and values, behaviour means actions

// -> let us assume that we want to represent a car 
// -> properties : price, fuel type, engine, colour, capacity
// -> methods : setPrice(), setFuelType(), setEngine(), setColour(), setCapacity()
//              getPrict(), getFuelType(), getEngine(), getColour(), getCapacity()
// -> to represent a sports car 
// -> additional properties : alarm, navigator, safeGuard (but it is also a car)
// -> additional methods : setAlarm(), setNavigator(), setSafeGuard()
//                         getAlarm(), getNavigator(), getSafeGuard()
// -> so we have to link the sportscar to car, which will inherit all the properties of car 
//    and also have the additional properties
// -> it is a process of inheriting properties and behaviours of existing class into new class 
// -> existing class = old class = parent class = base class 
// -> new class = child class = derived class 

// type of inheritance
// 1. single inheritance 
//    -> one parent class and one child class 
class A {};
class B : public A {};

// 2. multilevel inheritance
//    -> parent -> child -> child
class C {};
class D : public C {};
class E : public D {};

// 3. multiple inheritance
//    -> many parent class -> one child class 
class F {};
class G {};
class H : public F, public G {};

// 4. hierarchical inheritance
//    -> one parent and multiple child classes
class I {};
class I1 : public I {};
class I2 : public I {};

// 5. hybrid inheritance
//    -> combination of multiple types 

// visibility modes 
// 1. private : accessible to only to its own class 
// 2. protected : inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
// 3. public : accessible outside of class also

// types of users of a class 
// -> user 1 will create object of your class
// -> user 2 will derived class from your class 

// when you create a class which has private data members and private methods 
// Availability : when you create object of such class,
//                memory is allocated to private data members and private methods,
//                but object cannot access them, the data is available to them
//                but cannot access them/
//                class methods can use the private methods inside the class,
//                but cannot be used by an object of that class. 
// Accessibility : when you also have access to such private data member and methods

// -> visibility : 
//    1. private : members of base class will not be accessible to derived class and will be inherited as private
//    2. protected : members of base class declared as protected will be accessible to derived class and will be inherited as protected 
//    3. public : members of base class are accessible to derived classses and will be inherited as private / protected / public (as declared in base class)

// is-a relationship
// -> Association
//    - Aggregation
//    - Composition
//    - Inheritance
//         -> banna (child : specific) is a fruit (parent : more generalised)
// -> is a relationship is always implemented as a public inheritance
//    but why ?
//    public servies provided by the parent class to its own object,
//    child class also wishes to use these services to its own objects
// -> when to use private and protected inheritance ?
//    opposite of is-a relationship, and also to provide encapsulation 


// constructors in inheritance
// -> we know that constructor is invoked implicitly when as object is created
// -> in inheritance, when we create object of derived class, what will happen ?
//    both classes constructor will be called
// -> child class constructor calls the parent class default constructor
//    first the parent class constructor will execute then the child class constructor will execute
// -> calling order : from child to parent
// -> executing order : from parent to child
// -> if we create our constructor in parent class, then the child class constructor searches for a default constructor to call
//    but it does not exist as we made our own constructor,
//    so we have create constructor in child class also and write code to call the parent class constructor passing the necessary arguments

// destructors in inheritance
// -> child class destructor will execute first then at the ending of destructor,
// -> parent destructor will be called
// -> if we don't write code for destructors, compiler will do it in the code block of child destructor 

class J {
    int a;
public:
    J (int A) {
        a = A;
    }

    ~J () {}
};

class K : public J {
    int b;
public:
    K (int x, int y) : J(x) {
        b = y;
    }

    ~K () {}
};


int main () {
    K obj(3, 5);
    return 0;
}