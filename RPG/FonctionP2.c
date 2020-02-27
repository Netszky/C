#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Rpg.h"
#include"global.h"

void MenuSpawn()
{
    printf("                                             Ou voulez vous commencer ? \n\n");
    printf("1. QG Gilets Jaunes (BAR), (marchand) \n");
    printf("2. Champs Elysee \n");

}
int GestSpawn()
{
    int entry = Choice(1,2);
    switch(entry)
    {
        case 1:
        system("color E0");
        printf("Vous etes au QG, vous avez la possibilite de rendre visite a un marchand\n");
        printf("Ce dernier peut vous vendre des objets. \n");
        printf("Voulez vous rendre visite au marchand ? \n");
        printf("1. Oui\n");
        printf("2. Non\n");
        int entry = Choice(1,2);
        switch(entry)
        {
            case 1:
            Marchand();
            break;
            case 2:
            system("color 70");
            MenuActions();
            break;
        }
        case 2:
        system("color 70");
        printf("Vous etes a Paris en Manifestation \n ");
        break;
    }
}

int Actions0()
{
   int entry = Choice(1,5);
   switch(entry)
   {
   case 1:
       system("cls");
       if (entry2 == entry+1)
       {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
       }
       else
       {
        printf(" Vous avancez en direction du Nord...\n ");
        Sleep(1000);
        move++;
        entry2=1;
        Mouvements();
       }
    entry2 = 1;
    break;
   case 2:
    system("cls");
    if (entry2 == entry-1)
    {
        printf("Vous revenez sur vos pas...");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous vous deplacez vers le Sud...\n ");
        Sleep(1000);
        move++;
        entry2=2;
        Mouvements();
    }
    entry2 = 2;
    break;
   case 3:
    system("cls");
    if (entry2 == entry+1)
    {
        printf("Vous revenez sur vos pas...");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous deplacez vers l'Est...\n ");
        Sleep(1000);
        move++;
        entry2=3;
        Mouvements();
    }
    entry2 =3;
    break;
   case 4:
    system("cls");
    if (entry2 == entry-1)
    {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous allez a l'Ouest...\n ");
        Sleep(1000);
        move++;
        entry2=4;
        Mouvements();
    }
    entry2 = 4;
    break;
   case 5:
    system("cls");
    printf(" Vous cherchez dans votre Banane Lacoste...\n ");
    Sleep(1000);
    inventaire1();
    MenuActions();
    break;
   }
}
void MenuActions()
{
    printf("            Que souhaitez vous faire ?\n");
    printf("1. Nord \n");
    printf("2. Sud\n");
    printf("3. Est\n");
    printf("4. Ouest\n");
    printf("5. Inventaire \n");
    Actions0();
}
void Marchand()
{
    printf("Bonjour, Que souhaitez vous acheter ?\n");
    printf ("Vous disposez de %d PO \n", gold);
    printf("1. Potion de Soin  | 50 PO\n");
    printf("2. Potion de Force            | 75 PO \n");
    printf("3. Rien \n ");
    int entry = Choice(1,3);
    if (entry == 1 && gold >= 50)
    {
        gold -= 50;
        inventaire[0]++;
        printf("Vous avez %d Potion de soins \n", inventaire[0]);
        Marchand();
    }
    else if (entry == 1 && gold < 50)
    {
        printf("Vous n'avez pas assez d'argent \n");
        system("color 70");
        MenuActions();
    }
    if (entry == 2 && gold >= 75)
    {
        gold -= 75;
        inventaire[1]++;
        printf("Vous avez %d Potion de Force \n", inventaire[1]);
        Marchand();
    }
    else if (entry == 2 && gold < 75)
    {
        printf("Vous n'avez pas assez d'argent \n");
        system("color 70");
        MenuActions();
    }
    if (entry == 3)
    {
        system("color 70");
        MenuActions();
    }
    system("color 70");
    MenuActions();
}
void Mouvements()
{
    switch(move)
    {
    case 0:
        printf("Vous etes sur les champs Elysee");
        MenuActions();
        break;
    case 1:
        printf(" Vous arrivez devant l'arc de Triomphe\n\n ");
        MenuActions();
        break;
    case 2:
        printf(" Vous trebuchez sur un CRS !\n ");
        printf(" Vous perdez donc 10PV !\n");
        hp -= 10;
        MenuActions();
        break;
    case 3:
        printf(" Un Homme etrange, vous propose une enigme pour obtenir une recompense \n ");
        printf(" Un pere et un fils ont a eux deux 36 ans Sachant que le pere a 30 ans de plus que le fils, quel âge a le fils ? \n");
        printf(" 1. Utilisez la Force ! \n");
        printf(" 2. 3 ans ? \n");
        printf(" 3. 6 ans ? \n");
        printf(" 4. La reponse 4!\n");
        int entry = Choice(1,4);
        switch(entry)
        {
        case 1:
         system("cls");
         printf(" G A M E  O V E R ! ");
         Sleep(2000);
         Menu();
        case 2:
            system("cls");
            printf(" Felicitation vous n'etes pas si bete ! \n");
            printf(" Vous obtenez 100 d'XP !\n");
            printf(" Vous gagnez un niveau, HP +50 / Force + 5 \n");
            XP += 100;
            hp += 50;
            force += 5;
            MenuActions();
        case 3:
            printf(" Ce n'est pas la bonne reponse !");
            MenuActions();
        case 4:
            printf(" Bien essaye mais non !");
            MenuActions();
        }break;

    case 4:
        system("cls");
        printf(" Emmanuel Macron apparait \n");
        Combat();
        MenuActions();
        break;
    case 5:
        printf(" Vous trouvez un billet de 50 euros ");
        gold += 50;
        MenuActions();
        break;
    case 6:
        printf(" Vous croisez Rafael un vendeur a la sauvette ");
        Rafael(gold);
        MenuActions();
        break;
    case 7:
        printf(" Vous arrivez en Gestion de Projet \n");
        printf(" Le combat ultime se prepare !\n");
        Utilisation();
        break;
    case 8:

    Menu();
    break;
    }
}
void Rafael()
{
    printf("Keske ye pe faire pur vous ?\n");
    printf ("Vous disposez de %d PO \n", gold);
    printf("1. Potion de Soin  | 50 PO\n");
    printf("2. Potion de Force | 75 PO \n");
    printf("3. Rien            | 10 PO \n ");
    int entry = Choice(1,3);
    if (entry == 1 && gold >= 50)
    {
        gold -= 50;
        inventaire[0]++;
        printf("Vous avez %d Potion de soins \n", inventaire[0]);
        Marchand();
    }
    else if (entry == 1 && gold < 50)
    {
        printf("Vous n'avez pas assez d'argent \n");
        MenuActions();
    }
    if (entry == 2 && gold >= 75)
    {
        gold -= 75;
        inventaire[1]++;
        printf("Vous avez %d Potion de Force \n", inventaire[1]);
        Marchand();
    }
    else if (entry == 2 && gold < 75)
    {
        printf("Vous n'avez pas assez d'argent \n");
        MenuActions();
    }
    if (entry == 3)
    {
        gold -= 10;
        MenuActions();
    }
    MenuActions();
}
void inventaire1()
{
for(int i=0;i<6;i++);
printf("Potions de soin x %d \n",inventaire[0]);
printf("Potions de force x %d \n",inventaire[1]);
Utilisation();
}
int Combat()
{
    srand(time(NULL));
    int tour = rand()%2+1;
    switch(tour)
    {
    case 1:
    printf("L'ennemi commence en premier \n");
    break;
    case 2:
    printf("Vous commencez en premier \n");
    break;
    }
while (hp && hpIA > 0)
    {
        if (tour == 1)
        {
            AttaqueIA();
            AttaqueJ();
        }
        else
        {
            AttaqueJ();
            AttaqueIA();
        }

    }
if (hpIA <= 0)
    {
        Sleep(1000);
        system("cls");
        printf("Votre manifestation est un succes vous gagnez 100 d'experience et recuperez 200 euros");
        gold += 200;
        XP += 100;
        Experience();

    }
else if (hp <= 0)
    {
        Sleep(1000);
        system("cls");
        printf(" Macron vous T BAG ");
        system("cls");
        Menu();
    }
}

void AttaqueIA()
{
    srand(time(NULL));
    int ChoixIA = rand()%2+1;
    switch(ChoixIA)
    {
    case 1:
        printf(" Macron utilise impots  \n");
        if (gold <= 0)
        {
            printf(" Vous n'avez plus d'argent, L'Etat vous remercie \n");
            hp -= 15;
            printf("Il vous reste %d points de vie \n", hp);
        }
        else
        {
            gold-=30;
            printf(" Vous perdez de l'argent \n");
            printf(" Il vous reste %d euros \n", gold);
        }
    break;
    case 2:
        printf(" Macron utilise CRS \n");
        printf(" Tu te fais matraquer \n");
        hp -= 20;
        printf("Il vous reste %d point de vie \n", hp);
        break;
    }
}
void AttaqueJ()
{
    printf("Choisissez une attaque : \n");
    printf("1. Gilets Jaunes \n");
    printf("2. Lance de Pave des Champs Elysee \n");
    printf("3. Potions \n");
    int entry = Choice(1,3);
    switch(entry)
    {
    case 1:
        hpIA -= 2*force;
        printf ("Il reste a l'ennemi %d points de vie \n", hpIA);
        printf(" Votre force augmente \n");
        force += 5;
        break;
    case 2:
        srand(time(NULL));
    int chance = rand()%3+1;
    if (chance == 1 || chance == 3)
        {
            printf(" Vous lancez un pave sur l'ennemi \n");
            hpIA -= 3*force;
            printf(" Il le prend en pleine tete, il lui reste %d points de vie\n", hpIA);

        }
    else
        {
            printf(" Le pave vous echappe des mains et vous blesse \n");
            hp -= 10;
            printf(" Il vous reste %d points de vie \n", hp);
        }
        break;
    case 3:
        Utilisation();
        break;
    }
}
void Utilisation()
{
    printf("Voulez vous utiliser : \n");
    printf("1. x1 Potion de Vie (%d Potions de vie restantes)\n", inventaire[0]);
    printf("2. x1 Potion de Force(%d Potions de force restantes) \n", inventaire[1]);
    printf("3. Rien \n");
    int entry = Choice(1,3);
    if(entry == 1 && inventaire[0]>=1)
    {
        hp += 20;
        inventaire[0]--;
        printf("Vous venez d'utiliser une Potion de Vie \n");
        printf("Il vous en reste %d\n", inventaire[0]);
        printf("Vous avez %d Points de vie\n", hp);
        Utilisation();
    }
    else if(entry == 1 && inventaire[0]<1)
    {
        printf("Vous n'avez plus de potions \n");
        Utilisation();
    }
    if(entry == 2 && inventaire[1]>=1)
    {
        inventaire[1]--;
        force += 5;
        printf("Vous venez d'utiliser une Potion de Force \n");
        printf("Il vous en reste %d \n", inventaire[1]);
        printf(" Votre Force est de %d \n", force);
        Utilisation();
    }
    else if(entry ==2 && inventaire[1] < 1)
    {
        printf("Vous n'avez plus de potions\n");
        Utilisation();
    }
}
void inventaire2()
{
inventaire[0] = 1;
inventaire[1] = 1;
for(int i=0;i<6;i++);
printf("Potions de soin x %d \n",inventaire[0]);
printf("Potions de force x %d \n",inventaire[1]);
}
void Combat2()
{
    hpIA = 500;
    srand(time(NULL));
    int tour = rand()%2+1;
    switch(tour)
    {
    case 1:
    printf("L'ennemi commence \n");
    break;
    case 2:
    printf("Vous commencez \n");
    break;
    }
while (hp && hpIA > 0)
    {
        if (tour == 1)
        {
            AttaqueIA2();
            AttaqueJ2();
        }
        else
        {
            AttaqueJ2();
            AttaqueIA2();
        }

    }
if (hpIA <= 0)
    {
        system("cls");
        printf("Felicitations vous avez termine le jeu");
         printf("\n Ce jeu vous est presente par Bruno et Julien \n");
    }
else if (hp <= 0)
    {
        printf(" Vous etes mort d'ennui... ");
        system("cls");
        Menu();
    }
}
void AttaqueIA2()
{
    srand(time(NULL));
    int ChoixIA = rand()%3+1;
    switch(ChoixIA)
    {
    case 1:
        printf(" Gestion de Projet utilise baisse de note globale \n");
        printf("Vous perdez de la sante mentale et commencez a deprimer...");
        printf(" Il vous reste %d de Sante mentale \n", santeMentale );
        if (santeMentale <= 0)
        {
            printf(" Vous devenez fou et vous frappez votre tete contre la table \n");
            hp -= 30;
            printf("Il vous reste %d points de vie \n", hp);
        }
    break;
    case 2:
        printf(" Gestion de projet utilise : Cours Magistral \n");
        printf(" Tout le monde s'en fiche \n");
        hp -= 20;
        printf("Il vous reste %d point de vie \n", hp);
        break;
    case 3:
        printf(" Gestion de projet utilise : Capture de Telephone \n");
        printf(" Vous perdez la moitie de votre sante mentale \n");
        santeMentale/=2;
        hp -= 25;
        printf(" Il vous reste %d de Sante mentale \n", santeMentale );
        printf("Il vous reste %d points de vie \n", hp);
        break;
    }
}
void AttaqueJ2()
{
    printf("1. Absence \n");
    printf("2. Partir a la pause  \n");
    printf("3. Potions \n");
    int entry = Choice(1,3);
    switch(entry)
    {
    case 1:
        hpIA -= 2*force;
        printf ("Il reste a l'ennemi %d points de vie \n", hpIA);
        printf(" Votre force augmente \n");
        force += 5;
        break;
    case 2:
        srand(time(NULL));
    int chance = rand()%3+1;
    if (chance == 1 || chance == 3)
        {
            printf(" Vous partez a la pause \n");
            hpIA -= 3*force;
            printf(" Cela fonctionne, il reste %d points de vie\n", hpIA);

        }
    else
        {
            printf(" Vous vous faites attraper \n");
            hp -= 10;
            printf(" Il vous reste %d points de vie \n", hp);
        }
        break;
    case 3:
        Utilisation();
        break;
    }
}
void Experience()
{
    if (XP > 100)
    {
        printf("Vous venez de gagner un niveau \n");
        printf("Vos caracteristiques augmentes : \n");
        printf("Vos points de vie augmentent de 50 \n");
        printf("Votre force augmente de 5 \n");
        hp += 50;
        force += 5;
    }
    else
    {
        printf("Vous n'avez pas assez d'exprience pour passer de niveau");
    }
}
