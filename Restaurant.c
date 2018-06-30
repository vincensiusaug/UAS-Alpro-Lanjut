#include <stdio.h>
#include <string.h>

typedef struct menu{
    int code;
    char nama[100];
    int harga;

};

typedef struct purchase{
    int code;
    char nama[100];
    int harga;
    int jumlah;
    int total;

};

int jumlah_makanan = 10;
int jumlah_minuman = 10;

struct menu makanan[100];
struct menu minuman[100];

struct purchase purchase[100];



void Menu_Header(){
    system("clear");
    puts ("");
    puts ("================================");
    puts ("     Mont Blanc Restaurant      ");
    puts ("================================");
}

int Makanan(){
    char nama;
    int harga;
    printf ("Masukan nama makanan: ");
    scanf ("%s",&nama);
    printf ("Masukan harga makanan: ");
    scanf ("%d",&harga);
}

int Minuman(){
    char nama;
    int harga;
    printf ("Masukan nama minuman: ");
    scanf ("%s",&nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&harga);
}

void Menu_Add(){
    int choice;
    Menu_Header();
    puts ("1 - Tambah Makanan");
    puts ("2 - Tambah Minuman");
    puts ("Q - Kembali");
    
    printf ("Masukan pilihan anda: ");
    scanf ("%d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Makanan();
            Menu_Main();
        case 2:
            Minuman();
            Menu_Main();
    }
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
    puts ("Makanan");
    for(int i = 0; i<10; ++i){
        printf ("%d - %s - %d\n", makanan[i].code, makanan[i].nama, makanan[i].harga);
    }
    puts("\nMinuman");
    for(int i = 0; i<10; ++i){
        printf ("%d - %s - %d\n", minuman[i].code, minuman[i].nama, minuman[i].harga);
    }
    puts ("");
}

void Menu_Show(){
    Menu_Header();
    Data_Show();
    scanf ("%d");
}

void receipt(total, total_price){
    int bayar, a;

    Menu_Header();
    for (int i = 0; i < total;++i){
        printf ("%3d - %10s - %3d - %5d - %7d\n", purchase[i].code, purchase[i].nama, purchase[i].jumlah, purchase[i].harga, purchase[i].total);
    }
    printf ("Total yang harus di bayar: %d\n", total_price);
    printf ("Masukan jumlah bayar: ");
    scanf ("%d", &bayar);
    printf ("Kembalian: %d", bayar - total_price);
    scanf ("%d", &a);
}

void Menu_Purchase(){
    int choice_code, choice_jumlah, choice_total, choice;
    int total_price = 0;

    Menu_Header();

    for(int i = 0;i >= 0;++i){
        Data_Show();
        printf ("Masukan kode barang: ");
        scanf ("%d", &choice_code);
        printf ("Masukan jumlah barang: ");
        scanf ("%d", &choice_jumlah);

        choice_total = i;

        if (choice_jumlah == 0 || choice_code == 0){
            break;
        }

        if(choice_code<200){ // makanan
            choice = choice_code-100;
            purchase[i].code = makanan[choice].code;
            strcpy (purchase[i].nama, makanan[choice].nama);
            purchase[i].harga = makanan[choice].harga;
            purchase[i].jumlah = choice_jumlah;
            purchase[i].total = makanan[choice].harga * choice_jumlah;
            total_price += makanan[choice].harga * choice_jumlah;
        }
        else{ // minuman
            choice = choice_code-200;
            purchase[i].code = minuman[choice].code;
            strcpy (purchase[i].nama, minuman[choice].nama);
            purchase[i].harga = minuman[choice].harga;
            purchase[i].jumlah = choice_jumlah;
            purchase[i].total = minuman[choice].harga * choice_jumlah;
            total_price += minuman[choice].harga * choice_jumlah;
        }
    }
    receipt(choice_total, total_price);
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
        case 4:
            Menu_Show();
            Menu_Main();
        case 5:
            Menu_Purchase();
            Menu_Main();
        default:
            Menu_Main();
    }
}



void main(){
    for (int i = 0; i<jumlah_makanan; ++i){
        makanan[i].code = 100+i;
        strcpy (makanan[i].nama, "Makanan");
        makanan[i].harga = i*1000+1000;
    }
    for (int i = 0; i<jumlah_minuman; ++i){
        minuman[i].code = 200+i;
        strcpy (minuman[i].nama, "Minuman");
        minuman[i].harga = i*100+100;
    }
    puts("masukan q untuk keluar!");

    Menu_Main();
}
