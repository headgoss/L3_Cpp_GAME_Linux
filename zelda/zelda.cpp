#include <iostream>
#include <string>
#include "link.h"
#include "ennemi.h"
#include "instructeur.h"
#include "plateau.h"

using namespace std;

int main(){
srand(time(NULL));
char tab[e][f];
int vie,viemax,lig,col;
system("clear");
int saisie,save,dif,ren,fin;
string menu[3][1]={//creation d'un tableau menu
	{"\u001b[38;5;50m Start game\u001b[0m"},
	{"\u001b[38;5;50m load game\u001b[0m"},
	{"\u001b[38;5;50m exit game\u001b[0m"}
	};
string sauvegarde[3][1]={//creation d'un tableau sauvegarde
	{"\u001b[38;5;50m save1\u001b[0m"},
	{"\u001b[38;5;50m save2\u001b[0m"},
	{"\u001b[38;5;50m save3\u001b[0m"}
	};
string difficulte[3][1]={//creation d'un tableau difficulté
	{"\u001b[38;5;2m facile \u001b[0m"},
	{"\u001b[38;5;3m normal \u001b[0m"},
	{"\u001b[38;5;1m difficile \u001b[0m"}
	};
	
cout<<"\u001b[38;5;11m*****Menu*****\u001b[0m"<<endl;
cout<<"1°)"<<menu[0][0]<<endl;
cout<<"2°)"<<menu[1][0]<<endl;
cout<<"3°)"<<menu[2][0]<<endl;
cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
cin>>saisie;
system("clear");
while(saisie!=1 and saisie!=2 and saisie!=3){
	cout<<"\u001b[38;5;11m*****Menu*****\u001b[0m"<<endl;
	cout<<"1°)"<<menu[0][0]<<endl;
	cout<<"2°)"<<menu[1][0]<<endl;
	cout<<"3°)"<<menu[2][0]<<endl;
	cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
	cin>>saisie;
	system("clear");}
while(saisie==1 or saisie==2){
switch (saisie){
	case 1://New game
		{cout<<"\u001b[38;5;11m*****save*****\u001b[0m"<<endl;
		cout<<"1°)"<<sauvegarde[0][0]<<endl;
		cout<<"2°)"<<sauvegarde[1][0]<<endl;
		cout<<"3°)"<<sauvegarde[2][0]<<endl;
		cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
		cin>>save;
		system("clear");
		while(save!=1 and save!=2 and save!=3){
			cout<<"entrez une saisie valide"<<endl;
			cout<<"\u001b[38;5;11m*****save*****\u001b[0m"<<endl;
			cout<<"1°)"<<sauvegarde[0][0]<<endl;
			cout<<"2°)"<<sauvegarde[1][0]<<endl;
			cout<<"3°)"<<sauvegarde[2][0]<<endl;
			cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
			cin>>save;
			system("clear");}
		system("clear");
		cout<<"\u001b[38;5;11m****dificulté****\u001b[0m"<<endl;
		cout<<"1°)"<<difficulte[0][0]<<endl;
		cout<<"2°)"<<difficulte[1][0]<<endl;
		cout<<"3°)"<<difficulte[2][0]<<endl;
		cout<<"\u001b[38;5;11m*****************\u001b[0m"<<endl;
		cin>>dif;
		system("clear");
		while(dif!=1 and dif!=2 and dif!=3){
			cout<<"entrez une saisie valide"<<endl;
			cout<<"\u001b[38;5;11m****dificulté****\u001b[0m"<<endl;
			cout<<"1°)"<<difficulte[0][0]<<endl;
			cout<<"2°)"<<difficulte[1][0]<<endl;
			cout<<"3°)"<<difficulte[2][0]<<endl;
			cout<<"\u001b[38;5;11m*****************\u001b[0m"<<endl;
			cin>>dif;
			system("clear");}
		system("clear");
		link joueur=link(save,dif);
		joueur.initialiser();
		joueur.aventure();
		system("clear");}
		break;
	case 2://load game
		{cout<<"\u001b[38;5;11m*****save*****\u001b[0m"<<endl;
		cout<<"1°)"<<sauvegarde[0][0]<<endl;
		cout<<"2°)"<<sauvegarde[1][0]<<endl;
		cout<<"3°)"<<sauvegarde[2][0]<<endl;
		cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
		cin>>save;
		system("clear");
		while(save!=1 and save!=2 and save!=3){
			cout<<"entrez une saisie valide"<<endl;
			cout<<"\u001b[38;5;11m*****save*****\u001b[0m"<<endl;
			cout<<"1°)"<<sauvegarde[0][0]<<endl;
			cout<<"2°)"<<sauvegarde[1][0]<<endl;
			cout<<"3°)"<<sauvegarde[2][0]<<endl;
			cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
			cin>>save;
			system("clear");}
		switch (save){
			case 1:
				{system("clear");
				link joueur=link(save,1);
				joueur.load(tab,vie,viemax,dif,ren,fin);//s'assure d'avoir tout
				for(int l=0;l<=e;l++){
					for(int c=0;c<=f;c++){
						if (tab[l][c]=='X'){
							lig=l;
							col=c;
							break;}
							}
						}
				system("clear");
				if (joueur.res!=1){
					if(vie==0 or fin==1){
						joueur.difficulte=dif;
						if (fin==1){
							if (dif<3)
							joueur.difficulte+=1;
						}
					joueur.initialiser();
					joueur.aventure();
					}
					else{
					joueur.vie=vie;
					joueur.viemax=viemax;
					joueur.difficulte=dif;
					joueur.rencontre=ren;
					joueur.aventure(lig,col);}
				system("clear");}							
				}
				break;
			case 2:
				{system("clear");
				link joueur=link(save,1);
				joueur.load(tab,vie,viemax,dif,ren,fin);//s'assure d'avoir tout
				for(int l=0;l<=e;l++){
					for(int c=0;c<=f;c++){
						if (tab[l][c]=='X'){
							lig=l;
							col=c;
							break;}
							}
						}
				system("clear");
				if (joueur.res!=1){
					if(vie==0 or fin==1){
						joueur.difficulte=dif;
						if (fin==1){
								if (dif<3)
								joueur.difficulte+=1;
							}
						joueur.initialiser();
						joueur.aventure();
						}
					else{
					joueur.vie=vie;
					joueur.viemax=viemax;
					joueur.difficulte=dif;
					joueur.rencontre=ren;
					joueur.aventure(lig,col);}
				system("clear");}							
				}
				break;
			case 3:
				{system("clear");
				link joueur=link(save,1);
				joueur.load(tab,vie,viemax,dif,ren,fin);//s'assurer que les valeur on bien été prise en bas
				for(int l=0;l<=e;l++){
					for(int c=0;c<=f;c++){
						if (tab[l][c]=='X'){
							lig=l;
							col=c;
							break;}
							}
						}
				system("clear");
				if (joueur.res!=1){
					if(vie==0 or fin==1){
						joueur.difficulte=dif;
						if (fin==1){
							if (dif<3)
							joueur.difficulte+=1;
						}
						joueur.initialiser();
						joueur.aventure();
					}
					else{
					joueur.vie=vie;
					joueur.viemax=viemax;
					joueur.difficulte=dif;
					joueur.rencontre=ren;
					joueur.aventure(lig,col);}
				system("clear");}							
				}
				break;		
		}
		}
		break;
	case 3://quit Game
		cout<<"Au revoir"<<endl;
		break;
	default:
		cout<<"Entrez soit 1 soit 2 soit 3"<<endl;
	}
cout<<"\u001b[38;5;11m*****Menu*****\u001b[0m"<<endl;
cout<<"1°)"<<menu[0][0]<<endl;
cout<<"2°)"<<menu[1][0]<<endl;
cout<<"3°)"<<menu[2][0]<<endl;
cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
cin>>saisie;
system("clear");
while(saisie!=1 and saisie!=2 and saisie!=3){
	cout<<"entrez une saisie valide"<<endl;
	cout<<"\u001b[38;5;11m*****Menu*****\u001b[0m"<<endl;
	cout<<"1°)"<<menu[0][0]<<endl;
	cout<<"2°)"<<menu[1][0]<<endl;
	cout<<"3°)"<<menu[2][0]<<endl;
	cout<<"\u001b[38;5;11m**************\u001b[0m"<<endl;
	cin>>saisie;
	system("clear");}
system("clear");
}

cout<<"Au revoir"<<endl;
return 0;

}
