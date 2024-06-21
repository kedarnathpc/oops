#include <bits/stdc++.h>
using namespace std;


// Static Memory Allocation
// -> compile time allocation
// -> cannot be changed (increased or decreased) when program is running
// -> memory allocation is done when program is started running
// -> no flexibility

// Dynamic Memory Allocation : runtime allocation 

int main () {

    // new : to allocate memory of a type and return its base address
    int *p = new int;
    float *q = new float;
    float *r = new float[10];

    // delete : to release memory allocated by DMA declaration
    delete p;
    delete q;
    delete []r;
    return 0;
}