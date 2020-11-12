/*=====================================================================
*
*         GESTION DES CARTES, DES JEUX ET DE L'AFFICHAGE
*
*======================================================================
*
* File : carte.h
* Date : 5 novembre 2020
* Author : Ghais Ben Mohamed
* 
* Contient les prototypes des fonctions
* permettant de gérer les cartes, les jeux et l'affichage
*======================================================================
*/


#ifndef __CARTE_H__
#define __CARTE_H__

typedef enum {coeur = 0, pique, carreau, trefle}t_signe;
     		 
typedef struct {int valeurC; t_signe signeC; }t_carte;

typedef struct{t_carte tabC[52];}t_jeu;

typedef struct { t_jeu jeu; int nbCartes; char nom[20];}t_main;

typedef struct{t_jeu pioche; int posPioche; t_main mainCPU ; t_main mainJoueur;}t_partie; 

void AfficheCarte(const t_carte* carteIn);
void AfficheJeu(const t_jeu* NewJeu);
void RemplitJeu (t_jeu* NewJeu);
void MelangeJeu (t_jeu* NewJeu, int nbMelange);
void InitPartie(t_partie* NewPartie,char nomCPU[20], char nomJoueur[20]);
void DistribueCarte(t_partie* NewPartie, int pourqui);
void AfficherMain(t_main* main);
int CalculValMain(t_main* main);

#endif
