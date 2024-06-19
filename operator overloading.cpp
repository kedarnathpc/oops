#include <bits/stdc++.h>
using namespace std;

// operator overloading
// -> when an operator is overloaded with multiple jobs
// -> way to implement compile time polymorphism
// -> any symbol can be used as a function name 
//    if it a valid operator in C language 
//    if it is preceded by operator keyword
// -> operators that cannot be overloaded are sizof, ?: (ternary)
// -> binary operator : 2 operands required, unary operator : 1 operand


class Complex {
private:
    int a, b;
public:
    void SetData (int x, int y) {
        a = x, b = y;
    }

    void showData () {
        cout << a << " " << b << endl;
    }

    Complex operator + (Complex C) {
        Complex temp;
        temp.a = a + C.a;
        temp.b = b + C.b;

        return temp;
    }

    Complex operator - () {
        Complex temp;
        temp.a = -a;
        temp.b = -b;

        return temp;
    }
};

// pre increment and post increment operator overloading
class Integer {
private:
    int a;

public:
    void setData (int x) {
        a = x;
    }

    void getData () {
        cout << "a : " << a << endl;
    }

    // pre increment operator 
    Integer operator ++ () {
        Integer temp;
        temp.a = ++a;
        return temp;
    }

    // post increment operator  
    // we have passed an additional argument because 
    //    as the function names are same and their behaviour is similar
    //    to distinguish between them we pass an additional argument for overloading
    
    Integer operator ++ (int) {
        Integer temp;
        temp.a = a++;
        return temp;
    }
};

int main () {
    Complex C1, C2, C3, C4;

    C1.SetData(1, 3);
    C2.SetData(4, 5);
    
    C3 = C1 + C2;
    C3.showData();

    C4 = -C1;
    C4.showData();

    Integer I1, I2, I3;
    I1.setData(5);

    I2 = ++I1;
    I2.getData();

    I3 = I1++;
    I1.getData();

    return 0;
}