#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct menu{
    int code;
    char nama[100];
    int harga;
    int status;
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

void Data_hide(int jenis){
    int index;
    puts ("masukan index: ");
    scanf ("%d",&index);
    if (jenis == 1){
        makanan[index].status = 0;
    }
    else if (jenis == 2){
        minuman[index].status = 0;
    }
}

void Menu_Header(){
    system("clear");
    puts ("");
    puts ("================================");
    puts ("     Mont Blanc Restaurant      ");
    puts ("================================");
}

int Makanan_add(){
    char nama;
    int harga;
    int index;
    puts ("masukan index: ");
    scanf ("%d",&index);
    if (makanan[index].code != 0)
    {
        puts ("telah terdapat data sebelumnya untuk mengubah silahkan masuk menu edit!");
        puts ("masukan 0 untuk kembali");

    }
    else 
    {
    printf ("Masukan nama makanan: ");
    scanf ("%s",&makanan[index].nama);
    printf ("Masukan harga makanan: ");
    scanf ("%d",&makanan[index].harga);
    }
    scanf("%p");
}

int Minuman_add(){
    char nama;
    int harga;
    int index;
    puts ("masukan index: ");
    scanf ("%d",&index);
    if (minuman[index].code != 0)
    {
        puts ("telah terdapat data sebelumnya untuk mengubah silahkan masuk menu edit!");
        puts ("masukan 0 untuk kembali");

    }
    else 
    {
    printf ("Masukan nama minuman: ");
    scanf ("%s",&minuman[index].nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&minuman[index].harga);
    }
    scanf("%p");
}

int Makanan_edit(){
    int index;
    char lanjut = 'n';
    puts ("masukan index: ");
        scanf ("%d",&index);
        char nama = makanan[index].nama;
        int harga = makanan[index].harga;
        printf ("Masukan nama makanan: ");
        scanf ("%s",&makanan[index].nama);
        printf ("Masukan harga makanan: ");
        scanf ("%d",&makanan[index].harga);
        if (nama != makanan[index].nama){
            puts("Menu berhasil di edit");
        }
    // while (lanjut == 'n' || lanjut == 'N')
    // {
    //     puts ("masukan index: ");
    //     scanf ("%d",&index);
    //     char nama = makanan[index].nama;
    //     int harga = makanan[index].harga;
    //     printf ("Masukan nama makanan: ");
    //     scanf ("%s",&makanan[index].nama);
    //     printf ("Masukan harga makanan: ");
    //     scanf ("%d",&makanan[index].harga);
    //     if (nama != makanan[index].nama){
    //         puts("Menu berhasil di edit");
    //     }

    //     puts ("continue?(Y/N)");
    //     scanf("%c",&lanjut);
    // }
}

int Minuman_edit(){
    char nama;
    int harga;
    int index;
    puts ("masukan index: ");
    scanf ("%d",&index);
    printf ("Masukan nama minuman: ");
    scanf ("%s",&minuman[index].nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&minuman[index].harga);
    scanf("%p");
}
void Menu_Add(){
    int choice;
    Menu_Header();
    puts ("1 - Tambah Makanan");
    puts ("2 - Tambah Minuman");
    puts ("0 - Kembali");
    
    printf ("Masukan pilihan anda: ");
    scanf ("%d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Makanan_add();
            Menu_Add();
        case 2:
            Minuman_add();
            Menu_Add();
    }
}

void Menu_Edit(){
    int choice;
    Menu_Header();
    puts ("1 - Edit Makanan");
    puts ("2 - Edit Minuman");
    puts ("3 - Hide Makanan");
    puts ("4 - Hide Minuman");
    puts ("0 - Kembali");
    
    printf ("Masukan pilihan anda: ");
    scanf ("%1d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Makanan_edit();
            Menu_Edit();
        case 2:
            Minuman_edit();
            Menu_Edit();
        case 3:
            Data_hide(1);
            Menu_Edit();
        case 4:
            Data_hide(2);
            Menu_Edit();

            
    }
}

void Menu_Sort(){
    Menu_Header();
}

void Data_Show(){
    puts ("Makanan");
    printf ("%-4s | %-20s | %8s\n","Kode", "Nama", "Harga");
    printf ("--------------------------------------\n");
    for(int i = 0; i<10; ++i){
        if (makanan[i].status == 1){
            printf ("%-4d | %-20s | Rp%6d\n", makanan[i].code, makanan[i].nama, makanan[i].harga);
        }
    }
    puts("\nMinuman");
    printf ("%-4s | %-20s | %8s\n","Kode", "Nama", "Harga");
    printf ("--------------------------------------\n");
    for(int i = 0; i<10; ++i){
        if (minuman[i].status == 1){
            printf ("%-4d | %-20s | %6d\n", minuman[i].code, minuman[i].nama, minuman[i].harga);
        }   
    }
    puts ("");
}

void Menu_Show(){
    Menu_Header();
    Data_Show();
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
}

void receipt(total, total_price){
    int bayar, a;

    if(total_price>0){
        Menu_Header();
        for (int i = 0; i < total;++i){
            printf ("%3d - %10s - %3d - %5d - %7d\n", purchase[i].code, purchase[i].nama, purchase[i].jumlah, purchase[i].harga, purchase[i].total);
        }
        printf ("Total yang harus di bayar: %d\n", total_price);
        printf ("Masukan jumlah bayar : ");
        scanf ("%d", &bayar);
        printf ("Kembalian            : %d\n", bayar - total_price);
        printf ("Press Any Key to Continue...");
        getchar();
        getchar();
    }
}

void Menu_Purchase(){
    int choice_code, choice_jumlah, choice_total, choice;
    int total_price = 0;

    Menu_Header();

    for(int i = 0;i >= 0;++i){
        Data_Show();
        choice_total = i;
        printf ("Masukan kode barang: ");
        scanf ("%d", &choice_code);
        if (choice_code == 0){
            break;
        }
        printf ("Masukan jumlah barang: ");
        scanf ("%d", &choice_jumlah);
        if (choice_jumlah == 0){
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
        makanan[i].status = 1;
    }
    for (int i = 0; i<jumlah_minuman; ++i){
        minuman[i].code = 200+i;
        strcpy (minuman[i].nama, "Minuman");
        minuman[i].harga = i*100+100;
        minuman[i].status = 1;
    }
    Menu_Main();
}
