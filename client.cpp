#include "client.h"
#include "magasin.h"
#include "produit.h"

std::string Client::getNom() const
{
    return nom_;
}

std::string Client::getPrenom() const
{
    return prenom_;
}

int Client::getIdentifiantUnique() const
{
    return identifiant_unique_;
}

std::vector<Produit> Client::getPanierAchat() const
{
    return panier_de_achat_;
}

bool Client::ajouterAuPAnier(const Produit& p  )
{
    if (p.getQuantiteDisponible() > 0) {
        panier_de_achat_.push_back(p);
        return 1;
    }
    return 0;
}

void Client::flushPanierAchat()
{
    panier_de_achat_.erase(panier_de_achat_.begin(), panier_de_achat_.end());
}

void Client::miseAjourQuantitePanier(std::string nom_produit, int updateQuantite)
{
    auto it = std::find_if(panier_de_achat_.begin(),panier_de_achat_.end(), [nom_produit](const Produit& p)
        {p.getTitreArticle() == nom_produit; });
    if (it != panier_de_achat_.end()) {
        if (updateQuantite >= 0) {
            auto produit = *it;
            produit.setQuantiteDisponible(updateQuantite);
        }
    }
}
