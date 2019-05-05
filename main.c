#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <SDL/SDL_rotozoom.h>

 
#define TEMPS 50 // Le temps qu'il y a entre chaque augmentation de l'angle.
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *perso = NULL, *rotation = NULL, *perso1= NULL, *rotation1= NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
    double zoom = 1;
    int sens = 1;
    
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
 
    perso = IMG_Load("ghost.png");
    perso1= IMG_Load("girl.png");
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 4; //On augmente l'angle pour que l'image tourne sur elle-même.
 
            tempsPrecedent = tempsActuel;
        
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(perso, angle, zoom, 0); //On transforme la surface image.
     rotation1 = rotozoomSurface(perso1, angle, zoom, 0);
     //SDL_BlitSurface(rotation, rect->new(0, 0, rotation->w, rotation->h), ecran,  rect->new(0, 0, 0, 0) );
    
    //SDL_UpdateRect( ecran, 0, 0, 0, 0 );

     //sleep(2);
    
        //On repositionne l'image en fonction de sa taille.
        rect.x =  event.button.x - rotation->w / 4;
        rect.y =  event.button.y - rotation->h / 4;
 
    if((angle>0)&&(angle<185))
        {SDL_BlitSurface(rotation , NULL, ecran, &rect);} //On affiche la rotation de la surface image.
    else if ((angle>185)&&(angle<360))
        {SDL_BlitSurface(rotation1 , NULL, ecran, &rect);}
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire. 
 
        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5){sens = 1;}
 
        if(sens == 0){zoom -= 0.01;}
        else{zoom += 0.01;}

        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(perso);
    SDL_FreeSurface(perso1);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
