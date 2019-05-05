#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_mixer.h>
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL;
    SDL_Rect positionFond;

    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    /* Chargement d'une image Bitmap dans une surface */
    image = IMG_Load("coin.png");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(image, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
    //pause();

    SDL_FreeSurface(image); /* On libère la surface */
SDL_Delay(1000);
    SDL_Quit();

    return EXIT_SUCCESS;
}
