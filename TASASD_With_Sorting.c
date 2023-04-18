#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int kebutuhan_kalori = 2000;
int kalori[]={680, 628, 740, 600, 480, 320, 290};
int uang;
int ulang = 0;
    
struct perbandingan{
	int kalori;
	int harga;
	char makanan[40];
	int harga_asli;
};

void Menu_Animation(){
	int end, count = 0, i, j, x=1, y=1;
	
	while (count!=162){
		gotoxy(x, y);
		printf("%c", 475);
		
		count++;
		
		if(count<65){
			x++;
		}else if(count>=65 && count < 82){
			y++;
		}else if(count>= 82 && count < 146){
			x--;
		}else if(count>= 146 && count < 162){
			y--;
		}
		
		if(ulang == 0){
			for (i=1;i<=2300;i++)
				for (j=1;j<=2300;j++);
		}
	}
}

int sort(const void *v1, const void *v2){
	struct perbandingan *m1 = (struct perbandingan *)v1;
	struct perbandingan *m2 = (struct perbandingan *)v2;
	
	if (m2->kalori == m1->kalori){
		return m1->harga - m2->harga;
	}
	else if (m2->kalori != m1->kalori){
		return ( *(int*)m2 - *(int*)m1 );
	}
}

int main(){
	struct perbandingan banding[]={{0, 0, "Nasi rames tanpa daging", 10000}, {0, 0, "Combo meal KFC", 32000}, {0, 0, "Nasi goreng dengan daging", 12000}, {0, 0, "Indomie goreng", 3100}, {0, 0, "PizzaHut Pepperoni", 101000}, {0, 0, "Popmie", 5200}, {0, 0, "Chicken katsu OTI", 12000}};
	
    int sisa_uang = 0;
    int banyak_makanan = 0;
    int i, y;
    char makanan[][40]={"Nasi rames tanpa daging", "Combo meal KFC", "Nasi goreng dengan daging", "Indomie goreng", "PizzaHut Pepperoni", "Popmie", "Chicken katsu OTI"};
	int harga[]={10000, 32000, 12000, 3100, 101000, 5200, 12000};
    
    system("cls");
    
    Menu_Animation();
    
	gotoxy(20,2);
	printf("Daftar yang ingin dibeli");
	gotoxy(3,4);
	printf("1. %s\t= Rp. %i,", makanan[0], harga[0]);
	gotoxy(50,4);
	printf("kalori = %i", kalori[0]);
	
	gotoxy(3,6);
	printf("2. %s \t\t= Rp. %i,", makanan[1], harga[1]);
	gotoxy(50,6);
	printf("kalori = %i", kalori[1]);
	
	gotoxy(3,8);
	printf("3. %s = Rp. %i,", makanan[2], harga[2]);
	gotoxy(50,8);
	printf("kalori = %i", kalori[2]);
	
	gotoxy(3,10);
	printf("4. %s \t\t= Rp. %i,", makanan[3], harga[3]);
    gotoxy(50,10);
	printf("kalori = %i", kalori[3]);
	
	gotoxy(3,12);
	printf("5. %s \t= Rp. %i,", makanan[4], harga[4]);
	gotoxy(50,12);
	printf("kalori = %i", kalori[4]);
	
	gotoxy(3,14);
	printf("6. %s \t\t\t= Rp. %i,", makanan[5], harga[5]);
	gotoxy(50,14);
	printf("kalori = %i", kalori[5]);
	
	gotoxy(3,16);
	printf("7. %s	\t= Rp. %i,", makanan[6], harga[6]);
	gotoxy(50,16);
	printf("kalori = %i", kalori[6]);
	
    gotoxy(78,3);
	printf("Budget/uang kamu : ");
    scanf("%i", &uang);
    
    sisa_uang = uang;
    
    y=19;
    
    for(i=0;i<7;i++){
		banding[i].kalori = kebutuhan_kalori/kalori[i];
		
    	check:
		if((banding[i].harga_asli * banding[i].kalori) > uang){
			banding[i].kalori -= 1;
			goto check;
		}else if((banding[i].harga_asli * banding[i].kalori) <= uang){
			if((banding[i].harga_asli * (banding[i].kalori + 1)) <= uang && (banding[i].kalori + 1) * kalori[i] <= kebutuhan_kalori + 650){
				banding[i].kalori += 1;
	    		banding[i].harga = banding[i].harga_asli * banding[i].kalori;
				goto check;
			}
	    	banding[i].harga = banding[i].harga_asli * banding[i].kalori;
		}
		
//    					cara kerja
		gotoxy(0, y);
		printf("%i", banding[i].harga_asli);
		printf(" %i", banding[i].kalori);
		printf(" Kalori : %i", banding[i].kalori*kalori[i]);
    	printf(" %s", banding[i].makanan);
    	printf(" total : %i", banding[i].harga);
    	y++;
	}
	
	for(i=0;i<7;i++){
		banding[i].kalori = banding[i].kalori*kalori[i];
	}
	
	qsort(banding, 7, sizeof(struct perbandingan), sort);
	
//						cara kerja setelah di sorting
	y++;
	for(i=0;i<7;i++){
		gotoxy(1, y);
    	printf("%i", banding[i].harga_asli);
		printf(" %i", banding[i].kalori);
    	printf(" %s", banding[i].makanan);
    	printf(" total : %i", banding[i].harga);
    	y++;
	}
	
	if(uang < 3100){
		gotoxy(68,7);
		printf("Kamu terlalu miskin untuk membeli makanan...");
	}else{
		gotoxy(68,7);
		printf("Makanan yang paling optimal \t: %s", banding[0].makanan);
		gotoxy(68,9);
	    printf("Hanya dengan memakan makanan tersebut sebanyak %i kali", banding[0].harga/banding[0].harga_asli);
		gotoxy(68,10);
		printf("Kamu mendapatkan total kalori \t: %i", banding[0].kalori);
		gotoxy(68,11);
		printf("Sedangkan remaja membutuhkan sebanyak %i - %i per hari", kebutuhan_kalori, kebutuhan_kalori+650);
		gotoxy(68,12);
		printf("Uang yang dihabiskan \t\t: %i", banding[0].harga);
		gotoxy(68,13);
		printf("Sisa uang kamu \t\t\t: %d", uang - banding[0].harga);
		if(banding[0].kalori >= 2000){
			gotoxy(70,15);
			printf("Kebutuhan kalorimu terpenuhi");
		}else{
			gotoxy(70,15);
			printf("Kebutuhan kalorimu tidak terpenuhi");
		}
	}
	
	ulang++;
	
	gotoxy(68,17);
	
	system("pause");
	main();
}
