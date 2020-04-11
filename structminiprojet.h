typedef struct
{
   int jj;
   int mm;
   int aaaa;
}date;
typedef struct
{
  int idVoiture;
  char marque[15];
  char nomVoiture[15];
  char couleur[7];
  int nbplaces;
  int prixJour;
  char enLocation[4];
}voiture;
typedef struct
{
    int idClient;
    char nom[20];
    char prenom[20];
    int cin;
    char adresse[15];
    int telephone;
}client;
typedef struct
{
  float numContrat;
  int idVoiture;
  int idClient;
  date debut;
  date fin;
  int cout;
}contrat;
