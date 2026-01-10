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
	Client& getProrietaireCommade();
	std::vector<Produit> getPanierCommande()const;
	std::string getEtatLivraison()const;
	void setEtatdeLivraison();
	bool operator == (const Commande& other_commande)const;
};
std::ostream& operator << (std::ostream& os, const Commande& Com);

