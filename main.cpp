#include <iostream>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"
#include <limits>
#include <fstream>
#include <sstream>
#include "helper.h"
int main() {
	//creation de produits
		/*Produit biscuit("biscuit", "biscuits au chocolat fourre", 10, 0.90);
		Produit gel("gel nivea", "gel de nettoyage masculin ", 30, 5.55);
		Produit pain("pain", "un pain ideale pour la croissance", 25, 1.30);
		Produit lait("lait", "lait caille Nido", 75, 1.10);
		Produit savon("savon de marseille", "savon tout usage", 20, 0.5);
		Produit jouet("voiture", "voiture pat patrouille", 40, 45.0);
		Produit chocolat("nutella", "chocolat a base de cacao et d'huile vegetale", 50, 6.99);*/
	std::vector<Produit> produits = {};
	//lecture des fichiers csv brick by brick

	//creation de client 
	Client client1("chakoutio", "junior", 0);
	Client client2("nguewo", "rose", 1);
	Client client3("nanmegni", "Alain", 2);
	Client client4("keti", "sorelle", 3);
	Client client5("tonfeu", "styve", 0);
	std::vector<Client> clients = { client1 };
	//creation d'un vector de commande vide ;
	std::vector<Commande> commandes = {};
	//creation de mo magasin
	Magasin easystock(produits, clients, commandes);
	std::ifstream file;
	file.open("produit.csv");
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
			easystock.ajouterUnProduit(nouveau);
		}

		file.close();
	}
	/*file.open("client.csv");
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
			easystock.ajouterClient(client);
		}
		file.close();



	}*/
	chargement_fichier_client("client.csv", easystock);

	std::cout<<"====================================" << std::endl;
	std::cout << "       Menu gestion de magasin      " << std::endl;
	std::cout << "1-gestion du magasin  " << std::endl;
	std::cout << "2-gestion des clients " << std::endl;
	std::cout << "3-gestion des commandes " << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "entrez le numero de l'action que vous souhaitez realiser : ";
	int p;
	std::cin >> p;

	if (p == 1) {
		std::cout << "1-ajouter un produit " << std::endl;;
		std::cout << "2-affichages des produits "<<std::endl;
		std::cout << "3-Mise a jour quantite produits "<<std::endl;
		std::cout << "entrez le numero de l'action que vous souhaitez realiser : ";
		std::cout << "====================================" << std::endl;
		int x;
		std::cin >> x;

		if (x == 2) {
			easystock.produitRefenceMagasin();
		}
		else if (x == 1) {
			try {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "entrez le non du produit " << std::endl;
				std::string nom_produit;
				std::getline(std::cin, nom_produit);
				std::cout << "entrez la description du produit " << std::endl;
				std::string description;
				std::getline(std::cin, description);
				std::cout << "entrez le stock disponible  " << std::endl;;
				int stock;
				std::cin >> stock;
				std::cout << "entrez le prix unitaire  " << std::endl;
				double prix;
				std::cin >> prix;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//Produit nouveau_produit(nom_produit, description, stock, prix);
				//easystock.ajouterUnProduit(nouveau_produit);
				std::ofstream file;
				file.open("produit.csv", std::ios::app);
				if (file.is_open()) {
					file << nom_produit;
					file << ",";
					file << description;
					file << ",";
					file << stock;
					file << ",";
					file << prix << std::endl;
				}
				file.close();
				produits = {};
				chargement_fichier_produit("produit.csv", easystock);
				easystock.produitRefenceMagasin();


			}
			catch (const std::invalid_argument& e) {
				std::cerr << " erreur de creation du produit:" << e.what() << std::endl;
			}
		}
		else if (x==3){
			std::cout << "quelle produit souhaiter vous mettre la quantite a jour" << std::endl;
			std::string produit_a_mettre_a_jour;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, produit_a_mettre_a_jour);
			std::cout << " entrez la quantite " << std::endl;
			int quantite_a_mettre_a_jour;
			std::cin >> quantite_a_mettre_a_jour;
			easystock.miseAjourQuantite(produit_a_mettre_a_jour, quantite_a_mettre_a_jour);
			easystock.produitRefenceMagasin();



		}
	}
	else if (p == 2) {
		std::cout << "1-ajouter un client \n";
		std::cout << "2-afficher tout les clients \n";
		std::cout << "3-afficher commande client \n";
		std::cout << "4-afficher client specifique \n";
		std::cout << "entrez le numero de l'action que vous souhaitez realiser : ";
	}
	else if (p == 3) {
		std::cout << "1- afficher toute les commandes \n";
		std::cout << "2- afficher une commande \n";
		std::cout << "3 -valider une commande \n";
		std::cout << "4 -modifier une commande \n";
		std::cout << "entrez le numero de l'action que vous souhaitez realiser : ";
	}
	else {
		std::cout << "entrez une numero d'action valide ): \n";
		std::cout << "entrez a nouveau le numero de l'action que vous souhaitez realiser : ";
	}

	return 0;
}