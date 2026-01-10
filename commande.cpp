#include "commande.h"

Commande::Commande(Client& client, std::vector<Produit> panier_commande)
    : proprietaire_commande_(client),
      panier_commande_(panier_commande)
{
}

Client Commande::getProprietaireCommande() const
{
    return proprietaire_commande_;
}

std::vector<Produit> Commande::getPanierCommande() const
{
    return panier_commande_;
}

std::string Commande::getEtatLivraison() const
{
    return etat_;
}

std::ostream& operator<<(std::ostream& os, const Commande& com)
{
    os << com.getProprietaireCommande().getNom() << " " << com.getProprietaireCommande().getPrenom() 
       << com.getProprietaireCommande().afficherProduitPanier()<<std::endl<<com.getEtatLivraison();

    return os;
}
