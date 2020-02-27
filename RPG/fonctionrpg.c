#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Rpg.h"

int Choice(int min, int max)
{
    int entry = -1000;
  while(entry>max||entry<min)
  {
      printf("Entrez un chiffre entre %d et %d \n", min,max);
      scanf("%d", &entry);
  }
    return entry;
}
void Synopsis()
{
    system("cls");
    printf("                                                          Synopsis\n");
    printf("Vous etes un Gilet Jaune mecontent de la politique du gouvernement et vous decidez de vous rendre a Paris pour manifester.\n");
    printf("Vous commencez votre manifestation avec 100PV, 200PO, 15 de Force \n");
    inventaire2();
}
void Menu()
{
     system("color 0E");
    printf("                                        __                                           __ \n");
    printf("                                       (**)                                         (**) \n");
    printf("                                       IIII                                         IIII \n");
    printf("                                       ####              Gilets Jaunes              #### \n");
    printf("                                       HHHH                SIMULATOR                HHHH \n");
    printf("                                       HHHH                  2018                   HHHH \n");
    printf("                                       ####                                         #### \n");
    printf("                                    ___IIII___                                   ___IIII___ \n");
    printf("                                   .-`_._"  "_._`-.                                 .-`_._"  "_._`-. \n");
    printf("                                |/``  .`\\/`.  ``\\| 1 - Nouvelle Manifestation|/``  .`\\/`.  ``\\| \n");
    printf("                                      }    {       2 - Charger une Manifestation   }    { \n");
    printf("                                      ) () (         3 - Informations              ) () ( \n");
    printf("                                      ( :: )         4 - Quitter                   ( :: ) \n");
    printf("                                      | :: |                                       | :: | \n");
    printf("                                      | )( |                                       | )( | \n");
    printf("                                      | || |                                       | || | \n");
    printf("                                      | || |                                       | || | \n");
    printf("                                      | || |                                       | || | \n");
    printf("                                      | || |                                       | || | \n");
    printf("                                      | || |                                       | || | \n");
    printf("                                      ( () )                                       ( () ) \n");
    printf("                                       \\  /                                         \\  /  \n");
    printf("                                        \\/                                           \\/   \n");
    GestionMenu();
}

int GestionMenu()
{
    int entry = Choice(1,4);
    char prenom[100];
    switch(entry)
    {
        case 1:
        system("color 0E");
        printf("Entrez votre Nom \n");
        scanf("%s", prenom);
        printf("Bonjour %s ! \nBonne chance dans ta manifestation!\n ", prenom);
        Sleep(2000);
        Synopsis();
        Sleep(2000);
        system("cls");
        MenuSpawn();
        break;

        case 2:
        system("cls");
        system("color 0C");
        break;

        case 3:
        system("cls");
        system("color 0E");
        printf("\n Ce jeu vous est presente par Bruno et Julien \n");
        printf("\n Il s'agit d'un RPG textuel inspire de la Manifestation a succes GILETS JAUNES\n");
        Sleep(2000);
        system("cls");
        Menu();
        break;

        case 4:
        Quitter();
        break;
    }
}
void Quitter()
{
    system("cls");
    system("color 0E");
    for(int i=0;i<100;i++)
        {
                printf(" A bientot \n");
        }
}
