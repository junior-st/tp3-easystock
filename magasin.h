#pragma once
#include <vector>
#include <iostream>
#include "commande.h"
#include "client.h"
#include "produit.h"
class Magasin
{
private:
	std::vector<Produit> produit_;
	std::vector<Client> clients_;
	std::vector<Commande> commandes_;
public:
	Magasin(std::vector<Produit> produit = {}, std::vector<Client> clients = {}, std::vector<Commande> commandes = {});
	bool ajouterUnProduit(const Produit& p1);
	void produitRefenceMagasin() const;
	void produitSpecifique(std::string nom_produit);
	void miseAjourQuantite(std::string nom_produit,int updateQuantite);
	std::vector<Produit> getProduitMagasin()const;

};

