#include "entite.h"

int nb_frames_e = 15;


void init_tab_anim_entite(SDL_Rect *clip)
{
    for (int i = 0; i < nb_frames_e; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w *i;
        clip[i].y = 0;
    }


}

void initialiser_entite(entite *e, int t)
{
    e->entite = IMG_Load("graphic/air-guy.png");
    e->entite_pos.x = 900;
    e->entite_pos.y = 100;
    init_tab_anim_entite(e->animation_entite);
    e->frame_entite=0;
    e->type=t;
e->col=0;
e->up=100;
e->down=400;
e->maxup=200;
e->maxdown=500;
e->affich_minimap=1;
}
/*
int detect_collision(perso *p, entite* e){
  if (e->col==0){
if ((p->position_perso.x + p->position_perso. w< e->entite_pos. x) || (p->position_perso.x> e->entite_pos. x + e->entite_pos. w) ||
(p->position_perso.y + p->position_perso.h< e->entite_pos. y) || (p->position_perso.y> e->entite_pos. y + e->entite_pos. h ))
e->col= 0;
else
e->col=1;
}
return e->col;
}

int gestion_collision(perso* p, entite* e){

//entite reste apres collision -> retour 1
if (!e->type) //si type=0 (bad)
{
 if(p->position_perso.x<= e->entite_pos.x) p->position_perso.x-=150;
  if(p->position_perso.x>= e->entite_pos.x) p->position_perso.x+=150;
  return 1;
}

//entite disparait apres collision -> retour 0;
if (e->type)//si type =1 (good)
 {
  e->entite_pos.y=100;
e->down=110;
e->up=100;
e->maxup=e->up+rand()%2;
e->maxdown=e->down+rand()%2;
e->affich_minimap=0;
return 0;
}

}
*/

void afficher_entite(entite * e , SDL_Surface *screen)
{

   SDL_BlitSurface(e->entite,&e->animation_entite[e->frame_entite], screen, &e->entite_pos);



}

void anim_entite(entite *e)
{    e->frame_entite++;

    if (e->frame_entite <0 || e->frame_entite > 14)
       e->frame_entite=0;

}
  int down=0,up=0;

int distance;

void mvt_entite(entite *e/*, perso *p*/)
{
/*
var dans structure entite secondaire
int maxup,maxdown;
int type ; //definie effet de l'entite (win or lose score/vie/....)
int collision; //determine si il y a collision par defaut =0
*/
//mvt vertical par defaut
if(e->entite_pos.y<=e->maxup){
  down=1;
  up=0;}
if(e->entite_pos.y>=e->maxdown){
  down=0;
  up=1;
randomise_min_max(e);}

  if (up==1) e->entite_pos.y-=5;
  if (down==1) e->entite_pos.y+=5;
/*
//mvt horizontal : interaction avec perso si entite nefaste
if(!e->type){
  distance=e->entite_pos.x-p->position_perso.x;
  //mvt entite si distance avec perso (x_entite-x_perso) < |200|
  if (distance<300 && distance>50 ){
//if x_perso < x_entite  =>entite recule
e->entite_pos.x--;
  }

if (distance >-300 && distance < 0){
  //if x_perso > x_entite => entite avance
  e->entite_pos.x++;
  }

}
*/

}

void mise_a_jour_entite(entite *e/*,perso *p*/){
mvt_entite(e/*,p*/);
anim_entite (e);

}
void randomise_min_max(entite *e){
  srand (time(0));
  e->maxup=e->up+rand()%200;
  e->maxdown=e->down+rand()%200;

  //printf("maxup : %d\tmaxdown : %d\n",e->maxup,e->maxdown );

}
