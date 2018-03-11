#include <chrono>
#include <random>
#include <cstdlib>

enum TYPE_OF_ARRAY{
  EQUALS, //genFunc1
  ASC,   //genFunc2
  DISC,  //genFunc3
  NORMAL      //genFunc4
};

int* genFunc4(const int N){
  int* ar=new int[N];
  std::default_random_engine generator(time(0));
  for(int i = 0; i < N; ++i){
      std::uniform_int_distribution<int> distribution(-10000,10000);
      ar[i] = distribution(generator);
    }
  return ar;
}

int* genFunc1(const int N){
  int* ar=new int[N];
  for(int i=0; i<N; ++i)
    ar[i]=0;
  return ar;
}

int* genFunc2(const int N){
  int* ar=genFunc4(N);
  std::qsort(ar,N,sizeof(*ar),[](const void *a, const void *b) {
      return ( *(int*)a - *(int*)b );
    } );
  return ar;
}

int* genFunc3(const int N){
  int* ar=genFunc4(N);
  std::qsort(ar,N,sizeof(*ar),[](const void *a, const void *b) {
      return ( *(int*)b - *(int*)a );
    } );
  return ar;
}


int* genFunc(TYPE_OF_ARRAY typeArray, const int N){
  typedef int* (*func)(const int N);
  func myFunc[4];
    myFunc[0]=genFunc1;
    myFunc[1]=genFunc2;
    myFunc[2]=genFunc3;
    myFunc[3]=genFunc4;
  return ((myFunc[typeArray])(N));
}
