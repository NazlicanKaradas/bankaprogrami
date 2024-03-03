#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void yeni();
void listele();
void sil();
void borctoplami();

int main()
{ int a,b;
bas:
printf ("Yeni bir dosya icin 1 ---> \nListelemek icin 2 ---> \nKayit silmek icin 3 ---> \nToplam borc ogrenmek icin 4 ---> \n");
printf ("\nLutfen tercihinizi giriniz: ");
scanf ("%d",&a);
if (a==1) yeni();
if (a==2) listele();
if (a==3) sil();
if (a==4) borctoplami();
printf ("baska islem varsa 1, yoksa 2 giriniz\n");
scanf ("%d",&b);
if (b==1) {system("CLS"); goto bas;}
if (b==2) {
son:
getch();
return 0; } }
 

void yeni()
{
 	int musterino, borc;
 	char isim[30], telno[30];
 	FILE *cfPtr;
 	
 	if((cfPtr=fopen("borc.txt","w"))==NULL)
 	printf("dosya acilamadi\n");
 	else{
 		printf ("musteri numarasini giriniz: ");
 		scanf("%d",&musterino);
 		printf( "musteri ad-soyad giriniz: " );
        scanf ("%s",isim);
        printf( "musteri tel numarasini giriniz: " );
        scanf ("%s",telno);
        printf( "musteri bakiyesini giriniz: " );
        scanf ("%d",&borc); 
	    }
while( !feof( stdin ) ) 
     {
     fprintf( cfPtr, "%d %s %s %d \n", musterino, isim, telno, borc );
     printf( "musteri numarasini giriniz: " );
     scanf("%d",&musterino);
     printf( "musteri ad-soyad giriniz: " );
     scanf("%s",isim);
     printf( "musteri tel numarasini giriniz: " );
     scanf("%s",telno);
     printf( "musteri bakiyesini giriniz: " );
     scanf("%d",&borc);
     } 
fclose(cfPtr);
}

void listele()
{ 
    int musterino,borc;
    char isim[30],telno[30];
    FILE *cfPtr;
    
    if ((cfPtr=fopen("borc.txt","r"))==NULL)
    printf( "Dosya acilmadi\n" );
    else{
        printf( "%-10s%-13s%-13s%-13s\n", "Musteri No", "Isim", "Telno", "Borc Toplami" );
        fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
        while(!feof(cfPtr))
		{
        printf( "%-10d%-13s%-17s%-10d\n", musterino, isim, telno, borc);
        fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
        }
        printf( "%-10d%-13s%-17s%-10d\n", musterino, isim, telno, borc);
        fclose( cfPtr );
		} 
} 

void sil()
{ 
    int musterino,silno,borc;
    char isim[30],telno[30],dogum[30];
    FILE *cfPtr;
    FILE *silcfPtr;
    printf("Silmek istediginiz musterinin numarasini giriniz : \n");
    scanf("%d", &silno);
    cfPtr = fopen("borc.txt","r");
    silcfPtr = fopen("yeniborc.txt","w");
    fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
    while(!feof( cfPtr )) 
    {
    if( silno!=musterino ) 
	{
    fprintf( silcfPtr, "%d %s %s %d \n", musterino, isim, telno, borc ); }
    fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
    }
    if( silno!=musterino ) { fprintf( silcfPtr, "%d %s %s %d \n", musterino, isim, telno, borc );}
    fclose( cfPtr );
    fclose( silcfPtr );
    remove("borc.txt"); // Dosya silinir.
    rename("yeniborc.txt","borc.txt"); // geçici dosyanýn ismi asýl dosya ismi deðiþtirilir.
}

void borctoplami()
{ 
    int musterino,borc,gtop=0;
    char isim[30],telno[30];
    FILE *cfPtr;
    if ( ( cfPtr = fopen( "borc.txt", "r" ) ) == NULL )
    printf( "Dosya acilmadi\n" );
    else
	{
    fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
    while(!feof( cfPtr )) 
	{
    gtop=gtop+borc;
    fscanf( cfPtr, "%d %s %s %d ", &musterino, isim, telno, &borc );
    }
    gtop=gtop+borc;
    fclose( cfPtr );
    }
    printf("toplam bakiye= %d\n",gtop);
}

