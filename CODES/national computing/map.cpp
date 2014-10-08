// map::find
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['d']=200;

  it=mymap.find('b');
  mymap.erase (it);
  mymap.erase (mymap.find('d'));

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap['a'] << '\n';
  if(mymap.find('a')!=mymap.end())
  {std::cout << "empty" << '\n';}

  return 0;
}
