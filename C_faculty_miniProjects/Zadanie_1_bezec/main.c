#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Definovanie farieb
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    system("Color ");
	int bezec_1,bezec_2,ciel,dsk,num;
	int r1,r2;
	dsk = 0;   // stav pre diskvalifikaciu
	bezec_1 = 0;
	bezec_2 = 0;
	ciel = 400;
	printf("Vneste cislo pre pocet bezcov(maximalne 10): ");
	scanf("%d",&num);
	/*char bezci[num];

	for (int i = 0; i < num; i++)
    {
        bezci[i] = 0;
    }

    */
	srand(time(NULL));
	int generuj_cislo(int a,int b) // funkcia pre generovanie nahodneho čísla <1,25>
	{
		int v;
		v = rand()%(b-a+1)+a;
		return v;
	}

	while (bezec_1 <= ciel || bezec_2 <= ciel) // zaciatok while cyklu
	{
		r1 = generuj_cislo(1,25); // generujeme nahodne čísla
		r2 = generuj_cislo(1,25);
		bezec_1 = bezec_1 + r1;   // pricitujeme ich k bezcom
		bezec_2 = bezec_2 + r2;
		system("clear");          // funkcia pre vycistenie plochy (pre gcc compilator)
		if (bezec_1  >= ciel || bezec_2 >= ciel)
		{
			dsk = 1;
		}
		if (bezec_1 % 50  == 0 && bezec_1 != ciel)
		{
			printf("Bezec 1 narazil na prekazku pri %dm a bol diskvalifikovany. \n",bezec_1);
			dsk = 2;
		}
		if (bezec_2 % 50 == 0 && bezec_2 != ciel)
		{
			printf("Bezec 2 narazil na prekazku pri %dm a bol diskvalifikovany. \n",bezec_2);
            dsk = 1;
		}else
		{
        printf("Bezec");
        printf(ANSI_COLOR_MAGENTA " 1 "  ANSI_COLOR_RESET);
		printf("prebezal %d m\n",bezec_1);
        printf("Bezec");
        printf(ANSI_COLOR_YELLOW " 2 "  ANSI_COLOR_RESET);
		printf("prebezal %d m\n",bezec_2);
		}
        for(int i = 0; i < 25; i++){printf("-");}
        printf("\n");
        printf("\n");
        for (int j = 0; j < 2; j = j + 1)
        {
            printf("Bezec %d\n",j+1);
            for (int i = 0; i<ciel/5; i = i + 1)
            {
                if (i == 0)
                {
                printf("Z");
                }
                else if(i == ciel/5-1)
                {
                    printf("C");
                }
                else if (i % 10 == 0)
                {
                    printf(ANSI_COLOR_RED "/" ANSI_COLOR_RESET);
                }
                else if (i <= bezec_1/5 && j == 0)
                {
                    if(i == bezec_1/5)
                    {
                        printf("X");
                    }else{printf("*");}
                }
                else if (i <= bezec_2/5 && j == 1)
                {
                    if(i == bezec_2/5)
                    {
                        printf("X");
                    }else{printf("*");}
                }
                else
                {
                    printf(ANSI_COLOR_GREEN "." ANSI_COLOR_RESET);
                }
            }
        printf("\n");
        printf("\n");
        }
        for(int i = 0; i < 100; i++){printf("=");}
        printf("\n");
        sleep(0.5);
        if (dsk == 1 || dsk == 2){break;}
	}
	if (dsk ==  1)
	{
	    printf("Bezec");
        printf(ANSI_COLOR_MAGENTA " 1 "  ANSI_COLOR_RESET);
		printf("zvitazil!");
	}
	else
	{
	    printf("Bezec");
        printf(ANSI_COLOR_YELLOW " 2 "  ANSI_COLOR_RESET);
		printf("zvitazil!");
	}
	return 0;
}
