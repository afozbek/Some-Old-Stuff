// Yunus Emre AK 
// 1306150001
// Date : 14.12.2016 
// Development Environment : Visual Studio 2015
// D�kkat: Program t�rk�e karakterler de special char diye al�n�yor.
// Dikkat: Her bir karakterin tekrar etme say�s� g�sterilmektedir.(�zel karakterler ve say�lar da mevcuttur.)(sadece harfler de�il)
// Dikkat: Karakterleri tekrar�na g�re dizdi�imiz a�amada her harf ufak harf olarak ele al�nm��t�r, karakter boyutlar�n�da ay�raca eklemek i�in tolower'lari siliniz. (44 ~ 74)

#include <stdio.h> // Genel giri� ��k�� k�t�phanesi.
#include <stdlib.h> // Standart k�t�phane
#include <string.h> // String fonksiyonlar� i�in. �rn. strlen/strcpy
#include <locale.h> // T�rk�e karakteri tan�mlamak i�in gereken k�t�phane.
#include <ctype.h> // Tolower i�in.(Dev C++'da bu k�t�phane olmadan �al��m�yor.VS'de gerek yok.)
#define dim 400 // Girilen c�mlenin boyutu.
int fsize(char s[dim]) {
	int size;
	for (size = 0; s[size] != '\0'; size++);// NULL olana kadar artt�r�l�r. NULL son karakterdir.
	return size;
	// return strlen(s);
}
//Girilen c�mlenin boyutunu tan�mlama fonksiyonu.(strlen ile de yap�labilir.)
void fstrcpy(char s2[], const char s1[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		s2[i] = s1[i];
	}
	s2[i + 1] = '\0';
}
// strcpy fonksiyonu.
int fchoose(char s[dim]); // Fonksiyon tan�mlama. 
// Kullan�c�n�n girdi�i c�mleye g�re i�lem yapan program.(�nt. to Alg. �devi 1)
void f1(char s[dim], int size, int endsize) {
	for (int i = 0; i < size; i++) {
		if (i > size - endsize - 1)break; 
		printf("%c", s[size - i - 1]);
	}
}
//Tersten yaz�rma fonksiyonu.Size'dan ba�l�y�p endsize'a kadar yazar. (yaz�lacak c�mle,boyut,bitirici boyut)
void ftype(char s[dim]) {
	printf("Please type any sentence to do something.I'll ask u after you type\n For true reason dont use turkish char.\n(This program will show u all of chars. repetitions)\n");
	gets(s);
}
// C�mle girdisi alma fonsiyonu.
void fcbyc(const char s[dim], int size) {
	int c[dim] = { 0 };
	char t[dim];
	strcpy(t, s); // Dikkat: strcopy fonksiyonu yukar�da fstrcpy ile a��klanm��t�r.
	for (int a = 0; a < size; a++) { // Her bir karakteri(a) di�er karakterlere(b) g�re k�yaslama.
		for (int b = 0; b < size; b++) { // Birden fazla ayn� karaktere bakmamak i�in ayn� olan di�er karakterlerin sayisini ald�ktan sonra ' '(bo�luk) at�yoruz ki kontrol edilmesin.
			if (t[a] != ' '&&	tolower(t[a]) == tolower(t[b])) { c[a]++; if (a != b)t[b] = ' '; }
		}// tolower yaparak her harfi k���k harf olarak ele al�yoruz.
	}
	for (int a = 0; a < size; a++) {
		if (c[a] != 0)printf(" %c : %d ", tolower(t[a]), c[a]);
	}
}
// Karakterlerin tekrar�n� yazan fonksiyon.
void f6(const char s[dim], int size) {
	int b = 0;
	int c[dim] = { 0 };
	char t[dim];
	strcpy(t, s); // Warning
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			if (t[a] != ' '&&	tolower(t[a]) == tolower(t[b])) { c[a]++; if (a != b)t[b] = ' '; }
		}// t[b]'yi bo�luk yap�yoruz ki ayn� karakteri tekrardan sayaca sokmas�n.
	}
	printf(" "); // G�zel g�r�n�m i�in ilk k�sma bo�luk at�lm��t�r.
	for (int k = size; k>0; k--) {
		b = 0;
		for (int a = 0; a < size; a++) {
			if (c[a] != 0)
				if (c[a] == k) { b = 1; printf("%c", tolower(t[a])); }
			if (a == (size - 1) && b == 1)printf(" ");
			// b de�i�keninin olmas�n�n sebebi, e�er hi� bir harf yaz�lmazsa gereksiz yere bo�luk atmas�n diyedir.
			// a = size-1 olmas�n�n sebebi, e� say�da olan harflerin yaz�lmas� bitmeden bo�luk at�lmas�n diyedir.
		}
	}
}
//Karakterleri tekrarlar�na g�re yazan fonksiyon.
int fwords(char s[dim]) {
	int words = 1, i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')words++;
	}
	return words;
}
// Kelime say�s�n� bulan fonksiyon.
void f5(char s[dim]) { 
	int p, i, a, wsize[dim / 2] = { 0 }, wlenght[dim / 2] = { 0 }, t[dim / 2] = { 0 };
	// Wsize; Kelimenin uzunlu�u. Wlenght; Kelimenin ba�lang�ca olan uzakl���.
	// �rn; "how to make C" wsize[2]=2 wlenght[2]=6
	for (i = 1; s[i - 1] != '\0'; i++) { // Kelime biti�leri bo�luk veya �zel karakterlerle ifade edilir.
		if (s[i] == ' ' || s[i] == '\0' || s[i] == '.' || s[i] == '?' || s[i] == '!' || s[i] == ',' || s[i] == '_' || s[i] == '-' || s[i] == ':' || s[i] == ';') {
			for (a = 1; a <= i; a++) { // Kelimelerin uzunluklar�n� bir diziye kaydeder.
				if (wsize[a] == 0) { wsize[a] = i + 1 - wlenght[a - 1]; wlenght[a] = i + 1; break; }
			}
		}

	}
	for (p = 1; wsize[p] != 0; p++) {// B�y�k oldu�u her say� i�in 1 puan al�yor.
		for (int j = 1; wsize[j] != 0; j++)
			if (wsize[p] > wsize[j])t[p]++;
	}
	for (int k = 1; k < p + 1; k++) {
		for (int j = 1; j < p + 1; j++) {
			if (t[j] == p - k) { // Puan� en y�ksek olan� ilk yaz�yor
				for (int i = wlenght[j] - wsize[j]; i < wlenght[j]; i++) {
					if (i == (wlenght[j] - wsize[j]) || i == (wlenght[j] - 1))printf(" ");
					printf("%c", s[i]);
				}
				//wlenght -wsize 'dan ba�lat wsize kadar yazd�r.
			}
		}
	}

}
// Kelimelerin uzunllu�unu bulap, uzunluguna g�re s�ralayan fonksiyon.
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
//Terstten kelime kelime yazan fonksiyon.
int fspc(char s[dim]) {
	int size, temp = 0;
	size = fsize(s);
	char a[33] = { 'a','b','c','�','d','e','f','g','�','h','�','i','j','k','l','m','n','o','�','p','r','s','�','t','u','�','v','y','z','q','w','x' };
	char b[33] = { 'A','B','C','�','D','E','F','G','�','H','I','�','J','K','L','M','N','O','�','P','R','S','�','T','U','�','V','Y','Z','Q','W','X' };
	char c[33] = { '0','1','2','3','4','5','6','7','8','9',' ' };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j<33; j++) // Her �zel karakter olmayan karakter icin 1 artiyor.
			if (s[i] == a[j] || s[i] == b[j] || s[i] == c[j])temp++;
	}
	return size - temp; // �zel karakter say�s�= Toplam karakter - �zel olmayan karakter say�s�.

}
// �zel karakter say�s�n� bulan fonksiyon.
void fprint(char s[dim], int size) {
	int i;
	printf("\nThe input is :\n ");
	for (i = 0; i < size; i++) { //Diziler 0 dan ba�lar s[0]. Bu sebeple i=0'dan ba�l�yoruz ve size'a kadar yaz�yoruz.(s[size]=NULL)
		printf("%c", s[i]);
	}
}
// Girdiyi yazd�ran fonksiyon.
int fmain(char s[dim]) {
	fprint(s, fsize(s));
	printf("\n---------------------------------------------------------\nThe reverse of the sentence:\n---------------------------------------------------------\n"); f1(s, fsize(s), 0);
	printf("\n---------------------------------------------------------\n"); f2(s);
	printf("\n---------------------------------------------------------\nCounts:\n---------------------------------------------------------\n Characters: %d	Words: %d	Special Char: %d", fsize(s), fwords(s), fspc(s));
	printf("\n---------------------------------------------------------\nEach character repetition:\n---------------------------------------------------------\n"); fcbyc(s, fsize(s)); printf("\n");
	printf("\n---------------------------------------------------------\nThe words by length\n---------------------------------------------------------\n"); f5(s);
	printf("\n---------------------------------------------------------\nCharacters by repetition:\n---------------------------------------------------------\n"); f6(s, fsize(s));
	printf("\n---------------------------------------------------------\n");
	return fchoose(s);
}
//Hepsini yazd�ran fonksiyon.
int fchoose(char s[dim]) {
	char answer[dim];
	printf("\n---------------------------------------------------------\nType any number(between 0-6(with 0 & 6)) to do any thing\n--) Retype sentence if u want to change(ex. hello guys)\n1-) Write reverse of the sentence\n2-) Write reverse in words\n3-) Write Counts\n4-) Counts each character repetition\n5-) Order the words by length\n6-) Order characters by repetition\n7-) For exit\n0-) For show all.\n---------------------------------------------------------\n");
	gets(answer);
	if (answer[0] == '0') return fmain(s);
	else if (answer[0] == '1') {
		printf("\n---------------------------------------------------------\nThe reverse of the sentence:\n---------------------------------------------------------\n"); f1(s, fsize(s), 0);
	}
	else if (answer[0] == '2') {
		printf("\n---------------------------------------------------------\n"); f2(s);
	}
	else if (answer[0] == '3') {
		printf("\n---------------------------------------------------------\nCounts:\n---------------------------------------------------------\n Characters: %d	Words: %d	Special Char: %d", fsize(s), fwords(s), fspc(s));
	}
	else if (answer[0] == '4') {
		printf("\n---------------------------------------------------------\nEach character repetition:\n---------------------------------------------------------\n"); fcbyc(s, fsize(s));
	}
	else if (answer[0] == '5') {
		printf("\n---------------------------------------------------------\nThe words by length\n---------------------------------------------------------\n"); f5(s);
	}
	else if (answer[0] == '6') {
		printf("\n---------------------------------------------------------\nCharacters by repetition:\n---------------------------------------------------------\n"); f6(s, fsize(s));
	}
	else if (answer[0] == '7')return 0;
	else {
		printf("\n---------------------------------------------------------\n");
		strcpy(s, answer); fprint(s, fsize(s)); //Yeni veriyi eskisinin yerine kopyalar.
	}
	return fchoose(s); //Ba�a sarma kodu.
}
// Se�im yapma fonksiyonu.
int main() {
	char s[dim];
	ftype(s);
	fprint(s, fsize(s));
	fchoose(s);
	printf(" Thank u for using my program :)\n\n");
	system("PAUSE");
}
// Ana fonksiyon.
