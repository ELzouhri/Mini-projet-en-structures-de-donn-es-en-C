
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>  
#define Max 100 
enum identifiant {CIN,CNE,APOGEE};
enum type_utilisateur{ETUDIANT,ADMNISTRATEUR};
typedef union Nom_utilisateur {char CIN[8];char CNE[10];int APOGEE;}Nom_utilisateur;

typedef struct user{
	enum identifiant id;
	union Nom_utilisateur login;
	char password[20];
	enum type_utilisateur type;
	char nom[20];
	char prenom[20];
	char date_N[10];
	struct user* suivant;
}user;

typedef struct livre{
	char ISBN[13];
	char titre[50];
	char auteur[50];
	struct livre *suivant ;
}livre;

typedef struct Liste{
    user *debut;
    user *fin;
    int taille;
}Liste;
typedef struct Liste2{
    livre *debut;
    livre *fin;
    int taille;
}Liste2;


void inisialiser_liste_vide(Liste *u){
    u->debut=NULL;
    u->fin=NULL;
    u->taille=0;
}
void inisialiser_liste_vide_livre(Liste2 *l){
    l->debut=NULL;
    l->fin=NULL;
    l->taille=0;
}
void ins_Liste_Vide (Liste *u, user *nouv){
 nouv->suivant = NULL;
 u->debut = nouv;
 u->fin = nouv;
 u->taille++;
}
void ins_Liste_Vide_livre (Liste2 *l,livre *nouv){
 nouv->suivant = NULL;
 l->debut = nouv;
 l->fin = nouv;
 l->taille++;
}
void ins_Fin_Liste (Liste *u, user *nouv) {
    nouv->suivant = NULL;
    u->fin->suivant = nouv;
    u->fin = nouv;
    u->taille++;
}
void ins_Fin_Liste_livre (Liste2 *l, livre *nouv) {
    nouv->suivant = NULL;
    l->fin->suivant = nouv;
    l->fin = nouv;
    l->taille++;
}




void crypt( char *lettre ){
	int i=0 ;
	while( lettre[i] != '\0')
	{

		if( lettre[i] >='a' && lettre[i] <= 'z')
		{
			int decalage = 0 ;
			decalage = (lettre[i] -'a' + 5 )%26 ;
			lettre[i] = 'a' + decalage ;
		}
		else

				if( lettre[i] >='A' && lettre[i] <= 'Z')
		{
			int decalage = 0 ;
			decalage = (lettre[i] -'A' + 5 )%26 ;
			lettre[i] = 'A' + decalage ;
		}

			i++;
	}
}
void decrypt( char *lettre ){
	int i=0 ;
	while( lettre[i] != '\0')
	{
		if( lettre[i] >='a' && lettre[i] <= 'z')
		{
			int decalage = 0 ;
			decalage = ('z'- lettre[i] + 5 )%26 ;
			lettre[i] = 'z' - decalage ;
		}
		else

				if( lettre[i] >='A' && lettre[i] <= 'Z')
		{
			int decalage = 0 ;
			decalage = ('Z'- lettre[i] + 5)%26 ;
			lettre[i] = 'Z' - decalage ;
		}

			i++;
	}
}



void Afficher_utilisateurs(Liste *u){
    user *courant;
    courant=u->debut; 
    printf("================Afficher_utilisateurs================\n");
    while(courant!=NULL){
        printf("nom=%s\n",courant->nom);
        printf("prenom=%s\n",courant->prenom);
        printf("date_N=%s\n", courant->date_N);
        if(courant->type==1){
           printf("Type=ADMINISTRATEUR\n");
        }else
           printf("Type=ETUDIANT\n");
        printf("============================\n");
        courant=courant->suivant;
    }
}
void ajouter_ficher(user *u){
     FILE *FP;
     FP=fopen("ficher_utilisateur.txt","a");
     crypt(u->password);
    printf("utilisateur est ajouter dans ficher !");
    if(u->id==0){
        fprintf(FP,"( %u %s %s %s %s %s %u)",u->id,u->login.CIN,u->password,u->nom,u->prenom,u->date_N,u->type);
    }else if(u->id==1){
        fprintf(FP,"( %u %s %s %s %s %s %u)",u->id,u->login.CNE,u->password,u->nom,u->prenom,u->date_N,u->type);
    }else{
        fprintf(FP,"( %u %d %s %s %s %s %u)",u->id,u->login.APOGEE,u->password,u->nom,u->prenom,u->date_N,u->type);
        
    }
}
 
void ajouter_utilisateur(Liste *u){
    int n;
    user NewUtilisateur;
    printf("============ ajouter un utilisateur ============\n");
    printf("donner le nom d'utilisateur :");
     scanf("%s", NewUtilisateur.nom);
    printf("donner le prenom d'utilisateur :");
     scanf("%s", NewUtilisateur.prenom);
    printf("donner le date_N d'utilisateur :");
     scanf("%s", NewUtilisateur.date_N);
    printf("donner type: \n 0.ETUDIANT \n1.ADMINISTRATEUR \n donner votre choix : ");
     scanf("%u",&NewUtilisateur.type);
 
    printf("identifiant : \n0.CIN \n1.CNE \n2.APOGEE \n donner votre choix : ");
    scanf("%u",&NewUtilisateur.id);
    
     if(NewUtilisateur.id==0){
        printf("donner le CIN : ");
        scanf("%s",NewUtilisateur.login.CIN);
    }else if(NewUtilisateur.id==1){
        printf("donner le CNE : ");
        scanf("%s",NewUtilisateur.login.CNE);
    }else if(NewUtilisateur.id==2){
        printf("donner le APOGEE : ");
        scanf("%d",&NewUtilisateur.login.APOGEE);
    }
    printf("donner le password d'utilisateur :");
    scanf("%s",NewUtilisateur.password);
    
        ajouter_ficher(&NewUtilisateur);
}

void Afficher_livre(Liste2 *l){
    livre *courant;
    courant =l->debut;  
    printf("============= Afficher les livres =============\n");
    while(courant!=NULL){
        printf("ISBN=%s\n", courant->ISBN);
        printf("titre=%s\n",courant->titre);
        printf("auteur=%s\n",courant->auteur);
        printf("============================\n");
        courant=courant->suivant;
    }
}

void authentification(Liste *u,Liste2 *l,Nom_utilisateur *Nom,char *pass);

 void MenuADMINISTRATEUR(Liste *u,Liste2 *l,Nom_utilisateur *Nom,char *pass,user *courant){
    int n;
    printf("================ Menu =================\n");
    printf("Bonjour administrateur %s %s !\n",courant->nom,courant->prenom);
    printf("1.Afficher la liste d'utilisateurs \n2.Ajouter un utilisateur \n3.Afficher la liste des livres\n4.Se deconnecter \n");
    printf("donner votre choix : ");
    scanf("%d",&n);
    if(n==1){
        Afficher_utilisateurs(u);
    }else if(n==2){
        ajouter_utilisateur(u);
    }else if(n==3){
        Afficher_livre(l);
    }else if(n==4){
        exit(0);
    }
}   
void MenuETUDIANT(Liste *u,Liste2 *l,Nom_utilisateur *Nom,char *pass,user *courant){
    int n;
    printf("================= Menu =================\n");
    printf("Bonjour etudiant %s %s !\n",courant->nom,courant->prenom);
    printf("1.Afficher la liste des livres \n2.Se deconnecter\n");
    printf("donner votre choix : ");
    scanf("%d",&n);
    if(n==1){
       Afficher_livre(l);
    }else if(n==2){
        exit(0);
    };
}
void authentification(Liste *u,Liste2 *l,Nom_utilisateur *Nom,char *pass){
    int i;
    user *courant;
    courant=u->debut;
    while(courant!=NULL){
    if(strcmp(Nom->CIN,courant->login.CIN)==0||
       strcmp(Nom->CNE,courant->login.CNE)==0||
        Nom->APOGEE==courant->login.APOGEE){
          if(strcmp(pass,courant->password)==0){
             if(courant->type==ETUDIANT){
                MenuETUDIANT(u,l,Nom,pass,courant);
            }else{
               MenuADMINISTRATEUR(u,l,Nom,pass,courant);;
            }
    }   }
    courant=courant->suivant;
    }
}

 

int main() {
    int n;
    Liste L;
    Liste2 L2;
    Nom_utilisateur Nom;
    char pass[20];
    printf("(CIN:aaa    password:123)\n");
    //tableau pour utilisateur 
    user u[10]={0,{"aaa"},"123",1,"houssine","zouhri","6/4/2004"};
    
    
    //ajouter utilisateur 
    inisialiser_liste_vide(&L);
    ins_Liste_Vide (&L,&u[0]);
   
    //ajouter livre 
    livre livre[10]={{"2007","Harry Potter","J_K_Rowling"},
                     {"1997","Harry Potter","J_K_Rowling"}};
    inisialiser_liste_vide_livre(&L2);
    ins_Liste_Vide_livre (&L2,&livre[0]);
    ins_Fin_Liste_livre (&L2,&livre[1]);
    //login 
    FILE *FP;
    int i;
    FP=fopen("ficher_utilisateur.txt","a");
     FP=fopen("ficher_utilisateur.txt","r");
    for(i=1;i<=10;i++){
        fscanf(FP,"( %u",&u[i].id);
    if(u[i].id==0){
        fscanf(FP," %s %s %s %s %s %u )",u[i].login.CIN,u[i].password,u[i].nom,u[i].prenom,u[i].date_N,&u[i].type);
    }else if(u[i].id==1){
        fscanf(FP," %s %s %s %s %s %u )",u[i].login.CNE,u[i].password,u[i].nom,u[i].prenom,u[i].date_N,&u[i].type);
    }else if(u[i].id==2){
        fscanf(FP," %d %s %s %s %s %u )",&u[i].login.APOGEE,u[i].password,u[i].nom,u[i].prenom,u[i].date_N,&u[i].type);
    }else  break;
    decrypt(u[i].password);
    ins_Fin_Liste(&L,&u[i]);
    }
     
    
    
	
    printf("login:\n 0.CIN \n 1.CNE  \n 2.APOGEE\n choix:");
    scanf("%d",&n);
	
    if(n==CIN){
        printf("donner le CIN : ");
        scanf("%s",Nom.CIN);
        printf("donner password : ");
        scanf("%s",pass);
        authentification(&L,&L2,&Nom,pass);
    }else if(n==CNE){
        printf("donner le CNE : ");
        scanf("%s",Nom.CNE);
        printf("donner password : ");
        scanf("%s",pass);
        authentification(&L,&L2,&Nom,pass);
    }else if(n==APOGEE){
        printf("donner le APOGEE : ");
        scanf("%d",&Nom.APOGEE);
        printf("donner password : ");
        scanf("%s",pass);
        authentification(&L,&L2,&Nom,pass);
    }
      
    
   
   
    return 0;
   
}


