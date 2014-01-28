#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>

//deklarasi fungsi
void Menu_Utama();
void ani();
void baca_fileDTK();
void buka_fileDTK();
void tambahDTK();
void tampilDTK();
void cari1();
void cariDTK();
void cariDTK2();
void cariDTK3();
void hapusDTK();
void ubahDTK();
void tambahDAK();
void tampilDAK();
void cariDAK();
void ubahDAK();
void tampil_DGK();
void cari_DGK();
void keuangan();

//deklarasi struct
typedef struct
{
  char nama[20];
  char alamat[20];
  char jabatan;
  char NIK[6];
  char status;
  float ket;
  int minggu1;
  int minggu2;
  int minggu3;
  int minggu4;
  char bulan;
  long int gaji_pokok, gaji_kotor, potongan, gaji_bersih;
  float tunja, tunga;
}data_gaji;

//deklarasi variable struct
data_gaji penggajian; 
   
 
//deklarasi variabel
FILE *Pfk;
int menu;
char kmbli_menu, jawab;
int i, nomor;
char z[6],nm[20],jb[20];
int tdkketemu;
char c;
int no_record, hasil_baca;
long int ofset_byte;


char *bln (char bulan)
{ switch (bulan)
  { case 'a' : return("Januari");
    case 'b' : return("Februari");
    case 'c' : return("Maret");
    case 'd' : return("April");
    case 'e' : return("Mei");
    case 'f' : return("Juni");
    case 'g' : return("Juli");
    case 'h' : return("Agustus");
    case 'i' : return("September");
    case 'j' : return("Oktober");
    case 'k' : return("November");
    case 'l' : return("Desember");
  }
  return("Tidak Ada");
}

char *stts (char status)
{ switch (status)
  { case '1' : return("Menikah");
    case '2' : return("Belum Menikah");
  }
  return("Tidak Ada");
}

char *jbtn (char jabatan)
{ switch (jabatan)
  { case '1' : return("Manager");
    case '2' : return("Sekretaris");
    case '3' : return("Bendahara");
    case '4' : return("Leader");
    case '5' : return("Operator");
  }
  return("Tidak Ada");
}

int main(int argc, char *argv[])
{
    int i;
    char pasword[5],pass[5];
    
    
    awal:
    textcolor(LIGHTBLUE);     
    strcpy(pass,"prodas");       
    //animasi
    for (i=61; i>=20; i--)
    {
           Sleep(50);
           gotoxy(i,1);
           printf("=\n");
    }
           gotoxy(20,2);
    printf("|           PROGRAM PENGGAJIAN           |\n");
    for (i=20; i<=61; i++)
    {
           Sleep(50);
           gotoxy(i,3);
           printf("-\n");
    }
    Sleep(75);
    gotoxy(20,4);
    printf("|     ARIEF  NUR     |      10112040     |\n");
    Sleep(600);
    gotoxy(20,5);
    printf("|     IKHSAN  A      |      10112033     |\n");
    Sleep(600);
    gotoxy(20,6);
    printf("|       KIKI I       |      10112008     |\n");
    Sleep(600);
    gotoxy(20,7);
    printf("|       HERWIN       |      10111613     |\n");
    Sleep(600);
    for (i=61; i>=20; i--)
    {
        Sleep(30);
        gotoxy(i,8);
    printf("=\n");
    }
    //login
    
    i=0;
    do
    {
      gotoxy(20,10);
      printf("Masukkan Pasword : ");fflush(stdin);gets(pasword);
      if((strcmp(pass,pasword))==0)
          Menu_Utama();
      else
      {   
          textcolor(LIGHTRED);
          gotoxy(30,12);printf("Password anda salah!");
          getch();
          clrscr();
          textcolor(LIGHTRED);
          gotoxy(35,4);printf("PERINGATAN!");
          gotoxy(22,5);printf("Anda hanya memiliki %i kesempatan lagi !",2-i);
          textcolor(LIGHTGREEN);          
      }
      i++;
     }while((strcmp(pass,pasword)!=0)&&(i!=3)); 
   clrscr();
   textcolor(LIGHTRED);
   ani();Sleep(9000);
return 0;    
}

void ani()
{
printf("         ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n");
printf("       ¶¶                ¶¶\n");
printf("     ¶¶        ¶¶         ¶¶\n");
printf("   ¶¶                        ¶¶\n");
printf("  ¶¶                          ¶¶\n");
printf("  ¶                           ¶´¶\n");
printf("´¶                ¶             ¶\n");
printf("´¶             ¶¶¶¶              ¶\n");
printf("´¶            ¶¶ ¶           ¶   ¶\n");
printf("´¶         ¶¶¶¶¶¶       ¶¶¶¶     ¶\n");
printf("´¶         ¶¶¶¶¶¶¶      ¶¶  ¶    ¶\n");
printf("  ¶        ¶¶¶¶¶´¶     ¶¶¶¶¶¶   ¶          SELAMAT TINGGAL !\n");
printf("  ¶¶       ¶     ¶    ¶¶¶¶¶¶   ¶¶\n");
printf("   ¶¶      ¶    ¶    ¶¶¶¶     ¶\n");
printf("    ¶      ¶   ¶     ¶       ¶\n");
printf("    ¶      ¶¶¶¶      ¶     ¶¶\n");
printf("    ¶¶              ¶¶¶  ¶\n");
printf("     ¶¶¶       ¶¶¶¶¶      ¶\n");
printf("       ¶¶¶     ¶¶       ¶¶\n");
printf("           ¶¶     ¶¶¶¶¶¶´\n");
printf("         ¶¶      ¶¶ ¶\n");
printf("       ¶¶¶¶        ¶´¶¶\n");
printf("        ¶  ¶¶     ¶   ¶\n");
printf("    ¶¶¶¶¶¶ ¶       ¶  ¶ \n");
printf("  ¶¶   ¶¶¶¶ ¶      ¶   ¶¶¶¶¶¶¶\n");
printf("  ¶¶      ¶¶¶¶     ¶ ¶¶     ¶¶\n");
printf("  ¶          ¶¶¶¶¶¶¶¶        ¶\n");
printf("   ¶¶        ¶   ¶          ¶\n");
printf("    ¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶¶¶¶¶¶¶¶");
}     

void buka_fileDTK()
{
  //buka file
  if((Pfk=fopen("DataKaryawan.txt","at"))==NULL) 
  {
    clrscr();  
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
    exit(1);                             
  }
} 
   
   
   
void Menu_Utama()
{

void DataKaryawan();
void DataAbsensiKaryawan();
void DataGajiKaryawan();

  do
  {                   
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("   Program Penggajian   ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Data Karyawan        ");
    gotoxy(28,7);printf("2. Data Absensi Karyawan");
    gotoxy(28,8);printf("3. Data Gaji Karyawan   ");
    gotoxy(28,9);printf("4. Keluar               ");
    gotoxy(28,11);printf("========================");
    gotoxy(28,12);printf("   Pilihan [1..4] = ");scanf("%i", &menu);     
   
    switch(menu)
   {       
      case 1:DataKaryawan();break;
      case 2:DataAbsensiKaryawan();break;
      case 3:DataGajiKaryawan();break;  
      case 4:exit(1);break;
   }
   gotoxy(24,15);textcolor(LIGHTRED);
   printf("Salah memasukkan pilihan! Ulangi!");
   gotoxy(26,16);textcolor(15);
   printf("Tekan Enter Untuk Melanjutkan");
   getch(); 
   }while((menu<=0)||(menu>4));        
}

void baca_fileDTK()
{
  //baca file
  if((Pfk=fopen("DataKaryawan.txt","rt"))==NULL)
  {
    clrscr();
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
   exit(1);                                   
  }
}

void file_ubahDTK()
{
  if((Pfk=fopen("DataKaryawan.txt","rt+"))==NULL)
  {
    clrscr();
    printf("Kesalahan File Tidak Dapat Dibuka!!\n");    
   exit(1);                                   
  }      
}     
 
void tambahDTK()
{   
   buka_fileDTK();
   do
   {
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan");
      gotoxy(31,3);printf("Input Data Karyawan");
      gotoxy(28,4);printf("==========================\n\n");
      printf(" NIK          \t : ");fflush(stdin);gets(penggajian.NIK);
      printf(" Nama         \t : ");fflush(stdin);gets(penggajian.nama);
      printf(" Alamat       \t : ");fflush(stdin);gets(penggajian.alamat);
      printf("\n ================\n");
      printf(" Pilihan Status\n");
      printf(" ================\n");
      printf(" 1. Menikah \n");
      printf(" 2. Belum Menikah \n");
      printf(" ================\n");
      printf(" Silahkan masukkan pilihan Status [1..2] : ");penggajian.status = getche();printf("\n");
      printf("\n ================\n");
      printf(" Pilihan Jabatan\n");
      printf(" ================\n");
      printf(" 1. Manager \n");
      printf(" 2. Sekretaris \n");
      printf(" 3. Bendahara \n");
      printf(" 4. Leader \n");
      printf(" 5. Operator \n");
      printf(" ================\n");
      printf(" Silahkan masukkan pilihan Jabatan [1..5] : ");penggajian.jabatan = getche();printf("\n");
      printf(" =================================\n");  
      keuangan();
      //masukan data mahasiswa ke file
      fwrite(&penggajian,sizeof(penggajian),1,Pfk);
      printf("\nMau Memasukan Data Lagi (Y/T)? ");
      jawab=getche();
    }while((jawab=='Y')||(jawab=='y'));
      
      //tutup file
      fclose(Pfk);
}

    
void tampilDTK()
{   
   clrscr();
   baca_fileDTK();
   nomor=0;
   gotoxy(34,2);printf("Data  Karyawan");
   gotoxy(31,3);printf("Tampil Data Karyawan");
   gotoxy(28,4);printf("==========================\n\n");
   printf
   (" ==============================================================================\n");
   printf
   (" | No |  NIK  |        Nama         |    Alamat    |    Status    |  Jabatan  |\n");
   printf
   (" ==============================================================================\n");
   for(;;)
   {
    fread(&penggajian,sizeof(penggajian),1,Pfk);
    if(feof(Pfk))break;
    printf(" | %i%3c%-5s%3c%-21s%c%-10s%5c%-14s%c%-11s%c\n",++nomor,'|', penggajian.NIK,'|'
    , penggajian.nama,'|',penggajian.alamat,'|',stts(penggajian.status),'|', jbtn(penggajian.jabatan),'|'); 
   }
   printf
   (" ==============================================================================\n");
   
   //tutup file
   fclose(Pfk);
}

void cari1()
{
   do
  {                    
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("PENCARIAN DATA  KARYAWAN");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Cari Berdasarkan NIP    ");
    gotoxy(28,7);printf("2. Cari Berdasarkan Nama   ");
    gotoxy(28,8);printf("3. Kembali                 ");
    gotoxy(28,9);printf("========================");
    gotoxy(28,10);printf("   Pilihan [1..3] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:cariDTK();break;        
      case 2:cariDTK2();break;
      case 3:DataKaryawan();break;
   }
   if((menu<=0)||(menu>3))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>3));           
}
     
void cariDTK()
{
  clrscr();
  baca_fileDTK();
  gotoxy(25,12);printf("Masukan NIK yang dicari : ");fflush(stdin);gets(z);  
  tdkketemu=1;  
  while(!feof(Pfk))
  {
    if(strcmp(penggajian.NIK,z)==0)
     {              
      tdkketemu=0;
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan\n");
      gotoxy(26,3);printf("Tampil Data Pencarian Karyawan\n");
      gotoxy(26,4);printf("==============================\n\n");
      gotoxy(19,5);printf("---------------------------------------------\n");
      gotoxy(19,6);printf("   NIK Karyawan    \t= %s\n", z);
      gotoxy(19,7);printf("   Nama Karyawan   \t= %s\n", penggajian.nama);
      gotoxy(19,8);printf("   Alamat          \t= %s\n", penggajian.alamat);
      gotoxy(19,9);printf("   Status          \t= %s\n", stts(penggajian.status));
      gotoxy(19,10);printf("   Jabatan         \t= %s\n", jbtn(penggajian.jabatan));
      gotoxy(19,11);printf("---------------------------------------------\n");
      break;
     }
      else
       fread(&penggajian,sizeof(penggajian),1,Pfk);    
  }
  if(tdkketemu==1)
  {
    gotoxy(30,16);printf("Data Tidak Ditemukan!!!");
  }
  
  //tutup file
  fclose(Pfk);
}

void cariDTK2()
{
  clrscr();
  baca_fileDTK();
  gotoxy(25,12);printf("Masukan Nama yang dicari : ");fflush(stdin);gets(nm);  
  tdkketemu=1;  
  while(!feof(Pfk))
  {
    if(strcmp(penggajian.nama,nm)==0)
     {              
      tdkketemu=0;
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan\n");
      gotoxy(26,3);printf("Tampil Data Pencarian Karyawan\n");
      gotoxy(26,4);printf("==============================\n\n");
      gotoxy(19,5);printf("---------------------------------------------\n");
      gotoxy(19,6);printf("   Nama Karyawan   \t= %s\n", nm);
      gotoxy(19,7);printf("   NIK Karyawan    \t= %s\n", penggajian.NIK);
      gotoxy(19,8);printf("   Alamat          \t= %s\n", penggajian.alamat);
      gotoxy(19,9);printf("   Status          \t= %s\n", stts(penggajian.status));
      gotoxy(19,10);printf("   Jabatan         \t= %s\n", jbtn(penggajian.jabatan));
      gotoxy(19,11);printf("---------------------------------------------\n");
      break;
     }
      else
       fread(&penggajian,sizeof(penggajian),1,Pfk);    
  }
  if(tdkketemu==1)
  {
    gotoxy(30,16);printf("Data Tidak Ditemukan!!!");
  }
  
  //tutup file
  fclose(Pfk);
}

void ubahDTK()
{
    awal: 
    tampilDTK();
    gotoxy(34,2);printf("Data  Karyawan");
    gotoxy(31,3);printf("Ubah Data Karyawan");
    gotoxy(28,4);printf("==========================\n\n");
    file_ubahDTK();
    do
    {
      
      gotoxy(28,20);printf("\n");
      printf(" Masukkan nomor record yang akan diubah [1..%i] : ",nomor);
             scanf("%d",&no_record);       
      /* atur penunjuk posisi file ke record yang di kehendaki */
      ofset_byte=(no_record-1)*sizeof(penggajian);
      fseek(Pfk,ofset_byte,SEEK_SET);
      /* baca record yang ditunjuk oleh penunjuk posisi file */
      hasil_baca=fread(&penggajian,sizeof(penggajian),1,Pfk);      
      if(hasil_baca==0)
        {
          printf(" Nomor record tak absah !\r\n");
        }
       else
        {
         printf("\n\n");
         printf(" ==============================================================\n");
         printf(" Edit Data Karyawan \n");
         printf(" ==============================================================\n\n");
         printf(" NIK Karyawan \t\t = %s\n",penggajian.NIK);
         printf("----------------------------------------------------\n");
         printf(" Data Sebelum Diubah\n");
         printf("----------------------------------------------------\n");
         printf("\n Nama Karyawan \t\t = %s\n", penggajian.nama);
         printf(" Alamat \t\t = %s\n", penggajian.alamat);
         printf(" Status \t\t = %s\n", stts(penggajian.status));
         printf(" Jabatan \t\t = %s\n", jbtn(penggajian.jabatan));

         printf("\n\n");
         printf("----------------------------------------------------\n");
         printf(" Data Yang Akan Diubah\n");
         printf("----------------------------------------------------\n");
         printf(" NIK          \t : ");fflush(stdin);gets(penggajian.NIK);
         printf(" Nama         \t : ");fflush(stdin);gets(penggajian.nama);
         printf(" Alamat       \t : ");fflush(stdin);gets(penggajian.alamat);
         printf("\n ================\n");
         printf(" Pilihan Status\n");
         printf(" ================\n");
         printf(" 1. Menikah \n");
         printf(" 2. Belum Menikah \n");
         printf(" ================\n");
         printf(" Silahkan masukan kode Status [1..2] : ");penggajian.status = getche();
         printf("\n =======\n");
         printf(" Pilihan Jabatan\n");
         printf(" =======\n");
         printf(" 1. Manager \n");
         printf(" 2. Sekretaris \n");
         printf(" 3. Bendahara \n");
         printf(" 4. Leader \n");
         printf(" 5. Operator \n");
         printf(" ================\n");
         printf(" Silahkan masukan kode Jabatan [1..5]: ");penggajian.jabatan = getche();printf("\n");
         printf("\n=================================\n");  

         /* atur penunjuk posisi file ke posisi sebelumnya*/
         fseek(Pfk,ofset_byte,SEEK_SET);

         /* rekam ulang */
         fwrite(&penggajian,sizeof(penggajian),1,Pfk);
       }//nelse
       cputs("\n\n Mau mengubah lagi (Y/T)?");
       jawab = getche();
       if((jawab=='Y'||jawab=='y'))
       { 
         clrscr();fclose(Pfk);goto awal;
       }         
    }while (jawab=='Y'||jawab=='y');
    
        
    /* tutup file */
   fclose(Pfk); 
}

void hapusDTK()
{  
  FILE *Pfhapusdtk;
  char *pstr1, *pstr2;
  int banding;
  char nik[16];
  
  do
  {
  clrscr();
  tampilDTK();
  gotoxy(34,2);printf("Data  Karyawan");
  gotoxy(31,3);printf("Hapus Data Karyawan");
  gotoxy(28,4);printf("==========================\n\n");  
  baca_fileDTK();  
  
  gotoxy(2,20);printf(" Masukkan NIK yang akan dihapus = ");fflush(stdin);gets(nik);
    
  
  for(;;){
    fread(&penggajian, sizeof(penggajian), 1, Pfk);
    if(feof(Pfk))break;

    //strcmp: membandingkan apa yg dicari dengan nik yang ada di dalam file
    //strlwr: string to lower, mengecilkan semua karakter
    pstr1 = nik;
    pstr2 = penggajian.NIK;
    banding = strcmp(strlwr(pstr1), strlwr(pstr2));

    if(banding != 0)
    {
     //open file
     if((Pfhapusdtk = fopen("bantu.txt", "at")) == NULL)
      {
       clrscr();
       printf("File tidak dapat dibaca !!\n");
       exit(1);
      }//nif
     //di fwrite ke file baru, selain yg dicari
     fwrite(&penggajian,sizeof(penggajian),1,Pfhapusdtk);
     fclose(Pfhapusdtk);
    }//nif

  }//nfor
  //tutup file
  fclose(Pfk);
  remove("DataKaryawan.txt");
  //rename file temp dengan current name
  rename("bantu.txt", "DataKaryawan.txt");

  cputs("\n\n Mau menghapus data lagi (Y/T)?");
  jawab = getche();
  }while (jawab=='Y'||jawab=='y');

  /* tutup file */
  fclose(Pfk);
}//nvoid 
        

void DataKaryawan()
{
  do
  {
   do
    {
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("     DATA  KARYAWAN     ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tambah Data          ");
    gotoxy(28,7);printf("2. Tampil Data          ");
    gotoxy(28,8);printf("3. Cari Data            ");
    gotoxy(28,9);printf("4. Ubah Data           ");
    gotoxy(28,10);printf("5. Hapus Data           ");
    gotoxy(28,11);printf("6. Kembali             ");
    gotoxy(28,13);printf("========================");
    gotoxy(28,14);printf("   Pilihan [1..6] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:tambahDTK();break;        
      case 2:tampilDTK();break;
      case 3:cari1();break;
      case 4:ubahDTK();break;
      case 5:hapusDTK();break;
      case 6:Menu_Utama();break;
    }
    if((menu<=0)||(menu>6))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>6));           
   
   printf("\n\n\n"); printf("\t\t Tekan M untuk kembali ke Menu Data Karyawan = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n");  
} 

void tambahDAK()
{
    awal:
    tampilDAK();
    gotoxy(34,2);printf("  Data Absensi");
    gotoxy(31,3);printf("Tambah Data Absensi");
    gotoxy(28,4);printf("==========================\n\n");
    file_ubahDTK();
     
    do
    {
      
      gotoxy(28,20);printf("\n");
      printf(" Masukkan nomor record yang akan dimasukkan Absen [1..%i] : ",nomor);
             scanf("%d",&no_record);       
      /* atur penunjuk posisi file ke record yang di kehendaki */
      ofset_byte=(no_record-1)*sizeof(penggajian);
      fseek(Pfk,ofset_byte,SEEK_SET);
      /* baca record yang ditunjuk oleh penunjuk posisi file */
      hasil_baca=fread(&penggajian,sizeof(penggajian),1,Pfk);      
      if(hasil_baca==0)
        {
          printf(" Nomor record tak absah !\r\n");
        }
       else
        {
         printf("\n\n");
         printf(" ==============================================================\n");
         printf(" Absensi Data Karyawan \n");
         printf(" ==============================================================\n\n");
         printf(" NIK Karyawan \t\t = %s\n",penggajian.NIK);
         printf("----------------------------------------------------\n");
         printf(" Data Karyawan\n");
         printf("----------------------------------------------------\n");
         printf("\n Nama Karyawan \t\t = %s\n", penggajian.nama);
         printf(" Alamat \t\t = %s\n", penggajian.alamat);
         printf(" Status \t\t = %s\n", stts(penggajian.status));
         printf(" Jabatan \t\t = %s\n", jbtn(penggajian.jabatan));

         printf("\n\n");
         printf("----------------------------------------------------\n");
         printf(" Data Absensi\n");
         printf("----------------------------------------------------\n");
         printf(" Pilihan Bulan\n");
         printf(" ================\n");
         printf(" a. Januari                g. Juli \n");
         printf(" b. Februari               h. Agustus \n");
         printf(" c. Maret                  i. September \n");
         printf(" d. April                  j. Oktober \n");
         printf(" e. Mei                    k. November \n");
         printf(" f. Juni                   l. Desember \n");
         printf(" ================\n");
         printf(" Silahkan masukkan pilihan Bulan [a..l] : ");penggajian.bulan = getche();printf("\n");
         printf(" \nKehadiran\n");
         printf(" ================\n");
         printf("\n Kehadiran Minggu Ke- 1 : ");scanf("%i",&penggajian.minggu1);
         printf("\n Kehadiran Minggu Ke- 2 : ");scanf("%i",&penggajian.minggu2);
         printf("\n Kehadiran Minggu Ke- 3 : ");scanf("%i",&penggajian.minggu3);
         printf("\n Kehadiran Minggu Ke- 4 : ");scanf("%i",&penggajian.minggu4);
         printf(" =================================\n");  
         penggajian.ket = (penggajian.minggu1 + penggajian.minggu2 + penggajian.minggu3 + penggajian.minggu4)/4;
         keuangan();
         /* atur penunjuk posisi file ke posisi sebelumnya*/
         fseek(Pfk,ofset_byte,SEEK_SET);

         /* rekam ulang */
         fwrite(&penggajian,sizeof(penggajian),1,Pfk);
       }//nelse
       cputs("\n\n Mau Input Absen lagi (Y/T)?");
       jawab = getche();
       if((jawab=='Y'||jawab=='y'))
       { 
         clrscr();fclose(Pfk);goto awal;
       }         
    }while (jawab=='Y'||jawab=='y');
      
      //tutup file
      fclose(Pfk);
}

void tampilDAK()
{
   clrscr();
   baca_fileDTK();
   nomor=0;
   gotoxy(34,2);printf("Data  Absensi\n");
   gotoxy(31,3);printf("Tampil Data Absensi\n");
   gotoxy(28,4);printf("==========================\n\n");
   printf
   (" ==============================================================================\n");
   printf
   (" | No |  NIK  |    Bulan    | Minggu 1 | Minggu 2 | Minggu 3 | Minggu 4 | Ket |\n");
   printf
   (" ==============================================================================\n");
   for(;;)
   {
    fread(&penggajian,sizeof(penggajian),1,Pfk);
    if(feof(Pfk))break;
    printf(" | %i%3c%-7s%c%-13s%c%-10i%c%-10i%c%-10i%c%-10i%c%2.f%c%3c\n",++nomor,'|', penggajian.NIK,'|'
    , bln(penggajian.bulan),'|',penggajian.minggu1,'|',penggajian.minggu2,'|',penggajian.minggu3,'|'
    ,penggajian.minggu4,'|',penggajian.ket,'%','|'); 
   }
   printf
   (" ==============================================================================\n");
   //| %i%3c%-7s%c%-8s%c%-3i%c%-3i%c%-3i%c%-3i%c%-3i%c%f%c
   //tutup file
   fclose(Pfk);     
}
void cariDAK()
{
  clrscr();
  baca_fileDTK();
  gotoxy(25,12);printf("Masukan NIK yang dicari : ");fflush(stdin);gets(z);  
  tdkketemu=1;  
  while(!feof(Pfk))
  {
    if(strcmp(penggajian.NIK,z)==0)
     {              
      tdkketemu=0;
      clrscr();
      gotoxy(34,2);printf("Data  Karyawan\n");
      gotoxy(26,3);printf("Tampil Data Pencarian Absensi\n");
      gotoxy(26,4);printf("==============================\n\n");
      gotoxy(19,5);printf("---------------------------------------------\n");
      gotoxy(19,6);printf(" NIK Karyawan                   = %s\n", z);
      gotoxy(19,7);printf(" Nama Karyawan                  = %s\n", penggajian.nama);
      gotoxy(19,8);printf(" Bulan                          = %s\n", bln(penggajian.bulan));
      gotoxy(19,9);printf(" Kehadiran Minggu ke-1          = %i %c\n", penggajian.minggu1,'%');
      gotoxy(19,10);printf(" Kehadiran Minggu ke-2          = %i %c\n", penggajian.minggu2,'%');
      gotoxy(19,11);printf(" Kehadiran Minggu ke-3          = %i %c\n", penggajian.minggu3,'%');
      gotoxy(19,12);printf(" Kehadiran Minggu ke-4          = %i %c\n", penggajian.minggu4,'%');
      gotoxy(19,13);printf(" Persentasi Kehadiran Bulan Ini = %2.f %c\n", penggajian.ket,'%');
      gotoxy(19,14);printf("---------------------------------------------\n");
      break;
     }
      else
       fread(&penggajian,sizeof(penggajian),1,Pfk);    
  }
  if(tdkketemu==1)
  {
    gotoxy(30,16);printf("Data Tidak Ditemukan!!!");
  }
  
  //tutup file
  fclose(Pfk);
}

void ubahDAK()
{
    awal:
    tampilDAK();
    gotoxy(34,2);printf("  Data Absensi");
    gotoxy(31,3);printf("Tambah Data Absensi");
    gotoxy(28,4);printf("==========================\n\n");
    file_ubahDTK();
     
    do
    {
      
      gotoxy(28,20);printf("\n");
      printf(" Masukkan nomor record yang akan Diubah [1..%i] : ",nomor);
             scanf("%d",&no_record);       
      /* atur penunjuk posisi file ke record yang di kehendaki */
      ofset_byte=(no_record-1)*sizeof(penggajian);
      fseek(Pfk,ofset_byte,SEEK_SET);
      /* baca record yang ditunjuk oleh penunjuk posisi file */
      hasil_baca=fread(&penggajian,sizeof(penggajian),1,Pfk);      
      if(hasil_baca==0)
        {
          printf(" Nomor record tak absah !\r\n");
        }
       else
        {
         printf("\n\n");
         printf(" ==============================================================\n");
         printf(" Ubah Data Absensi \n");
         printf(" ==============================================================\n\n");
         printf(" NIK Karyawan \t\t = %s\n",penggajian.NIK);
         printf("----------------------------------------------------\n");
         printf(" Data Sebelum Diubah\n");
         printf("----------------------------------------------------\n");
         printf("\n Bulan \t\t = %s\n", bln(penggajian.bulan));
         printf(" Kehadiran Minggu ke-1         = %i %c\n", penggajian.minggu1,'%');
         printf(" Kehadiran Minggu ke-2         = %i %c\n", penggajian.minggu2,'%');
         printf(" Kehadiran Minggu ke-3         = %i %c\n", penggajian.minggu3,'%');
         printf(" Kehadiran Minggu ke-4         = %i %c\n", penggajian.minggu4,'%');
         printf("\n\n");
         printf("----------------------------------------------------\n");
         printf(" Data Yang Akan Diubah\n");
         printf("----------------------------------------------------\n");
         printf(" Pilihan Bulan\n");
         printf(" ================\n");
         printf(" a. Januari                g. Juli \n");
         printf(" b. Februari               h. Agustus \n");
         printf(" c. Maret                  i. September \n");
         printf(" d. April                  j. Oktober \n");
         printf(" e. Mei                    k. November \n");
         printf(" f. Juni                   l. Desember \n");
         printf(" ================\n");
         printf(" Silahkan masukkan pilihan Bulan [a..l] : ");penggajian.bulan = getche();printf("\n");
         printf(" \nKehadiran\n");
         printf(" ================\n");
         printf("\n Kehadiran Minggu Ke- 1 : ");scanf("%i",&penggajian.minggu1);
         printf("\n Kehadiran Minggu Ke- 2 : ");scanf("%i",&penggajian.minggu2);
         printf("\n Kehadiran Minggu Ke- 3 : ");scanf("%i",&penggajian.minggu3);
         printf("\n Kehadiran Minggu Ke- 4 : ");scanf("%i",&penggajian.minggu4);
         printf(" =================================\n");  
         penggajian.ket = (penggajian.minggu1 + penggajian.minggu2 + penggajian.minggu3 + penggajian.minggu4)/4;
         keuangan();
         /* atur penunjuk posisi file ke posisi sebelumnya*/
         fseek(Pfk,ofset_byte,SEEK_SET);

         /* rekam ulang */
         fwrite(&penggajian,sizeof(penggajian),1,Pfk);
       }//nelse
       cputs("\n\n Mau Input Absen lagi (Y/T)?");
       jawab = getche();
       if((jawab=='Y'||jawab=='y'))
       { 
         clrscr();fclose(Pfk);goto awal;
       }         
    }while (jawab=='Y'||jawab=='y');
      
      //tutup file
      fclose(Pfk);
}
     
     
void DataAbsensiKaryawan()
{
  do
  {
   do
    {                     
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf(" DATA  ABSENSI KARYAWAN ");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tambah Data          ");
    gotoxy(28,7);printf("2. Tampil Data          ");
    gotoxy(28,8);printf("3. Cari Data            ");
    gotoxy(28,9);printf("4. Ubah Data           ");
    gotoxy(28,10);printf("5. Kembali             ");
    gotoxy(28,11);printf("========================");
    gotoxy(28,12);printf("   Pilihan [1..5] = ");scanf("%i", &menu);
    switch(menu)
    {
      case 1:tambahDAK();break;        
      case 2:tampilDAK();break;
      case 3:cariDAK();break;
      case 4:ubahDAK();break;
      case 5:Menu_Utama();break;
   }
   if((menu<=0)||(menu>5))
    {
     gotoxy(24,15);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,16);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>5));           
   
   printf("\n\n\n"); printf("\t Tekan M untuk kembali ke menu Data Absensi = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n");
}


void keuangan()
{    
  
  if((strcmp((jbtn(penggajian.jabatan)), "Manager")==0)&&(strcmp((stts(penggajian.status)), "Menikah")==0))
   {
      penggajian.gaji_pokok=8000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
      penggajian.tunga=0.05 * penggajian.gaji_pokok;
   }  
   else if((strcmp((jbtn(penggajian.jabatan)), "Manager")==0)&&
          ((strcmp((stts(penggajian.status)), "Belum Menikah")==0)||(strcmp((stts(penggajian.status)), "Tidak Ada")==0)))
   {
      penggajian.gaji_pokok=8000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
   } 
   else if((strcmp((jbtn(penggajian.jabatan)), "Sekretaris")==0)&&(strcmp((stts(penggajian.status)), "Menikah")==0))
   {
      penggajian.gaji_pokok=6000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
      penggajian.tunga=0.05 * penggajian.gaji_pokok;
   }  
    else if((strcmp((jbtn(penggajian.jabatan)), "Sekretaris")==0)&&
           ((strcmp((stts(penggajian.status)), "Belum Menikah")==0)||(strcmp((stts(penggajian.status)), "Tidak Ada")==0)))
   {
      penggajian.gaji_pokok=6000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
   }  
    else if((strcmp((jbtn(penggajian.jabatan)), "Bendahara")==0)&&(strcmp((stts(penggajian.status)), "Menikah")==0))
   {
      penggajian.gaji_pokok=5000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
      penggajian.tunga=0.05 * penggajian.gaji_pokok;
   } 
   else if((strcmp((jbtn(penggajian.jabatan)), "Bendahara")==0)&&
          ((strcmp((stts(penggajian.status)), "Belum Menikah")==0)||(strcmp((stts(penggajian.status)), "Tidak Ada")==0)))
   {
      penggajian.gaji_pokok=5000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
   } 
    else if((strcmp((jbtn(penggajian.jabatan)), "Leader")==0)&&(strcmp((stts(penggajian.status)), "Menikah")==0))
   {
      penggajian.gaji_pokok=4000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
      penggajian.tunga=0.05 * penggajian.gaji_pokok;
   } 
    else if((strcmp((jbtn(penggajian.jabatan)), "Leader")==0)&&
           ((strcmp((stts(penggajian.status)), "Belum Menikah")==0)||(strcmp((stts(penggajian.status)), "Tidak Ada")==0)))
   {
      penggajian.gaji_pokok=4000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
   } 
    else if((strcmp((jbtn(penggajian.jabatan)), "Operator")==0)&&(strcmp((stts(penggajian.status)), "Menikah")==0))
   {
      penggajian.gaji_pokok=2000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
      penggajian.tunga=0.05 * penggajian.gaji_pokok;
   } 
   else if((strcmp((jbtn(penggajian.jabatan)), "Operator")==0)&&
          ((strcmp((stts(penggajian.status)), "Belum Menikah")==0)||(strcmp((stts(penggajian.status)), "Tidak Ada")==0)))
    {
      penggajian.gaji_pokok=2000000;
      penggajian.tunja=0.2 * penggajian.gaji_pokok;
   } 
   else
   {
      penggajian.gaji_pokok=0;
      penggajian.tunja=0;
      penggajian.tunga=0;
   }
   penggajian.gaji_kotor = penggajian.gaji_pokok + penggajian.tunja + penggajian.tunga;
   penggajian.potongan = penggajian.gaji_pokok *((100-penggajian.ket)/100);
   penggajian.gaji_bersih = penggajian.gaji_kotor - penggajian.potongan;
} 


void tampil_DGK()
{
   clrscr();
   baca_fileDTK();
   nomor=0;
   gotoxy(34,2);printf("Data  Gaji Karyawan\n");
   gotoxy(31,3);printf("Tampil Data Gaji Karyawan\n");
   gotoxy(28,4);printf("==============================\n\n");
   printf("================================================================================");
   printf("| No |        Nama        |  Jabatan  |    Status    | Gaji Pokok |Gaji Bersih |");
   printf("================================================================================");
   for(;;)
   {
    fread(&penggajian,sizeof(penggajian),1,Pfk);
    if(feof(Pfk))break;
    printf("|%2i%3c%-20s%c%-11s%c%-14s%cRp.%-9ld%cRp.%-9ld%c",++nomor,'|', penggajian.nama,'|', 
    jbtn(penggajian.jabatan),'|', stts(penggajian.status),'|', penggajian.gaji_pokok,'|',penggajian.gaji_bersih,'|'); 
   }
   printf("================================================================================");

   //tutup file
   fclose(Pfk);
}
   
void cari_DGK()
{
  baca_fileDTK();
  gotoxy(22,14);printf("Masukan Nama Karyawan: ");fflush(stdin);gets(z); 
  tdkketemu=1;
  while(!feof(Pfk))
  {
    if(strcmp(penggajian.nama,z)==0)
    {              
    tdkketemu=0;
    clrscr();
    gotoxy(34,2);printf("Data  Karyawan\n");
    gotoxy(26,3);printf("Tampil Data Penggajian Karyawan\n");
    gotoxy(26,4);printf("===============================\n\n");
    gotoxy(19,5);printf("---------------------------------------------\n");
    gotoxy(19,6);printf("Nama Karyawan         \t: %s\n", z);
    gotoxy(19,7);printf("Jabatan Karyawan      \t: %s\n", jbtn(penggajian.jabatan));
    gotoxy(19,8);printf("Status Karyawan       \t: %s\n", stts(penggajian.status));
    gotoxy(19,9);printf("Gaji Pokok            \t: Rp. %8ld\n", penggajian.gaji_pokok);
    gotoxy(19,10);printf("Tunjangan Jabatan     \t: Rp. %8.f\n", penggajian.tunja);
    gotoxy(19,11);printf("Tunjangan Keluarga    \t: Rp. %8.f\n", penggajian.tunga);
    gotoxy(19,12);printf("Gaji Kotor            \t: Rp. %8ld\n", penggajian.gaji_kotor);
    gotoxy(19,13);printf("Potongan              \t: Rp. %8ld\n", penggajian.potongan);
    gotoxy(19,14);printf("=============================================\n");
    gotoxy(19,15);printf("Gaji Bersih           \t: Rp. %8ld\n", penggajian.gaji_bersih);
    gotoxy(19,16);printf("---------------------------------------------\n");
    break;
  }
  else
  fread(&penggajian,sizeof(penggajian),1,Pfk);    
  }
  if(tdkketemu==1)
  {
    gotoxy(30,17);printf("Data Tidak Ditemukan!!!");
  }
  
  //tutup file
  fclose(Pfk);
}


void DataGajiKaryawan()
{
  do
  {
   do
    {                     
    textcolor(LIGHTGREEN);
    clrscr();
    gotoxy(28,2);printf("DATA PENGGAJIAN KARYAWAN");
    gotoxy(28,3);printf("      Menu Pilihan      ");
    gotoxy(28,4);printf("========================");
    gotoxy(28,6);printf("1. Tampil Data          ");
    gotoxy(28,7);printf("2. Cari Data            ");
    gotoxy(28,8);printf("3. Kembali             ");
    gotoxy(28,10);printf("========================");
    gotoxy(28,11);printf("   Pilihan [1..3] = ");scanf("%i", &menu);
    switch(menu)
    {       
      case 1:tampil_DGK();break;
      case 2:cari_DGK();break;
      case 3:Menu_Utama();break;
   }
   if((menu<=0)||(menu>3))
    {
     gotoxy(24,20);textcolor(LIGHTRED);
     printf("Salah memasukkan pilihan! Ulangi!");
     gotoxy(26,21);textcolor(15);
     printf("Tekan Enter Untuk Melanjutkan");
     getch(); 
    }
   }while((menu<=0)||(menu>3));           
   
   printf("\n\n\n"); printf("\t Tekan M untuk kembali ke Menu Data Gaji Karyawan = ");
   kmbli_menu=getche();
  }while((kmbli_menu=='M')||(kmbli_menu=='m'));
  printf("\n\n"); 
}
