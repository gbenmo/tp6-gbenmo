/*=====================================================================
*
*								TP6: BLACKJACK         
*
*======================================================================
*
* File : blackjack.c
* Date : 5 novembre 2020
* Author : Ghais Ben Mohamed
* 
* Contient la fonction principale du programme
* Les commentaires ne sont pas défénitifs, ils seront 
* plus explicites en fin de TP.
*======================================================================
*/

// Librairie nécéssaire
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carte.h"
#include <stdbool.h>
#include <string.h>

int main(){
	
	// Q1), Q2) et Q3) Commenté
	
	/*t_carte c1;
	c1.valeurC = 2;
	c1.signeC = pique;

	t_carte c2;
	c2.valeurC = 1;
	c2.signeC = coeur;
	
	t_carte c3;
	c3.valeurC = 10;
	c3.signeC = carreau;
	
	t_carte c4;
	c4.valeurC = 13;
	c4.signeC = trefle;
	
	AfficheCarte(&c1);
	AfficheCarte(&c2);
	AfficheCarte(&c3);
	AfficheCarte(&c4);*/
	
	
	// Q4) et Q5) et Q6)
	
	srand(time(NULL));
	/*t_jeu jeuDeC;
	
	RemplitJeu(&jeuDeC);
	
	printf("Jeu originale remplit...\n");
	AfficheJeu(&jeuDeC);
	
	printf("Mélange en cours...\n");
	MelangeJeu(&jeuDeC,1000);
	
	printf("Jeu mélangé...\n");
	AfficheJeu(&jeuDeC);*/
	
	// On définit la partie actuelle
	t_partie laPartie;
	
	// Nom des joueurs
	char nomJoueur[20] = "Ghais";
	char nomCPU[20] = "Polytech";
	
	// Variable pour le bon déroulement de la partie
	int valeurMainJoueur;
	int ChoixUser;
	int partieCommence = false;
	
	// On initialise la partie et on affiche le jeu mélangé
	InitPartie(&laPartie,nomCPU,nomJoueur);
	printf("Jeu mélangé...\n");
	AfficheJeu(&laPartie.pioche);
	
	// On distribue 2 cartes à chaques joueurs
	DistribueCarte(&laPartie,1);
	DistribueCarte(&laPartie,0);
	DistribueCarte(&laPartie,1);
	DistribueCarte(&laPartie,0);

	// Onaffiche les mains des joueurs
	printf("\nMain de %s",nomJoueur);
	AfficherMain(&laPartie.mainJoueur);
	printf("\nMain de %s",nomCPU);
	AfficherMain(&laPartie.mainCPU);
	
	// On demande à l'utilisateur si il veut commencer à jouer
	printf("\nVoulez-vous une nouvelle carte ? (1 pour Oui) (0 pour Non) : ");
	scanf("%d",&ChoixUser);
	
	// Si l'utilisateur est pret à jouer on indique que la partie commence
	if (ChoixUser==1){
		partieCommence = true;
		
		// Traitement de file
		while(ChoixUser==1){
			ChoixUser =0;
			
			// On distriue une carte à l'utilisateur
			DistribueCarte(&laPartie,1);
			
			// On affiche la main du joueur
			printf("\nMain de %s",nomJoueur);
			AfficherMain(&laPartie.mainJoueur);
			
			// On récupère la valeur de la main
			valeurMainJoueur = CalculValMain(&laPartie.mainJoueur);
			
			// Si le joueur n'a toujours pas gagné on redemande de jouer
			if(valeurMainJoueur<=21){
			printf("\nVoulez-vous une nouvelle carte ? (1 pour Oui) (0 pour Non) : ");
			scanf("%d",&ChoixUser);
			}
		}
	}
	
	// Si l'utilisateur ne choisit pas une valeur correcte on lui signal
	else if(ChoixUser !=0) printf("Erreur vous devez saisir 1 ou 0\n");
		
	// Si le joueur à plus de 21 et qu'il a commencé une partie 
	if(valeurMainJoueur>=21 && partieCommence){
		printf("\nLa main de %s vaut %d\n",nomJoueur, valeurMainJoueur);
		printf("Bravo ! Vous avez gagné\n");
	}

	// Si le joueur quitte en cours de route
	else if(valeurMainJoueur<21 && partieCommence){
		printf("\nLa main de %s vaut %d\n",nomJoueur, valeurMainJoueur);
		printf("Dommage, je suis certain que vous gagnerez la prochaine fois\n");
	}
	
	// Si le joueur n'a pas joué depuis le début
	else printf("Vous n'avez pas joué ??? Bizarre...\n");
			
	return 0;
}


