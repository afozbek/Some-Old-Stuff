#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define boyut 200

void f2(char s[dim]) {// Sorunlu--------
	printf("The reverse in words of the sentence :\n---------------------------------------------------------\n");
	int i, wlenght[dim / 2] = { 0 }, a;// Dikkat !
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i+1] == ' ' || s[i+1] == '\0') { // Kelimelerin bitti�i nokta bo�luk veya NULL oldu�u i�in bu ko�ullara g�re i�lem yap�yoruz.
			for (a = 1; a <= i+1; a++) { // Bo�luklar�n bulundu�u s�ray� kaydediyoruz.
				if (wlenght[a] == 0) { // E�er atanm�� de�er varsa de�i�tirmemesi i�in sadece 0 oldu�unda(de�er atanmam��sa) atama de�eri yap�yoruz.
				 wlenght[a] = i + 2;f1(s,wlenght[a], wlenght[a - 1]); // 2 bo�luk aras�ndaki karakterleri yazd�r�yoruz.
				 break;// Birden fazla yazd�rma islemi olmamasi i�in break ile d�ng�den cikiyoruz. 
				 }
			}
		}
	}
}
int main()
{
	f2(char s[dim]);
}
