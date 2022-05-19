//200201128 ÞÜHEDA YAREN ULUSOY
//190201069 ESRA DÝNÇ
#include <stdio.h>
#include <stdlib.h>

#define N 24

void kuyruga_ekle(int ucakid, int oncelikid, int talepsaati, int izinsaati);

void create();
void inis_pisti_kullanim_sirasi(int ucakid, int oncelikid, int talepsaati, int izinsaati);
void kontrol2(int ucakid, int oncelikid, int talepsaati, int izinsaati);
int satirsay();
void dosyayayaz();
void yazdir();
int ucak_id[N], oncelik_id[N], talep_saati[N], izin_saati[N], gecici_ucakid[N],kalkis_saati[N],gecikme_suresi[N], gecici_oncelikid[N], gecici_talepsaati[N], gecici_izinsaati[N];
int geciciucakid, gecicioncelikid, gecicitalepsaati, geciciizinsaati;
int f, r;

int main()

{
  int a;
  a = satirsay();
  int oncelikid[a], ucakid[a], talep_edilen_inis_saati[a];
  FILE * filep = fopen("input.txt", "r");
  if (filep == NULL) {
    printf("Dosya acilamadi.");
  } else {
    // printf("Dosya acildi.\n");
    for (int i = 0; i < a; i++) {
      fscanf(filep, "%d %d %d ", & oncelikid[i], & ucakid[i], & talep_edilen_inis_saati[i]);
      //printf("oncelik id:%d ucak id:%d saat %d talep edildi.  \n", oncelikid[i], ucakid[i], talep_edilen_inis_saati[i]);
    }
  }

  int n, ch;

  printf("\n1 - Kuyruga ekle");

  printf("\n2 - Yazdir");

  printf("\n4 - Cikis");

  create();

  while (1)

  {

    printf("\nSecim : ");

    scanf("%d", & ch);

    switch (ch)

    {

    case 1:

      for (int i = 0; i < a; i++) {
        izin_saati[i] = talep_edilen_inis_saati[i];
        kuyruga_ekle(ucakid[i], oncelikid[i], talep_edilen_inis_saati[i], izin_saati[i]);
      }

      break;

    case 2:

      yazdir();

      break;
    
    case 3:
    	dosyayayaz();

	break;

    case 4:

      exit(0);

    default:

      printf("\nYanlis secim");

    }

  }

}


void create()

{

  f = r = -1;

}


void kuyruga_ekle(int ucakid, int oncelikid, int talepsaati, int izinsaati)

{

  if (r >= N - 1)

  {
   printf("Kuyruk dolu %d idli ucak baska havalimanina yonlendiriliyor.\n",ucakid);
   return;
  }

  if ((f == -1) && (r == -1))

  {
    f++;

    r++;
	printf("%d idli ucak saat %d icin izin istedi.\n",ucakid,izinsaati);	
    ucak_id[r] = ucakid;
    oncelik_id[r] = oncelikid;
    talep_saati[r] = talepsaati;
    izin_saati[r] = izinsaati;
    printf("%d idli ucaga saat %d icin inis izni verildi.\n",ucakid,izinsaati);

    return;
  } 
  else

    inis_pisti_kullanim_sirasi(ucakid, oncelikid, talepsaati, izinsaati);

  	r++;

}

  int a = 0;
  int b=0;
  int c=0;
  

void inis_pisti_kullanim_sirasi(int ucakid, int oncelikid, int talepsaati, int izinsaati)

{	
	printf("%d idli ucak saat %d icin izin istedi.\n",ucakid,izinsaati);	
	

  int saat = 0;
  int x, j, y,k;

a=0;
b=0;
c=0;
  for (x = 0; x <= r; x++)
  {
    if (izinsaati == izin_saati[x]) {

		if (oncelikid < oncelik_id[x]) {
      		geciciucakid = ucak_id[x];
        	gecicioncelikid = oncelik_id[x];
        	gecicitalepsaati = talep_saati[x];
        	geciciizinsaati = izin_saati[x]+1;
     		
        for (k = 0; k < x+1; k++) {
          			if(ucak_id[k]==ucakid){
    						ucak_id[k] = ucakid;
							oncelik_id[k] = oncelikid;
							talep_saati[k] = talepsaati;
							izin_saati[k] = izinsaati;
          			}
          			if(ucak_id[k]!=ucakid) {
							b++;
          				}
          			if(b==x+1){
						ucak_id[x] = ucakid;
						oncelik_id[x] = oncelikid;
						talep_saati[x] = talepsaati;
						izin_saati[x] = izinsaati;
					
						
					}
		  		}
        
			printf("%d idli ucak oncelikten dolayi saat %d inis izni verildi ve %d idli ucagin yerine gecti.\n",ucakid,izinsaati,geciciucakid);		
        	inis_pisti_kullanim_sirasi(geciciucakid, gecicioncelikid, gecicitalepsaati, geciciizinsaati);
     	 }
     	else if (oncelikid > oncelik_id[x]) {
    		printf("%d idli ucak oncelikten dolayi saat %d inis izni verilmedi.\n",ucakid,izinsaati);
     		izinsaati=izinsaati+1;
        	inis_pisti_kullanim_sirasi(ucakid, oncelikid, talepsaati, izinsaati);
        
      
      	}
      	else if(oncelikid==oncelik_id[x]){
          
             if(ucakid<ucak_id[x]){
            	geciciucakid = ucak_id[x];
        		gecicioncelikid = oncelik_id[x];
        		gecicitalepsaati = talep_saati[x];
        		geciciizinsaati = izin_saati[x]+1;
           
          		for (y = 0; y< x+1; y++) {
          			if(ucak_id[y]==ucakid){
          			
    						ucak_id[y] = ucakid;
							oncelik_id[y] = oncelikid;
							talep_saati[y] = talepsaati;
							izin_saati[y] = izinsaati;
							
						
							
						
          			}
          			if(ucak_id[y]!=ucakid) {
          			
							c++;
          				}
          			if(c==x+1){
          			
						ucak_id[x] = ucakid;
						oncelik_id[x] = oncelikid;
						talep_saati[x] = talepsaati;
						izin_saati[x] = izinsaati;
					
						
					}
		  		}
          			
					printf("%d idli ucak oncelikten dolayi saat %d inis izni verildi ve %d idli ucagin yerine gecti.\n",ucakid,izinsaati,geciciucakid);
        			inis_pisti_kullanim_sirasi(geciciucakid, gecicioncelikid, gecicitalepsaati, geciciizinsaati);
            		
					}
            else if(ucakid>ucak_id[x]){
            	printf("%d idli ucak oncelikten dolayi saat %d inis izni verilmedi.\n",ucakid,izinsaati);
            	izinsaati=izinsaati+1;
            	
        		inis_pisti_kullanim_sirasi(ucakid, oncelikid, talepsaati, izinsaati);
        
            	}
           	}
		
        return;
	}

}
for (j = 0; j < x+1; j++) {
    if(ucak_id[j]==ucakid){
    	ucak_id[j] = ucakid;
		oncelik_id[j] = oncelikid;
		talep_saati[j] = talepsaati;
		izin_saati[j] = izinsaati;
	
	}
	if(a==x){
		ucak_id[x] = ucakid;
		oncelik_id[x] = oncelikid;
		talep_saati[x] = talepsaati;
		izin_saati[x] = izinsaati;
		printf("%d idli ucaga saat %d icin inis izni verildi.\n",ucakid,izinsaati);
	
	}
    if(ucak_id[j]!=ucakid) {
		a++;
	}
	
}

}

int satirsay() {
  int sayi = 0;
  int ch;
  int satirsayisi;
  FILE * filep = fopen("input.txt", "r");
  if (filep == NULL) {
    printf("Dosya acilamadi.");
  } else {
    while (feof(filep) == NULL) {
      ch = fgetc(filep);
      if (ch == '\n') {
        sayi++;
      }
    }
    satirsayisi = sayi + 1;
    fclose(filep);
  }
  return satirsayisi;
}

void yazdir()

{

  if ((f == -1) && (r == -1))

  {

    printf("\nKuyruk bos");

    return;

  }

  for (f = 0; f <= 23; f++)

  {
	kalkis_saati[f]=izin_saati[f]+1;
	gecikme_suresi[f]=izin_saati[f]-talep_saati[f];
    printf("\nId= %d\tOncelik id = %d   talep saati=%d   izin saati=%d   kalkis saati=%d   gecikme suresi=%d", ucak_id[f], oncelik_id[f], talep_saati[f], izin_saati[f],kalkis_saati[f],gecikme_suresi[f]);
	
  }

  f = 0;

}

void dosyayayaz()
{
	 FILE * filep = fopen("output.txt", "w+");
	 for (f = 0; f <= r; f++)

  	{
	kalkis_saati[f]=izin_saati[f]+1;
    fprintf(filep,"%d %d %d %d %d %d\n",oncelik_id[f], ucak_id[f], talep_saati[f], izin_saati[f],gecikme_suresi[f],kalkis_saati[f]);
  	}
  	printf("output.txt dosyasina yazdilirdi.");
	fclose(filep);
  	f = 0;
	
}

