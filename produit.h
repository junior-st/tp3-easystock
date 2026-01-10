#pragma once
#include <string>
#include <iostream>
class Produit
{
private:
	std::string titre_article_;
	std::string description_;
	int quantite_disponible_;
	double prix_unitaire_;
public:
	Produit(std::string titre_article = "nom_article", std::string description = "caracteristiques: inconnu ",
		int quantite = 0, double prix_unitaire = 1.0);
	std::string getTitreArticle()const;
	std::string getDescription()const;
	int getQuantiteDisponible()const;
	double getPrixUnitaire()const;
	void setQuantiteDisponible(int updateQuantite);
	bool operator==(const Produit& other) const;

	
};
std::ostream& operator << (std::ostream& os, const Produit& p);
