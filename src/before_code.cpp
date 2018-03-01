#include <stdio.h>
#include <stdlib.h>
#incude <cstdio>
#include <fstream>
#include <iostream>
#include "sol.cpp"

using namespace std;

int main()
{
  cout << "Making array\n" << endl;
  FILE* fi=fopen("numbers.in","rb");

  int N=0;
  fread(&N, sizeof (int), 1, fi);

  int* ar=new int[N];
  fread(ar, sizeof (int)*N, N, fi);
  fclose(fi);
  cout << "The array:\n" << endl;
  for(int i=0;i<N;++i){
          cout<<ar[i]<<' ';
      }
  cout << "\nSorting\n" << endl;
  IHoaraSort(ar,N);
  cout << "The sorted array:\n" << endl;
  for(int i=0;i<N;++i)
          cout<<ar[i]<<' ';
  FILE* fo=fopen("numbers.out","wb");
  fwrite(ar, sizeof (int)*N, N, fo);

  fclose(fo);
  //free(ar);?????????????
  return 0;
}
