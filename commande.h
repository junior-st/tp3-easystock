#pragma once
#include "client.h"
#include "produit.h"
class Commande
{
private:
	Client& proprietaire_commande_;
	std::vector<Produit> panier_commande_;
	std::string etat_ = "pas liver";
public:
	Commande(Client& client,std::vector<Produit> panier_commande = {});
	Client getProprietaireCommande()const;
	std::vector<Produit> getPanierCommande()const;
	std::string getEtatLivraison()const;
};
std::ostream& operator << (std::ostream& os, const Commande& Com);

