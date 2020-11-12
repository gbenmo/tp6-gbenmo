/*=====================================================================
*
*         GESTION DES CARTES, DES JEUX ET DE L'AFFICHAGE
*
*======================================================================
*
* File : carte.c
* Date : 5 novembre 2020
* Author : Ghais Ben Mohamed
* 
* Contient les définitions des fonctions
* permettant de gérer les cartes, les jeux et l'affichage
*======================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carte.h"


void AfficheCarte(const t_carte* carteIn){
	
	// On traite les valeurs de carte pour les figures et les as
	switch (carteIn->valeurC){
		case 1 : printf("  A"); break;
		case 11 : printf("  V"); break;
		case 12 : printf("  D"); break;
		case 13 : printf("  R"); break;
		default : printf("  %*d",2,carteIn->valeurC);
	}
	
	// On affiche les signes sur la console
	switch (carteIn->signeC){
		case coeur : printf("\u2665 "); break;
		case pique : printf("\u2660 "); break;
		case trefle : printf("\u2663 "); break;
		case carreau : printf("\u2666 "); break;
	}
}

void AfficheJeu(const t_jeu* NewJeu){

	// On utilise la fonction AfficheCarte 52 fois pour chaque valeur de la pioche
	for(int i=0; i<52;i++)
		AfficheCarte(&NewJeu->tabC[i]);
}


void RemplitJeu ( t_jeu* NewJeu){

	// On remplit les 52 valeurs du tableau de jeu composé de struct carte
	int r=0; int s=0;
	for(int i=0;i<52;i++){
		NewJeu->tabC[i].valeurC = ++r;
		NewJeu->tabC[i].signeC = s;
		if(i==12||i==25||i==38) s++;
		if(r==13) r=0;	
	}
}


void MelangeJeu (t_jeu* NewJeu, int nbMelange){

	// On effectue un changement de variable dex fois 
	// Sur deux cartes deux à deux
	
	t_carte carteInt1 ,carteInt2;
	for(int i=0; i<nbMelange; i++){
	
		int randNb1 = rand()%51;
		carteInt1 = NewJeu->tabC[randNb1];
		int randNb1Bis = rand()%51;
		NewJeu->tabC[randNb1] = NewJeu->tabC[randNb1Bis];
		NewJeu->tabC[randNb1Bis] =  carteInt1;
		
		
		int randNb2 = rand()%51;
		carteInt2 = NewJeu->tabC[randNb2];
		int randNb2Bis = rand()%51;
		NewJeu->tabC[randNb2] = NewJeu->tabC[randNb2Bis];
		NewJeu->tabC[randNb2Bis] =  carteInt2;
	}
}

void InitPartie(t_partie* NewPartie,char nomCPU[20], char nomJoueur[20]){

	// Pour initialiser une partie on remplit la pioche
	RemplitJeu(&NewPartie->pioche);
	// On la mélange 1000 fois
	MelangeJeu(&NewPartie->pioche,1000);
	
	// On indique la position de la pioche
	NewPartie->posPioche = 0;
	
	// On affecte les noms aux joueurs
	strcpy(NewPartie->mainCPU.nom,nomCPU);
	strcpy(NewPartie->mainJoueur.nom,nomJoueur);
	
	// On indique leurs nombres de cartes
	NewPartie->mainCPU.nbCartes = 0;
	NewPartie->mainJoueur.nbCartes = 0;

}

void DistribueCarte(t_partie* NewPartie, int pourqui){
	
	// On donne la carte à la position posPioche à l'utlisiteur voulu
	// On incrémente la position de la pioche et le nombre de carte des joueurs
	if(pourqui==0){
	NewPartie->mainCPU.jeu.tabC[NewPartie->mainCPU.nbCartes] = NewPartie->pioche.tabC[NewPartie->posPioche];
	NewPartie->posPioche++;
	NewPartie->mainCPU.nbCartes++;
	}
	
	else if(pourqui==1){
	NewPartie->mainJoueur.jeu.tabC[NewPartie->mainJoueur.nbCartes] = NewPartie->pioche.tabC[NewPartie->posPioche];
	NewPartie->posPioche++;
	NewPartie->mainJoueur.nbCartes++;
	}
	
}

void AfficherMain(t_main* main){

	// Pour afficher la main on affiche toute les carte de 0 à nbCartes
	for (int i=0; i< main->nbCartes; i++)
		AfficheCarte(&main->jeu.tabC[i]);
}

int CalculValMain(t_main* main){

	// On prend la valeur de chaque cartes, on les sommes et on vérifie si un As apparaît
	// plus d'une fois
	int valeurMain =0;
	int nbAs =0;
	for(int i=0; i< main->nbCartes; i++){
		 valeurMain += main->jeu.tabC[i].valeurC;
		 if(main->jeu.tabC[i].valeurC == 1) nbAs++;
		 if(nbAs>1) valeurMain += 10;
		 	
	}

// On retourne le résultat
return valeurMain;
}





