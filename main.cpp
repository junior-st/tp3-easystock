#include <iostream>










int main() {
//creation de 10 produits
	
	std::cout<<"====================================" << std::endl;
	std::cout << "       Menu gestion de magasin      " << std::endl;
	std::cout << "1-gestion du magasin  " << std::endl;
	std::cout << "2-gestion des clients " << std::endl;
	std::cout << "3-gestion des commandes " << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "entrez le numero de l'action que vous souhaitez realiser : " << std::endl;
	int p;
	std::cin >> p;
	if (p == 1) {
		std::cout << "1-ajouter un produit \n";
		std::cout << "2-affichages des produits \n";
		std::cout << "3-Mise a jour quantite produits \n";
	}
	else if (p == 2) {
		std::cout << "1-ajouter un client \n";
		std::cout << "2-afficher tout les clients \n";
		std::cout << "3-afficher commande client \n";
		std::cout << "4-afficher client specifique \n";
	}
	else if (p == 3) {
		std::cout << "1- afficher toute les commandes \n";
		std::cout << "2- afficher une commande \n";
		std::cout << "3 -valider une commande \n";
		std::cout << "4 -modifier une commande \n";
	}
	else {
		std::cout << "entrez une numero d'action valide ): \n";
	}

	return 0;
}