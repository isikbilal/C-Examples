// Kullanıcı tarafından programa argüman olarak akrep ve yelkovan değerleri alınacaktır. Alınan bu değerler arasındaki açıyı hesaplayacak olan c programı. (Örn: 17 00 için Aradaki açı: 120)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){

float saat=atof(argv[1]);
float dakika=atof(argv[2]);
float akrep,yelkovan,sonuc=0;

if(saat<0 || saat>23){
	printf("Lütfen geçerli bir saat giriniz");
	exit(1);
}
else{
	if(saat>12)
		saat=saat-12;
}
if(yelkovan<0 || yelkovan>59){
	printf("Lütfen geçerli bir dakika giriniz");
	exit(1);
}

akrep=(saat*30)+(dakika/2);
yelkovan=dakika*6;

if(akrep>yelkovan){
	sonuc=akrep-yelkovan;
}
else{
	sonuc=yelkovan-akrep;
}
printf("Aradaki açı: %.2f",sonuc);
}
