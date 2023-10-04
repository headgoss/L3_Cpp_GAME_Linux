#include <iostream>
#include <string>
#include <cstdlib> // pour system("clear")
#include <unistd.h> // pour sleep();
#include "kbhit.h"
#include "getch.h"//initialiser après Kbhit pour les static
#include "link.h"
#include "plateau.h"
#include "ennemi.h"
#include "instructeur.h"

using namespace std;

link::link(int s,int d):sauvegarde(s),difficulte(d){}

void link::initialiser(){//initialise le plateau
		p.initialise(tab);
		}
		
void link::save(char tab[][f],int &vie,int &viemax,int &difficulte,int &rencontre,int &fin){//sauvegarde 
		FILE *save;
		if (sauvegarde==1){
			save = fopen("save1.txt","wt");
			if (save){
				fwrite(tab,e,f,save);
				fwrite(&vie,1,1,save);
				fwrite(&viemax,1,1,save);
				fwrite(&difficulte,1,1,save);
				fwrite(&rencontre,1,1,save);
				fwrite(&fin,1,1,save);
				fclose(save);}
			else
				cout<<"échec"<<endl;}
		else if (sauvegarde==2){
			save = fopen("save2.txt","wt");
			if (save){
				fwrite(tab,e,f,save);
				fwrite(&vie,1,1,save);
				fwrite(&viemax,1,1,save);
				fwrite(&difficulte,1,1,save);
				fwrite(&rencontre,1,1,save);
				fwrite(&fin,1,1,save);
				fclose(save);}
			else
				cout<<"échec"<<endl;}
		else {
			save = fopen("save3.txt","wt");
			if (save){
				fwrite(tab,e,f,save);
				fwrite(&vie,1,1,save);
				fwrite(&viemax,1,1,save);
				fwrite(&difficulte,1,1,save);
				fwrite(&rencontre,1,1,save);
				fwrite(&fin,1,1,save);
				fclose(save);}
			else
				cout<<"échec"<<endl;}
		}
		
void link::load(char tab[][f],int &vie,int &viemax,int &difficulte,int &rencontre,int &fin){//charge
		FILE *save;
		if (sauvegarde==1){
			save = fopen("save1.txt","rt");
			if (save){
				fread(tab,e,f,save);
				fread(&vie,1,1,save);
				fread(&viemax,1,1,save);
				fread(&difficulte,1,1,save);
				fread(&rencontre,1,1,save);
				fread(&fin,1,1,save);
				fclose(save);}
			else{
				cout<<"échec"<<endl;
				res=1;}}
		else if (sauvegarde==2){
			save = fopen("save2.txt","rt");
			if (save){
				fread(tab,e,f,save);
				fread(&vie,1,1,save);
				fread(&viemax,1,1,save);
				fread(&difficulte,1,1,save);
				fread(&rencontre,1,1,save);
				fread(&fin,1,1,save);
				fclose(save);}
			else{
				cout<<"échec"<<endl;
				res=1;}}
		else {
			save = fopen("save3.txt","rt");
			if (save){
				fread(tab,e,f,save);
				fread(&vie,1,1,save);
				fread(&viemax,1,1,save);
				fread(&difficulte,1,1,save);
				fread(&rencontre,1,1,save);
				fread(&fin,1,1,save);
				fclose(save);}
			else{
				cout<<"échec"<<endl;
				res=1;}}
			
		}
		
void link::attaque(int dif){//fait les attaque au hasard selon la difficulté choisi
		if (dif==1)
			{res=rand()%6+1;}
		else if (dif==2)
			{res=rand()%4+1;}
		else 
			{res=rand()%2+1;}
	}	

void link::combat(){//combat contre les pantins fonctionne bien
		system("clear");
		sleep(1);
		char choix;
		int nn=rand()%3+1;
		int d1,d2,d3;
		cout<<"\u001b[48;5;232m";
		switch (nn){//donne au hasard un type d'adversaire
			case 1:
				{bois en=bois();
				cout<<"Vous avez rencontré un "<<en.name<<" voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
					choix=getch();
					while(choix!='a' and choix!='e')
						{cout<<"entrez soit a soit e"<<endl;
						choix=getch();
						}
					while(vie!=0 and en.vie!=0){
						if (choix=='e'){
							parade=2;
							cout<<"Tu t'es protégé pour deux tours."<<endl;
						}
						else
							{attaque(difficulte);//chance de toucher 
							if (res!=1)//on touche
							{
								en.vie-=atq;
							if (parade!=0)
								{parade-=1;
								cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
							else
								cout<<"Tu n'est pas protégé"<<endl;
							}
							else//on se fait toucher
								{
								if (parade!=0)
									{parade-=1;
									cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
								else
									vie= vie-en.atq;
								}
							}
						if (en.vie!=0 and vie!=0){
							cout<<"Le "<<en.name<<" a encore "<<en.vie<<" et vous avez "<<vie<<". Voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
							choix=getch();
						while(choix!='a' and choix!='e')
							{cout<<"entrez soit a soit e"<<endl;
							choix=getch();
							}
						}
						else 
							parade=0;
						}
						en.vie=15;//On remet la vie à 15 pour pouvoir les réutiliser
							}
						
					break;
				case 2:
					{fer en=fer();
					cout<<"Vous avez rencontré un "<<en.name<<" voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
					choix=getch();
					while(choix!='a' and choix!='e')
						{cout<<"entrez soit a soit e"<<endl;
						choix=getch();
						}
					while(vie!=0 and en.vie!=0){
						if (choix=='e'){
							parade=2;
							cout<<"Tu t'es protégé pour deux tours."<<endl;
						}
						else
							{attaque(difficulte);//chance de toucher 
							if (res!=1)//on touche
							{
								en.vie-=atq;
							if (parade!=0)
								{parade-=1;
								cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
							else
								cout<<"Tu n'est pas protégé"<<endl;
							}
							else//on se fait toucher
								{
								if (parade!=0)
									{parade-=1;
									cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
								else
									vie= vie-en.atq;
								}
							}
						if (en.vie!=0 and vie!=0){
							cout<<"Le "<<en.name<<" a encore "<<en.vie<<" et vous avez "<<vie<<". Voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
							choix=getch();
						while(choix!='a' and choix!='e')
							{cout<<"entrez soit a soit e"<<endl;
							choix=getch();
							}
						}
						else 
							parade=0;
						}
						en.vie=20;//On remet la vie à 20
							}					
				break;
				case 3:
					{acier en=acier();
					cout<<"Vous avez rencontré un "<<en.name<<" voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
					choix=getch();
					while(choix!='a' and choix!='e')
						{cout<<"entrez soit a soit e"<<endl;
						choix=getch();
						}
					while(vie!=0 and en.vie!=0){
						if (choix=='e'){
							parade=2;
							cout<<"Tu t'es protégé pour deux tours."<<endl;
						}
						else
							{attaque(difficulte);//chance de toucher 
							if (res!=1)//on touche
							{
								en.vie-=atq;
							if (parade!=0)
								{parade-=1;
								cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
							else
								cout<<"Tu n'est pas protégé"<<endl;
							}
							else//on se fait toucher
								{
								if (parade!=0)
									{parade-=1;
									cout<<"Il te reste "<<parade<<" tours de protection."<<endl;}
								else
									vie= vie-en.atq;
								}
							}
						if (en.vie!=0 and vie!=0){
							cout<<"Le "<<en.name<<" a encore "<<en.vie<<" et vous avez "<<vie<<". Voulez-vous vous défendre(e) ou attaquer(a)?"<<endl;
							choix=getch();
						while(choix!='a' and choix!='e')
							{cout<<"entrez soit a soit e"<<endl;
							choix=getch();
							}
						}
						else 
							parade=0;
						}
						en.vie=25;//on remet la vie à 25
					break;}}
				cout<<"\u001b[0m";
			}	

void link::deplacement(){//deplacement des ennemi et si il rencontre le joueur un combat commence
	for(int lig=0;lig<=e;lig++){
		for(int col=0;col<=f;col++){	
			int dep=rand()%4+1;//déplacement aléatoire choisi
			if (tab[lig][col]=='o'){
			switch (dep){
				case 1://haut
					{
					if (tab[lig-1][col]=='_' or tab[lig-1][col]=='|')
						break;
					else if (tab[lig-1][col]=='o')
						break;
					else if (tab[lig-1][col]=='c')
						break;
					else if (tab[lig-1][col]=='T')
						break;
					else if (tab[lig-1][col]=='?')
						break;
					else if (tab[lig-1][col]=='X')//rencontre le joueur combat
						{combat();
						if (vie!=0){
							tab[lig][col]=' ';}
						
						break;}
					else {
						tab[lig][col]=' ';
						tab[lig-1][col]='o';
					break;}}
				case 2://bas
					{
					if (tab[lig+1][col]=='_' or tab[lig+1][col]=='|')
						break;
					else if (tab[lig+1][col]=='o')
						break;
					else if (tab[lig+1][col]=='c')
						break;
					else if (tab[lig+1][col]=='T')
						break;
					else if (tab[lig+1][col]=='?')
						break;
					else if (tab[lig+1][col]=='X')//rencontre le joueur combat
						{combat();
						if (vie!=0){
							tab[lig][col]=' ';}
						
						break;}
					else {
						tab[lig][col]=' ';
						tab[lig+1][col]='o';
					break;}}
					break;
				case 3://gauche
					{
					if (tab[lig][col-1]=='_' or tab[lig][col-1]=='|')
						break;
					else if (tab[lig][col-1]=='o')
						break;
					else if (tab[lig][col-1]=='c')
						break;
					else if (tab[lig][col-1]=='T')
						break;
					else if (tab[lig][col-1]=='?')
						break;
					else if (tab[lig][col-1]=='X')//rencontre le joueur combat
						{combat();
						if (vie!=0){
							tab[lig][col]=' ';}
						
						break;}
					else {
						tab[lig][col]=' ';
						tab[lig][col-1]='o';
					break;}}
					break;
				case 4://droite
					{
					if (tab[lig][col+1]=='_' or tab[lig][col+1]=='|')
						break;
					else if (tab[lig][col+1]=='o')
						break;
					else if (tab[lig][col+1]=='c')
						break;
					else if (tab[lig][col+1]=='T')
						break;
					else if (tab[lig][col+1]=='?')
						break;
					else if (tab[lig][col+1]=='X')//rencontre le joueur combat
						{combat();
						if (vie!=0){
							tab[lig][col]=' ';}
						
						break;}
					else {
						tab[lig][col]=' ';
						tab[lig][col+1]='o';
					break;}}
			}				
			}
		}
	}
	}

void link::aventure(int lig,int col){//le jeu
	char mouv;
	char suite;
	p.rencontre=rencontre;//pour la sauvegarde si on charge avoir la valeur
	cout<<"\u001b[48;5;232mPour arrêter le jeu appuyer sur toute autre touche de déplacement(zqsd) mais je vous conseille d'appuyer doucement sur les touche pour éviter des problèmes d'affichage.\u001b[0m"<<endl;
	suite=getch();//problème de buffer qui prend entré en compte
	suite=getch();
	system("clear");//efface
	p.print(tab,lig,col,vie,viemax);//affiche le tableau
	mouv='z';
	while((mouv=='q' or mouv=='s' or mouv=='z' or mouv=='d') and vie!=0 and fin!=1){//fait le déplacement des ennemi même sans déplacement du joueur
	enable_raw_mode();
	if (kbhit())
		{	
			mouv=getch();
			char temp=0;
			while(kbhit()){
			temp=getch();
			};
			switch(mouv){
				case'z'://déplacer vers le haut
					if (tab[lig-1][col]=='_' or tab[lig-1][col]=='|')
						break;
					else if(tab[lig-1][col]=='?')
						{if(difficulte==1){
							i.rencontre1();}
						else if(difficulte==2){
							i.rencontre2();
							}
						else
							i.rencontre3();
						for(int col=16;col<=20;col++)
							tab[17][col]=' ';
																				
						p.rencontre=1;
						rencontre=1;
						break;}
					else if(tab[lig-1][col]=='c')
						{coeur+=1;
						tab[lig][col]=' ';
						lig-=1;
						tab[lig][col]='X';
						if (coeur==2){
						coeur=0;
						viemax+=1;
						vie=viemax;}
						break;
						}
					else if(tab[lig-1][col]=='o')
						{
						combat();
						if (vie!=0){
							tab[lig-1][col]=' ';}
						break;
						}
					else if(tab[lig-1][col]=='T')
						{fin+=1;
						tab[lig][col]=' ';
						lig-=1;
						tab[lig][col]='X';
						break;}
					else
						{tab[lig][col]=' ';
						lig-=1;
						tab[lig][col]='X';}
					break;
				case's'://déplacer vers le bas
					if (tab[lig+1][col]=='_' or tab[lig+1][col]=='|')
						break;
					else if(tab[lig+1][col]=='?')
						{if(difficulte==1){
							i.rencontre1();}
						else if(difficulte==2){
							i.rencontre2();
							}
						else
							i.rencontre3();
							
						for(int col=16;col<=20;col++)
							tab[17][col]=' ';
																								
						p.rencontre=1;
						rencontre=1;
						break;}
					else if(tab[lig+1][col]=='c')
						{coeur+=1;
						tab[lig][col]=' ';
						lig+=1;
						tab[lig][col]='X';
						if (coeur==2){
						coeur=0;
						viemax+=1;
						vie=viemax;
						}
						break;}
					else if(tab[lig+1][col]=='o')
						{
						combat();
						if (vie!=0){							
							tab[lig+1][col]=' ';}
						break;
						}
					else if(tab[lig+1][col]=='T')
						{fin+=1;
						tab[lig][col]=' ';
						lig+=1;
						tab[lig][col]='X';
						break;}
					else
						{tab[lig][col]=' ';
						lig+=1;
						tab[lig][col]='X';}
					break;
				case'q'://déplacer à gauche
					if (tab[lig][col-1]=='_' or tab[lig][col-1]=='|')
						break;
					else if(tab[lig][col-1]=='?')
						{if(difficulte==1){
							i.rencontre1();}
						else if(difficulte==2){
							i.rencontre2();
							}
						else
							i.rencontre3();
							
						for(int col=16;col<=20;col++)
							tab[17][col]=' ';
																								
						p.rencontre=1;
						rencontre=1;
						break;}
					else if(tab[lig][col-1]=='c')
						{coeur+=1;
						tab[lig][col]=' ';
						col-=1;
						tab[lig][col]='X';
						if (coeur==2){
						coeur=0;
						viemax+=1;
						vie=viemax;}
						break;
						}
					else if(tab[lig][col-1]=='T')
						{fin+=1;
						tab[lig][col]=' ';
						col-=1;
						tab[lig][col]='X';
						break;}
					else if(tab[lig][col-1]=='o')
						{
						combat();
						if (vie!=0){
							tab[lig][col-1]=' ';}
						break;
						}
					else
						{tab[lig][col]=' ';
						col-=1;
						tab[lig][col]='X';}
					break;
				case'd'://déplacer vers la droite
					if (tab[lig][col+1]=='_' or tab[lig][col+1]=='|')
						break;
					else if(tab[lig][col+1]=='?')
						{if(difficulte==1){
							i.rencontre1();}
						else if(difficulte==2){
							i.rencontre2();
							}
						else
							i.rencontre3();
							
						for(int col=16;col<=20;col++)
							tab[17][col]=' ';
																							
						p.rencontre=1;
						rencontre=1;
						break;}
					else if(tab[lig][col+1]=='c')
						{coeur+=1;
						tab[lig][col]=' ';
						col+=1;
						tab[lig][col]='X';
						if (coeur==2){
						coeur=0;
						viemax+=1;
						vie=viemax;
						}
						break;}
					else if(tab[lig][col+1]=='o')
						{
						combat();
						if (vie!=0){
							tab[lig][col+1]=' ';}
						break;
						}
					else if(tab[lig][col+1]=='T')
						{fin+=1;
						tab[lig][col]=' ';
						col+=1;
						tab[lig][col]='X';
						break;}
					else
						{tab[lig][col]=' ';
						col+=1;
						tab[lig][col]='X';}
					break;
				default:
					break;
			}
	}
	disable_raw_mode();
	tcflush(0, TCIFLUSH);
	if (tempo==10){
		deplacement();
		tempo=0;}
	save(tab,vie,viemax,difficulte,rencontre,fin);//sauvegarde automatique
	usleep(100000);//raffraichisement
	system("clear");
	p.print(tab,lig,col,vie,viemax);//affichage
	tempo+=1;
		}
	if (vie==0)
			{cout<<"\u001b[38;5;124m"<<"GAME OVER"<<"\u001b[0m"<<endl;//perdu
			char suite;
			cin.get(suite);
			cin.get(suite);}
	else if (fin==1)
			{cout<<"\u001b[38;5;190m"<<"Bravo vous avez fini ce petit jeu"<<"\u001b[0m"<<endl;//gagné
			char suite;
			cin.get(suite);}
	}
		
		
