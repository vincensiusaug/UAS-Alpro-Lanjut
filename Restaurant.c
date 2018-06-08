#include <stdio.h>


int jumlah_barang = 50; 

typedef struct barang
{
   char barang[256];

} barang;



void File_Read()
{

}

void File_Write(x)
{  
   FILE *fptr;
   fptr = fopen("db.txt","a");
   if(fptr == NULL)
   {
      printf("error");
      exit(1);
   }
   fprintf(fptr,"%",x);
   fclose(fptr);
}

void Data_Show(){

}

void Data_Hide(){

}

void Data_Unhide(){

}

void Data_Add(){

}

void Data_Sort(){

}

void Menu_Header(){
    puts ("====================================");
    puts ("Mont Blanc Restaurant");
    puts ("");
    puts ("");
    puts ("====================================");
}

void Menu_Main(){
    puts ("1 - Tambah Barang");
    puts ("2 - Ubah Barang");
    puts ("3 - Urutkan Barang");
    puts ("4 - Pembelian");

}

void Menu_Add(){

}

void Menu_Edit(){

}

void Menu_Sort(){

}

void Menu_Purchase(){

}

void main(){
    barang nama[jumlah_barang];
    int jenis[jumlah_barang];
    int harga[jumlah_barang];
}
