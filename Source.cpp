#include <iostream>
#include <string>
#include <windows.h>
#include "Personne.h"

int ClassPersonnemain() {
    // Cr\202er une personne avec un num\202ro de s\202curit\202 sociale
    Personne personne("171121927207936");

    // Modifier l'adresse et le nombre d'enfants
    personne.setAdresse("123 Rue de la Test");
    personne.setNbe(1);

    // Afficher les informations de la personne
    std::cout << "Informations de la personne : \n";
    std::cout << personne.toString() << "\n";
    
    personne.getChargement();

    // V\202rifier la cl\202 du num\202ro de s\202curit\202 sociale
    if (personne.verifCleNumSecu()) {
        std::cout << "Cl\202 du num\202ro de s\202curit\202 sociale valide.\n";
    }
    else {
        std::cout << "Cl\202 du num\202ro de s\202curit\202 sociale invalide.\n";
    }

    // Ajouter un enfant et mettre à jour les informations
    personne.naissanceEnfant();
    //personne.evalAttributs();

    // Afficher les informations mises à jour
    std::cout << "\nInformations mises à jour de la personne : \n";
    std::cout << personne.toString() << "\n";

    return 0;
}


//#include "catch2/catch_test_macros.hpp"
//#include "catch2/benchmark/catch_benchmark.hpp"
//#include <cstdint>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int addition(int x, int y) {
    return x + y;
}

TEST_CASE("Addition of two numbers", "[addition]") {
    REQUIRE(addition(1, 7) == 8);
    REQUIRE(addition(2, 1) == 3);
    REQUIRE(addition(3, 9) == 12);
    REQUIRE(addition(10, 15) == 25);
}

TEST_CASE("Test de la classe Personne", "[Personne]") {


    SECTION("Test de la vérification de la clé du numéro de sécurité sociale valide") {
        Personne personne("171121927207936");
        REQUIRE(personne.verifCleNumSecu() == true);
    }

    SECTION("Test de la vérification de la clé du numéro de sécurité sociale invalide") {
        Personne personne("123456789012345");
        REQUIRE(personne.verifCleNumSecu() == false);
    }

    SECTION("Test de la modification de l'adresse") {
        Personne personne("171121927207936");
        personne.setAdresse("123 Rue de la Test");
        REQUIRE(personne.getAdresse() == "123 Rue de la Test");
    }

    SECTION("Test de la modification du nombre d'enfants") {
        Personne personne("171121927207936");
        personne.setNbe(2);
        REQUIRE(personne.getNbe() == 2);
    }

    SECTION("Test de l'ajout d'un enfant") {
        Personne personne("171121927207936");
        personne.naissanceEnfant();
        REQUIRE(personne.getNbe() == 1);
    }

    SECTION("Test de la conversion en chaîne de caractères") {
        Personne personne("171121927207936");
        std::string expected = "Ann\202e de naissance: 2023\nAge: 0\nNombre d'enfants: 0\nAdresse: \nNuméro de sécurité sociale: 171121927207936\nGenre: INCONNU";
        REQUIRE(personne.toString() == expected);
    }
}

TEST_CASE("Tests pour le constructeur de la classe Personne", "[Personne]") {

    SECTION("Test des exceptions pour le numéro de sécurité sociale invalide") {
        REQUIRE_THROWS_AS(Personne("12345"), const char*); // Numéro trop court
        REQUIRE_THROWS_AS(Personne("12345678901234567890"), const char*); // Numéro trop long
        REQUIRE_THROWS_WITH(Personne("12345"), "Taille du num\202ro de s\202cu incorrect");
    }

    SECTION("Test des exceptions pour la clé de sécurité sociale invalide") {
        // Supposons que "103061730041810" soit un numéro avec une clé invalide
        REQUIRE_THROWS_AS(Personne("103061730041810"), const char*);
        REQUIRE_THROWS_WITH(Personne("103061730041810"), "Cle s\202cu incorrect");
    }

    SECTION("Test de la création valide d'une personne") {
        // Supposons que "103061730041813" soit un numéro valide
        REQUIRE_NOTHROW(Personne("103061730041813"));
    }
}


int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}