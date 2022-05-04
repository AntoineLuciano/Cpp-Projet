#pragma once
#include <stdio.h>
# include <iostream>
using namespace std;

class Chaine {
public:
	int taille;
	char *ch;
	Chaine();
	Chaine(int);
	Chaine(const Chaine&);
	void afficher();
	~Chaine();
	Chaine& operator =(const Chaine &);
	char& operator [](int);
	friend Chaine operator +(const Chaine&,const Chaine&);
	void convertMaj();
	void convertMin();
	void convertMot();
	friend bool estAnagramme(const Chaine&, const Chaine&);
	friend bool estPalindrome(const  Chaine&);
};

class Sigle : public Chaine {
public:
	Chaine* sigle;
public:
	Sigle();
	void afficherSigle();
	Sigle(const Sigle&);
	Sigle& operator =(const Sigle&);
	friend Sigle operator+(const Sigle&, const Sigle&);
	~Sigle();
	const char& operator[](int);
	void operator()(int);

};
