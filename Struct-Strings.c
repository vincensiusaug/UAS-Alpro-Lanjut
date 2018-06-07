#include <stdio.h>

typedef struct barang
{
   char barang[100]; // 100 character array
}barang;

void main()
{
   barang nama[10]; // 10 strings
   printf("Enter something\n");
   printf ("String 1 = ");
   scanf("%s",nama[0].barang);
   printf ("String 2 = ");
   scanf("%s",nama[1].barang);
   puts ("");
   printf ("String 1 = %s\n", nama[0].barang);
   printf ("String 2 = %s\n", nama[1].barang);
 }
