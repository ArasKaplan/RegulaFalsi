#include <stdio.h>

double Fonksiyon_deger_bul(double x,double fonksiyon[100],int n){
	int i;
	int j;
	double deger;
	deger=0;
	double z;
	for(i=0;i<=n;i++){
		z=1;
		for(j=0;j<i;j++){
			z=z*x;
		}
		deger=deger+z*fonksiyon[i];
	}
	return deger;
}
int main(){
	double x1,x2;
	int derece;
	double epsilon;
	double fonksiyon[100];
	printf("X1 degeri giriniz");
	scanf("%lf",&x1);
	printf("X2 degeri giriniz");
	scanf("%lf",&x2);
	printf("Epsilon giriniz");
	scanf("%lf",&epsilon);
	printf("fonksiyonun derecesi");
	scanf("%d",&derece);
	int i=0;
	for(i=0;i<=derece;i++){
		printf("%d elemanin katsayisi",i);
		scanf("%d",&fonksiyon[i]);
	}
	double fx1,fx2,c,fc;
	while(fc>epsilon){
		fx1=Fonksiyon_deger_bul(x1,fonksiyon,derece);
		fx2=Fonksiyon_deger_bul(x2,fonksiyon,derece);
		c=((x2*fx1)-(x1*fx2))/(fx1-fx2);
		fc=Fonksiyon_deger_bul(c,fonksiyon,derece);
		if(fc*fx1<0){
			x2=c;
		}
		else{
			x1=c;
		}
		if(fc<0){
			fc=-1*fc;
		}
	}
	printf("Kok= %lf",c);
}
