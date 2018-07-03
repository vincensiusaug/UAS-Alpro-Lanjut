#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const char * nama_makanan[]={
    "French Fries ",
    "Spagetti Bolognaise",
    "Mie Ayam Teriyaki",
    "Mie + Nasi Ayam Teriyaki Saos",
    "Ayam + Mie Katsu Teriyaki Saos",
    "Nasi + Sapo Tahu Seafood",
    "Chicken Cordon Bleu",
    "Chicken Mozarella",
    "Chicken Chicken Steak Cheesy",
    "Fish & Chips",
    "Bihun Ayam",
    "Bihun Ayam Bakso",
    "Bihun Siram Ayam",
    "Bihun Kuah Ayam",
    "Bihun Goreng Sapi",
    "Bihun Seafood",
    "Bakso Urat Mie",
    "Bakso Halus Mie",
    "Bakso Campur Mie",
    "Kwetiau Ayam",
    "Kwetiau Bakso Ayam",
    "Kwetiau Ayam Goreng",
    "Kwetiau Ayam Siram",
    "Kwetiau Sapi Goreng",
    "Kwetiau Goreng Seafood",
    "Kwetiau Seafood Siram",
    "Lo Mie",
    "Nasi + Bistik Sapi",
    "Nasi + Bistik Ayam",
    "Nasi Cap Cay Seafood",
    "Nasi Ayam Cah Kapri",
    "Nasi Ayam Cah Jamur",
    "Nasi Fu Yung Hai",
    "Nasi Cap Cay",
    "Soup Ayam",
    "Nasi Putih"
};

#define n_makanan (sizeof (nama_makanan) / sizeof (const char *))

const int harga_makanan[]={
    15500,
    19000,
    24000,
    25000,
    25000,
    29000,
    34000,
    34000,
    34000,
    34000,
    39000,
    19000,
    24000,
    25000,
    25000,
    29500,
    29500,
    18000,
    18500,
    18500,
    21000,
    23000,
    27500,
    27500,
    29500,
    31500,
    31500,
    27500,
    31000,
    29500,
    29500,
    27500,
    27500,
    26500,
    26500,
    19500,
    6000
};

const char * nama_minuman[]={
    "Black Currant",
    "Juice Alpukat / Lemon / Sirsak / Tomat",
    "Harga Orange Juice",
    "Frozen Cappucino",
    "Milkshake Strawberry",
    "Teh Tarik",
    "Es Lemon tea",
    "Es Green Tea",
    "Harga Es Jeruk",
    "Teh Botol Sosro",
    "Coca Cola / Fanta",
    "Air Mineral",
    "Es Teh Tawar",
    "Es Teh Manis"
};

#define n_minuman (sizeof (nama_minuman) / sizeof (const char *))

int harga_minuman[]={
    17500,
    17500,
    17500,
    16500,
    15500,
    15500,
    15000,
    15000,
    7000,
    7000,
    8000,
    6500,
    4500,
    5000
};

typedef struct menu{
    int code;
    char nama[50];
    int harga;
    int status;
};

typedef struct purchase{
    int code;
    char nama[50];
    int harga;
    int jumlah;
    int total;
};

typedef struct temporary{
    int code;
    char nama[50];
    int harga;
    int status;
};

int jumlah_makanan = n_makanan;
int jumlah_minuman = n_minuman;

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
    puts ("====================================================================");
    puts ("                       Mont Blanc Restaurant      ");
    puts ("====================================================================\n");
}

void File_Write(){

}

void Makanan_add(){
    char nama;
    int harga;
    int index = jumlah_makanan + 1;
    printf ("Masukan nama makanan: ");
    scanf ("%s",&makanan[index].nama);
    printf ("Masukan harga makanan: ");
    scanf ("%d",&makanan[index].harga);
    makanan[index].status = 1;
    ++jumlah_makanan;
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
    }

void Minuman_add(){
    char nama;
    int harga;
    int index = jumlah_minuman + 1;
    printf ("Masukan nama minuman: ");
    scanf ("%s",&minuman[index].nama);
    printf ("Masukan harga minuman: ");
    scanf ("%d",&minuman[index].harga);
    minuman[index].status = 1;
    ++jumlah_minuman;
    printf ("Press Any Key to Continue...");
    getchar();
    getchar();
    }

void Makanan_edit(){
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

void Minuman_edit(){
    char nama;
    int harga;
    int index;
    Data_Show();
    puts ("masukan kode: ");
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
            Menu_Sort_Code();    if (makanan[index].code != 0)
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
    printf ("%-4s | %-50s | %8s\n","Kode", "Nama", "Harga");
    printf ("--------------------------------------------------------------------\n");
    for(int i = 0; i<jumlah_makanan; ++i){
        if (makanan[i].status == 1){
            printf ("%-4d | %-50s | Rp%6d\n", makanan[i].code, makanan[i].nama, makanan[i].harga);
        }
    }
    puts("\nMinuman");
    printf ("%-4s | %-50s | %8s\n","Kode", "Nama", "Harga");
    printf ("--------------------------------------------------------------------\n");
    for(int i = 0; i<jumlah_minuman; ++i){
        if (minuman[i].status == 1){
            printf ("%-4d | %-50s | Rp%6d\n", minuman[i].code, minuman[i].nama, minuman[i].harga);
        }   
    }
    puts ("");
}

void Menu_Show(){
    Menu_Header();
    Data_Show();
    printf ("Press Enter to Continue...");
    getchar();
    getchar();
}

void receipt(total, total_price){
    int bayar, a;

    if(total_price>0){
        int choice;
        Menu_Header();
        printf ("%4s | %-50s | %6s | %5s | %6s\n", "Kode", "Nama", "Jumlah", "Harga", "Total");
        puts ("--------------------------------------------------------------------");
        for (int i = 0; i < total;++i){
            printf ("%4d | %-50s | %6d | %5d | %6d\n", purchase[i].code, purchase[i].nama, purchase[i].jumlah, purchase[i].harga, purchase[i].total);
        }
        printf ("\nTotal yang harus di bayar: %d\n", total_price);
        printf ("Masukan jumlah bayar : ");
        scanf ("%d", &bayar);
        printf ("\nKembalian            : %d\n\n", bayar - total_price);
        puts ("1 - Print Receipt");
        puts ("0 - Kembali");
        printf ("\nPilihan anda:");
        scanf ("%1d",&choice);
        switch (choice){
            case 0:
                break;
            case 1:
                File_Write();
                break;
        }
    }
}

void Menu_Purchase(){
    int choice_code, choice_jumlah, choice_total, choice, index;
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
        index = Index(choice_code);

        if(choice_code<200){ // makanan
            purchase[i].code = makanan[index].code;
            strcpy (purchase[i].nama, makanan[index].nama);
            purchase[i].harga = makanan[index].harga;
            purchase[i].jumlah = choice_jumlah;
            purchase[i].total = makanan[index].harga * choice_jumlah;
            total_price += makanan[index].harga * choice_jumlah;
        }
        else{ // minuman
            purchase[i].code = minuman[index].code;
            strcpy (purchase[i].nama, minuman[index].nama);
            purchase[i].harga = minuman[index].harga;
            purchase[i].jumlah = choice_jumlah;
            purchase[i].total = minuman[index].harga * choice_jumlah;
            total_price += minuman[index].harga * choice_jumlah;
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
        strcpy (makanan[i].nama, nama_makanan[i]);
        makanan[i].harga = harga_makanan[i];
        makanan[i].status = 1;
    }
    for (int i = 0; i<jumlah_minuman; ++i){
        minuman[i].code = 200+i;
        strcpy (minuman[i].nama, nama_minuman[i]);
        minuman[i].harga = harga_minuman[i];
        minuman[i].status = 1;
    }
    Menu_Main();
}
