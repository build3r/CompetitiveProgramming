// This function demonstrates a generic stack.
#include <iostream>
using namespace std;
const int SIZE = 10;

template <class StackType> class stack {
StackType stck[SIZE];
int tos;
public:
stack() { tos = 0; }
void push(StackType ob)
{
if(tos==SIZE) {
cout << "Stack is full.\n";
return;
}
stck[tos] = ob;
tos++;
}
StackType pop()
{
if(tos==0) {
cout << "Stack is empty.\n";
return 0; // return null on empty stack
}
tos--;
return stck[tos];
}
};


int main()
{
// Demonstrate character stacks.
stack<char> s1, s2; // create two character stacks
int i;
s1.push('a');
s2.push('x');
s1.push('b');
s2.push('y');
s1.push('c');
s2.push('z');
for(i=0; i<3; i++) cout << "Pop s1: " << s1.pop() << "\n";
for(i=0; i<3; i++) cout << "Pop s2: " << s2.pop() << "\n";
// demonstrate double stacks
stack<double> ds1, ds2; // create two double stacks
ds1.push(8.54);
ds2.push(2.2);
ds1.push(3.3);
ds2.push(4.4);
ds1.push(5.5);
ds2.push(6.6);
for(i=0; i<3; i++) cout << "Pop ds1: " << ds1.pop() << "\n";
for(i=0; i<3; i++) cout << "Pop ds2: " << ds2.pop() << "\n";
return 0;
}
