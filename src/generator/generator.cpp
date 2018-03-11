#include <iostream>
#include <random>
#include "genfunc.cpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 4) {
      cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
  }

  char typeOfArray=argv[1][0];
  int N=atoi(argv[2]);
  int* ar=NULL;

  switch (typeOfArray)
    {
    case 'e':
      ar=genFunc1(N);
      break;
    case 'a':
      ar=genFunc2(N);
      break;
    case 'd':
      ar=genFunc3(N);
      break;
    case 'n':
      ar=genFunc4(N);
      break;
    }

  FILE* outFile=fopen(argv[3],"wb");
  fwrite(&N,sizeof(N),1,outFile);
  fwrite(ar,sizeof(*ar),N,outFile);

  delete ar;
  return 0;
}
