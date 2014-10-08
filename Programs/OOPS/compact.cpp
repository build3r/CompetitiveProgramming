#include <iostream>
using namespace std;
template <class X> void compact(
X *items, // pointer to array to be compacted
int count, // number of items in array
int start, // starting index of compacted region
int end) // ending index of compacted region
{
register int i;
for(i=end+1; i<count; i++, start++)
items[start] = items[i];
/* For the sake of illustration, the remainder of
the array will be zeroed. */
for( ; start<count; start++) items[start] = (X) 0;
}
int main()
{
int nums[7] = {0, 1, 2, 3, 4, 5, 6};
double str[8] ={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8} ;
int i;
cout << "Here is uncompacted integer array: ";
for(i=0; i<7; i++)
cout << nums[i] << ' ';
cout << endl;
cout << "Here is uncompacted string: ";
for(i=0; i<8; i++)
cout << str[i] << ' ';
cout << endl;
compact(nums, 7, 2, 4);
compact(str, 8, 5, 8);
cout << "Here is compacted integer array: ";
for(i=0; i<7; i++)
cout << nums[i] << ' ';
cout << endl;
cout << "Here is compacted string: ";
for(i=0; i<8; i++)
cout << str[i] << ' ';
cout << endl;
return 0;
}
