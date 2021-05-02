/**
* @file personne.c
* @brief developper les foctions .
* @author mindunits
* @version 0.1
* @date Apr 20, 2021
*
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"

/**
* @brief initialiser personnage .
* @param p personnage
* @return Nothing
*/


  void initperso(personnage *p)
{
p->position_personnage.x=0;
p->position_personnage.y=300;


char nomFich[130];
int i;
for(i=0;i<130;i++)
{
    sprintf(nomFich,"per/%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
}

p->Frame=0;
p->vitesse=5;
TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
p->v.text=TTF_OpenFont("avocado.ttf",35);

SDL_Color couleur={255,255,255};
 
 p->v.texte= TTF_RenderText_Blended(p->v.text,"Vie :",couleur);
 p->v.position_texte.x=490;
 p->v.position_texte.y=20;


// implemetation des images de la vie dans un tableau sans une boucle 
p->v.image_vie[0]=IMG_Load("hearts03.png") ;
p->v.image_vie[1]=IMG_Load("hearts02.png") ;
p->v.image_vie[2]=IMG_Load("hearts01.png") ;
p->v.image_vie[3]=IMG_Load("hearts00.png") ;
// positions
 p->v.position_vie.x=600;
 p->v.position_vie.y=20;
 p->v.val=3;
TTF_CloseFont(text);
SDL_Surface *texte1=NULL; // l'affichage du texte score sous forme d'une chaine 
SDL_Surface *number1=NULL;// affichage de la valeur du score sous forme d'une chaine de caractere 
TTF_Font *police=NULL;

p->s.police = TTF_OpenFont("avocado.ttf", 35);

SDL_Color blanc={255,255,255}; 


p->s.position_number.x=170;
p->s.position_number.y=20;

p->s.position_texte1.x=15;
p->s.position_texte1.y=20;
char textes[20];

strcpy(textes,"Score :"); // variable pouur l'affichage du message score sur l ecran 

char number[5]={0,0,0,0,0}; //tableau de chaine de c ou on va stocker la valeur du score 




p->s.texte1= TTF_RenderText_Blended(p->s.police,textes,blanc);
p->s.number1= TTF_RenderText_Blended(p->s.police,number,blanc);
TTF_CloseFont(police);

}
/**
* @brief initialiser personnage .
* @param p personnage
* @return Nothing
*/
  void initperso2(personnage *p)
{
p->position_personnage.x=100;
p->position_personnage.y=300;


char nomFich[130];
int i;
for(i=0;i<130;i++)
{
    sprintf(nomFich,"per/%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
}

p->Frame=0;
p->vitesse=5;}
/**
* @brief afficher personnage .
* @param p personnage 
* @param *ecran l'ecran 
* @return Nothing
*/

void afficherperso(personnage p,SDL_Surface * ecran)
{
    SDL_BlitSurface(p.tab[p.Frame],NULL,ecran,&(p.position_personnage));
    int vies=3;
 
    /*p.v.val--;
vies--;
    if (vies==2)
    {
	SDL_FreeSurface(p.v.image_vie[0]);
    else if (vies==1)
    {SDL_FreeSurface(p.v.image_vie[1]);}  
    else if (vies==0)
    {SDL_FreeSurface(p.v.image_vie[2]);}
	printf("val vie :%d \n",p.v.val);*/
  
  SDL_BlitSurface(p.v.texte,NULL,ecran,&(p.v.position_texte));
SDL_BlitSurface(p.v.image_vie[p.v.val],NULL,ecran,&(p.v.position_vie));
SDL_Color blanc={255,255,255}; 
char textes[20];
strcpy(textes,"Score :");

char number[5]; 
p.s.valeur_score=0;

sprintf(number, "%d ", p.s.valeur_score);
p.s.texte1= TTF_RenderText_Blended(p.s.police,textes,blanc);
p.s.number1= TTF_RenderText_Blended(p.s.police,number,blanc);


 SDL_BlitSurface(p.s.texte1, NULL, ecran,&(p.s.position_texte1));
SDL_BlitSurface(p.s.number1, NULL, ecran,&(p.s.position_number));
}

void afficherperso2(personnage p,SDL_Surface * ecran)
{
    SDL_BlitSurface(p.tab[p.Frame],NULL,ecran,&(p.position_personnage));}
void animation_walk_right (personnage *p)
{
  if(p->Frame<=0 || p->Frame>=9)
		p->Frame=1;
	p->Frame++;
}


void animation_walk_left (personnage *p)
{
	if(p->Frame<=10 || p->Frame>=19)
		p->Frame=11;

	p->Frame++;	
}


void animation_jump_right (personnage *p)
{
	if(p->Frame<=24 || p->Frame>=31)
		p->Frame=25;

	p->Frame++;

}

void animation_jump_left (personnage *p)
{
  if(p->Frame<=39 || p->Frame>=46)
		p->Frame=40;

	p->Frame++;
}



void animation_run_right (personnage *p)
{
	if(p->Frame<=51 || p->Frame>=60)
		p->Frame=52;

	p->Frame++;
	
}


void animation_run_left (personnage *p)
{
	if(p->Frame<=61 || p->Frame>=70)
		p->Frame=62;

	p->Frame++;
	
}



void animation_slide_right (personnage *p)
{
int nb_frames_p=0;
  
	if(p->Frame<=79 || p->Frame>=88)
		p->Frame=80;

	p->Frame++;
	
}

void animation_attack_right (personnage *p)
{
int nb_frames_p=0;
  
	if(p->Frame<=99 || p->Frame>=108)
		p->Frame=100;

	p->Frame++;
	
}


void animation_attack_left (personnage *p)
{
int nb_frames_p=0;
  
	if(p->Frame<=109 || p->Frame>=118)
		p->Frame=110;

	p->Frame++;
	
}



void animation_crouch_right (personnage *p)
{
int nb_frames_p=0;
  
	if(p->Frame<=119 || p->Frame>=124)
		p->Frame=120;

	p->Frame++;
	
}


/**
* @brief deplacer personnage .
* @param p personnage 
* @param clic nombre de clic pour detection du deplacement 
* @return Nothing
*/
void deplacerperso(personnage *p,int clic)
{


          if (clic==1)
               {
		 p->position_personnage.x -=p-> vitesse;
		 animation_walk_left (p);
               }




         else if(clic==2)
               {
		 p->position_personnage.x += p->vitesse;
                 animation_walk_right (p);
               }




         else if (clic==3)
 	       {
            	 p->position_personnage.x += p->vitesse;
           	 p->position_personnage.y -= p->vitesse;
            	 animation_jump_right (p);

               }



         else if(clic==4)
               {
                 p->position_personnage.x += p->vitesse;
                 p->position_personnage.y += p->vitesse;
                 animation_crouch_right (p);

               }



	else if(clic==5)
               {
                 p->position_personnage.x += p->vitesse+2;
                 animation_run_right (p);
               }



	else if(clic==6)
               {
                 p->position_personnage.x -= p->vitesse+2;
                 animation_run_left (p);
               }




	else if(clic==7)
               {
                 p->position_personnage.x += p->vitesse;
                 animation_slide_right (p);
               }



	else if(clic==8)
               {
                 p->position_personnage.x += p->vitesse;
                 animation_attack_right (p);
               }



	else if(clic==9)
               {
                 p->position_personnage.x -= p->vitesse;
                 animation_attack_left (p);
               }

}
/**
* @brief saut du personnage .
* @param p personnage  
* @param impulsion  
* @return Nothing
*/
void Saut(personnage *p, float impulsion)
{      
    p->vx = -impulsion;

    p->vy = -impulsion;

    p->status = STAT_AIR;

    animation_jump_right (p);

}

//--------------------------------RETOUR AU SOL---------------------------------//
void ControleSol(personnage *p)
{
   if (p->position_personnage.y>450.0f)
    {
       p->position_personnage.y = 450.0f;}
        if (p->vy>0)
            p->vy = 0.0f;
        p->status = STAT_SOL;
    }



void Gravite(personnage *p,int clic,float factgravite,float factsautmaintenu)
{
    if (p->status == STAT_AIR && (clic==3))
        factgravite/=factsautmaintenu;
    	p->vy += factgravite;
    	p->vy -= factsautmaintenu;
}


void Evolue(personnage *p, int clic)
{	


// declarations de quelques variables 

    float impulsion=0.5f;
    float lateralspeed = 0.2f;
    float airlateralspeedfacteur = 0.1f;
    float maxhspeed = 9.0f;
    float adherance = 0.5f;
    float factgravite = 2.5f;
    float factsautmaintenu = 0.5f;


// controle lateral
    if (p->status == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
   
	 if ((p->status == STAT_SOL))
 // (*1)
        p->vx-=lateralspeed;
    	
	if ((p->status == STAT_SOL))

        p->vx+=lateralspeed;
   	 
	if (p->status == STAT_SOL && !(clic==2) && !(clic==1)) // (*3)

        (p->vx)/=adherance;

// limite vitesse

    if (p->vx>maxhspeed) // (*4)
        p->vx = maxhspeed;

    if (p->vx<-maxhspeed)
        p->vx =-maxhspeed;

// saut

    if ((clic==3) && p->status == STAT_SOL)


        Saut(p,impulsion);

    	Gravite(p,clic,factgravite,factsautmaintenu);

   	ControleSol(p);

// application du vecteur à la position.
    if((clic == 3) && p->status == STAT_AIR)
{
    p->position_personnage.x +=p->vx;
    p->position_personnage.y +=p->vy-40;
}
  
}







