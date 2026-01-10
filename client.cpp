#include "client.h"
#include "magasin.h"
#include "produit.h"
#include <stdexcept>
#include <algorithm>

Client::Client(std::string nom, std::string prenom, int identifiant_unique, std::vector<Produit> panier_de_achat):
    nom_(nom),prenom_(prenom),identifiant_unique_(identifiant_unique)
{
    if (nom.empty() || prenom.empty()) {
        throw std::invalid_argument("le nom et prenom ne peuvent etre vide");
    }
}

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
        { return p.getTitreArticle() == nom_produit; });
    if (it != panier_de_achat_.end()) {
        if (updateQuantite >= 0) {
           
            it->setQuantiteDisponible(updateQuantite);
        }
    }
}

bool Client::supprimerUnproduit(const Produit& p)
{
    auto it = std::find(panier_de_achat_.begin(), panier_de_achat_.end(), p);
    if (it != panier_de_achat_.end()) {
        auto it1 = std::remove(panier_de_achat_.begin(), panier_de_achat_.end(), *it);
        panier_de_achat_.erase(it1, panier_de_achat_.end());
        return true;
    }
    return false;
}

std::string Client::afficherProduitPanier() const
{
    std::string liste_produit = "";
    for (Produit p : panier_de_achat_) {
        liste_produit = "-" + p.getTitreArticle() + " -----X " + std::to_string(p.getQuantiteDisponible()) +"\n";
    }
    return liste_produit;
}

std::ostream& operator<<(std::ostream& os, const Client& c)
{
    os << "-" + c.getNom() + "\n" +
        "-" + c.getPrenom() + "\n" +
        "-" + std::to_string(c.getIdentifiantUnique()) + "\n"
        + "panier d'achat:"+c.afficherProduitPanier();

    return os;
}
