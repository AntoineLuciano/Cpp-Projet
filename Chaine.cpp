#include <stdio.h>
#include "Chaine.h"
#include <iostream>
using namespace std;

// PARTIE 1 

// Question 1
Chaine::Chaine() {
	cout << "Nombre de lettres : ";

	while (!(cin >> taille) || taille <= 0){
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Rentrez une valeur strictement postitive : ";
	}
	char * ch1 = new char[taille + 1];
	cout << "Entrez votre chaine : ";
	cin >> ch1;
	ch = new char[taille];
	int i = 0;
	while (i < taille && ch1[i] != '\0') {
		ch[i] = ch1[i];
		i++;
	}
	if (i != taille) {
		taille = i;
	}
	ch[taille] = '\0';
}

Chaine::Chaine(int t) {
	taille = t;
	ch = new char[taille+1];
	for (int i = 0; i < taille; i++) {
		ch[i] =' ';
	}
	ch[taille] = '\0';
}


Chaine::Chaine(const Chaine& c) {
	taille = c.taille;
	ch = new char[c.taille+1];
	for (int i = 0; i < taille; i++) {
		ch[i] = c.ch[i];
	}
	ch[taille] = '\0';
}

void Chaine::afficher() {
	for (int i = 0; i < taille; i++) {
		cout << ch[i];
	}
	cout << '\n';
}

Chaine ::~Chaine() {
	ch = NULL;
	delete [] ch;
}

// Question 2
Chaine& Chaine :: operator =(const Chaine& c) {
	if (this != &c) {
		ch = NULL;
		delete [] ch;
		taille = c.taille;
		ch = new char[taille+1];
		for (int i = 0; i < taille; i++) {
			ch[i] = c.ch[i];
		}
		ch[taille] = '\0';
	}
	return *this;
}

char& Chaine :: operator [](int i) {
	if (i < 0 || i >= taille) {
		cout << "Indice incorrect !";
		return ch[taille];
	}
	return ch[i];
}

Chaine operator +(const Chaine &c1, const Chaine &c2) {
	int t = c1.taille + c2.taille;
	Chaine c(t);
	c.ch = new char[t+1];
	for (int i = 0; i < c1.taille; i++) {
		c.ch[i] = c1.ch[i];
	}
	for (int i = c1.taille; i <t; i++) {
		c.ch[i] = c2.ch[i-c1.taille];
	}
	c.ch[t] = '\0';
	return c;
}
// Question 3 
void Chaine::convertMaj() {
	
	for (int i = 0; i < taille; i++) {
		if (ch[i] <= 122 && ch[i] >= 97) {
			ch[i] = char(ch[i] - 32);
		}
	}
}

void Chaine::convertMin() {
	for (int i = 0; i < taille; i++) {
		if (ch[i] <= 90 && ch[i] >= 65) {
			ch[i] = char(ch[i] + 32);
		}
	}
}
//Pour la partie 2
void Chaine::convertMot() {
	for (int i = 0; i < taille; i++) {
		if (i == 0 && ch[i] <= 122 && ch[i] >= 97) {
			ch[i] = char(ch[i] - 32);
		}
		if (i > 0 && ch[i] >= 65 && ch[i] <= 90) {
			ch[i] = char(ch[i] + 32);
		}
	}
}

bool estAnagramme(const Chaine& c1, const Chaine& c2) {
	if (c2.taille != c1.taille) {
		return false;
	}
	Chaine c3(c1);	
	Chaine c4(c2);
	c3.convertMin();
	c4.convertMin();
	bool A = false;
	int ind = 0;
	for (int i = 0; i < c3.taille; i++) {
		A = false;
		for (int j = 0; j < c4.taille; j++) {
			if (c3.ch[i] == c4.ch[j]) {
				A = true;
				ind = j;
			}
		}
		if (A) {
			c4[ind] = 0;
		}
		else {
			return false;
		}
		
	}
	return true;
}

bool estPalindrome(const Chaine& c1) {
	Chaine c(c1);
	c.convertMin();
	for (int i = 0; i < c.taille; i++) {
		if (c.ch[i] != c.ch[c.taille-i-1]) {
			return false;
		}
	}
	return true;
}


// PARTIE 2 

// Question 1

Sigle::Sigle() : Chaine(1){
	cout << "\nVOTRE SIGLE\n";
	Chaine c;
	c.afficher();
	c.convertMaj();
	taille = c.taille;
	ch = new char[taille];
	cout << "\nSIGNIFICATION DES LETTRES\n";
	sigle = new Chaine[taille];
	for (int i = 0; i < taille; i++) {
		ch[i] = c.ch[i];
		sigle[i].convertMaj();
		while (sigle[i].ch[0] != ch[i]) {
			cout << "La signification de " << ch[i] << " :\n";
			sigle[i].afficher();
			cout << "ne commence pas par " << ch[i] << " !\nRerentrez sa signification : \n";
			sigle[i].~Chaine();
			sigle[i] = Chaine();
			sigle[i].convertMaj();
		}
		sigle[i].convertMot();
	}
}

void Sigle::afficherSigle() {
	cout << "\nLE SIGLE : ";
	this->afficher();
	cout << "\nSIGNIFICATION DES LETTRES : \n";
	for (int i = 0; i < taille; i++) {
		sigle[i].afficher();
	}
}

Sigle::Sigle(const Sigle& s): Chaine(1){
	taille=s.taille;																									
	ch = new char[taille];
	allocator<Chaine> alloc;
	sigle = alloc.allocate(taille);
	for (int i = 0; i < taille; i++) {
		ch[i] = s.ch[i];
		sigle[i] = s.sigle[i];
	}
	ch[taille] = '\0';
}

// Question 2
Sigle& Sigle::operator=(const Sigle& s){
	if (this != &s) {
		sigle = NULL;
		ch = NULL;
		delete sigle;
		delete ch;
		taille = s.taille;
		allocator<Chaine> alloc;
		sigle = alloc.allocate(taille);
		ch = new char[taille + 1];
		for (int i = 0; i < taille; i++) {
			ch[i] = s.ch[i];
			sigle[i] = s.sigle[i];
		}
		ch[taille] = '\0';
	}
	return *this;
}

Sigle::~Sigle() {
	sigle = NULL;
	delete[] sigle;
}

Sigle operator +(const Sigle& s1, const Sigle& s2) {
	Sigle s(s1);
	s.taille = s1.taille + s2.taille;
	s.ch = new char[s.taille+1];
	allocator<Chaine> alloc;
	s.sigle = alloc.allocate(s.taille);
	for (int i = 0; i < s1.taille; i++) {
		s.ch[i] = s1.ch[i];
		s.sigle[i] = s1.sigle[i];
	}
	for (int i = s1.taille; i < s.taille; i++) {
		s.ch[i] = s2.ch[i - s1.taille];
		s.sigle[i] = s2.sigle[i - s1.taille];
	}
	s.ch[s.taille] = '\0';
	return s;
}

const char& Sigle::operator[](int i) {
	return ch[i];
}

void Sigle::operator()(int i) {
	cout << "On remplace le mot ";
	sigle[i].afficher();
	Chaine c;
	c.convertMot();
	sigle[i] = c;
	ch[i] = sigle[i].ch[0];
}