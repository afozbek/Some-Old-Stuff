#include <stdlib.h>
#include <stdio.h>
main() {
	int answer;
	printf("\nWelcome to unnecessary painter program, it's realy unnecessary so how do you \nwanna dilly-dally(linger) =D\nType 0 for exit\nType 1 to draw square\nType 2 to draw right triangle\nType 3 to draw reverse right triangle\nType 4 to draw right triangle with number\nType 5 to draw equilateral quadrangle(eskenar dortgen)\n");
	scanf("%d", &answer);// Al�nan veriyi answer adl� de�ere verir.
	if (answer == 0) {
		printf("But i wanna draw something for u :'(\n");
		system("PAUSE");
		return 0;
	}
	printf("Enter rows to create that unnecessary figure :D\n");//Kullan�c�dan bir say� ister o say� kadar sat�r'a sahip �ekil olu�turulur.
	int i, a, r, b, c; //Tan�mlanan say�lar�n tamsay� oldu�unu ifade eden kod dizisi.
	scanf("%d", &r);//Kullan�c�dan veri isteme.
	printf("------------------------\n");
	switch (answer) {

	case 1: //Kare �izme program�.
		for (int i = 1; i <= r; ++i) {//i, s�ras�yla 1,2,3,4...r de�erlerini al�r. r kez i�lem tekrarlan�r.
			for (int a = 1; a <= r; ++a) {// r-1+1=r kez * koyulur.
				printf("* ");
			}
			printf("\n");// * koyma i�lemi bitince sat�r ge�ilir.
		}
		break;
	case 2://Dik ��gen �izme program�
		for (int i = 1; i <= r; ++i) {//i, s�ras�yla 1,2,3,4...r de�erlerini al�r. r kez i�lem tekrarlan�r.
			for (int a = 1; a <= i; ++a) {//a, s�ras�yla 1,2,3...i de�erlerini al�r.
				printf("* ");
			}
			printf("\n");// * koyma i�lemi bitince sat�r ge�ilir.
		}

	
		break;
	case 3:// Ters dik ��gen �izme program�
		for (int i = r; i >= 1; --i) {// i, s�ras�yla r,r-1....1 de�erlerini al�r. r-1+1=r kez tekrarlan�r.
			for (int b = 1; b <= i; b++) {//b, s�ras�yla 1,2,3,4...i de�erlerini al�r. i-1+1=i kez tekrarlanir.
				printf("* ");
			}
			printf("\n");// * koyma i�lemi bitince sat�r ge�ilir.
		}

		break;
	case 4://Dik ��gen �izme program�
		for (int i = 1; i <= r; ++i) {//i, s�ras�yla 1,2,3,4...r de�erlerini al�r. r kez i�lem tekrarlan�r.
			for (int a = 1; a <= i; ++a) {//a, s�ras�yla 1,2,3...i de�erlerini al�r.
				printf("%d",a);;// a de�erlerini ekrana yansitir.
			}
			printf("\n");// * koyma i�lemi bitince sat�r ge�ilir.
		}
		
		break;
		
	case 5://E�kenar d�rtgen �izme program�.
		for (int i = 1; i <= r; ++i) {//i ,s�ras�yla 1,2,3...r de�erlerini al�r.r kez i�lem yap�l�r.
			for (int a = 2 * r - 2; a > 2 * i - 2; --a) {//r ye g�re a de�eri tan�mlan�r ve her baslang��ta (2r-2)-(2i-2)=2r-2i kadar bo�luk at�l�r.
				printf(" ");
			}
			for (b = 1; b < 2 * i; ++b) {// 2i-1 kadar * simgesi konulur.
				printf("* ");
			}


			printf("\n");//Her i�lem biti�inde sat�r ge�ilir.
		}
		for (int i = 1; i <= r - 1; ++i) {//i, s�ras�yla 1,2,3,4,5,6...r-1 de�erlerini al�r. r-1-1+1=r-1 kere i�lem yap�l�r.
			for (int a = 1; a <= 2 * i; a++) {//2i-1+1=2i tane bo�luk konulur.
				printf(" ");
			}
			for (int b = 2 * i - 1; b < 2 * r - 2; ++b) {//2r-2-(2i-1)=2r-2i-1 tane * simgesi konulur.
				printf("* ");
			}
			printf("\n");// Her i�lem biti�inde sat�r atlan�r.
		}
		break;
	case 6://yap�m a�amas�nda...
		
	default: break;

	}
	printf("\n Hehehe i (always) succeed :P\n\n\n");// Program ba�ard��� i�in sevinir :D
	system("PAUSE");//Hemen kapanmamas� i�in bir komut dizisi.
}
