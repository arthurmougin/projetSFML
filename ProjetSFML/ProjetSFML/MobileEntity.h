#pragma once
#include "GameObject.h"

class MobileEntity:public GameObject //d�signe tout �l�ment qui se d�place de mani�re autonome
{
protected:
	bool flying;//	vrai pour les blocks, d�finis si une entit� subit la gravit� ou pas
	double speed;//	vitesse de deplacement
	Vector2f acceleration;//	vecteur d'acceleration (utilis� principalement pour la gravit�)
	Vector2f direction;//	vecteur de direction
	bool TraverseBlock;//	Si une entit� peut traverser les blocks ou pas : les animaux ne traversent pas les blocks
	bool TraverseMur;//	Si une entit� peut traverser les murs ou pas : les Blocks traversent les murs
	bool MarcheSurBlock;//	Si une entit� peut marcher sur les blocks ou pas : le personnage en mode Rocher tombe au travers des blocks
	double Hauteur;// 0 au sol, 1++ quand on est en air (utilis� pour activer la gravit� ou pas
	Sprite Fantome;//	Sprite identique � la sprite de l'entit�, elle est d�plac�e avant un vrai d�placement pour savoir si l'espace est libre 
	/*

	Retour sur le syst�me de collision fantome

	Positif : Simple � mettre en place et adapt� dans un jeu 2D ou les �l�ments ne se survolent pas
	(Dans un jeu 3D classique, cette solution est parfaite)

	Negatif : En 2D, D�s que l'on a des �l�ments que l'on peut traverser sans probl�me, on a des glitchs.

	*/

public:
	/* CONSTRUCTEURS */ 
	MobileEntity();//Constructeur standard
	/*
		Les constructeurs suivant servent pour etre int�gr�s dans la construction de classes filles
	*/
	MobileEntity(Vector2f, Texture, IntRect);
	MobileEntity(int, Vector2f, Texture, IntRect);
	MobileEntity(bool, double, bool, bool,bool);
	MobileEntity(bool, double, bool, bool, bool, Vector2f, Texture, IntRect);
	MobileEntity(bool, double, bool, bool, bool, int, Vector2f, Texture, IntRect);
	MobileEntity(bool, double, Vector2f, Vector2f, bool, bool, bool, double);
	MobileEntity(bool, double, Vector2f, Vector2f, bool, bool, bool, double, Vector2f, Texture, IntRect);
	MobileEntity(bool, double, Vector2f, Vector2f,bool, bool, bool, double, int, Vector2f, Texture, IntRect);

	/* FONCTIONS MEMBRES DE LA CLASSE */
	void moveTo(Direction);
	void updatePos(double);//Gravity
	void initDirection();

	Sprite getUpdatedFantome(Direction);


	/* GETER SETER */
	bool getFlying();
	void setFlying(bool);

	double getSpeed();
	void setSpeed(double);

	Vector2f getAcceleration();
	void setAcceleration(Vector2f);

	Vector2f getDirection();
	void setDirection(Vector2f);

	bool getTraverseBlock();
	void setTraverseBlock(bool);

	bool getTraverseMur();
	void setTraverseMur(bool);

	bool getMarcheSurBlock();
	void setMarcheSurBlock(bool);

	double getHauteur();
	void setHauteur(double);

	Sprite getFantome();
	void setFantome(Sprite);

};

