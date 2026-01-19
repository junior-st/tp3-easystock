#pragma once
#include <string>
#include <vector>
#include "produit.h"
#include <fstream>
#include<sstream>
#include "client.h"
#include "magasin.h"
void chargement_fichier_client(std::string nom_fichier,
    Magasin& easy);
void chargement_fichier_produit(std::string nom_fichier, Magasin& easy);
