#include <iostream>
#include <string>
#include "plateau.h"
#include "link.h"
using namespace std;

void plateau::initialise(char tab[][f]){//initialise le tableaux deux d
	for(int lig=0;lig<e;lig++){
		for(int col=0;col<f;col++)
			{tab[lig][col]=' ';
			if (lig==3 and col==1)
				tab[lig][col]='X';//personnage link
			if (lig==12 and col==19)
				tab[lig][col]='?';//instructeur
			if (lig==12 and col==20)
				tab[lig][col]='c';//demi-coeur
			if (lig==25 and col==23)
				tab[lig][col]='c';//demi-coeur
			if (lig==27 and col==3)
				tab[lig][col]='c';//demi-coeur
			if (lig==46 and col==1)
				tab[lig][col]='c';//demi-coeur
			if (lig==29 and col==34)
				tab[lig][col]='c';//demi-coeur
			if (lig==39 and col==25)
				tab[lig][col]='c';//demi-coeur
			if (lig==32 and col==26)
				tab[lig][col]='T';}//épée
			}
		//déclaration des limites du tableau
		for(int col=16;col<=20;col++)
			tab[17][col]='_';
		for(int col=1;col<=9;col++)
			tab[0][col]='_';
		for(int lig=1;lig<=14;lig++)
			tab[lig][0]='|';
		for(int col=1;col<=14;col++)
			tab[14][col]='_';
		for(int lig=1;lig<=9;lig++)
			tab[lig][10]='|';
		for(int col=11;col<=20;col++)
			tab[9][col]='_';
		for(int lig=10;lig<=23;lig++)
			tab[lig][21]='|';
		for(int col=22;col<=34;col++)
			tab[23][col]='_';
		for(int col=1;col<=34;col++)
			tab[48][col]='_';
		for(int lig=24;lig<=48;lig++)
			tab[lig][0]='|';
		for(int lig=24;lig<=48;lig++)
			tab[lig][35]='|';
		for(int col=1;col<=14;col++)
			tab[23][col]='_';
		for(int lig=15;lig<=23;lig++)
			tab[lig][15]='|';
		for(int col=8;col<=23;col++)
			tab[31][col]='_';
		for(int lig=32;lig<=41;lig++)
			tab[lig][7]='|';
		for(int col=8;col<=29;col++)
			tab[41][col]='_';
		for(int lig=24;lig<=41;lig++)
			tab[lig][24]='|';
		//déclaration des ennemies
		for(int lig=24;lig<=30;lig+=3)
			tab[lig][8]='o';
		for(int col=1;col<=6;col+=3)
			tab[37][col]='o';
		for(int lig=42;lig<=47;lig+=3)
			tab[lig][8]='o';
		for(int lig=42;lig<=47;lig+=3)
			tab[lig][24]='o';
		for(int lig=24;lig<=40;lig+=3)
			tab[lig][28]='o';
		
		}
		
void plateau::print (char matrix[][f],int l,int c,int vie,int viemax){//affiche le tableau 2d mais que autour du personnage 
		int lig,col;
		linkvie=vie;
		linkviemax=viemax;
		char tab[14][16];
		for (int i=1;i<14;i++){
			for(int j=0;j<16;j++){
				tab[i][j]=' ';}
				}
		for (int i=1;i<16;i++)
			tab[0][i]='_';
		for (int j=1;j<14;j++)
			tab[j][0]='|';
		for (int i=1;i<16;i++)
			tab[13][i]='_';
		for (int j=1;j<14;j++)
			tab[j][15]='|';
		int ll=2,cc=2;
		if (rencontre==0)
			{cout<<"\u001b[38;5;1m"<<"Allez chez l'instructeur(🧙 ) pour savoir quoi faire."<<"\u001b[0m"<<"\u001b[38;5;2m"<<"		Vie:"<<"\u001b[0m"<<"\u001b[38;5;1m"<<linkvie<<"\u001b[0m"<<"/"<<"\u001b[38;5;1m"<<linkviemax<<"\u001b[0m"<<endl;
			cout<<endl;}
		else
			{cout<<"\u001b[38;5;1m"<<"Allez chercher l'épée(🗡️ )."<<"\u001b[0m"<<"\u001b[38;5;2m"<<"		Vie:"<<"\u001b[0m"<<"\u001b[38;5;1m"<<linkvie<<"\u001b[0m"<<"/"<<"\u001b[38;5;1m"<<linkviemax<<"\u001b[0m"<<endl;
			cout<<endl;}
			
		if (l-5<=0 and c-5<=0){//cas d'affiche quand on est à 0 ou moins dans le tableau
			for(int lig=0;lig<=l+5;lig++){
				for (int col=0;col<=c+5;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}
				}
		else if(l+5>=e and c-5<=0){//cas d'affichage avec ligne dépasse max et colone vers 0
			for(int lig=l-5;lig<e;lig++){
				for (int col=0;col<=c+5;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else if (l+5>=e and c+5>=f){//cas d'affichage avec excédent
			for(int lig=l-5;lig<e;lig++){
				for (int col=c-5;col<f;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else if (l-5<=0){//cas d'affichage avec ligne -5 inférieur
			for(int lig=0;lig<=l+5;lig++){
				for (int col=c-5;col<=c+5;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else if (c-5<=0){//cas d'affichage avec colonne -5 inférieur
			for(int lig=l-5;lig<=l+5;lig++){
				for (int col=0;col<=c+5;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else if (l+5>=e){//cas d'affichage avec ligne dépasse max 
			for(int lig=l-5;lig<e;lig++){
				for (int col=c-5;col<=c+5;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else if (c+5>=f){//cas d'affichage avec collone dépasse max
			for(int lig=l-5;lig<=l+5;lig++){
				for (int col=c-5;col<f;col++)
					{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		else {//cas d'affichage sans soucis
			for(lig=l-5;lig<=l+5;lig++){
				for(col=c-5;col<=c+5;col++)
				{tab[ll][cc]=matrix[lig][col];
					cc+=1;}
				ll+=1;
				cc=2;}}
		for (int i=0;i<14;i++){
			for(int j=0;j<16;j++){
				if (tab[i][j]=='X'){
					cout<<"\u001b[48;5;22m🧝\u001b[0m";
				}
				else if (tab[i][j]=='?'){
					cout<<"\u001b[48;5;22m🧙\u001b[0m";
				}
				else if (tab[i][j]=='c'){
					cout<<"\u001b[48;5;22m❤️ \u001b[0m";
				}
				else if (tab[i][j]=='o'){
					cout<<"\u001b[48;5;22m🤖\u001b[0m";
				}	
				else if (tab[i][j]=='T'){
					cout<<"\u001b[48;5;22m🗡️ \u001b[0m";
				}
				else if((i>=2 and i<13) and (j>=2 and j<13)){
					cout<<"\u001b[48;5;22m";
					if (tab[i][j]=='_' or tab[i][j]=='|'){
						cout<<"\u001b[38;5;51m"<<tab[i][j];}
					else{
						cout<<tab[i][j];}
					cout<<" \u001b[0m";
					}
					
				else
					cout<<tab[i][j]<<" ";
			}
			cout<<endl;
		}
	}
