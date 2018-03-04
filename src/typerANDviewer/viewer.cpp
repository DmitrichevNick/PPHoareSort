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
      cout<<"\n Ошибка открытия файла";
      exit(1);
  }
  int curNum;
  int size=0;
  fread(&size,sizeof(size),1,inFile);
  outFile<<size<<" ";
  for(int i=0;i<size;++i){
      fread(&curNum,sizeof(curNum),1,inFile);
      outFile<<curNum<<" ";
    }

  outFile.close();
  fclose(inFile);

  return 0;
}
