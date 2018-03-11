#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <omp.h>
#include <new>
#include "sol.cpp"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 3) {
      cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
  }
   FILE *fIn = NULL,
        *fOut = NULL;
   if ((fIn = fopen(argv[1], "rb")) == NULL) {
     cout << argv[0] << "\n  ERROR: can not open '"<<argv[1]<<"'\n\n";
     exit(1);
     }
   if ((fOut = fopen(argv[2], "wb")) == NULL) {
     cout << argv[0] << "\n  ERROR: can not open '"<<argv[2]<<"'\n\n";
     exit(2);
     }
   int N = 0,
       *numbers = NULL;
   if((fread(&N, sizeof(int), 1, fIn)) != 1) {
     cout << argv[0] << "\n  ERROR: can not read the size of the array from 'numbers.in'\n\n";
     exit(3);
     }
   else {
       numbers = new int[N];
    if (numbers == NULL || (fread(numbers, sizeof(*numbers), N, fIn)) != N) {
       cout << argv[0] << "\n  ERROR: can not read the array from '"<<argv[1]<<"'\n\n";
       if (numbers!=NULL)
         delete[] numbers;
       exit(4);
       }
     }
   /* for (int i=0; i<N; ++i)
      cout << numbers[i] << ' ';
    cout<<endl; */
   double time = omp_get_wtime();
   IHoaraSort(numbers, N); // the seq. hoara sort
   time = omp_get_wtime() - time;
   /*for(int i=0;i<N;++i)
     cout<<numbers[i]<<' ';
   cout<<endl;*/
   if ((fwrite(&N, sizeof(N), 1, fOut)) != 1) {
      cout << argv[0] << "\n  ERROR: the size of the array hadn't been written\n\n";
      delete[] numbers;
      exit(5);
      }
   if ((fwrite(numbers, sizeof(*numbers), N, fOut)) != N) {
      cout << argv[0] << "\n  ERROR: the array hadn't been written\n\n";
      delete[] numbers;
      exit(6);
      }
   if ((fwrite(&time, sizeof(time), 1, fOut)) != 1) {
      cout << argv[0] << "\n  ERROR: the time hadn't been written\n\n";
      delete[] numbers;
      exit(7);
      }

   if (fIn)
     fclose(fIn);
   else {
     cout << argv[0] << "\n  ERROR: can not close '"<<argv[1]<<"'\n\n";
     delete[] numbers;
     exit(8);
     }
   if (fOut)
     fclose(fOut);
   else {
     cout << argv[0] << "\n  ERROR: can not close '"<<argv[2]<<"'\n\n";
     delete[] numbers;
     exit(1);
     }
   delete[] numbers;
    cout<< argv[0]<<"\n  OK\n\n";
   return 0;
}
