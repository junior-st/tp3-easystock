#include "magasin.h"
#include "produit.h"

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
	auto it = std::find_if(produit_.begin(), produit_.end(), [nom_produit](const Produit& p) {p.getTitreArticle() == nom_produit; });
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
		{p.getTitreArticle() == nom_produit; });
	if (it != produit_.end()) {
		if (updateQuantite >= 0) {
			auto produit = *it;
			produit.setQuantiteDisponible(updateQuantite);
		}
	}
}

std::vector<Produit> Magasin::getProduitMagasin() const
{
	return produit_;
}
