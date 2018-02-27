void hoaraSort(int*&, int, int);
void IHoaraSort(int*&,const int);

void IHoaraSort(int* &arr,const int sizeArr){
    hoaraSort(arr,0,sizeArr);
}
void hoaraSort(int* &arr, int first, int last){

    int i = first,
        j = last,
        tmp,
        x = arr[(first + last) / 2];

    do {
       while (arr[i] < x)
         i++;
       while (arr[j] > x)
         j--;

       if (i <= j)
       {
         if (i < j)
         {
           tmp=arr[i];
           arr[i]=arr[j];
           arr[j]=tmp;
         }
         i++;
         j--;
       }
    } while (i <= j);

    if (i < last)
       hoaraSort(arr, i, last);
    if (first < j)
       hoaraSort(arr, first,j);
}
