void fterskelime(char dizi[],int size){// 2. �dev....
	int j=1,i,a,ksize[boyut]={0},kelimesayisi=1;
	for(i=0;i<size;i++)if(dizi[i]==' ')kelimesayisi++;// Kelime say�s� bulundu.
	for(j=1;j<=kelimesayisi;j++){// Kelime say�s� j
		for(i=0;i<=size;i++){// Dizideki karakter diz[1] ...
			if(dizi[i]==' ' || dizi[i]=='\0'){// Kelimeler bo�luklarla veya NULL ile son buldu�u i�in if i�inde ' ' veya NULL 
				for(a=1;a<=j;a++)
				if(i!=ksize[j-a]){ // �ncekilerine e�it de�ilse atas�n. (ayn� de�erden 1den fazla olmas�n).
					ksize[j]=i;// atama .
					break; // 1. kelimeye 1den fazla de�er atamams� i�in.
				}
			}
		}
	}
	for(j=1;j<=kelimesayisi;j++){ // Kelime say�s� kadar tekrar eder.
		for(i=ksize[j]-1;i>=ksize[j-1];i--){ // 2 bo�luk aras�n� yazd�r�r.
			printf("%c",dizi[i]);
		}
		printf(" ");
	}
}
