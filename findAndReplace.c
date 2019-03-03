// Programa kullanıcı tarafından 3 argüman girilecektir. 1. argüman aranacak ifadeyi, 2. argüman değiştirilecek yeni ifadeyi, 3. argüman ise ifadenin aranacağı dosyanın ismidir.
// Eğer aranan ifade dosyada bulunuyorsa ifadenin bulunduğu konumu veya konumları (kaçıncı karakter) yeni ifade ile değiştirecek, eğer ifade bulunmaz ise buna dair uygun bir mesaj gösterecek olan c programı.

#include<stdio.h>
#include<string.h>

int main(char argc,char *argv[]){

char *aranan=argv[1];
char *yeniKelime=argv[2];
char *dosyaYolu=argv[3];

FILE *dosya1=fopen(dosyaYolu,"r");
FILE *dosya2=fopen("yedek.txt","w");
char pointer;
int i,j;

int eslesenHarf=0;
int eslesenKelime=0;
int arananUzunluk=strlen(aranan);
int yeniKelimeUzunluk=strlen(yeniKelime);

printf("aranan kelime: %s | uzunluğu: %d \n",aranan,arananUzunluk);
printf("yeni Kelime: %s | uzunluğu: %d \n",yeniKelime,yeniKelimeUzunluk );

if(dosya1==NULL)
printf("dosya bulunamadı \n");
else{

	printf("dosya açıldı \n");

	pointer=fgetc(dosya1);
	i=0;

	do{

		for(j=0;j<arananUzunluk;j++){
			printf("i=%d %c==%c \n",i,pointer,aranan[j]);
			if(pointer==aranan[j]){
				eslesenHarf++;}

			pointer=fgetc(dosya1);

			if(pointer==EOF){
				break;}

		}//end for

		if(eslesenHarf==arananUzunluk){
			eslesenKelime++;
			printf("%d. indiste %s bulundu ve %s ile değiştirildi \n",i,aranan,yeniKelime);
			fprintf(dosya2,"%s",yeniKelime);
			i=i+arananUzunluk-1;
			fseek(dosya1,i,SEEK_SET);
		}//end if

		else{
			fseek(dosya1,i,SEEK_SET);
			pointer=fgetc(dosya1);
			fprintf(dosya2,"%c",pointer);
		}//end else
		pointer=fgetc(dosya1);
		i++;
		eslesenHarf=0;
	}while(pointer!=EOF);//end do while loop

	remove(dosyaYolu);
	rename("yedek.txt",dosyaYolu);
	fclose(dosya2);
	printf("bulunan kelime sayısı: %d \n",eslesenKelime);

}//end else

return 0;
}//end main
