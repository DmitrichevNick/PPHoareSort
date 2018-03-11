#include "classResult.cpp"

int main (int argc, char* argv[])
{
   if (argc != 4) {
      //cout << argv[0] << "\n  ERROR: not enough arguments\n";
      exit(1);
   }

   FILE * bui = fopen(argv[1], "rb");
   FILE * buo = fopen(argv[2], "rb");
   FILE * bua = fopen(argv[3], "rb");
   int N;

   fread(&N, sizeof (N), 1, bui);

   int *ans = new int[N],
       *res = new int[N];
   double ans_time,
          res_time;
  /* // Считываем время работы программы участника и матрицу участника
   fread(&res_time, sizeof (res_time), 1, buo);
   fread(res, sizeof (*res), n * n, buo);
   // Считываем время работы программы и матрицу жюри
   fread(&ans_time, sizeof (ans_time), 1, bua);
   fread(ans, sizeof (*ans), n * n, bua);
   // Вычисляем ошибку, как квадрат нормы разности решений
   double diff = 0.0;
   for (int i = 0; i < n * n; i++)
     diff += (ans[i] - res[i]) * (ans[i] - res[i]);
   // Проверяем, что ошибка мала, тогда сообщаем, что решение корректно, иначе - некорректно.
   if (diff < 1e-6)
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
   fclose(buo);*/
   return 0;
}
