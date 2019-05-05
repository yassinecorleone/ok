#include "ES.h"

void init_es(entitesecond *es)
{
    int i;
    char chaine[20];
    es->act=IMG_Load("1.png");
    for (i=1;i<6;i++)
    {
        sprintf(chaine,"%d.png",i);
        es->sprite[i-1]=IMG_Load(chaine);
    }
    es->frame=1;
    es->pos.x=100;
    es->pos.y=150;
    es->type=1;
    es->value=5;
}
void annimer_es(entitesecond *es)
{
    SDL_Delay(100);
    es->act=es->sprite[es->frame];
    es->frame++;
    if(es->frame==5)
        es->frame=1;
}
void afficher_es(entitesecond es,SDL_Surface *screen)
{
    SDL_BlitSurface(es.act,NULL,screen,&es.pos);
    SDL_Flip(es.act);
}
