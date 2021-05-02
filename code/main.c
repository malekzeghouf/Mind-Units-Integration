/**
* @file main.c
* @brief Tester le programme.
* @author mindunits
* @version 0.1
* @date Apr 20, 2021
*
* afficher et deplacer le personnage 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"

 
int main(int argc, char *argv[]){ personnage p,p2; 
SDL_Surface *ecran=NULL ,*imagedefond=NULL;
SDL_Event event;
SDL_Rect positionimage;
int clic=0,continuer=1, cl=0; 
   SDL_Rect postionimage;
   postionimage.x=0;
   postionimage.y=0;

   imagedefond= IMG_Load("image.png");
   
    
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 TTF_Init();
 SDL_EnableKeyRepeat(100,100); 
    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF); //Fonctions de la SDL permettant d'initialiser la fenêtre
    SDL_WM_SetCaption("perso ", NULL);
 
 initperso(&p); 
 initperso2(&p2); 
while (continuer)
{SDL_BlitSurface(imagedefond, NULL, ecran, &positionimage);
afficherperso( p, ecran);
afficherperso2( p2, ecran);
                              while(SDL_PollEvent(&event))
        {
		
           switch(event.type)
            {
                case SDL_QUIT:
                continuer=0;
                break;

                //les touches de clavier 
                case SDL_KEYDOWN: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:  // echape 
                    continuer = 0;
                    break;

                    case SDLK_LEFT: // Flèche droite
                     clic=1;
                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;
                    break;

                    case SDLK_UP: // Flèche bas 
                        clic=3;
                    break;

                    case SDLK_DOWN: // Flèche haut
                        clic=4;
                    break;
                    
                    // Touche d'attaque clic sur "espace"
                    case SDLK_SPACE: 
                    clic=5;
                    break; 
                    // Touche pour slide:glisser clic sur "0"
                    case SDLK_RETURN: 
                    clic=6;
                    break; 

                    // option pour le joueur
                  /*  case SDLK_w: 
                        clic=7;
                        break;
                    case SDLK_q: 
			clic=9;
                        break;

                   case SDLK_d:
			clic=8; 
                        break;
			case SDLK_p: 
			clic=12;
                        break;
                 */
                 case SDLK_p: 
			clic=12;
                        break;
                   

                    case SDLK_a: // Flèche droite
                     cl=1;
                    break;

                    case SDLK_e: // Flèche gauche
                        cl=2;
                    break;

                    case SDLK_z: // Flèche bas 
                        cl=3;
                    break;

                    case SDLK_s: // Flèche haut
                        cl=4;
                    break;
                    // Touche d'attaque clic sur "espace"
                    case SDLK_t: 
                    cl=5;
                    break; 
                    // Touche pour slide:glisser clic sur "0"
                    case SDLK_r: 
                    cl=6;
                    break; 
                    case SDLK_m: 
			cl=12;
                   
      }break; }

                    // touche de la sourie 
                
           /*  case SDL_MOUSEBUTTONDOWN :

                if(event.button.button == SDL_BUTTON_LEFT)
                    { clic=1;}
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    {clic=2;}
                    
		        else if (event.button.button== SDL_BUTTON_WHEELUP)
		          {clic=3;}
                else if (event.button.button == SDL_BUTTON_WHEELDOWN)
		          {clic=4;}
              
			     break;
                 }   */
              

}         /*if (clic!=0)
{*/
/*deplacement du personnage */
deplacerperso(&p,clic);
deplacerperso(&p2,cl);
Evolue(&p,clic);
 SDL_Flip (ecran);
 printf("pos:%d\n",p.position_personnage.x );
} 
   TTF_Quit();
SDL_Quit();
   
 return EXIT_SUCCESS;
}
                            
