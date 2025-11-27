#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Urun
{
    char urunAdi[30];
    float fiyat;
    int stok;
};

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
        for (i = 0; i < n; i++)
        {
            printf("Urun adini giriniz: ");
            scanf("%s", urunler[i].urunAdi);
            printf("Urun fiyatini giriniz: ");
            scanf("%f", &urunler[i].fiyat);
            printf("Urunun stok fiyatini giriniz: ");
            scanf("%d", &urunler[i].stok);
        }
        printf("\n\n----URUN LİSTESİ----\n\n");
        for (i = 0; i < n; i++)
        {
            printf("\nUrun Adi: %s \t Urun fiyati: %0.01f \t Stok Adedi: %d\n", urunler[i].urunAdi, urunler[i].fiyat, urunler[i].stok);
        }
    }
    free(urunler);
}