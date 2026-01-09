#include "produit.h"
#include <stdexcept>

Produit::Produit(std::string titre_article, std::string description, int quantite, double prix_unitaire):
	titre_article_(titre_article),description_(description),quantite_disponible_(quantite),
	prix_unitaire_(prix_unitaire)
{
	if (titre_article.empty() || prix_unitaire == 0) {
		throw std::invalid_argument("titre vide ou prix unitaire non valide");
	}
}
std::string Produit::getTitreArticle()const{
	return titre_article_;
}

std::string Produit::getDescription() const
{
	return description_+titre_article_+" "+std::to_string(prix_unitaire_);
}

int Produit::getQuantiteDisponible() const
{
	return quantite_disponible_;
}

double Produit::getPrixUnitaire() const
{
	return prix_unitaire_;
}

void Produit::setQuantiteDisponible(int updateQuantite)
{
	if (updateQuantite > 0) {
		quantite_disponible_ = updateQuantite;
	}
}

std::ostream& operator << (std::ostream& os, const Produit& p)
{
	os << p.getDescription()+p.getTitreArticle()+" prix unitaire " + std::to_string(p.getPrixUnitaire())+" $"
		" quantite disponible "+std::to_string(p.getQuantiteDisponible());
	return os;
}

