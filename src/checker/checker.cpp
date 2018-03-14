#include <iostream>
#include "classResult.h"

int main (int argc, char* argv[])
{
   if (argc != 3) {
      std::cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
   }

   FILE *buo = fopen(argv[1], "rb");
   FILE *bua = fopen(argv[2], "rb");
   int N;
   double ans_time,
          res_time;
  // fread(&N, sizeof (N), 1, bui);
   fread(&res_time, sizeof (res_time), 1, buo);
   fread(&N, sizeof (N), 1, buo);
   double *ans = new double[N],
       *res = new double[N];

   fread(res, sizeof (*res), N, buo);

   fread(&ans_time, sizeof (ans_time), 1, bua);
   fread(&N, sizeof (N), 1, bua);
   fread(ans, sizeof (*ans), N, bua);

   bool result = true;
   for (int i = 0; i < N; ++i)
     if (ans[i]!=res[i])
       {
         result=false;
         break;
       }

   if (result)
   {
     checker_result.write_message ("AC. Numbers are equal.");
     checker_result.write_verdict (verdict::AC);
   }
   else
   {
     checker_result.write_message ("WA. Output is not correct.");
     checker_result.write_verdict (verdict::WA);
   }
   // Записываем время в правильной размерности (интервалы по 100 нс = 10 ^ (-7) сек).
   checker_result.write_time (res_time * 1e7);
   fclose(bua);
   fclose(buo);
   return 0;
}
