#include <iostream>
#include "sol.cpp"

using namespace std;

int main()
{
  cout << "Making array\n" << endl;
  int* ar=new int[10];
  for(int i=0;i<10;++i){
          ar[i]=((i%2==0)?(i*2-10):(i+10));
      }
  cout << "It stops\n" << endl;
  cout << "The array:\n" << endl;
  for(int i=0;i<10;++i){
          cout<<ar[i]<<' ';
      }
  cout << "\nSorting\n" << endl;
  IHoaraSort(ar,10);
  cout << "The sorted array:\n" << endl;
  for(int i=0;i<10;++i){
          cout<<ar[i]<<' ';
      }
  system("pause");
  return 0;
}
