#include <iostream>
#include <random>
#include "genfunc.cpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
      cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
  }

  int N = atoi(argv[1]);
  int* ar = genFunc(N);

  FILE* outFile=fopen(argv[2],"wb");
  fwrite(&N,sizeof(N),1,outFile);
  fwrite(ar,sizeof(*ar),N,outFile);

  delete[] ar;
  return 0;
}
