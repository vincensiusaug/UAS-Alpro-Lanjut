#include <stdio.h>



int jumlah_barang = 50; 


typedef struct barang
{
   char barang[256];

} barang;



char* File_Read(char fname[10])
{
   typedef struct arr
   {
      char arr[100]; // 100 character array
   }arr;
   arr index[100];
   FILE *fptr;
   fptr = fopen(fname,"a");
   int count=0;
   if(fptr == NULL)
   {
      printf("error");
      exit(1);
   }
   while (!foef(fptr))
   {
      
      fgets(index[count].arr,20, fptr);
      ++count;
   }
   fclose(fptr);
   for (int a=count;a<100;++a)
   {
      index[count].arr = 0;
   }
   return arr;
}

void File_Write(char x[20], char fname[10])
{  
   FILE *fptr;
   fptr = fopen(fname,"a");
   if(fptr == NULL)
   {
      printf("error");
      exit(1);
   }
   fprintf(fptr,"%c",x);
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
    puts ("");
    puts ("=================================");
    puts ("     Mont Blanc Restaurant");
    puts ("");
    puts ("=================================");
}

void Menu_Main(){
    char pilihan;
    for(;;){
        Menu_Header();
        puts ("1 - Tambah Menu");
        puts ("2 - Ubah Menu");
        puts ("3 - Urutkan Menu");
        puts ("4 - Tampilkan Menu");
        puts ("5 - Pembelian");
        puts ("Q - Keluar");
        puts ("");
        printf ("Masukan pilihan anda: ");
        scanf ("%c",&pilihan);

        if (pilihan == "1"){
            Menu_Add();
            continue;
        }
        else if(pilihan == "2"){
            Menu_Edit();
            continue;
        }
        else if(pilihan == "3"){
            Menu_Sort();
            continue;
        }
        else if(pilihan == "4"){
            Data_Show();
            continue;
        }
        else if(pilihan == "5"){
            Menu_Purchase();
            continue;
        }
        else{
            break;
        }
    }
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

void Menu_Add(){
    Menu_Header();
    puts ("1 - Tambah Makanan");
    puts ("2 - Tambah Minuman");
    puts ("Q - Kembali");
}

void Menu_Edit(){
    Menu_Header();
    puts ("1 - Masukan Kode");
    puts ("2 - Tampilkan Menu");
    puts ("Q - Kembali");
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
