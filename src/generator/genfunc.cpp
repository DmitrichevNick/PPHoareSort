#include <chrono>
#include <random>

int* genFunc(const int N){
  int* ar=new int[N];
  std::default_random_engine generator(time(0));
  for(int i = 0; i < N; ++i){
      std::uniform_int_distribution<int> distribution(-10000,10000);
      ar[i] = distribution(generator);
    }
  return ar;
}
