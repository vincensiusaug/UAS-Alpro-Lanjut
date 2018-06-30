#include <stdio.h>

typedef struct barang
{
   char barang[256];

} barang;

barang nama_makanan[10];
barang nama_minuman[10];
int harga_makanan[10];
int harga_minuman[10];

int price_total;



void Menu_Header(){
    system("clear");
    puts ("");
    puts ("================================");
    puts ("     Mont Blanc Restaurant      ");
    puts ("");
    puts ("================================");
}

int Makanan(){
    char nama;
    int harga;
    printf ("Masukan nama makanan: ");
    scanf ("%c",&nama);
    printf ("Masukan harga makanan: ");
    scanf ("%d",&harga);
}

int Minuman(){
    char nama;
    int harga;
    printf ("Masukan nama minuman: ");
    scanf ("%c",&nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&harga);
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

void Data_Show(){
    puts ("aaa");
}

void Menu_Show(){
    Menu_Header();
    Data_Show();
}

void Menu_Purchase(){
    Menu_Header();
    int choice_list[100];
    int choice_code, choice_jumlah;


    printf ("Masukan kode barang: ");
    scanf ("%d", &choice_code);
    printf ("Masukan jumlah barang: ");
    scanf ("%d", &choice_jumlah);
    
}

void Menu_Main(){

    int choice;

    Menu_Header();
    puts ("1 - Tambah Menu");
    puts ("2 - Ubah Menu");
    puts ("3 - Urutkan Menu");
    puts ("4 - Tampilkan Menu");
    puts ("5 - Pembelian");
    puts ("0 - Keluar");
    puts ("");
    printf ("Masukan pilihan anda: ");
    scanf ("%d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Menu_Add();
            Menu_Main();
        case 2:
            Menu_Edit();
            Menu_Main();
        case 3:
            Menu_Sort();
            Menu_Main();
        case '4':
            Data_Show();
            Menu_Main();
        case 5:
            Menu_Purchase();
            Menu_Main();
        default:
            Menu_Main();
    }
}



void main(){
    
    Menu_Main();
}
