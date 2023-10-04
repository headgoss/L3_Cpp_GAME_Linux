#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi{//création d'une classe mère ennemi
	friend class link;
	private:
	std::string name;
	int vie;
	int atq=1;//dégat à la vie de link
	protected:
	ennemi(std::string n,int v);
	};
	
class bois:public ennemi{//ennemi en bois
	friend class Link;
	public:
	int vie=15;//la vie de l'ennemi en bois
	
	bois();
};

class fer:public ennemi{//ennemi en fer
	friend class Link;
	public:
	int vie=20;//la vie de l'ennemi en fer
	
	fer();
};

class acier:public ennemi{//ennemi en acier
	friend class Link;
	public:
	int vie=25;//la vie de l'ennemi en acier
	
	acier();
};
#endif
