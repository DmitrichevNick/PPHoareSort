#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <new>
#include "sol.cpp"

using namespace std;

int main()
{
   FILE *fIn=NULL,
        *fOut=NULL;
   fIn=fopen("numbers.in","rb");
   fOut=fopen("numbers.out","wb");

   int N=0,
       *numbers=NULL;
   if((fread(&N,sizeof(int),1,fIn))!=1)
     cout<<"ERROR\n";
   else {
       numbers=new int[N];
    if(numbers==NULL || (fread(numbers,sizeof(*numbers),N,fIn))!=N)
       cout<<"ERROR\n";
     }
    for(int i=0;i<N;++i)
      cout<<numbers[i]<<' ';
    cout<<endl;
   IHoaraSort(numbers,N);
   for(int i=0;i<N;++i)
     cout<<numbers[i]<<' ';
   cout<<endl;
   fwrite(&N,sizeof(N),1,fOut);
   fwrite(numbers,sizeof(*numbers),N,fOut);

   if(fIn)
     fclose(fIn);
   if (fOut)
     fclose(fOut);
   delete[] numbers;

   return 0;
}
