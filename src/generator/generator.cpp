#include <iostream>
#include <random>
#include <chrono>

double* genFunc(const int N){
  double* ar=new double[N];
  std::default_random_engine generator(time(0));
  for(int i = 0; i < N; ++i){
      std::uniform_real_distribution<double> distribution(-10000.0,10000.0);
      ar[i] = distribution(generator);
    }
  return ar;
}

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3 && argc != 2) {
      cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
  }
  int N = 0;
  if (argc == 3) {
      if ((N = atoi(argv[1])) < 0) {
        cout << argv[1] << "\n  ERROR: the size has to be more than 0\n";
        exit(1);
      }
  } else {
      std::default_random_engine generator(time(0));
      std::uniform_int_distribution<int> distribution(0,2000000);
      N = distribution(generator);
  }
  double* ar = genFunc(N);

  FILE* outFile=fopen(((argc==3)?argv[2]:argv[1]),"wb");
  fwrite(&N,sizeof(N),1,outFile);
  fwrite(ar,sizeof(*ar),N,outFile);

  delete[] ar;
  return 0;
}
