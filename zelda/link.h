#ifndef LINK_H
#define LINK_H
#include "link.h"
#include "plateau.h"
#include "ennemi.h"
#include "instructeur.h"


class link{
	private:
	std::string nom="Link";//le nom du personnage
	int coeur=0;//le nombre de demi coeurs
	int atq=5;//l'attaque de link
	int fin=0;//réussi a avoir l'épée ou pas
	plateau p;
	instructeur i;
	char tab[50][36];
	int parade=0;//quand on se protège
	int tempo=0;//pour le raffraichisement
	public:
	int vie=5;
	int viemax=5;
	int difficulte;
	int sauvegarde;
	int res=0;
	int rencontre=0;
	
	link(int s,int d);
	
	void initialiser();
		
	void save(char tab[][f],int &vie,int &viemax,int &difficulte,int &rencontre,int &fin);

	

	void load(char tab[][36],int &vie,int &viemax,int &difficulte,int &rencontre,int &fin);
		
	void attaque(int dif);
	
	
	void combat();
		
	void deplacement();
	
	void aventure(int lig=3,int col=1);
};
#endif
