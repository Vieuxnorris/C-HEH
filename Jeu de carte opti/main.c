do
    {
        choix = menu_game(manche);

        switch(choix)
        {
            if(manche == 0)
                {
                case 1:
                    system("cls");
                    printf("joueur %d dit : 'Dame de coeur ! A vous l'honneur ! Dame de pique, a vous la suite !' \n\n\n",joueur_actu);
                    manche++;
                    break;
                }
        case 2:
            system("cls");
            affichage(deck,deck_couleur,joueur,joueur_actu);
            break;
        case 3:
            system("cls");
            regle();
            break;
        case 4:
            system("cls");
            echange(deck,deck_couleur,joueur,joueur_actu);
            joueur_actu++;
            if(joueur_actu > joueur-1)
            {
                joueur_actu=0;
            }
            break;
        case 5:
            system("cls");
            temp = kilo(deck,deck_couleur,joueur,joueur_actu);
            printf("voici votre score : %d \n\n", temp);
            break;
        case 6:
            system("cls");
            joueur_actu++;
            break;
        case 7:
            system("cls");
            return 0;
            break;
        }
    }while(choix != 7);
