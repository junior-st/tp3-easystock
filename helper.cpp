#include "helper.h"

void chargement_fichier_client(std::string nom_fichier, Magasin& easy)
{
	std::ifstream file;
	file.open(nom_fichier);
	if (file.is_open()) {
		std::string nom;
		std::string prenom;
		std::string identififiant;
		std::string ligne;
		std::getline(file, ligne);
		while (std::getline(file, ligne)) {
			std::stringstream ss(ligne);
			std::getline(ss, nom, ',');
			std::getline(ss, prenom, ',');
			std::getline(ss, identififiant);
			int id = std::stoi(identififiant);
			Client client(nom, prenom, id);
			easy.ajouterClient(client);
		}
		file.close();



	}
}

void chargement_fichier_produit(std::string nom_fichier, Magasin& easy)
{
	std::ifstream file;
	file.open(nom_fichier);
	if (file.is_open()) {
		std::string ligne;
		while (std::getline(file, ligne)) {
			std::stringstream ss(ligne);
			std::string article;
			std::string description;
			std::string quantite;
			std::string prix;
			std::getline(ss, article, ',');
			std::getline(ss, description, ',');
			std::getline(ss, quantite, ',');
			std::getline(ss, prix, ',');
			int q = std::stoi(quantite);
			double p = std::stod(prix);
			Produit nouveau(article, description, q, p);
			easy.ajouterUnProduit(nouveau);
		}

		file.close();
	}
}
