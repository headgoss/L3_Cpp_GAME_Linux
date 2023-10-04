#ifndef PLATEAU_H
#define PLATEAU_H
const int e=50;
const int f=36;
	
class plateau{
	friend class link;
	private:
	int rencontre=0;
	char tab[e][f];
	int reussi=0;
	int linkvie=0;	
	int linkviemax=0;	
	
	void initialise(char tab[][f]);
	

	void print (char matrix[][f],int l,int c,int vie,int viemax);
};
#endif
