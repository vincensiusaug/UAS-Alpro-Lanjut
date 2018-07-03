#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct menu{
    int code;
    char nama[20];
    int harga;
    int status;
};

typedef struct purchase{
    int code;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

typedef struct temporary{
    int code;
    char nama[20];
    int harga;
    int status;
};

int jumlah_makanan = 1;
int jumlah_minuman = 1;

struct menu makanan[100];
struct menu minuman[100];
struct purchase purchase[100];
struct temporary temp;

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
void Data_unhide(int jenis){
    int index;
    puts ("masukan index: ");
    scanf ("%d",&index);
    if (jenis == 1){
        makanan[index].status = 1;
    }
    else if (jenis == 2){
        minuman[index].status = 1;
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
    makanan[index].status = 1;
    }
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
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

    }
    else 
    {
    printf ("Masukan nama minuman: ");
    scanf ("%s",&minuman[index].nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&minuman[index].harga);
    minuman[index].status = 1;
    }
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
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
        printf ("Press Any Key to Continue...");
        getchar();
        getchar();
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
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
}
void Menu_Add(){
    int choice;
    Menu_Header();
    puts ("1 - Tambah Makanan");
    puts ("2 - Tambah Minuman");
    puts ("0 - Kembali");
    puts ("");
    printf ("Masukan pilihan anda: ");
    scanf ("%d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Makanan_add();
            Menu_Add();
            break;
        case 2:
            Minuman_add();
            Menu_Add();
            break;
    }
}

void Menu_Edit(){
    int choice;
    Menu_Header();
    puts ("1 - Edit Makanan");
    puts ("2 - Edit Minuman");
    puts ("3 - Hide Makanan");
    puts ("4 - Hide Minuman");
    puts ("5 - Unhide Makanan");
    puts ("6 - Unhide Minuman");
    puts ("0 - Kembali");
    puts ("");
    printf ("Masukan pilihan anda: ");
    scanf ("%1d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Makanan_edit();
            Menu_Edit();
            break;
        case 2:
            Minuman_edit();
            Menu_Edit();
            break;
        case 3:
            Data_hide(1);
            Menu_Edit();
            break;
        case 4:
            Data_hide(2);
            Menu_Edit();
            break;
        case 5:
            Data_unhide(1);
            Menu_Edit();
            break;
        case 6:
            Data_unhide(2);
            Menu_Edit();
            break;

            
    }
}

void Sort_Makanan(int n){

    // tmp = n
    temp.code = makanan[n].code;
    strcpy (temp.nama, makanan[n].nama);
    temp.harga = makanan[n].harga;
    temp.status = makanan[n].status;

    // n = n+1
    makanan[n].code = makanan[n+1].code;
    strcpy (makanan[n].nama, makanan[n+1].nama);
    makanan[n].harga = makanan[n+1].harga;
    makanan[n].status = makanan[n+1].status;

    // n+1 = tmp
    makanan[n+1].code = temp.code;
    strcpy (makanan[n+1].nama, temp.nama);
    makanan[n+1].harga = temp.harga;
    makanan[n+1].status = temp.status;
}

void Sort_Minuman(int n){

    // tmp = n
    temp.code = minuman[n].code;
    strcpy (temp.nama, minuman[n].nama);
    temp.harga = minuman[n].harga;
    temp.status = minuman[n].status;

    // n = n+1
    minuman[n].code = minuman[n+1].code;
    strcpy (minuman[n].nama, minuman[n+1].nama);
    minuman[n].harga = minuman[n+1].harga;
    minuman[n].status = minuman[n+1].status;

    // n+1 = tmp
    minuman[n+1].code = temp.code;
    strcpy (minuman[n+1].nama, temp.nama);
    minuman[n+1].harga = temp.harga;
    minuman[n+1].status = temp.status;
}

void Name_Sort(int status){
    for(int i=0 ; i < jumlah_makanan-1 ; ++i){
        for(int j=0 ; j < jumlah_makanan-i-1 ; ++j){
            // Ascending
            if(status == 0){
                if(strcmp(makanan[j].nama, makanan[j+1].nama)>0){
                    Sort_Makanan(j);
                }
            }
            // Descending
            else{
                if(strcmp(makanan[j].nama, makanan[j+1].nama)<0){
                    Sort_Makanan(j);
                }
            }
        }
    }

    for(int i=0 ; i < jumlah_minuman-1 ; ++i){
        for(int j=0 ; j < jumlah_minuman-i-1 ; ++j){
            if(status == 0){
                // Ascending
                if(strcmp(minuman[j].nama, minuman[j+1].nama)>0){
                    Sort_Minuman(j);
                }
            }
            // Descending
            else{
                if(strcmp(minuman[j].nama, minuman[j+1].nama)<0){
                    Sort_Minuman(j);
                }
            }
        }
    }
}

void Price_Sort(int status){
    for(int i=0 ; i < jumlah_makanan-1 ; ++i){
        for(int j=0 ; j < jumlah_makanan-i-1 ; ++j){
            // Ascending
            if(status == 0){
                if(makanan[j].harga>makanan[j+1].harga){
                    Sort_Makanan(j);
                }
            }
            // Descending
            else{
                if(makanan[j].harga<makanan[j+1].harga){
                    Sort_Makanan(j);
                }
            }
        }
    }

    for(int i=0 ; i < jumlah_minuman-1 ; ++i){
        for(int j=0 ; j < jumlah_minuman-i-1 ; ++j){
            if(status == 0){
                // Ascending
                if(minuman[j].harga>minuman[j+1].harga){
                    Sort_Minuman(j);
                }
            }
            // Descending
            else{
                if(minuman[j].harga<minuman[j+1].harga){
                    Sort_Minuman(j);
                }
            }
        }
    }
}

void Code_Sort(int status){
    for(int i=0 ; i < jumlah_makanan-1 ; ++i){
        for(int j=0 ; j < jumlah_makanan-i-1 ; ++j){
            if(status == 0){
                if(makanan[j].code>makanan[j+1].code){
                    Sort_Makanan(j);
                }
            }
            else{
                if(makanan[j].code<makanan[j+1].code){
                    Sort_Makanan(j);
                }
            }
        }
    }

    for(int i=0 ; i < jumlah_minuman-1 ; ++i){
        for(int j=0 ; j < jumlah_minuman-i-1 ; ++j){
            if(status == 0){
                if(minuman[j].code>minuman[j+1].code){
                    Sort_Minuman(j);
                }
            }
            else{
                if(minuman[j].code<minuman[j+1].code){
                    Sort_Minuman(j);
                }
            }
        }
    }
}

void Menu_Sort_Name(){
    int choice;
    Menu_Header();
    puts ("1 - Ascending");
    puts ("2 - Descending");
    puts ("0 - Kembali");
    puts ("");
    printf ("\nMasukan pilihan anda: ");
    scanf ("%d",&choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Name_Sort(0);
            break;
        case 2:
            Name_Sort(1);
            break;
        default:
            Menu_Sort_Price();
            break;
    }
}

void Menu_Sort_Price(){
    int choice;
    Menu_Header();
    puts ("1 - Ascending");
    puts ("2 - Descending");
    puts ("0 - Kembali");
    puts ("");
    printf ("\nMasukan pilihan anda: ");
    scanf ("%d",&choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Price_Sort(0);
            break;
        case 2:
            Price_Sort(1);
            break;
        default:
            Menu_Sort_Price();
            break;
    }
}

void Menu_Sort_Code(){
    int choice;
    Menu_Header();
    puts ("1 - Ascending");
    puts ("2 - Descending");
    puts ("0 - Kembali");
    puts ("");
    printf ("\nMasukan pilihan anda: ");
    scanf ("%d",&choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Code_Sort(0);
            break;
        case 2:
            Code_Sort(1);
            break;
        default:
            Menu_Sort_Code();
            break;
    }
}

void Menu_Sort(){
    int choice;
    Menu_Header();
    puts ("1 - Sort by Name");
    puts ("2 - Sort by Price");
    puts ("3 - Sort by Code");
    puts ("0 - Kembali");
    puts ("");
    printf ("\nMasukan pilihan anda: ");
    scanf ("%d",&choice);



    switch (choice){
        case 0:
            break;
        case 1:
            Menu_Sort_Name();
            break;
        case 2:
            Menu_Sort_Price();
            break;
        case 3:
            Menu_Sort_Code();
            break;
        default:
            Menu_Sort();
    }
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
            printf ("%-4d | %-20s | Rp%6d\n", minuman[i].code, minuman[i].nama, minuman[i].harga);
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
        printf ("\nTotal yang harus di bayar: %d\n", total_price);
        printf ("Masukan jumlah bayar : ");
        scanf ("%d", &bayar);
        printf ("\nKembalian            : %d\n\n", bayar - total_price);
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
        puts ("Masukan 0 untuk selesai\n");
        printf ("Masukan kode barang  : ");
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
    scanf ("%1d", &choice);

    switch (choice){
        case 0:
            break;
        case 1:
            Menu_Add();
            Menu_Main();
            break;
        case 2:
            Menu_Edit();
            Menu_Main();
            break;
        case 3:
            Menu_Sort();
            Menu_Main();
            break;
        case 4:
            Menu_Show();
            Menu_Main();
            break;
        case 5:
            Menu_Purchase();
            Menu_Main();
            break;
        default:
            Menu_Main();
            break;
    }
}



void main(){
    srand(time(NULL));

    for (int i = 0; i<jumlah_makanan; ++i){
        makanan[i].code = 100+i;
        strcpy (makanan[i].nama, "Makanan");
        makanan[i].harga = rand()%20*2000+1000;
        makanan[i].status = 1;
    }
    for (int i = 0; i<jumlah_minuman; ++i){
        minuman[i].code = 200+i;
        strcpy (minuman[i].nama, "Minuman");
        minuman[i].harga = rand()%20*500+1000;
        minuman[i].status = 1;
    }
    Menu_Main();
}
