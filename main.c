int main()
{
    struct voyage T[1000];
    int n = 1000;
    int nb = 3;
    T[0].id = 1;
    T[0].npt = 100;
    T[0].npd = 10;
    T[0].prix = 400;
    strcpy(T[0].description, "the trip isn't an organized one.");
    strcpy(T[0].depart, "tunis");
    strcpy(T[0].destination, "algerie");
    T[0].ddd.j = 10;
    T[0].ddd.m = 02;
    T[0].ddd.a = 2023;
    T[0].ddr.j = 12;
    T[0].ddr.m = 03;
    T[0].ddr.a = 2023;
    T[1].id = 2;
    T[1].npt = 255;
    T[1].npd = 15;
    T[1].prix = 1200;
    strcpy(T[1].description, "price includes transport and stay");
    strcpy(T[1].depart, "tunis");
    strcpy(T[1].destination, "marroc");
    T[1].ddd.j = 14;
    T[1].ddd.m = 03;
    T[1].ddd.a = 2024;
    T[1].ddr.j = 15;
    T[1].ddr.m = 04;
    T[1].ddr.a = 2024;
    T[2].id = 3;
    T[2].npt = 233;
    T[2].npd = 4;
    T[2].prix = 2600;
    strcpy(T[2].description, "price includes transport and stay");
    strcpy(T[2].depart, "tunis");
    strcpy(T[2].destination, "coree du sud");
    T[2].ddd.j = 15;
    T[2].ddd.m = 06;
    T[2].ddd.a = 2025;
    T[2].ddr.j = 30;
    T[2].ddr.m = 06;
    T[2].ddr.a = 2025;

    // dashboard
    int test = 1;
    while (test)
    {
        printf("\t============MSS . TRIP============");
        printf("\n\n1.Add a trip.");
        printf("\n2.Display the trip's description.");
        printf("\n3.Delete a trip.");
        printf("\n4.Edit a trip.");
        printf("\n5.Look for a trip based on a precised date.");
        printf("\n6.Exit.");
        printf("\n\nPlease select your prefered operation: ");
        int opt;
        scanf("%d", &opt);
        printf("You have chosen %d ", opt);
        printf("\n\n");
        switch (opt)
        {
        case 1:
            system("cls");
            ajouter(T, nb);
            nb++;
            break;
        case 2:
            system("cls");
            affichage(T, n);
            break;
        case 3:
            system("cls");
            supprimer(T, n, nb);
            break;
        case 4:
            system("cls");
            printf("\tWhat are you willing to modify?:\n ");
            printf("\n\n1.Total number of places.");
            printf("\n2.Number of available places.");
            printf("\n3.Price.");
            printf("\n4.Description.");
            printf("\n5.Destination.");
            printf("\n6.Country of Departure.");
            printf("\n7.Date of departure.");
            printf("\n8.Date of return.");
            int b;
            printf("\n\nPlease select your prefered operation: ");
            scanf("%i", &b);
            printf("\nYou have chosen %i: ", b);
            int nid;
            printf("\nenter the id that you are willing to modify its value: ");
            scanf("%i", &nid);
            if (b == 4 || b == 5 || b == 6 || b == 7 || b == 8)
            {

                system("cls");
                update(T, n, b, nid);
                printf("updated successfully!");
            }
            else if (b == 1 || b == 2 || b == 3)
            {
                long p;
                system("cls");
                printf("enter the new value: ");
                scanf("%d", &p);
                update1(T, n, b, p, nid);
                printf("updated successfully!\n");
            }
            break;
        case 5:
            system("cls");
            struct date date1;
            struct date date2;
            printf("enter the 1st dates's day: \n");
            scanf("%i", &date1.j);
            printf("enter the 1st dates's month: \n");
            scanf("%i", &date1.m);
            printf("enter the 1st dates's year: \n");
            scanf("%i", &date1.a);
            printf("enter the 2nd dates's day: \n");
            scanf("%i", &date2.j);
            printf("enter the 2nd dates's month: \n");
            scanf("%i", &date2.m);
            printf("enter the 2nd dates's year: \n");
            scanf("%i", &date2.a);
            system("cls");
            Recherche(T, n, date1, date2);
            break;

        case 6:
            printf("\n\n\t Bye Bye :)\n\n");
            exit(1);
            break;
        default:
            printf("wrong choice!\n");
            break;
        }
        printf("do you want to perform any other operation?[y/n]: ");
        char oth;
        scanf("%s", &oth);
        if (oth == 'y')
        {
            test = 1;
        }
        else
        {
            test = 0;
        }
        system("cls");
        FILE *ftpr;
        // ftpr = fopen("C:\\Users\\mimou\\OneDrive\\Bureau\\work work work\\c\\c project.txt", "w");
        int i;
        fprintf(ftpr, "%-50s", "id");
        fprintf(ftpr, "%-50s", "total number of places");
        fprintf(ftpr, "%-50s", "available places");
        fprintf(ftpr, "%-50s", "price");
        fprintf(ftpr, "%-50s", "description");
        fprintf(ftpr, "%-50s", "departure");
        fprintf(ftpr, "%-50s", "destination");
        fprintf(ftpr, "%-50s", "date of departure");
        fprintf(ftpr, "%-50s", "date of return");
        fprintf(ftpr, "\n");
        for (i = 0; i < nb; i++)
        {
            fprintf(ftpr, "%-50i", T[i].id);
            fprintf(ftpr, "%-50i", T[i].npt);
            fprintf(ftpr, "%-50i", T[i].npd);
            fprintf(ftpr, "%-50i", T[i].prix);
            fprintf(ftpr, "%-50s", T[i].description);
            fprintf(ftpr, "%-50s", T[i].depart);
            fprintf(ftpr, "%-50s", T[i].destination);
            fprintf(ftpr, "%i/%i/%-50i", T[i].ddd.j, T[i].ddd.m, T[i].ddd.a);
            fprintf(ftpr, "%i/%i/%i", T[i].ddr.j, T[i].ddr.m, T[i].ddr.a);
            fprintf(ftpr, "\n");
        }
        fclose(ftpr);
    }
    return 0;
}