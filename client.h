#pragma once
#include "produit.cpp"
#include <vector>
class Client
{
private:
	std::string nom_;
	std::string prenom_;
	int identifiant_unique_;
	std::vector<Produit> panier_de_achat_;
public:
	Client(std::string nom = "nom", std::string prenom = "prenom",int identifiant_unique=00, std::vector<Produit> panier_de_achat = {});
	std::string getNom()const;
	std::string getPrenom()const;
	int getIdentifiantUnique()const;
	std::vector<Produit> getPanierAchat()const;
	bool ajouterAuPAnier(const Produit& p);
	void flushPanierAchat();
	void miseAjourQuantitePanier(std::string nom_produit, int updateQuantite);
	bool supprimerUnproduit(const Produit& p);
	std::string afficherProduitPanier()const;
};

std::ostream& operator << (std::ostream& os,const Client C);


