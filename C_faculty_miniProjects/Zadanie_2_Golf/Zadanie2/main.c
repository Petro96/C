#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
//// DEFINOVANIE KONSTANTOV A FARBOV ////
#define PI 3.14159265
#define RESET     "\x1b[0m"
#define ZELENA     "\x1b[42m"
#define BIELA      "\x1b[47m"
#define CIERNA      "\x1b[48m"
#define ZCIERNA    "\x1b[42;30m"
/////////////////////////////////////////

//// Funkcia pre vygenerovanie cislo v intervale <x,y> ////
int rndxy(int x,int y)
{
    int x1;
    x1=rand()%(y-x+1)+x;
    return x1;
}
///////////////////////////////////////////////////////////

//////// Funkcia pre vykreslenie hry na obrazovku /////////
void vykres(int lx,int ly,int jx, int jy)
{
    int zoom = 400/8;
    int stred = (zoom)/2;
    for(int i = 0; i <= zoom; i++)
    {
        printf("\n");
        for(int j = 0; j <= zoom; j++)
        {
           //////// Pre vykreslenie ramika  /////////
                if (j == 0 || j == zoom)
                {
                    printf(BIELA " | " RESET);
                }else if(i == zoom || i == 0){printf(BIELA "---" RESET);}

           /////// Pre vykreslenie travy, diery a lopticky ///////
                else if(j == lx/8 + stred && i == -ly/8 + stred)
                    {
                        //// LOPTICKA ////
                        printf(BIELA " * " RESET);
                    }
                else if (j == jx/8 + stred && i == -jy/8 + stred)
                {
                    //// DIERA ////
                    printf(CIERNA "   " RESET);
                }
                    //// TRAVA ////
                    else printf(ZELENA "   " RESET);
                }
        }
    printf("\n");
}
////////////////////////////////////////////////////////////////////

//// Funkcia ktora vypocita vzdialenost dvoch bodov ////
double vzdialenost(int ix,int iy,int jx,int jy)
{
      return sqrt(pow(jx-ix,2)+pow(jy-iy,2));
}
/////////////////////////////////////////////////////

// Funkcia pre vytvaranie nepresnosti uhla //
int n1(int s)
{
    return rndxy(-(s*s/(sqrt(s)+s*s+100)*45),(s*s/(sqrt(s)+s*s+100)*45));
}
////////////////////////////////////////////

// Funkcia pre vytvaranie nepresnosti dialky
int n2(int s)
{
    return rndxy(-s/10,s/10);
}
////////////////////////////////////////////

//// Funkcia ktora vypocita pomocou n1, n2 a sily uderu o kolko sa lx ma posunut ////

int px(int x1,int y1,int s,int jx,int jy)
{   int r=vzdialenost(x1,y1,jx,jy);
    int uhol=n1(s)+round(atan(fabs(y1)/fabs(x1)) * (180.0 / PI));
    if (x1==0) return 0;
    if (x1>0) return -round((double)s*(cos(uhol * (PI / 180.0))))+n2(s);
    if (x1<0) return  round((double)s*(cos(uhol * (PI / 180.0))))+n2(s);

}
/////////////////////////////////////////////////////////////////////////////////////

//// Funkcia ktora vypocita pomocou n1, n2 a sily uderu o kolko sa ly ma posunut ////

int py(int x1,int y1,int s,int jx,int jy)
{   int r=vzdialenost(x1,y1,jx,jy);
    int uhol=n1(s)+round(atan(fabs(y1)/fabs(x1)) * (180.0 / PI));
     if (y1==0) return 0;
    if (y1>0) return -round((double)s*(sin(uhol * (PI / 180.0))))+n2(s);
    if (y1<0) return  round((double)s*(sin(uhol * (PI / 180.0))))+n2(s);

}
//////////////////////////////Začiatok mainu///////////////////////////////
main()
{
    system("Color ");
    srand(time(NULL));
    int jx=0,jy=0,lx=0,ly=0,s;
    int j1x=jx,j1y=jy;


    printf("Stlacte ENTER \n");
    getchar();

    /////Inicializacia
    while((vzdialenost(jx,jy,lx,ly)<=10.0) || (vzdialenost(jx,jy,lx,ly)>=200.0))
    {
        lx=rndxy(-200,200);
        ly=rndxy(-200,200);
        jx=rndxy(-200,200);
        jy=rndxy(-200,200);

        j1x=jx;
        j1y=jy;

        jx=0;
        jy=0;
        lx=lx-j1x;
        ly=ly-j1y;


    }
    int v=round(vzdialenost(jx,jy,lx,ly));

    vykres(lx+j1x,ly+j1y,jx+j1x,jy+j1y);

    printf("Lopticka sa nachadza na (%d,%d)",lx+j1x,ly+j1y);
    for(int i = 0; i < 88; i++){printf(" ");}
    printf("Jama sa nachadza na (%d,%d) \n",jx+j1x,jy+j1y);

    printf("Lopticka je %d m od jame \n",v);

    //// Hra sa pokracuje pokym lopticka nie je < 2m od diery ////
    while (v>2)
    {

        s=v+1;

        while (s>v || s<0)
        {
            printf("Zadajte silu uderu od 1 po %d: ",v);
            scanf("%d",&s);
        }
        system("CLS");
        //// Z funkcii px a py pricitame hodnotu do lx a ly ////
        lx = lx + px(lx,ly,s,jx,jy);
        ly = ly + py(lx,ly,s,jx,jy);
        v = round(vzdialenost(jx,jy,lx,ly));
        vykres(lx+j1x,ly+j1y,jx+j1x,jy+j1y);
        printf("Lopticka sa nachadza na (%d,%d)",lx+j1x,ly+j1y);
        for(int i = 0; i < 88; i++){printf(" ");}
        printf("Jama sa nachadza na (%d,%d) \n",jx+j1x,jy+j1y);
        printf("Lopticka je %d m od jame \n",v);


    }
    printf("Lopticka bola umiestnena :)\n");



}
