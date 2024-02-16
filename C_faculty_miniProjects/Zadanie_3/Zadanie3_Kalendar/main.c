#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define BIELA      "\x1b[47;31m"
#define RESET     "\x1b[0m"
#define ZELENA     "\x1b[42m"
#define MODRA     "\x1b[46m"
#define PURPLE     "\x1b[45m"

int menu()
{
    int i, vstup;
    printf(MODRA "                        MENU                       \n" RESET);
    for(int i = 0; i < 51; i++)printf(ZELENA " " RESET);
    printf("\n");
    printf(BIELA "1. Zvolte mesiac a rok pre prikaz:                 \n" RESET);
    printf(BIELA "2. Zvolte rok pre prikaz vsetkych mesiacov:        \n");
    printf(BIELA "3. Napiste dva datumy pre vypocet ich rozdielu dni \n" RESET);
    printf(BIELA "4. Vypis vsetkych priestupnych rokov od R1 po R2   \n" RESET);
    printf(BIELA "5. Ukoncit program                                 \n" RESET);



    while(1)
    {
         scanf("%d",&i);

        switch(i)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
         case 5:

            break;
        default:
        printf(BIELA "ZVOLTE ZASE:                                       \n" RESET);
            continue;
    }
    break;
    }
    return i;
}

int pr_r(int r)
{

    if (r % 4 == 0 && r % 100 != 0 || r % 400 == 0)
    {
        return 1;
    }
    else return 0;



}

void zobraz_m(int m, int r)
{
        printf(PURPLE       "                %d                \n" RESET,r);
    switch(m){

    case(1):
        printf(MODRA  "              JANUARY               " RESET);
            break;
    case(2):
        printf(MODRA  "             FEBRUARY               " RESET);
            break;
    case(3):
        printf(MODRA  "               MARCH                " RESET);
            break;
    case(4):
        printf(MODRA  "               APRIL                " RESET);
            break;
    case(5):
        printf(MODRA  "                MAY                 " RESET);
            break;
    case(6):
        printf(MODRA  "               JUNE                 " RESET);
            break;
    case(7):
        printf(MODRA  "               JULY                 " RESET);
            break;
    case(8):
        printf(MODRA  "              AUGUST                " RESET);
            break;
    case(9):
        printf(MODRA  "             SEPTEMBER              " RESET);
            break;
    case(10):
        printf(MODRA  "              OCTOBER               " RESET);
            break;
    case(11):
        printf(MODRA  "             NOVEMBER               " RESET);
            break;
    case(12):
        printf(MODRA  "             DECEMBER               " RESET);
            break;
    }

    printf("\n");

    int dni;



    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        dni = 31;
    }
    else if(m==4 || m==6 || m==9 || m==11)
    {

        dni = 30;
    }
    else if(m==2)
    {
        if (pr_r(r))
        dni = 29;
        else{dni = 28;}
    }

    int rd = 0;
    for(int i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
            printf(ZELENA " " RESET);
            printf(ZELENA  " SA" RESET);
            break;
        case 1:
             printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " SU" RESET);
            break;
        case 2:
             printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " MO" RESET);
            break;
        case 3:
             printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " TU" RESET);
            break;
        case 4:
             printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " WE" RESET);
            break;
        case 5:
             printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " TH" RESET);
            break;
        case 6:
            printf(ZELENA " " RESET);
            printf(ZELENA " " RESET);
            printf(ZELENA " FR " RESET);
            printf(ZELENA " " RESET);

            break;

        }
    }
    printf("\n");
    for(int i = 0; i < 7;i++)printf(ZELENA "     " RESET);
    printf(ZELENA " " RESET);
    printf("\n");
    for(int i = 0; i < den_t(r,m,1); i++)
    {
        printf(BIELA "     " RESET);
        rd += 1;

    }
    for(int i = 0; i < dni; i++)
    {

        if ( (i+1) / 10 < 1)
            printf(BIELA "   %d " RESET,i+1);
        else
        printf(BIELA "  %d " RESET,i+1);

        rd += 1;
        if(i == dni-1 )
        {
            for(rd; rd < 7; rd++)
            {
                printf(BIELA "     " RESET);
            }
            printf(BIELA " " RESET);
            printf("\n");
        }
        else if(rd > 6 )
        {
            printf(BIELA " " RESET);
            printf("\n");
            rd = 0;
        }

    }

    printf("\n");
}

int den_t(int rok,int mesiac,  int datum)
{
    int dt,yc,s;
    if(mesiac == 1 || mesiac == 2)
    {
        mesiac += 12;
        yc = (rok-1) % 100;
        if (rok%100 == 0) s = (rok-1) / 100;
        else s=(rok-1)/100;
    }
    else
    {yc = rok % 100;
    s = rok / 100;
    }
    //if (mesiac==13 || mesiac==14)d=
    dt =  (datum+(13*(mesiac+1))/5+yc+yc/4+s/4+5*s)%7;

    return dt;
}



int main()
{
    int d1,d2,d,r1,r2,rs,prs=0,m1,m2,ms=0,s;   //ZA 3 ULOHU
    system("Color ");
    int m,r=0;
    while(1)
    switch(menu())
    {
        case 1:
            while (1)
            {
            if (r < 1582 || r > 4902)
            {printf(BIELA "ZADAJTE ROK:                                       \n" RESET);
            scanf( "%d",&r);

              if(r < 1582 || r > 4902)
              {
                  printf(BIELA "ROKE SU PLATNE OD 1582 po 4902                     \n" RESET);
                  continue;
              }
            }
            printf(BIELA       "ZADAJTE MESIAC:                                    \n" RESET);
            scanf("%d",&m);

            if(m < 1 || m > 12)
              {
                  printf(BIELA "MESIACE SU PLATNE OD 1 po 12                       \n" RESET);
                  continue;
              }
            system("CLS");
            zobraz_m(m,r);
            int i=1;
            printf(BIELA "              0  -  MENU            " RESET);

             while(i!=0)
             {
            printf("\n");
            scanf("%d", &i);
             }
            system("CLS");
            r=0;
            break;

            }
            break;
        case 2:
            while (1)
            {

            printf(BIELA "ZADAJTE ROK:                                       \n" RESET);
            scanf( "%d",&r);

              if(r < 1582 || r > 4902)
              {
                  printf(BIELA "ROKE SU PLATNE OD 1582 po 4902                     \n" RESET);
                  continue;
              }
              break;
            }
            for (int i = 0; i < 12; i++)
            {
                zobraz_m(i+1,r);
            }
                int j = 1;
             printf(BIELA "              0  -  MENU            " RESET);
              while(j!=0)
             {
            printf("\n");
            scanf("%d", &j);
             }
            system("CLS");
            r=0;
            break;
        case 3:

            system("CLS");
            printf(BIELA "ZADAJTE DEM,MESIAC A ROK  1.DATUMU                 \n" RESET);
            scanf("%d%d%d",&d1,&m1,&r1);
            printf(BIELA "ZADAJTE DEM,MESIAC A ROK  2.DATUMU                 \n" RESET);
            scanf("%d%d%d",&d2,&m2,&r2);
            int k;
            for (k=r1+1;k<r2;k++)
            {
             if (pr_r(k)==1) prs=prs+1;
            }
            rs=abs((r2-r1)*365)+prs;

            for(k=1;k<m1;k++)

            {
    if(k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12)  ms = ms-31;

    else if(k==4 || k==6 || k==9 || k==11)  ms = ms-30;

    else if(k==2)
    {
        if (pr_r(r1)) ms = ms-29;
        else ms = ms - 28;

    }

            }

            for(k=1;k<m2;k++)
            {
    if(k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12) ms = ms+31;

    else if(k==4 || k==6 || k==9 || k==11) ms = ms+30;

    else if(k==2) if (pr_r(r2)) ms = ms+29;

        else ms = ms + 28;

            }



            s=rs+ms+d2-d1;
            int rr=s/365;
            int mm=s%365/30;
            int dd=s%365%30/7;

            printf("\n\n");
                 printf(BIELA "ROZDIEL DNI MEDZI 2. DATUMAMI = %d             \n",s, RESET);
                j = 1;

                  printf(BIELA "ROZDIEL DNI MEDZI 2. DATUMAMI = %d rokov %d mesaci %d dni **ESTE SA TESTUJE \n",rr,mm,dd, RESET);


                 printf(BIELA "              0  -  MENU                           " RESET);
              while(j!=0)
             {
            printf("\n");
            scanf("%d", &j);
             }
             prs=0;
             ms=0;
             s=0;
            system("CLS");

            break;

        case 4:
            system("CLS");
              while (1)
            {
            printf(BIELA "ZADAJTE 2 ROKY PRE VYPIS PRIESTUPNYCH ROKOV        \n" RESET);
            scanf("%d%d",&r1,&r2);

              if((r1 < 1582 || r1 > 4902) || (r2 < 1582 || r2 > 4902))
              {
                  printf(BIELA "ROKE SU PLATNE OD 1582 po 4902                     \n" RESET);
                  continue;
              }

            for(int i=r1;i<=r2;i++)
            {
                if (pr_r(i)==1) printf(BIELA "%d                                               \n",i,RESET);
            }
            j = 1;
                 printf(BIELA "              0  -  MENU                           " RESET);
              while(j!=0)
             {
            printf("\n");
            scanf("%d", &j);
             }
            system("CLS");
            break;
            }
            break;
        case 5:
            printf(MODRA "PROGRAM JE UKONCENY                                " RESET);
            return 0;

    }


}
