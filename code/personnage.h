#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
#include<SDL/SDL_audio.h>


#define STAT_SOL 0
#define STAT_AIR 1
 
#define STAT_MARCHE 1
#define STAT_NOT_MARCHE 0
/**
* @struct score
* @brief stucture score .

*/
typedef struct score 
{
SDL_Surface *texte1;/*!< Surface*/
	
SDL_Surface *number1;/*!< Surface*/
char number[20];
char textes[20];
SDL_Rect position_texte1;/*!< Rectangle*/
SDL_Rect position_number;  /*!< Rectangle*/
TTF_Font *police;

int valeur_score;
}score ;
/**
* @struct vie 
* @brief sructure vie .

*/
typedef struct vie 
{
int val;
TTF_Font *text;
SDL_Surface *texte;/*!< Rectangle*/
SDL_Rect position_texte;/*!< Rectangle*/
SDL_Surface *image_vie[5]; /*!< Surface*/
SDL_Rect position_vie ;/*!< Rectangle*/
}vie; 
/**
* @struct personnage
* @brief  structure personnage.

*/
typedef struct  personnage
{      score s; 
	vie v;
	int vitesse;
	SDL_Rect position_personnage;/*!< Rectangle*/
	SDL_Surface *tab[130];/*!< Surface*/
	float time;
	int score;
	SDL_Rect pos_score;/*!< Rectangle*/
	SDL_Rect scroll;/*!< Rectangle*/
	int Frame;


	float factgravite;
	float factsautmaintenu;
	float impulsion;
    int status;

    float vx,vy;
}personnage;



void initperso(personnage *p);
void initperso2(personnage *p);
void afficherperso(personnage p,SDL_Surface * ecran);
void afficherperso2(personnage p,SDL_Surface * ecran);


void animation_walk_right (personnage *p);
void animation_walk_left (personnage *p);

void animation_jump_right (personnage *p);
void animation_jump_left (personnage *p);

void animation_run_right (personnage *p);
void animation_run_left (personnage *p);

void animation_fail_right (personnage *p);
void animation_slide_right (personnage *p);
void animation_crouch_right (personnage *p);

void animation_attack_right (personnage *p);
void animation_attack_left (personnage *p);

void Saut(personnage *p, float impulsion);
void deplacerperso(personnage *p,int clic);
void ControleSol(personnage *p);
void Gravite(personnage *p,int clic,float factgravite,float factsautmaintenu);

void Evolue(personnage *p, int clic);


