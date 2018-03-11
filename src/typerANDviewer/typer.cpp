#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <new>

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 3) {
      cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
  }
  ifstream inFile;
  FILE* outFile=fopen(argv[2],"wb");
  inFile.open(argv[1]);
  if (inFile.fail()) {
      cout << argv[0] << "\n  ERROR: can not open '"<<argv[1]<<"'\n";
      exit(1);
  }
  int curNum;

  int size=0;
  inFile>>size;
  fwrite(&size,sizeof(curNum),1,outFile);
  for(int i=0;i<size;++i){
      inFile>>curNum;
      fwrite(&curNum,sizeof(curNum),1,outFile);
    }

  inFile.close();
  fclose(outFile);

  return 0;
}
