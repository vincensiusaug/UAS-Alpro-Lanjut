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
    puts ("     Mont Blanc Restaurant");
    puts ("");
    puts ("====================================");
}

void Menu_Main(){
    Menu_Header();
    puts ("1 - Tambah Barang");
    puts ("2 - Ubah Barang");
    puts ("3 - Urutkan Barang");
    puts ("4 - Pembelian");
    puts ("Q - Keluar");

}

void Menu_Add(){
    Menu_Header();
    puts ("1 - Tambah Makanan");
    puts ("2 - Tambah Minuman");
    puts ("Q - Kembali");
}

int Makanan(){
    char nama;
    int harga;
    printf ("Masukan nama makanan: ");
    scanf ("%c",&nama);
    printf ("Masukan harga makanan: ");
    scanf ("%d",&harga);
    return harga;
}

int Minuman(){
    char nama[100];
    int harga;
    printf ("Masukan nama minuman: ");
    scanf ("%c",&nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&harga);
    return harga;
}

void Menu_Edit(){
    Menu_Header();
}

void Menu_Sort(){
    Menu_Header();
}

void Menu_Purchase(){
    Menu_Header();
}

void main(){
    barang nama[jumlah_barang];
    int jenis[jumlah_barang];
    int harga[jumlah_barang];
    Menu_Main();
}
