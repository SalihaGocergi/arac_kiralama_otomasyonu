#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Araclar
{
    int id;
    char plaka[20];
    char model[20];
    char y_turu[20];
    char v_turu[20];
    int gUcret;
    struct Araclar *sonraki;
}arac;
arac *ilk=NULL, *son=NULL, *gecici;
typedef struct Musteriler
{
    char ad[20];
    char soyad[20];
    char adres[50];
    char tc[11];
    char ehliyetNo[30];
    arac *araclar;
    int aSayisi;

}musteri;


void KayitEkle();
void KayitSil();
void KayitListele();
void AracKiralama();
int main()
{
    int secim;
    while(1)
    {

        printf("---------------------OTO KIRALAMA OTOMASYONU--------------------- \n\n");
        printf("\t\t Arac Eklemek icin:                            '1' e basin. \n");
        printf("\t\t Arac Silmek icin:                             '2' ye basin. \n");
        printf("\t\t Guncel Arac Listesi icin:                     '3' e basin. \n");
        printf("\t\t Arac Kiralama icin:                           '4' e basin. \n");
        printf("\t\t Kiralanan Arac Listesi icin:                  '5' e basin. \n");
        printf("\t\t Cikis:                                        '6' e basin. \n");
        printf("-----------------------------------------------------------------\n");
        printf("\t Bir islem Seciniz:");
        scanf("%d",&secim);
    switch(secim)
    {

    case 1:

        KayitEkle();
    break;

    case 2:
        KayitSil();
    break;

    case 3:
        KayitListele();
    break;

    case 4:
        AracKiralama();
    break;

    case 5:

    break;
    case 6:
       exit(0);
    break;
    }
    }

    return 0;
}

void KayitEkle()
{
    arac *araclar;
    araclar=(arac*)malloc(sizeof(arac));
    FILE *aDosya;
    printf("Arac ID numarasini giriniz:\n");
    scanf("%d",&araclar->id);
    printf("Aracin plakasini giriniz:\n");
    scanf("%s",araclar->plaka);
    printf("Aracin modelini giriniz:\n");
    scanf("%s",araclar->model);
    printf("Aracin yakit turunu giriniz:\n");
    scanf("%s",araclar->y_turu);
    printf("Aracin vites tipini giriniz:\n");
    scanf("%s",araclar->v_turu);
    printf("Aracin gunluk ucretini giriniz:\n");
    scanf("%d",&araclar->gUcret);

    aDosya=fopen("araclar.txt","a");

    if(aDosya==NULL)
    {
        printf("Dosya Acilamadi...");
        exit(0);
    }
    fprintf(aDosya,"\n%d %s %s %s %s %d\n",araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,araclar->gUcret);
    printf("Kayit isleminiz tamamlanmistir.\n");
    fclose(aDosya);


}

void KayitSil()
{
    arac *araclar;
    arac *onceki=NULL;
    char aranan[20];
    FILE *aDosya;
    aDosya=fopen("araclar.txt","r");
    printf("\n---Arac Listesi---\n");
    while(!feof(aDosya))
    {

        araclar=(arac*)malloc(sizeof(arac));
        fscanf(aDosya,"%d %s %s %s %s %d\n",&araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,&araclar->gUcret);
        printf("%d %s %s %s %s %d\n",araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,araclar->gUcret);

    }
    printf("\n------------------------------\n");
    fclose(aDosya);


    printf("Silmek istediginiz aracin plakasini giriniz:\n");
    scanf("%s",aranan);
    gecici=ilk;

    while(gecici !=NULL)
    {
        if(strcmp(gecici->plaka,aranan)==0)
        {
            break;
        }
        onceki=gecici;
        gecici=gecici->sonraki;
    }
    if(gecici==NULL)
    {
        printf("Silinmek istenilen %s plakali arac bulunamadi...\n",aranan);
    }
    else
    {
        if(gecici==ilk)
        {
            ilk=gecici->sonraki;
        }
        else if(gecici==son)
        {
           son=onceki;
           son->sonraki=NULL;
        }
        else
        {
            onceki->sonraki=gecici->sonraki;
        }
        free(gecici);
        printf("%s plakali arac silinmistir...\n",aranan);

    }



}

void KayitListele()
{
    int i=0;
    arac *araclar;
    FILE *aDosya;
    aDosya=fopen("araclar.txt","r");
    printf("\n---Arac Listesi---\n");
    while(!feof(aDosya))
    {

        araclar=(arac*)malloc(sizeof(arac));
        fscanf(aDosya,"%d %s %s %s %s %d\n",&araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,&araclar->gUcret);
        printf("%d %s %s %s %s %d\n",araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,araclar->gUcret);

    }
    fclose(aDosya);
}

void AracKiralama()
{
    char eklenen[20];
    musteri *musteriler;
    arac *araclar;
    musteriler=(musteri*)malloc(sizeof(musteri));
    FILE *mDosya;
    printf("Musteri adini giriniz:\n");
    scanf("%s",musteriler->ad);
    printf("Musteri soyadini giriniz:\n");
    scanf("%s",musteriler->soyad);
    printf("Musteri adresini giriniz:\n");
    scanf("%s",musteriler->adres);
    printf("Musteri TC numarasini giriniz:\n");
    scanf("%s",musteriler->tc);
    printf("Musteri ehliyet numarasini giriniz:\n");
    scanf("%s",musteriler->ehliyetNo);
    ///printf("Kiralanacak arabanin ID numarasini giriniz:\n");
    ///scanf("%d",&(musteriler->araclar)->id);
    mDosya=fopen("musteriler.txt","a");

    if(mDosya==NULL)
    {
        printf("Dosya Acilamadi...");
        exit(0);
    }
    fprintf(mDosya,"\n%s %s %s %s %s \n",musteriler->ad,musteriler->soyad,musteriler->adres,musteriler->tc,musteriler->ehliyetNo);
    printf("Kayit isleminiz tamamlanmistir.\n");
    fclose(mDosya);

    FILE *aDosya;
    aDosya=fopen("araclar.txt","r");
    while(!feof(aDosya))
    {
        araclar=(arac*)malloc(sizeof(arac));
        fscanf(aDosya,"%d %s %s %s %s %d\n",&araclar->id,araclar->plaka,araclar->model,araclar->y_turu,araclar->v_turu,&araclar->gUcret);

    }
    printf("\n------------------------------\n");
    printf("\nKiralamak istediginiz aracın plakasini giriniz:\n");
    scanf("%s\n",eklenen);

    while(!feof(aDosya))
    {
        if(strcmp(araclar->plaka,eklenen)==0)
        {
            break;
        }
    }


    printf("\n------------------------------\n");
    fclose(aDosya);

}


