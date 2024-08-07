#include<iostream>
using namespace std;

// we need to check nearest greater element towards right
// so we need to check from the immediate right of the element and then move towards the end of the arrar
// so to compare the immediate next element first, it should be on the top of the stack (as LIFO)
// so, we will push the last element of the array first