//SEFA ENES ERGİN-sefaenesergin@gmail.com
//2 dizinin ortak elemanlarını bulan pointer mantığı içeren kod örneği
#include <stdio.h>
void ortaklariBul(int x[],int y[],int z[],int n[]){
    int i,j,k,sayac=0;
    for (int i=0; i<n; i++) {
        
        for(int k=0;k<n;k++)
            if(x[k]==x[i])
                break;
         if(k!=i) //yani break çalıştıysa(x[i] daha önce aranmışsa)
             continue;// alttakini çalıştırma. bi sonrakine geç.
        for (int j=0; j<n; j++) {
            if(x[i]==y[j]) //ilk dizideki elemanı 2.de bulduysan.
                break;
        }
        if(j!=n) //Eşleşme varsa...
            z[sayac++]=x[i];
    }
}
int main(int argc, const char * argv[]) {
    /*srand(time(0));  eğer windows işletim sistemi kullanıyorsanız random sayı almak için buna ek olarak time.h kütüphanesini de koda ekleyiniz.*/
    int a[50], b[50], c[51];//dizileri, kaybolmasın diye main'de tanımladık.
    /*c dizisini 51 tanımlamamızın nedeni: a ile b'nin tamamen aynı olma durumunda, fonksiyonun en son indiste -1 değerini görünce döngüden çıkması için tanımladık.*/
    int n=50;
    for (int i=0; i<n; i++) {
        a[i]=(rand()%1000)+1; //a[] dizisine 1-1000 arası sayi atadık.
        b[i]=(rand()%1000)+1;//b[] dizisine 1-1000 arası sayi atadık.
    }
    printf("İlk dizi : \n");
    for (int i=0; i<n;i++) {
        printf("%d : ",a[i]);
    }
    printf("\n\nİkinci dizi : \n");
    for (int i=0; i<n;i++) {
        printf("%d : ",b[i]);
    }
    for (int i=0;i<n+1; i++) {
        c[i]=-1;
    }
    ortaklariBul(a, b, c, n);
    if(c[0]==-1)
        printf("\n\nOrtak eleman bulunamadı!");
        else{
            printf("\n\nBulunan ortak elemanlar : ");
            int e=0;
            while (c[e]!=-1) {
                printf("%d ",c[e++]);
            }
            
        }
    return 0;
}
