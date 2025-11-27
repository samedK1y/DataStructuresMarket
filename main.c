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
    struct Urun s1;
    printf("Urun adini giriniz: ");
    scanf("%s", &s1.urunAdi);
    printf("Urun fiyatini giriniz: ");
    scanf("%f", &s1.fiyat);
    printf("Urunun stok fiyatini giriniz: ");
    scanf("%d", &s1.stok);

    printf("\n\nUrun Adi: %s \t Urun fiyati: %0.01f \t Stok Adedi: %d", s1.urunAdi, s1.fiyat, s1.stok);
}