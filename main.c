#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Urun
{
    char urunAdi[30];
    float fiyat;
    int stok;
};
void listele(struct Urun *urunler, int n)
{

    printf("\n\n----URUN LİSTESİ----\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nUrun Adi: %s \t Urun fiyati: %0.01f \t Stok Adedi: %d\n", urunler[i].urunAdi, urunler[i].fiyat, urunler[i].stok);
    }
}
void ara(struct Urun *urunler, int n)
{
    char araİsim[30];
    printf("Aranacak ürünün ismini girin:");
    scanf("%s", araİsim);
    int bulundu = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(araİsim, urunler[i].urunAdi) == 0)
        {
            bulundu = 1;
            printf("Aradiginiz Urun:\nUrun adi: %s\tUrun Fiyati:%0.01f\tStok Adedi: %d\n", urunler[i].urunAdi, urunler[i].fiyat, urunler[i].stok);
            break;
        }
    }
    if (!bulundu)
    {
        printf("Aradiginiz urun bulunamadi!");
    }
}
void guncelle(struct Urun *urunler, int n)
{
    char updateName[30];
    printf("Guncellemek istedigin urun ismini gir:");
    scanf("%s", updateName);
    int bulundu = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(updateName, urunler[i].urunAdi) == 0)
        {
            printf("%s 'nin;\nYeni Fiyati:", urunler[i].urunAdi);
            scanf("%f", &urunler[i].fiyat);
            printf("%s 'nin;\nYeni Stok Adedi:", urunler[i].urunAdi);
            scanf("%d", &urunler[i].stok);
            bulundu = 1;
            break;
        }
    }
    if (!bulundu)
    {
        printf("Aradiginiz urun bulunamadi!");
    }
}

int main()
{
    struct Urun *urunler;
    int n, i;
    printf("Kac tane urun girilecek: ");
    scanf("%d", &n);

    urunler = malloc(n * sizeof(struct Urun));

    if (urunler == NULL)
    {
        printf("Bellek Ayrilamadi...");
        return 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Urun adini giriniz:");
            scanf("%s", urunler[i].urunAdi);
            printf("Urun fiyatini giriniz: ");
            scanf("%f", &urunler[i].fiyat);
            printf("Urunun stok adedini giriniz: ");
            scanf("%d", &urunler[i].stok);
        }
        int secim;
        while (1)
        {
            printf("\n1- Listele\n2- Ara\n3- Güncelle\n4- Cikis\nSecim: ");
            scanf("%d", &secim);

            if (secim == 1)
            {
                listele(urunler, n);
            }
            else if (secim == 2)
            {
                ara(urunler, n);
            }
            else if (secim == 3)
            {
                guncelle(urunler, n);
            }
            else if (secim == 4)
                break;
            else
            {
                printf("Lutfen deger araligindan bir sayi giriniz.");
            }
        }
    }
    free(urunler);
}