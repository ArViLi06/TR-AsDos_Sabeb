#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int kebutuhan_gizi = 2000;
int gizi[]={680, 628, 740, 600, 480, 320, 290};
int uang;
    
struct perbandingan{
	int gizi;
	int harga;
	char makanan[40];
	int harga_asli;
};

int sort(const void *v1, const void *v2){
	struct perbandingan *m1 = (struct perbandingan *)v1;
	struct perbandingan *m2 = (struct perbandingan *)v2;
	
	if (m2->gizi == m1->gizi){
		return m1->harga - m2->harga;
	}
	else if (m2->gizi != m1->gizi){
		return ( *(int*)m2 - *(int*)m1 );
	}
}

int main(){
	struct perbandingan banding[]={{0, 0, "Nasi rames tanpa daging", 10000}, {0, 0, "Combo meal KFC", 32000}, {0, 0, "Nasi goreng dengan daging", 12000}, {0, 0, "Indomie goreng", 3100}, {0, 0, "PizzaHut Pepperoni", 101000}, {0, 0, "Popmie", 5200}, {0, 0, "Chicken katsu OTI", 12000}};
	
    int sisa_uang = 0;
    int banyak_makanan = 0;
    int i;
    char makanan[][40]={"Nasi rames tanpa daging", "Combo meal KFC", "Nasi goreng dengan daging", "Indomie goreng", "PizzaHut Pepperoni", "Popmie", "Chicken katsu OTI"};
	int harga[]={10000, 32000, 12000, 3100, 101000, 5200, 12000};
    
    system("cls");
    
	gotoxy(1,1);
	printf("Daftar yang ingin dibeli :");
	gotoxy(1,3);
	printf("1. %s\t= Rp. %i,", makanan[0], harga[0]);
	gotoxy(50,3);
	printf("Gizi \t= %i", gizi[0]);
	
	gotoxy(1,5);
	printf("2. %s \t\t= Rp. %i,", makanan[1], harga[1]);
	gotoxy(50,5);
	printf("Gizi \t= %i", gizi[1]);
	
	gotoxy(1,7);
	printf("3. %s \t= Rp. %i,", makanan[2], harga[2]);
	gotoxy(50,7);
	printf("Gizi \t= %i", gizi[2]);
	
	gotoxy(1,9);
	printf("4. %s \t\t= Rp. %i,", makanan[3], harga[3]);
    gotoxy(50,9);
	printf("Gizi \t= %i", gizi[3]);
	
	gotoxy(1,11);
	printf("5. %s \t\t= Rp. %i,", makanan[4], harga[4]);
	gotoxy(50,11);
	printf("Gizi \t= %i", gizi[4]);
	
	gotoxy(1,13);
	printf("6. %s \t\t\t= Rp. %i,", makanan[5], harga[5]);
	gotoxy(50,13);
	printf("Gizi \t= %i", gizi[5]);
	
	gotoxy(1,15);
	printf("7. %s	\t= Rp. %i,", makanan[6], harga[6]);
	gotoxy(50,15);
	printf("Gizi \t= %i", gizi[6]);
	
    gotoxy(75,3);
	printf("Budget/uang kamu : ");
    scanf("%i", &uang);
    
    gotoxy(1,16);
    sisa_uang = uang;
    
    for(i=0;i<7;i++){
		banding[i].gizi = kebutuhan_gizi/gizi[i];
		
    	check:
		if((banding[i].harga_asli * banding[i].gizi) > uang){
			banding[i].gizi -= 1;
			goto check;
		}else if((banding[i].harga_asli * banding[i].gizi) <= uang){
			if((banding[i].harga_asli * (banding[i].gizi + 1)) <= uang && (banding[i].gizi + 1) * gizi[i] <= kebutuhan_gizi + 650){
				banding[i].gizi += 1;
	    		banding[i].harga = banding[i].harga_asli * banding[i].gizi;
				goto check;
			}
	    	banding[i].harga = banding[i].harga_asli * banding[i].gizi;
		}
		
//    					cara kerja
//    	printf("\n%i", banding[i].harga_asli);
//		printf(" %i", banding[i].gizi);
//		printf(" Gizi : %i", banding[i].gizi*gizi[i]);
//    	printf(" %s", banding[i].makanan);
//    	printf(" total : %i", banding[i].harga);
	}
	
	
	for(i=0;i<7;i++){
		banding[i].gizi = banding[i].gizi*gizi[i];
	}
	
	qsort(banding, 7, sizeof(struct perbandingan), sort);
	
//						cara kerja setelah di sorting
//	printf("\n");
//	for(i=0;i<7;i++){
//    	printf("\n%i", banding[i].harga_asli);
//		printf(" %i", banding[i].gizi);
//    	printf(" %s", banding[i].makanan);
//    	printf(" total : %i", banding[i].harga);
//	}
	
	if(uang < 2600){
		gotoxy(65,7);
		printf("Kamu terlalu miskin untuk membeli makanan...");
	}else{
		gotoxy(65,7);
		printf("Makanan yang paling optimal \t: %s", banding[0].makanan);
		gotoxy(65,9);
	    printf("Hanya dengan memakan makanan tersebut sebanyak %i kali", banding[0].harga/banding[0].harga_asli);
		gotoxy(65,10);
		printf("Kamu mendapatkan total gizi \t: %i", banding[0].gizi, kebutuhan_gizi, kebutuhan_gizi+650);
		gotoxy(65,11);
		printf("Sedangkan remaja membutuhkan sebanyak %i - %i per hari", kebutuhan_gizi, kebutuhan_gizi+650);
		gotoxy(65,12);
		printf("Uang yang dihabiskan \t\t: %i", banding[0].harga);
		gotoxy(65,13);
		printf("Sisa uang kamu \t\t: %d\n\n\n", uang - banding[0].harga);
	}
	
	gotoxy(65,15);
	
	system("pause");
	main();
}
