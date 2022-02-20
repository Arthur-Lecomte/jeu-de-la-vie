#include "structCellule.h"
#include "affichageMatrice.h"
#include "voisin.h"
#include "regle.h"
#include "remplirMatrice.h"
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

// fonction qui fait tourner un automate cellulaire avec des regles basiques
void jeuBasique(vector<vector<cellule>> & mat){
    while (true){
        afficherMatrice(mat);
        trouverVoisin(mat);
        regleBasique(mat);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Fonction permettant une interface de choix de regle et d'automate
void automate (vector<vector<cellule>> & mat){
    // etape de choix de taille de matrice
    cout << "Obligatoire : mettre le terminale en pleine écran" << endl << endl;
    cout << "Choisir une taille entre 50 et 100" << endl;
    unsigned choixTaille = 0;
    cin >> choixTaille;
    while (true){
        if (choixTaille <= 100 && choixTaille >= 50)
            break;
        else{
            cout << "Mauvais choix, veuillez remettre une taille appropriée" << endl;
            cin >> choixTaille;
        }
    }
    //etape de choix de regle
    unsigned choixRegle = 0;
    cout << endl << "Choisir parmis les règles suivante :" << endl;
    cout << "1 : Regle basique" << endl;
    cout << "2 : Regle du labyrinthe" << endl;
    cout << "3 : Regle de l'expension lente" << endl;
    cin >> choixRegle;
    while (true){
        if (choixRegle == 1 || choixRegle == 2 || choixRegle == 3)
            break;
        else{
            cout << "Mauvais choix, veuillez remettre une regle appropriée" << endl;
            cin >> choixRegle;
        }
    }
    if (choixRegle == 1){
        //etape de choix de l'automate pour des regles basiques
        unsigned choixAutomate = 0;
        cout << "Choisir parmis une des dispositions de matrice suivantes :" << endl;
        cout << "1 : Matrice aléatoire" << endl << "2 : Matrice floraison première configuration" << endl << "3 : Matrice floraison deuxième configuration" << endl << "4 : Matrice canon"<< endl;
        cin >> choixAutomate;
        while (true){
            if (choixAutomate == 1 || choixAutomate == 2 || choixAutomate == 3 || choixAutomate == 4)
                break;
            else{
                cout << "Mauvais choix, veuillez remettre une disposition approprié" << endl;
                cin >> choixAutomate;
            }
        }
        if (choixAutomate == 1){
            unsigned pourcentageAlea = 0;
            cout << "Choisir un nombre entre 0 et 99 correspondant au pourcentage de remplissage de l'automate :" << endl;
            cin >> pourcentageAlea;
            while (true){
                if (pourcentageAlea >= 0 && pourcentageAlea<=99)
                    break;
                else{
                    cout << "Mauvaise saisie, veuillez remettre un pourcentage :";
                    cin >> pourcentageAlea;
                }
            }
            mat=creerMat(mat,choixTaille);
            mat=remplirMatriceAlea(mat,pourcentageAlea);
            jeuBasique(mat);
        }
        else if (choixAutomate == 2){
            mat=creerMat(mat,choixTaille);
            mat=remplirMatriceFloraison(mat);
            jeuBasique(mat);
        }
        else if (choixAutomate == 3){
            mat=creerMat(mat,choixTaille);
            mat=remplirMatriceFloraison2(mat);
            jeuBasique(mat);
        }
        else{
            mat=creerMat(mat,choixTaille);
            mat=remplirMatriceCanon(mat);
            jeuBasique(mat);
        }
    }
    if (choixRegle == 2 || choixRegle == 3){
        //etape de choix du pourcentage de remplissage du centre pour les regles de conway et pour l'expension lente
        unsigned pourcentageAlea = 0;
        cout << "Pour les règle 2 et 3, la seul disposition interessante est de faire un centre purement aléatoire, veuillez donc choisir un pourcentage de remplissage du centre de la matrice entre 0 et 99" << endl;
        cin >> pourcentageAlea;
        while (true){
            if (pourcentageAlea >= 0 && pourcentageAlea <= 99)
                break;
            else{
                cout << "Mauvaise saisie, veuillez remettre un pourcentage :";
                cin >> pourcentageAlea;
            }
        }
        choixTaille=changeTailleMat5(choixTaille);
        mat=creerMat(mat,choixTaille);
        remplirMatriceAleaCentre(mat,pourcentageAlea,choixTaille);
        if (choixRegle == 2) // automate de conway
            while (true) {
                afficherMatrice(mat);
                trouverVoisin(mat);
                regleConway(mat);
                this_thread::sleep_for(chrono::milliseconds(200));
            }
        else   // automate de l'expension lente
            while (true) {
                afficherMatrice(mat);
                trouverVoisin(mat);
                regleExpensionLente(mat);
                this_thread::sleep_for(chrono::milliseconds(200));
            }
    }
}
