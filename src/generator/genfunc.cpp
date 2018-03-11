#include <chrono>
#include <random>

double* genFunc(const int N){
  double* ar=new double[N];
  std::default_random_engine generator(time(0));
  for(int i = 0; i < N; ++i){
      std::uniform_real_distribution<double> distribution(-10000.0,10000.0);
      ar[i] = distribution(generator);
    }
  return ar;
}
