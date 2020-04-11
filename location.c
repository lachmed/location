/*------------------- Code source du mini projet de location de voitures -------------------*/
/*------------------- Programmé par l'étudiant : Mohamed LACHGAR -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "./structminiprojet.h"

void menuPrincipal(void);
void menuLocation(void);
void menuVoitures(void);
void menuClients(void);

void afflistevoiture(void);
void ajoutervoiture(void);
void modifiervoiture(void);
void supprimervoiture(void);

void afflisteclient(void);
void ajouterclient(void);
void modifierclient(void);
void supprimerclient(void);

void visualisercontrat(void);
void louervoiture(void);
void retournervoiture(void);
void modifiercontrat(void);
void supprimercontrat(float);

void netstdin(void);
int verifierid(int,int);
int verfnum(float);
int debut_inf_fin(date,date);
int nbrdejour(date,date);
void sleepv2(int);
int main()
{
 //Pour créer les fichiers s'il n'existait pas
   FILE *fpv,*fpc,*fpco;
       fpv=fopen("./voitures.txt","a+");
           if(fpv==NULL)
              {
                printf("\n Erreure d'ouverture !");
                sleepv2(3);
                exit(1);          
                }
       fclose(fpv);
       fpc=fopen("./clients.txt","a+");
           if(fpc==NULL)
              {
                printf("\n Erreure d'ouverture !");
                sleepv2(3);
                exit(1);         
                }
       fclose(fpc);
       fpco=fopen("./contrats.txt","a+");
           if(fpco==NULL)
              {
                printf("\n Erreure d'ouverture !");
                sleepv2(3);
                exit(1); 
                }
       fclose(fpco);
    while(1) menuPrincipal();

    return 0;
}
void menuPrincipal(void)
{
  system("cls");
  int choix;
  printf("\n\t\t      -------MENU PRINCIPAL-------   \n");
  printf("\n\t\t   Choisir parmi les menu suivants :   \n");
  printf("\n\t\t       Location d'une voiture--->1");
  printf("\n\t\t       Gestion de voitures------->2");
  printf("\n\t\t       Gestion de clients--------->3");
  printf("\n\t\t       Quitter--------------------------->4");
  printf("\n\n\t\t\t      votre choix : ");
  scanf("%d",&choix);
  switch(choix)
  {
    case 1:
      menuLocation();
    break;
    case 2:
      menuVoitures();
      break;
    case 3:
       menuClients();
       break;
    case 4:
      exit(0);
    break;
    default:
    printf("\nChoix invalide !");
    return;
  }
}

void menuVoitures(void)
{  system("cls");
  int choix;
  printf("\n\t\t      -------GESTION DES VOITURES-------\n");
  printf("\n\t\t   Choisir parmi les tâches suivantes : \n");
  printf("\n\t\t     Afficher la liste------------------------->1");
  printf("\n\t\t     Ajouter voiture-------------------------->2");
  printf("\n\t\t     Modifier voiture------------------------>3");
  printf("\n\t\t     Supprimer voiture-------------------->4");
  printf("\n\t\t     Retour au menu principal--------->0");
printf("\n\n\t\t            votre choix : ");
  scanf("%d",&choix);
  switch(choix)
  {
    case 1:
      afflistevoiture();
      break;
    case 2:
      ajoutervoiture();
      break;
    case 3:
       modifiervoiture();
       break;
    case 4:
       supprimervoiture();
       break;
    case 0:
      menuPrincipal();
    break;
    default:
    printf("\nChoix invalide");
    return;
  }
}
void menuClients(void)
{   system("cls");
  int choix;
  printf("\n\t\t      -------GESTION DES CLIENTS-------\n");
  printf("\n\t\t   Choisir parmi les tâches suivantes : \n");
  printf("\n\t\t     Afficher la liste-------------------------->1");
  printf("\n\t\t     Ajouter client----------------------------->2");
  printf("\n\t\t     Modifier client--------------------------->3");
  printf("\n\t\t     Supprimer client------------------------>4");
  printf("\n\t\t     Retour au menu principal---------->0");
printf("\n\n\t\t              votre choix : ");
  scanf("%d",&choix);
  switch(choix)
  {
    case 1:
      afflisteclient();
      break;
    case 2:
      ajouterclient();
      break;
    case 3:
      modifierclient();
       break;
    case 4:
       supprimerclient();
       break;
    case 0:
      menuPrincipal();
    break;
    default:
    printf("\nChoix invalide");
    return;
  }
}
void menuLocation(void)
{   system("cls");
  int choix;
  float num;
  printf("\n\t\t      -------MENU LOCATION-------\n");
  printf("\n\t\t     Choisir parmi les tâches suivantes : \n");
  printf("\n\t\t     Visualiser contrat----------------------------------------->1");
  printf("\n\t\t     Louer une voiture----------------------------------------->2");
  printf("\n\t\t     Retourner une voiture et supprimer contrat-->3");
  printf("\n\t\t     Modifier contrat-------------------------------------------->4");
  printf("\n\t\t     Retour au menu principal----------------------------->0");
printf("\n\n\t\t             votre choix : ");
  scanf("%d",&choix);
  switch(choix)
  {
    case 1:
      visualisercontrat();
      break;
    case 2:
      louervoiture();
      break;
    case 3:
      retournervoiture();
       break;
    case 4:
       modifiercontrat();
       break;
    case 0:
      menuPrincipal();
    break;
    default:
    printf("\nChoix invalide");
    return;
  }
}
void afflistevoiture(void)
{
   FILE *fpv;
   char ch;
   int flag=1,choix;
    fpv=fopen("./voitures.txt","r");
     if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
   printf("\n Les informations sur les voitures sont organisées sous la forme :\n Id Marque Nom Couleur Nombre-de-Places Prix-par-jour En-location \n\n\n");
     while(!feof(fpv))
         {
          fscanf(fpv,"%c",&ch);
          putchar(ch);
        }
      while(flag)
        {
     printf("\n\n\n Appuyer sur 0 pour revenir au menu principal \n\n\n Appuyer sur 1 pour revenir au menu de gestion de voitures \n\n\n\t votre choix : ");
     scanf("%d",&choix);
        if(choix==0)
         {
           flag=0;
           fclose(fpv);
           menuPrincipal();
         }else
           if(choix==1)
         {
           flag=0;
           fclose(fpv);
           menuVoitures();
         }
         else
          printf("\nChoix invalide \n");
      }
}
void ajoutervoiture(void)
{

  FILE *fpv;
  voiture *tmp=(voiture*)malloc(sizeof(voiture));

  printf("\n\n\nDonner les informations de la voiture : \n");


    printf("\nIdentificateur : ");
    scanf("%d",&tmp->idVoiture);
    netstdin();
    while(verifierid(1,tmp->idVoiture))
    {
    printf("\n Identificateur déjà  utilisé, choisir un autre : ");
    scanf("%d",&tmp->idVoiture);
    netstdin();
    }
    printf("\nMarque : ");
    scanf("%14s",tmp->marque);
    netstdin();
    printf("\nNom : ");
    scanf("%14s",tmp->nomVoiture);
    netstdin();
    printf("\nCouleur : ");
    scanf("%6s",tmp->couleur);
    netstdin();
    printf("\nNombre de places : ");
    scanf("%d",&tmp->nbplaces);
    netstdin();
    printf("\nPrix par jour : ");
    scanf("%d",&tmp->prixJour);
    netstdin();
    strcpy(tmp->enLocation,"Non");

     fpv=fopen("./voitures.txt","a");
       if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
     fprintf(fpv,"%d %14s %14s %6s %d %d %3s\n",tmp->idVoiture,tmp->marque,tmp->nomVoiture,tmp->couleur,tmp->nbplaces,tmp->prixJour,tmp->enLocation);
     fclose(fpv);
  free(tmp);
  menuVoitures();
   }
void modifiervoiture(void)
{
   FILE *fpv;
   int cpt=0,i,id,choix,finished=0;
   voiture tmp,*tab=(voiture*)malloc(cpt*sizeof(voiture));

   fpv=fopen("./voitures.txt","r");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
     while(!feof(fpv))
      {
        cpt++;
        tab=(voiture*)realloc(tab,cpt*sizeof(voiture));
        fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tab[cpt-1].idVoiture,tab[cpt-1].marque,tab[cpt-1].nomVoiture,tab[cpt-1].couleur,&tab[cpt-1].nbplaces,&tab[cpt-1].prixJour,tab[cpt-1].enLocation);
    }
    cpt--;
   fclose(fpv);

   printf("\n\n Donner l'id du voiture à  modifier : ");
   scanf("%d",&id);
   for(i=0;i<cpt;i++)
     if(id==tab[i].idVoiture)
       {
        do
   {
   printf("\n\nChoisir l'information à  modifier :\n");
   printf("\nLa marque----------------->1");
   printf("\nLe nom---------------------->2");
   printf("\nLa couleur----------------->3");
   printf("\nLe nombre de places>4");
   printf("\nLe prix par jour--------->5");
   printf("\nTerminé------------------->6");
   printf("\n\t votre choix : ");
   scanf("%d",&choix);

   switch(choix)
     {
        case 1:
        printf("\nDonner la nouvelle marque : ");
        scanf("%14s",tab[i].marque);
        netstdin();
        break;
        case 2:
        printf("\nDonner le nouveau nom : ");
        scanf("%14s",tab[i].nomVoiture);
        netstdin();
        break;
        case 3:
        printf("\nDonner la nouvelle couleur : ");
        scanf("%6s",tab[i].couleur);
        netstdin();
        break;
        case 4:
        printf("\nDonner le nouveau nombre de places : ");
        scanf("%d",&tab[i].nbplaces);
        netstdin();
        break;
        case 5:
        printf("\nDonner le nouveau prix par jour : ");
        scanf("%d",&tab[i].prixJour);
        netstdin();
        break;
        case 6:
        finished=1;
        break;
        default:
        printf("\nChoix invalid");
        break;
     }
   }while(!finished);
       break;
    }
      fpv=fopen("./voitures.txt","w");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpv,"%d %14s %14s %6s %d %d %3s\n",tab[i].idVoiture,tab[i].marque,tab[i].nomVoiture,tab[i].couleur,tab[i].nbplaces,tab[i].prixJour,tab[i].enLocation);
    fclose(fpv);
free(tab);
menuVoitures();
}
void supprimervoiture(void)
{

  FILE *fpv;
  int cpt=0,i,id;
  voiture *tab=(voiture*)malloc(cpt*sizeof(voiture));

  fpv=fopen("./voitures.txt","r");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
      fflush(stdin);
      printf("\nDonner l'id du voiture à  supprimer : ");
      scanf("%d",&id);
     while(!feof(fpv))
      {
        cpt++;
        tab=(voiture*)realloc(tab,cpt*sizeof(voiture));
        fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tab[cpt-1].idVoiture,tab[cpt-1].marque,tab[cpt-1].nomVoiture,tab[cpt-1].couleur,&tab[cpt-1].nbplaces,&tab[cpt-1].prixJour,tab[cpt-1].enLocation);
        if(tab[cpt-1].idVoiture==id)
            cpt--;
    }
   fclose(fpv);
     fpv=fopen("./voitures.txt","w");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpv,"%d %14s %14s %6s %d %d %3s\n",tab[i].idVoiture,tab[i].marque,tab[i].nomVoiture,tab[i].couleur,tab[i].nbplaces,tab[i].prixJour,tab[i].enLocation);
     fclose(fpv);
free(tab);
menuVoitures();
}
void afflisteclient(void)
{

   FILE *fpc;
   char ch;
   int flag=1,choix;
    fpc=fopen("./clients.txt","r");
     if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
   printf("\n Les informations sur les clients sont organisées sous la forme :\n Id Nom Prénom CIN Adresse Téléphone \n\n\n");
     while(!feof(fpc))
         {
          fscanf(fpc,"%c",&ch);
          putchar(ch);
        }
      while(flag)
        {
     printf("\n\n\n Appuyer sur 0 pour revenir au menu principal \n\n\n Appuyer sur 1 pour revenir au menu de gestion des clients \n\n\n\t votre choix : ");
     scanf("%d",&choix);
        if(choix==0)
         {
           flag=0;
           fclose(fpc);
           menuPrincipal();
         }else
           if(choix==1)
         {
           flag=0;
           fclose(fpc);
           menuClients();
         }
         else
          printf("\nChoix invalide \n");
      }
}

void ajouterclient(void)
{
  FILE *fpc;
  client *tmp=(client*)malloc(sizeof(client));

  printf("\n\n\nDonner les informations du client : \n");

    printf("\nIdentificateur : ");
    scanf("%d",&tmp->idClient);
    netstdin();
    while(verifierid(2,tmp->idClient))
    {
    printf("\n Identificateur déjà  utilisé, choisir un autre : ");
    scanf("%d",&tmp->idClient);
    netstdin();
    }
    printf("\nNom : ");
    scanf("%19s",tmp->nom);
    netstdin();
    printf("\nPrénom : ");
    scanf("%19s",tmp->prenom);
    netstdin();
    printf("\nCIN : ");
    scanf("%d",&tmp->cin);
    netstdin();
    printf("\nAdresse : ");
    scanf("%14s",tmp->adresse);
    netstdin();
    printf("\nTélephone : ");
    scanf("%d",&tmp->telephone);

     fpc=fopen("./clients.txt","a");
       if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
     fprintf(fpc,"%d %19s %19s %d %14s %d\n",tmp->idClient,tmp->nom,tmp->prenom,tmp->cin,tmp->adresse,tmp->telephone);
     fclose(fpc);
  free(tmp);
  menuClients();
   }
void modifierclient(void)
{
   FILE *fpc;
   int cpt=0,i,id,choix,finished=0;
   client tmp,*tab=(client*)malloc(cpt*sizeof(client));

   fpc=fopen("./clients.txt","r");
      if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
     while(!feof(fpc))
      {
        cpt++;
        tab=(client*)realloc(tab,cpt*sizeof(client));
        fscanf(fpc,"%d %19s %19s %d %14s %d",&tab[cpt-1].idClient,tab[cpt-1].nom,tab[cpt-1].prenom,&tab[cpt-1].cin,tab[cpt-1].adresse,&tab[cpt-1].telephone);
    }
    cpt--;
   fclose(fpc);

   printf("\n\n Donner l'id du client à  modifier : ");
   scanf("%d",&id);
   for(i=0;i<cpt;i++)
     if(id==tab[i].idClient)
       {
        do
   {
   printf("\n\nChoisir l'information à  modifier :\n");
   printf("\nLe nom--------------->1");
   printf("\nLe prénom---------->2");
   printf("\nLe CIN---------------->3");
   printf("\nL'adresse------------>4");
   printf("\nLe télephone ----->5");
   printf("\nTerminé------------->6");
   printf("\n\t votre choix : ");
   scanf("%d",&choix);

   switch(choix)
     {
        case 1:
        printf("\nDonner le nouveau nom : ");
        scanf("%19s",tab[i].nom);
        netstdin();
        break;
        case 2:
        printf("\nDonner le nouveau prénom : ");
        scanf("%19s",tab[i].prenom);
        netstdin();
        break;
        case 3:
        printf("\nDonner le nouveau CIN : ");
        scanf("%d",&tab[i].cin);
        netstdin();
        break;
        case 4:
        printf("\nDonner la nouvelle adresse : ");
        scanf("%14s",tab[i].adresse);
        netstdin();
        break;
        case 5:
        printf("\nDonner le nouveau télephone: ");
        scanf("%d",&tab[i].telephone);
        netstdin();
        break;
        case 6:
        finished=1;
        break;
        default:
        printf("\nChoix invalid");
        break;
     }
   }while(!finished);
       break;
    }
      fpc=fopen("./clients.txt","w");
      if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpc,"%d %19s %19s %d %14s %d\n",tab[i].idClient,tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].adresse,tab[i].telephone);
    fclose(fpc);
free(tab);
menuClients();
}
void supprimerclient(void)
{

  FILE *fpc;
  int cpt=0,i,id;
  client *tab=(client*)malloc(cpt*sizeof(client));

  fpc=fopen("./clients.txt","r");
      if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
       fflush(stdin);
   printf("\nDonner l'id du client à  supprimer : ");
   scanf("%d",&id);
   while(!feof(fpc))
      {
        cpt++;
        tab=(client*)realloc(tab,cpt*sizeof(client));
        fscanf(fpc,"%d %19s %19s %d %14s %d",&tab[cpt-1].idClient,tab[cpt-1].nom,tab[cpt-1].prenom,&tab[cpt-1].cin,tab[cpt-1].adresse,&tab[cpt-1].telephone);
               if(tab[cpt-1].idClient==id)
                   cpt--;
    }
   fclose(fpc);
     fpc=fopen("./clients.txt","w");
      if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpc,"%d %19s %19s %d %14s %d\n",tab[i].idClient,tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].adresse,tab[i].telephone);
    fclose(fpc);
free(tab);
menuClients();
}


int verifierid(int f,int id)
{
    FILE *fpv,*fpc;
    voiture *tmp1=(voiture*)malloc(sizeof(voiture));
    client *tmp2=(client*)malloc(sizeof(client));
   switch(f)
   {
    case 1:
     fpv=fopen("./voitures.txt","r");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuVoitures();
       }
   while(!feof(fpv))
      {
     fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tmp1->idVoiture,tmp1->marque,tmp1->nomVoiture,tmp1->couleur,&tmp1->nbplaces,&tmp1->prixJour,tmp1->enLocation);
     if(tmp1->idVoiture==id)
      {
     free(tmp1);
     free(tmp2);
     fclose(fpv);
     return 1;
      }
     }
   fclose(fpv);
   free(tmp1);
   free(tmp2);
   return 0;
      case 2:
     fpc=fopen("./clients.txt","r"); 
      if(fpc==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuClients();
       }
   while(!feof(fpc))
      {
     fscanf(fpc,"%d %19s %19s %d %14s %d",&tmp2->idClient,tmp2->nom,tmp2->prenom,&tmp2->cin,tmp2->adresse,&tmp2->telephone);
      if(tmp2->idClient==id)
      {
     free(tmp1);
     free(tmp2);
     fclose(fpc);
     return 1;
      }
     }
   fclose(fpc);
   free(tmp1);
   free(tmp2);
   return 0;
  }
}
int verfnum(float num)
{
   contrat *tmp=(contrat*)malloc(sizeof(contrat));
   FILE *fpco;
     fpco=fopen("./contrats.txt","r"); 
      if(fpco==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
   while(!feof(fpco))
      {
   fscanf(fpco,"%f %d %d %d %d %d %d %d %d %d",&tmp->numContrat,&tmp->idVoiture,&tmp->idClient,&tmp->debut.jj,&tmp->debut.mm,&tmp->debut.aaaa,&tmp->fin.jj,&tmp->fin.mm,&tmp->fin.aaaa,&tmp->cout);
      if(tmp->numContrat==num)
      {
     free(tmp);
     fclose(fpco);
     return 1;
      }
     }
   fclose(fpco);
   free(tmp);
   return 0;
}
void visualisercontrat(void)
{
    FILE *fpco;
    contrat tmp;
    float num;
    int choix,flag=1;
    printf("\n\n Donner le numéro du contrat à  visualiser :");
    scanf("%f",&num);
    netstdin();

     fpco=fopen("./contrats.txt","r"); 
       if(fpco==NULL)
          {
        fprintf(stderr,"\n\nErreure lors de l'ouverture du fichier\nRetour au menu dans 3s");
        sleepv2(3);
        menuLocation();
        }
    while(!feof(fpco))
     {
       fscanf(fpco,"%f %d %d %d %d %d %d %d %d %d",&tmp.numContrat,&tmp.idVoiture,&tmp.idClient,&tmp.debut.jj,&tmp.debut.mm,&tmp.debut.aaaa,&tmp.fin.jj,&tmp.fin.mm,&tmp.fin.aaaa,&tmp.cout);
       if(tmp.numContrat==num)
        {
     printf("\n\nLes informations du contrat num: %f sont :\n",tmp.numContrat);
     printf("\nId du voiture : %d",tmp.idVoiture);
     printf("\nId du client : %d",tmp.idClient);
     printf("\nDate de début : %d/%d/%d",tmp.debut.jj,tmp.debut.mm,tmp.debut.aaaa);
     printf("\nDate de début : %d/%d/%d",tmp.fin.jj,tmp.fin.mm,tmp.fin.aaaa);
     printf("\nCout : %d",tmp.cout);
       break;
        }
     }
    while(flag)
        {
     printf("\n\n\n Appuyer sur 0 pour revenir au menu principal \n\n\n Appuyer sur 1 pour revenir au menu de location \n\n\n\t votre choix : ");
     scanf("%d",&choix);
        if(choix==0)
         {
           fclose(fpco);
           flag=0;
           menuPrincipal();
         }else
           if(choix==1)
         {
          fclose(fpco); 
           flag=0;
           menuLocation();
         }
         else
          printf("\nChoix invalide \n");
      }
}

void louervoiture(void)
{
  int cpt,i,trouve;
  client tmpc,tmpc1;
  voiture tmpv,tmpv1,*tab;
  contrat tmpco;
  int idv,idc,prix;
  FILE *fpv,*fpc,*fpco;
  printf("\n\nDonner les informations de la voiture à  louer");
  printf("\nMarque : ");
  scanf("%14s",tmpv.marque);
  netstdin();
  printf("\nNom : ");
  scanf("%14s",tmpv.nomVoiture);
  netstdin();
  printf("\nCouleur : ");
  scanf("%6s",tmpv.couleur);
  netstdin();
  printf("\nNombre de places : ");
  scanf("%d",&tmpv.nbplaces);
  netstdin();
  fpv=fopen("./voitures.txt","r");
   if(fpv==NULL)
    {
     fprintf(stderr,"\nErreure lors de l'ouverture du fichier\n Retour au menu de Location en 3s");
     sleepv2(3);
     menuLocation();
            }
     trouve=0;
     while(!feof(fpv))
      { cpt=0;
    fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tmpv1.idVoiture,tmpv1.marque,tmpv1.nomVoiture,tmpv1.couleur,&tmpv1.nbplaces,&tmpv1.prixJour,tmpv1.enLocation);
    if(strcmp(tmpv1.marque,tmpv.marque)==0)
     cpt++;
    if(strcmp(tmpv1.nomVoiture,tmpv.nomVoiture)==0)
     cpt++;
    if(strcmp(tmpv1.couleur,tmpv.couleur)==0)
     cpt++;
    if(tmpv1.nbplaces==tmpv.nbplaces)
     cpt++;
    if(cpt==4)
    {
      if(strcmp(tmpv1.enLocation,"Oui")==0||strcmp(tmpv1.enLocation,"oui")==0||strcmp(tmpv1.enLocation,"OUI")==0)
       continue;
      trouve=1;
      idv=tmpv1.idVoiture;
      prix=tmpv1.prixJour;
     break;
    }
    }
     if(!trouve)
      {
       fprintf(stderr,"\nLa voiture demandée n'est existe pas OU elle est déjà  en location,retour au menu location en 3s");
       sleepv2(3);
       menuLocation();
      }
  fclose(fpv);
   printf("\n\nDonner les informations du client ");
  printf("\nNom : ");
  scanf("%19s",tmpc.nom);
  netstdin();
  printf("\nPrénom : ");
  scanf("%19s",tmpc.prenom);
  netstdin();
  printf("\nCIN : ");
  scanf("%d",&tmpc.cin);
  netstdin();
  printf("\nAdresse : ");
  scanf("%14s",tmpc.adresse);
  netstdin();
  printf("\nTélephone : ");
  scanf("%d",&tmpc.telephone);
  fpc=fopen("./clients.txt","r");
   if(fpc==NULL)
    {
     fprintf(stderr,"\nErreure lors de l'ouverture du fichier\n Retour au menu de Location en 3s");
     sleepv2(3);
     menuLocation();
            }
            trouve=0;
     while(!feof(fpc))
      { cpt=0;
    fscanf(fpc,"%d %19s %19s %d %14s %d",&tmpc1.idClient,tmpc1.nom,tmpc1.prenom,&tmpc1.cin,tmpc1.adresse,&tmpc1.telephone);
    if(strcmp(tmpc.nom,tmpc1.nom)==0)
     cpt++;
    if(strcmp(tmpc1.prenom,tmpc.prenom)==0)
     cpt++;
    if(tmpc1.cin==tmpc.cin)
     cpt++;
    if(strcmp(tmpc1.adresse,tmpc.adresse)==0)
     cpt++;
    if(tmpc1.telephone==tmpc.telephone)
     cpt++;
    if(cpt==5)
    {
      trouve=1;
      idc=tmpc1.idClient;
      break;
    }
    }
     if(!trouve)
      {
       printf("\nLes informations du clients ne sont pas enregestré");
       printf("\nVeuilez ajouter le client via le menu de gestion de clients");
       sleepv2(3);
       menuLocation();
     }
  fclose(fpc);
  netstdin();
 printf("\n\nVeuillez remplir les champs du contrat:\n");
   printf("\nDonner le numéro de contrat :");
   scanf("%f",&tmpco.numContrat);
   netstdin();
   while(verfnum(tmpco.numContrat))
   {
   printf("\nNuméro de contrat déjé utilisé");
    printf("\nDonner le numéro de contrat :");
   scanf("%f",&tmpco.numContrat);
   netstdin();
   }
   tmpco.idVoiture=idv;
   tmpco.idClient=idc;
   printf("\nDonner la date de début :\n");
  do{
   printf("\nJour: ");
   scanf("%d",&tmpco.debut.jj);
   netstdin();
   }while(tmpco.debut.jj<1 || tmpco.debut.jj>31);
   do{
   printf("\nMois: ");
   scanf("%d",&tmpco.debut.mm);
   netstdin();
   }while(tmpco.debut.mm<1 || tmpco.debut.mm>12);
   do{
   printf("\nAnnée (Format : aaaa>=2020): ");
   scanf("%d",&tmpco.debut.aaaa);
   netstdin();
   }while(tmpco.debut.aaaa<2020);
   printf("\nDonner la date de fin :\n");
   do{
   printf("\nJour: ");
   scanf("%d",&tmpco.fin.jj);
   netstdin();
   }while(tmpco.fin.jj<1||tmpco.fin.jj>31);
   do{
  printf("\nMois: ");
   scanf("%d",&tmpco.fin.mm);
   netstdin();
   }while(tmpco.fin.mm<1||tmpco.fin.mm>12);
   do{
   printf("\nAnnée (Format aaaa>=2020): ");
   scanf("%d",&tmpco.fin.aaaa);
   }while(tmpco.fin.aaaa<2020);
    while(!debut_inf_fin(tmpco.debut,tmpco.fin))
    {
    printf("\nLa date de fin doit étre suppérieure é a date de fin");
   printf("\nDonner la date de début :\n");
   do{
   printf("\nJour: ");
   scanf("%d",&tmpco.debut.jj);
   netstdin();
   }while(tmpco.debut.jj<1 || tmpco.debut.jj>31);
   do{
   printf("\nMois: ");
   scanf("%d",&tmpco.debut.mm);
   netstdin();
   }while(tmpco.debut.mm<1 || tmpco.debut.mm>12);
   do{
   printf("\nAnnée (Format : aaaa>=2020): ");
   scanf("%d",&tmpco.debut.aaaa);
   netstdin();
   }while(tmpco.debut.aaaa<2020);
   printf("\nDonner la date de fin :\n");
   do{
   printf("\nJour: ");
   scanf("%d",&tmpco.fin.jj);
   netstdin();
   }while(tmpco.fin.jj<1||tmpco.fin.jj>31);
   do{
  printf("\nMois: ");
   scanf("%d",&tmpco.fin.mm);
   netstdin();
   }while(tmpco.fin.mm<1||tmpco.fin.mm>12);
   do{
   printf("\nAnnée (Format :aaaa>=2020): ");
   scanf("%d",&tmpco.fin.aaaa);
    }while(tmpco.fin.aaaa<2020);
 }
   tmpco.cout=nbrdejour(tmpco.debut,tmpco.fin)*prix;
      fpco=fopen("./contrats.txt","a");
      if(fpco==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
        fprintf(fpco,"%f %d %d %d %d %d %d %d %d %d\n",tmpco.numContrat,tmpco.idVoiture,tmpco.idClient,tmpco.debut.jj,tmpco.debut.mm,tmpco.debut.aaaa,tmpco.fin.jj,tmpco.fin.mm,tmpco.fin.aaaa,tmpco.cout);
      fclose(fpco);
      cpt=0;
  tab=(voiture*)malloc(cpt*sizeof(tab));
  fpv=fopen("./voitures.txt","r");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
     while(!feof(fpv))
      {
        cpt++;
        tab=(voiture*)realloc(tab,cpt*sizeof(voiture));
        fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tab[cpt-1].idVoiture,tab[cpt-1].marque,tab[cpt-1].nomVoiture,tab[cpt-1].couleur,&tab[cpt-1].nbplaces,&tab[cpt-1].prixJour,tab[cpt-1].enLocation);
        if(idv==tab[cpt-1].idVoiture)
         strcpy(tab[cpt-1].enLocation,"Oui");
 }
    cpt--;
   fclose(fpv);
      fpv=fopen("./voitures.txt","w");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpv,"%d %14s %14s %6s %d %d %3s\n",tab[i].idVoiture,tab[i].marque,tab[i].nomVoiture,tab[i].couleur,tab[i].nbplaces,tab[i].prixJour,tab[i].enLocation);
    fclose(fpv);
free(tab);
      menuLocation();
}

int debut_inf_fin(date d,date f)
{
     if(d.aaaa==f.aaaa)
      {
         if(d.mm==f.mm)
          {
           if(d.jj>f.jj)
             return 0;
             else
              return 1;
          }
          else
            if(d.mm>f.mm)
              return 0;
               else
                return 1;
      }
      else
        if(d.aaaa>f.aaaa)
          return 0;
          else
            return 1;
}
int nbrdejour(date d,date f)
{
     int diffa=f.aaaa-d.aaaa;
     int diffm=f.mm-d.mm;
     int diffj=f.jj-d.jj;

     return (diffa*356)+(diffm*30)+(diffj+1);
}
void retournervoiture(void)
{
       float num;
       FILE *fpco,*fpv;
       contrat tmp;
       voiture *tab;
       int cpt,i,id;
       printf("\n\n Donner le numéro de votre contrat pour retourner la voiture : ");
       scanf("%f",&num);
       fpco=fopen("./contrats.txt","r");
      if(fpco==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
   while(!feof(fpco))
      {
        fscanf(fpco,"%f %d %d %d %d %d %d %d %d %d",&tmp.numContrat,&tmp.idVoiture,&tmp.idClient,&tmp.debut.jj,&tmp.debut.mm,&tmp.debut.aaaa,&tmp.fin.jj,&tmp.fin.mm,&tmp.fin.aaaa,&tmp.cout);
         if(tmp.numContrat==num)
           {
           id=tmp.idVoiture;
           break;
           }
       }
   fclose(fpco);
        cpt=0;
  tab=(voiture*)malloc(cpt*sizeof(voiture));
  fpv=fopen("./voitures.txt","r");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
     while(!feof(fpv))
      {
        cpt++;
        tab=(voiture*)realloc(tab,cpt*sizeof(voiture));
        fscanf(fpv,"%d %14s %14s %6s %d %d %3s",&tab[cpt-1].idVoiture,tab[cpt-1].marque,tab[cpt-1].nomVoiture,tab[cpt-1].couleur,&tab[cpt-1].nbplaces,&tab[cpt-1].prixJour,tab[cpt-1].enLocation);
          if(id==tab[cpt-1].idVoiture)    
           strcpy(tab[cpt-1].enLocation,"Non");
    }
    cpt--;
   fclose(fpv);
      fpv=fopen("./voitures.txt","w");
      if(fpv==NULL)
       {
       fprintf(stderr,"\n Erreur lors de l'ouverture retour au menu en 3s");
       sleepv2(3);
       menuLocation();
       }
    for(i=0;i<cpt;i++)
      fprintf(fpv,"%d %14s %14s %6s %d %d %3s\n",tab[i].idVoiture,tab[i].marque,tab[i].nomVoiture,tab[i].couleur,tab[i].nbplaces,tab[i].prixJour,tab[i].enLocation);
    fclose(fpv);
   free(tab);
       supprimercontrat(num);
       menuLocation();
}
void modifiercontrat(void)
{
   FILE *fpco;
   float num;
   int i,cpt=0,termine,choix,prix;
   contrat *tab=(contrat*)malloc(cpt*sizeof(contrat));
   printf("\n\nDonner le numéro du contrat à modifier: ");
   scanf("%f",&num);

     fpco=fopen("./contrats.txt","r");
         if(fpco==NULL)
            {
              fprintf(stderr,"\nErreure lors de l'ouverture, retour au menu en 3s");
              sleepv2(3);
              menuLocation();
            }
        while(!feof(fpco))
          {
            cpt++;
            tab=(contrat*)realloc(tab,cpt*sizeof(contrat));
            fscanf(fpco,"%f %d %d %d %d %d %d %d %d %d",&tab[cpt-1].numContrat,&tab[cpt-1].idVoiture,&tab[cpt-1].idClient,&tab[cpt-1].debut.jj,&tab[cpt-1].debut.mm,&tab[cpt-1].debut.aaaa,&tab[cpt-1].fin.jj,&tab[cpt-1].fin.mm,&tab[cpt-1].fin.aaaa,&tab[cpt-1].cout);
              if(tab[cpt-1].numContrat==num)
                {
                 prix=tab[cpt-1].cout/nbrdejour(tab[cpt-1].debut,tab[cpt-1].fin);
                termine=0;
                  while(!termine)
                  {
                   printf("\n\nChoisir l'information à modifier :\n");
                   printf("\nDate de retour--------->1");
                   printf("\nTerminé------------------>2");
                   netstdin();
                   printf("\n\tVotre choix: ");
                   scanf("%d",&choix);
                   netstdin();
                     switch(choix)
                      {
                        case 1:
                          printf("\nDonner la nouvelle date de retour : \n");
                          printf("\nJour :");
                          scanf("%d",&tab[cpt-1].fin.jj);
                          netstdin();
                          printf("\nMoix :");
                          scanf("%d",&tab[cpt-1].fin.mm);
                          netstdin();
                          printf("\nAnnée :");
                          scanf("%d",&tab[cpt-1].fin.aaaa);
                          netstdin();
                          while(!debut_inf_fin(tab[cpt-1].debut,tab[cpt-1].fin))
                          {
                            printf("\nLa date de début doit étre inférieure é la date de fin.Donner la nouvelle date de retour : \n");
                          printf("\nJour :");
                          scanf("%d",&tab[cpt-1].fin.jj);
                          netstdin();
                          printf("\nMoix :");
                          scanf("%d",&tab[cpt-1].fin.mm);
                          netstdin();
                          printf("\nAnnée :");
                          scanf("%d",&tab[cpt-1].fin.aaaa);
                          netstdin();
                          }
            tab[cpt-1].cout=nbrdejour(tab[cpt-1].debut,tab[cpt-1].fin)*prix;
                  case 2:
                       termine=1;
                       break;
                  default:
                       printf("\nChoix invalide");
                       break;
            }
          }
        }
      }
        cpt--;
        fclose(fpco);
        fpco=fopen("./contrats.txt","w");
         if(fpco==NULL)
            {
              fprintf(stderr,"\nErreure lors de l'ouverture, retour au menu en 3s");
              sleepv2(3);
              menuLocation();
            }
            i=0;
        while(i<cpt)
            {
         fprintf(fpco,"%f %d %d %d %d %d %d %d %d %d\n",tab[i].numContrat,tab[i].idVoiture,tab[i].idClient,tab[i].debut.jj,tab[i].debut.mm,tab[i].debut.aaaa,tab[i].fin.jj,tab[i].fin.mm,tab[i].fin.aaaa,tab[i].cout);
            i++;
            }
     fclose(fpco);
     free(tab);
menuLocation();
}
void supprimercontrat(float num)
{
   FILE *fpco;
   int i,cpt=0;
   contrat *tab=(contrat*)malloc(cpt*sizeof(contrat));
     fpco=fopen("./contrats.txt","r");
         if(fpco==NULL)
            {
              fprintf(stderr,"\nErreure lors de l'ouverture, retour au menu en 3s");
              sleepv2(3);
              menuLocation();
            }
        while(!feof(fpco))
          {
            cpt++;
            tab=(contrat*)realloc(tab,cpt*sizeof(contrat));
            fscanf(fpco,"%f %d %d %d %d %d %d %d %d %d",&tab[cpt-1].numContrat,&tab[cpt-1].idVoiture,&tab[cpt-1].idClient,&tab[cpt-1].debut.jj,&tab[cpt-1].debut.mm,&tab[cpt-1].debut.aaaa,&tab[cpt-1].fin.jj,&tab[cpt-1].fin.mm,&tab[cpt-1].fin.aaaa,&tab[cpt-1].cout);
              if(tab[cpt-1].numContrat==num)
                cpt--;
            }
        fclose(fpco);
        fpco=fopen("./contrats.txt","w");
         if(fpco==NULL)
            {
              fprintf(stderr,"\nErreure lors de l'ouverture, retour au menu en 3s");
              sleepv2(3);
              menuLocation();
            }
            i=0;
        while(i<cpt)
            {
         fprintf(fpco,"%f %d %d %d %d %d %d %d %d %d\n",tab[i].numContrat,tab[i].idVoiture,tab[i].idClient,tab[i].debut.jj,tab[i].debut.mm,tab[i].debut.aaaa,tab[i].fin.jj,tab[i].fin.mm,tab[i].fin.aaaa,tab[i].cout);
            i++;
            }
     fclose(fpco);
     free(tab);
menuLocation();
}
void netstdin(void)
{
  char ch[100];
  fgets(ch,99,stdin);
}
void sleepv2(int nbs)
{
	clock_t but;
	but=(nbs*CLOCKS_PER_SEC)+clock();
	  while(but>clock())
	   {
         ;
      }
}
