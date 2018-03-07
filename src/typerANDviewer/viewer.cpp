#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <new>

using namespace std;

int main(int argc, char* argv[])
{
  ofstream outFile;
  FILE* inFile=fopen("numbers.out","rb");
  outFile.open(argv[1]);
  if (outFile.fail()) {
      cout << argv[0] << "\n  ERROR: can not open 'numbers.out'\n";
      exit(1);
  }
  int curNum;
  int size=0;
  double time=0;
  fread(&size,sizeof(size),1,inFile);
  outFile<<size<<endl;
  for(int i=0;i<size;++i){
      fread(&curNum,sizeof(curNum),1,inFile);
      outFile<<curNum<<" ";
    }
  fread(&time,sizeof(time),1,inFile);
  outFile<<endl<<time<<endl;
  outFile.close();
  fclose(inFile);

  return 0;
}
