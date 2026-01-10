#include "magasin.h"
#include "produit.h"
#include <algorithm>

Magasin::Magasin(std::vector<Produit> produit, std::vector<Client> clients, std::vector<Commande> commandes):
	produit_(produit),clients_(clients),commandes_(commandes)
{//rien a faire ici :)
}

bool Magasin::ajouterUnProduit(const Produit& p1) {
	produit_.push_back(p1);
	return 1;
}

void Magasin::produitRefenceMagasin() const
{

	for (auto p : produit_) {
		std::cout << p << std::endl;
	}
}

void Magasin::produitSpecifique(std::string nom_produit)
{
	auto it = std::find_if(produit_.begin(), produit_.end(), [nom_produit](const Produit& p) {return p.getTitreArticle() == nom_produit; });
	if (it != produit_.end()) {
		std::cout << *it;
	}
	else {
		std::cout << "ce produit n'est pas referencer";
	}

}

void Magasin::miseAjourQuantite(std::string nom_produit,int updateQuantite)
{
	auto it = std::find_if(produit_.begin(), produit_.end(), [nom_produit](const Produit& p) 
		{return p.getTitreArticle() == nom_produit; });
	if (it != produit_.end()) {
		if (updateQuantite >= 0) {
			
			it->setQuantiteDisponible(updateQuantite);
		}
	}
}

std::vector<Produit> Magasin::getProduitMagasin() const
{
	return produit_;
}

void Magasin::ajouterClient(const Client& client_ajouter)
{
	clients_.push_back(client_ajouter);
}

void Magasin::afficherLesClient() const
{
	for (auto client : clients_) {
		std::cout << "========================================" << std::endl;
		std::cout << client << std::endl;
		std::cout << "=========================================" << std::endl;
	}
}

bool Magasin::afficherClient(std::string nom)
{
	auto it = std::find_if(clients_.begin(), clients_.end(), [nom](const Client& c) {return nom == c.getNom(); });
	if (it != clients_.end()) {
		std::cout << *it << std::endl;
		return 1;
	}
	std::cout << "pas d'utilisateur a afficher ";
	return 0;
}

bool Magasin::afficherClient(int identifiant_unique)
{
	auto it = std::find_if(clients_.begin(), clients_.end(), [identifiant_unique](const Client& c)
		{return identifiant_unique == c.getIdentifiantUnique(); });
	if (it != clients_.end()) {
		std::cout << *it << std::endl;
		return 1;
	}
	std::cout << "pas d'utilisateur a afficher ";
	return 0;

}

void Magasin::ajouterProduitPanier(Client& client_panier_ajout, Produit& produit)
{
	client_panier_ajout.ajouterAuPAnier(produit);
	produit.setQuantiteDisponible(produit.getQuantiteDisponible() - 1);
}

void Magasin::retirerProduitPAnier(Client& client_panier_retiere, Produit& produit)
{
	client_panier_retiere.supprimerUnproduit(produit);
	produit.setQuantiteDisponible(produit.getQuantiteDisponible() + 1);
}

void Magasin::miseAjourQuantiteProduit(Client& client_panier_update,Produit& p, int nouvelle_quantite)
{
	client_panier_update.miseAjourQuantitePanier(p.getTitreArticle(), nouvelle_quantite);
}

std::string Magasin::validattionPanier(const Commande& commande_a_valider)
{
	auto it = std::find_if(commandes_.begin(), commandes_.end(), [&commande_a_valider](const Commande& c) {
		return c.getProprietaireCommande() == commande_a_valider.getProprietaireCommande();});
	if (it != commandes_.end()) {
		it->setEtatdeLivraison();
		it->getProrietaireCommade().flushPanierAchat();
		return "commande valide avec succes ";
	}
	  return "cette commande n'a pas ete valider car pas dans le panier de commande";
}
