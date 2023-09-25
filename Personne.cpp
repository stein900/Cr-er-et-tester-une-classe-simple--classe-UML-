// Personne.cpp

#include "Personne.h"
#include <sstream>
#include <iostream>
#include <windows.h>

Personne::Personne() : adn(0), age(0), nbe(0), adresse(""), numSecu(""), genre(Genre::INCONNU) {}

Personne::Personne(std::string numSecu) : Personne() {
    this->numSecu = numSecu;

    if (numSecu.length() != 15)
        throw("Taille du num\202ro de s\202curit\202 incorrecte");

    if (!verifCleNumSecu())
        throw("Cl\202 de s\202curit\202 incorrecte");

    evalAttributs();
}

std::string Personne::getAdresse() {
    return adresse;
}

void Personne::setAdresse(std::string adresse) {
    this->adresse = adresse;
}

int Personne::getNbe() {
    return nbe;
}

void Personne::setNbe(int nbe) {
    this->nbe = nbe;
}

void Personne::evalAttributs() {

    if (numSecu.length() != 15) {
        return;
    }

    char genderChar = numSecu.at(0);
    if (genderChar == '1') {
        genre = Genre::HOMME;
    }
    else if (genderChar == '2') {
        genre = Genre::FEMME;
    }
    else {
        genre = Genre::INCONNU;
    }

    adn = stoi(numSecu.substr(1, 2));
    if (adn <= 24) {
        adn += 2000;
    }
    else {
        adn += 1900;
    }

    age = 2023 - adn;
}


bool Personne::verifCleNumSecu()
{
    std::string numSecuSansCle = this->numSecu.substr(0, 13);
    int cleCalc = 0;

    for (int i = 0; i < numSecuSansCle.length(); i++)
        cleCalc = (cleCalc * 10 + (int)numSecuSansCle[i] - '0') % 97;
    cleCalc = 97 - cleCalc;

    int cle = stoi(this->numSecu.substr(13, 2));

    return (cleCalc == cle);
}

void Personne::naissanceEnfant() {
    nbe++;
}

std::string Personne::toString() {
    std::ostringstream oss;
    oss << "Ann\202e de naissance: " << adn << "\n"
        << "Age: " << age << "\n"
        << "Nombre d'enfants: " << nbe << "\n"
        << "Adresse: " << adresse << "\n"
        << "Num\202ro de s\202curit\202 sociale: " << numSecu << "\n"
        << "Genre: ";
    switch (genre) {
    case Genre::HOMME: oss << "HOMME"; break;
    case Genre::FEMME: oss << "FEMME"; break;
    default: oss << "INCONNU"; break;
    }
    return oss.str();
}

int Personne::getChargement()
{
    int fr = 2;
    int varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "Chargement en cours... " << varh << " %" << std::endl;
        varh += 1;
        Sleep(5);
        system("cls");
    }
    varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "connexion a la base de donn\202es... " << varh << " %" << std::endl;
        varh += fr;
        Sleep(5);
        system("cls");
        if (varh >= 100) return 0;
    }
    varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "identification... " << varh << " %" << std::endl;
        varh += fr;
        Sleep(5);
        system("cls");
        if (varh >= 100) return 0;
    }
    varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "R\202cup\202ration de vos donn\202es... " << varh << " %" << std::endl;
        varh += fr;
        Sleep(5);
        system("cls");
        if (varh >= 100) return 0;
    }
    varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "Test de s\202curit\202..." << varh << " %" << std::endl;
        varh += fr;
        Sleep(5);
        system("cls");
        if (varh >= 100) return 0;
    }
    varh = 0;
    for (int i = 0; i < 99; i++)
    {
        std::cout << "Finalisation..." << varh << " %" << std::endl;
        varh += fr;
        Sleep(5);
        system("cls");
        if (varh >= 100) return 0;
    }

}
