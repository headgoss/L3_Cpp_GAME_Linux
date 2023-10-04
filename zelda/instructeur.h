#ifndef INSTRUCTEUR_H
#define INSTRUCTEUR_H

class instructeur{//déclare la rencontre avec l'instructeur de mission
	friend class link;
	private:
	std::string name = "maitre instructeur";//Nom donné
	//les trois rencontre selon la difficulté
	void rencontre1();
	
	void rencontre2();
	
	void rencontre3();
};
#endif
