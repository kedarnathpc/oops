#include <bits/stdc++.h>
using namespace std;

// friend function 
// -> friend function is not a member function of a class to which it is a friend 
// -> declared in the class using the friend keyword
// -> as it is not a member function, it can be declared in public or private in a class    
// -> it must be defined outside of the class to which it is defined 
// -> can access any member of the class to which it is friend but cannot access directly
//    why not directly ?
//    because then we cannot determine for which class the variables belong to 
// -> it has no caller object 
// -> it should not be defined with membership label 
// -> it voilates the principle of private data members 

class Complex {
private:
    int a, b;

public:
    void setData (int x, int y) {
        a = x, b = y;
    }

    void showData () {
        cout << "a : " << a << " b : " << b << endl;
    }

    friend void add (Complex);
};

void add (Complex C) {
    cout << C.a + C.b << endl;
}

// -> friend function can become friend to one or more classes 
// -> it can access data members of multiple of classes

class B; // forward declaration

class A {
private:
    int a;
public:
    void setData (int x) {
        a = x;
    }

    friend void sum (A, B);
};

class B {
private:
    int b;
public:
    void setData (int x) {
        b = x;
    }

    friend void sum (A, B);
};

void sum (A obj1, B obj2) {
    cout << "sum is : " << obj1.a + obj2.b << endl;
}


// -> overloading of binary operators as a friend function 

class Account {
private:
    int balance;

public:
    void setData(int B) {
        balance = B;
    }

    void showData () {
        cout << "balance : " << balance << endl;
    }

    friend Account operator + (Account, Account);
};

Account operator + (Account A, Account B) {
    Account temp;
    temp.balance = A.balance + B.balance;
    return temp;
}


// -> overloading of unary operator as a friend function

class Integer {
private:
    int i;

public:
    void setData(int i) {
        this->i = i;
    }

    void showData() {
        cout << "i = " << this->i << endl;
    }

    friend Integer operator - (Integer I);
};

Integer operator - (Integer I) {
    Integer temp;
    temp.i = -I.i;
    return temp;
}



// -> overloading of insertion and extraction operator using a friend function
// -> cin >> obj1 is same as cin operator >> (obj1)
// -> cin is an object, for this object internal overloading of >> operator is done
//    based on which type of data we pass (int, char etc)
//    but internally it is not defined to take an non primitive data type


class Text {
private:
    string s;

public:
    void setData (string s) {
        this->s = s;
    }

    void showData () {
        cout << "string : " << s << endl;
    }

    friend ostream& operator << (ostream&, Text);
    friend istream& operator >> (istream&, Text&);
};

ostream& operator << (ostream& dout, Text t) {
    dout << t.s << endl;
    return dout;
}

istream& operator >> (istream& din, Text &t) {
    din >> t.s;
    return din;
}



// -> member function of one class can become friend to another class
// -> we want to make the member functions of class X friend to class Y

class X {
public:
    void fun () {}
    void foo () {}
};

class Y {
    // to make all the member functions of class X friend to class Y
    // make the class X friend to class Y
    friend class A;

    // to separately make member funtions of class X friend to class Y
    // then you have to declare each funtion separately using the scope resolution operator
    friend void X:: fun () {}
};


int main () {
    Complex C1, C2;
    C1.setData(3, 5);
    add(C1);

    A obj1;
    B obj2;
    obj1.setData(4);
    obj2.setData(4);
    sum(obj1, obj2);

    Account A1, A2, A3;
    A1.setData(1000);
    A2.setData(3000);
    A3 = A1 + A2;               // A3 = operator+(A1, A2)
    A3.showData();

    Integer I1, I2;
    I1.setData(4);
    I2 = -I1;
    I2.showData();

    Text T1;
    cout << "enter a string : ";

    // cin is an object, >> is an member function which can be internally of multiple versions, 
    // C1 is a non primitive argument, 
    // we can also pass primitive types 
    cin >> T1;                 
    cout << "the string is : ";
    cout << T1;                // operator << (cout, T1);
    return 0;
}