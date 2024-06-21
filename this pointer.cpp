#include <bits/stdc++.h>
using namespace std;


// object pointer 
// -> a pointer contains address of an object is called object pointer 
// -> this is a keyword
// -> this is a local object pointer in every instance member function containing address of the caller object 
// -> this pointer can not be modified 
// -> it is used to refer caller object in member function


class Box {
private:
    int l, b, h;
public:
    void setDimension(int l, int b, int h) {
        this->l = l, this->b = b, this->h = h;
    }

    void showDimension() {
        cout << "l : " << l << " b : " << b << " h : " << h << endl;
    }
};


int main () {
    Box smallBox;
    smallBox.setDimension(1,2,3);
    smallBox.showDimension();

    Box *p;
    p = &smallBox;
    p->showDimension();
    return 0;
}