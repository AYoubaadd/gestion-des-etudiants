#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {int Num;
                char Nom[30];
                char Prenom[30];
                int niveau;
                char password[60];
}etudiant;

typedef struct{
                char nom[30];
                char password[30];
}admin;

typedef struct{int Num;
               char matiere[100];
               int niveau;
               
}matier;

typedef struct{
               int num_mat;
			   char temps[50];             
}emploi;

typedef struct {int Num_etd;
                int Num_matiere;
                
                float nott;
}Note;

typedef struct{
    int Num_etd;
    int Num_matiere;
    int absent;
}Absence;

etudiant etud;
Note note;
matier mat;
Absence absenc ;
admin admn; 
emploi empl;
int num_etd;
int cheeck_etud(char nom[],char pas[]){
	FILE *F;
	F=fopen("etudiant.txt","r");
	while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	
	
	if((strcmp(etud.Nom, nom)==0) && (strcmp(etud.password,pas) == 0)){ fclose(F); return etud.Num;}
	
	}
	fclose(F);return 0;
	
}

int cheeck_admin(char nom[],char pas[]){
	FILE *F;
	F=fopen("admine.txt","r");
	if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
       }
	do{
	fscanf(F,"%s ;%s \n",&admn.nom,&admn.password);

	if((strcmp(admn.nom,nom)==0) && (strcmp(admn.password,pas)==0)) { fclose(F);return 1;}
	
	}while(!feof(F));
	fclose(F);return 0;	
}

int recherch_num(int Num){
	etudiant etud;	
	FILE *F;
	F=fopen("etudiant.txt","r");
	if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
       }
	while (fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	
	if(etud.Num==Num) { fclose(F);return 1;}
	
	}
    fclose(F);return 0;
}

void ajout_etud(){
	int num;
		FILE *F;
	F=fopen("etudiant.txt","a+");
	if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
       }
	printf("\n\t\t\t---donner le numero d inscription de l etudiant: ");
	scanf("%d",&num);
    while(recherch_num(num)==1){
		printf("\n ce numero existe deja !!");
		printf("\n entrer un autre numero :");
		scanf("%d",&num);
	}
	etud.Num=num;fflush(stdin);
	printf("\n\t\t\t----Ecrire le Nom :");
	gets(etud.Nom);
	fflush(stdin);
	
	printf("\n\t\t\t----Ecrire le Prenom :");
	gets(etud.Prenom);
	fflush(stdin);
	
	printf("\n\t\t\t----Niveau :");
	scanf("%d",&etud.niveau);
	fflush(stdin);
	
    strcpy(etud.password, etud.Prenom);
    sprintf(etud.password + strlen(etud.password), "%d", 2023);

	fflush(stdin);
	fprintf(F,"%d ;%s ;%s ;%d ;%s \n", etud.Num, etud.Nom, etud.Prenom, etud.niveau, etud.password);
	fclose(F);
} 

void chercher(){
	int num;
	FILE *F;
	F=fopen("etudiant.txt","r");
    
	d: printf("\n\t\t\t\t\t----Entrer le Num d inscription : ");scanf("%d",&num);
	          if(recherch_num(num)==0){printf("\t\t\t\t--- Desolee !! Ce Num d inscription n exist pas ---\n");goto d;}
			  else {
			   while (fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password) ==5){
			  
			            if(etud.Num==num){printf("\t\t\t----------------------------------------------------------------\n");
						                  printf("\t\t\t-------------------- Information de l Etudiant -----------------\n");
						                  printf("\t\t\t----------------------------------------------------------------\n");
						                  printf("\t\t\t-\tNumero d inscription:\t%d\n",etud.Num);
						                  printf("\t\t\t-\tNom:\t\t\t%s\n",etud.Nom);
						                  printf("\t\t\t-\tPrenom:\t\t\t%s\n",etud.Prenom);
						                  printf("\t\t\t-\tNiveau:\t\t\t%d\n",etud.niveau);
						                  printf("\t\t\t----------------------------------------------------------------\n");
								      	 }               
			            }
				   }
				   fclose(F);
	}    	

void affich_info(int num){
	FILE *F;
	F=fopen("etudiant.txt","r");
			   while (fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password) ==5){
			            if(etud.Num==num){printf("\t\t\t----------------------------------------------------------------\n");
						                  printf("\t\t\t-------------------- Information de l Etudiant -----------------\n");
						                  printf("\t\t\t----------------------------------------------------------------\n");
						                  printf("\t\t\t-\tNumero d inscription:\t%d\n",etud.Num);
						                  printf("\t\t\t-\tNom:\t\t\t%s\n",etud.Nom);
						                  printf("\t\t\t-\tPrenom:\t\t\t%s\n",etud.Prenom);
						                  printf("\t\t\t-\tNiveau:\t\t\t%d\n",etud.niveau);
						                  printf("\t\t\t----------------------------------------------------------------\n");break;
								      	 }               
			            }
				   fclose(F);
	}    	

void supprimer(){
	int num;
	FILE *F, *fich;
	 F=fopen("etudiant.txt","r");
	 fich=fopen("tempetudiant.txt","w");
	debut: printf("entrer le Num d inscription de l etudaiant :\n");
	 scanf("%d",&num);
    if(recherch_num(num)==1)
         while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	      
	      if(etud.Num!=num)fprintf(fich,"%d ;%s ;%s ;%d ;%s \n",etud.Num,etud.Nom,etud.Prenom,etud.niveau,etud.password);
	    }
	    
	else {
	     printf("\t\t\t----ce numero n existe pas----\n");goto debut;}
		    
		fclose(fich);
		fclose(F);
        remove("etudiant.txt");
        rename("tempetudiant.txt", "etudiant.txt");
        if (remove("etudiant.txt") != 0) {
    perror("Error removing etudiant.txt");
}

if (rename("tempetudiant.txt", "etudiant.txt") != 0) {
    perror("Error renaming files");
}
		printf("\t\t\t----L etudiant a ete supprimer avec succee----\n");
}

void affich_list(){
	FILE * F;int niv,i=0;
	F=fopen("etudiant.txt","r");
	do{
	printf("\t\t\t---------------------- donner le niveau (semestre)-------------------\n");
	scanf("%d",&niv);}while(niv<1||niv>6);
	printf("\t\t\t---------------------------------------------------------------------\n");
	printf("\t\t\t----------------------- La list des etudiants -----------------------\n");
	printf("\t\t\t---------------------------------------------------------------------\n");
	printf("\t\t\t- Num\t\tNumero Inscri\t\t Nom\t\tPrenom\n");
	printf("\t\t\t---------------------------------------------------------------------\n");
	while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	if(niv==etud.niveau){i++,	
	printf("\t\t\t-%d\t\t%d\t\t\t%s\t%s \n",i,etud.Num,etud.Nom,etud.Prenom);
	printf("\t\t\t---------------------------------------------------------------------\n");}	                   
	  }
 
	fclose(F);
}

int matiere_ch(int num_m){
	matier mat;
	FILE *F;
	F=fopen("matiere.txt","r");
		if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        }
	while (fscanf(F,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
	if(mat.Num==num_m){fclose(F);return 1;}
	
	}
	fclose(F);return 0;
}

void inser_note(){
	FILE *F,*f,*fille;int n,niv,num,Num_matiere;
	F=fopen("etudiant.txt","r");
	f=fopen("notes.txt","a+");
	fille=fopen("matiere.txt","r");
	if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;}
	debut: printf("\t\t\t----Est ce que tu veux insrer la note d un seul etudiant(1) ou bien tout(2)----\n");
	scanf("%d",&n);
	
	if(n==1){printf("\t\t\t   --------------------------------------------------------------------------\n");
        yy:printf("\t\t\t   ---Entrer le num d inscription de l etudiant :");
        	scanf("%d",&num);
            	if(recherch_num(num)!=0){
	                                    while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
									       if(etud.Num==num){ c: printf("\n\t\t\t   ---Numero de matiere :");scanf("%d",&note.Num_matiere);
	                                                                if( matiere_ch(note.Num_matiere)){ note.Num_etd=num;
	                                                                   while(fscanf(fille,"%d \n",&mat.niveau)==1){
                                                                                                                  if(etud.niveau==mat.niveau)do{printf("\n\t\t\t   ---Entrer la Note :");
	                                                                                                  
																	                                                                            scanf("%f",&note.nott);
																	                                                                           }while(note.nott<0||note.nott>20);
						fprintf(f,"%d ;%d ;%.2f \n",note.Num_etd,note.Num_matiere,note.nott); printf("\n\n\t\t\t\t ***l operation est effectuee avec succee ***\n\n") ;      break;      }	                                                                   	
																	   }
																	 
			 
																	 else{ printf("\t\t\tERREUR !! Ce numero de matiere n existe pas \n");goto c;}                       
									                           }
									                       
									  }}
				else { printf("\t\t\tERREUR !! Ce numero d etudiant n existe pas \n");goto yy;}  					  
									   printf("\n\t\t\t--------------------------------------------------------------------------\n");} 
	           
	else if(n == 2){printf("\t\t\t----------------------------------------------------------------------\n");
	                printf("\t\t\t----------------------------------------------------------------------\n");
                	printf("\t\t\t--------- Tu va remplire les notes de touts les etudiants   ----------\n");
                    printf("\t\t\t----------------------------------------------------------------------\n");
                    printf("\t\t\t----------------------------------------------------------------------\n");
      
        	
            	                d:ll:printf("\n\t\t---Quel semestre :");scanf("%d",&niv);
	                                printf("\n\t\t---Numero de matiere :");scanf("%d",&Num_matiere);
	                                                                 if( matiere_ch(Num_matiere)){ 
																	                                   while(fscanf(fille,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
																	                                   	if(mat.niveau==niv){note.Num_etd=num;
																										     while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
																										             if(niv==etud.niveau){ 
																										   do{printf("\n\t\t---Entrer la Note de la matiere %s de l etudinat %s  : ",mat.matiere,etud.Nom);
	                                                                                                   scanf("%f",&note.nott);
																	                                   }while(note.nott<0||note.nott>20);note.Num_matiere=Num_matiere;note.Num_etd=etud.Num;
																									   fprintf(f,"%d ;%d ;%.2f \n",note.Num_etd,note.Num_matiere,note.nott);
																	                                   printf("\t\t----------------------------------------------------------------------------------\n");}
																	                                                   else{printf("\t\t\t\t***ERREUR !!! le niveau de l etudiant et de la matiere n est pas compatible\n\n ");
																	                                                   goto d;
																													   }
																										   }
																										
																										}   
																										else {printf("\t\t *** ERREUR !!! le niveau  ne corespond pas a celle de la matiere ***\n");goto ll;
																	                                   	}
																									   }
																									
																									   
																									   
																	                               }
			 
																	 else{ printf("\n\t\t\tERREUR !! Ce numero de matiere n existe pas \n");goto d;}                       

    }
    else {printf("\t\t\t*** ERREUR !!! le nombre que tu choisi n est pas dans le menu *** \n\t\t\t\t***VOILA LE MENU*** \n\n");goto debut;
	}
fclose(F); 
fclose(f); 	
fclose(fille);        	
}

void voir_matier_note(int num){
	FILE *F,*f,*fille;
	
	F = fopen("etudiant.txt", "r");
	f=fopen("notes.txt","r");
    fille=fopen("matiere.txt","r");
	while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	   if(etud.Num==num){
	   printf("\n\t\t\t\t\t --- %s\t%s  BIENVENU ---\n",etud.Nom,etud.Prenom);break;}
	}
	
	while(fscanf(f,"%d ;%d ;%f \n",&note.Num_etd,&note.Num_matiere,&note.nott)==3){
	   if(note.Num_etd==num){
	   	                     while(fscanf(fille,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)){
	   	                        if(note.Num_matiere==mat.Num)printf("\t\t\t\t---%s\t %.2f \n",mat.matiere,note.nott);
								}rewind(fille);
	   	
	                         	
	                        }
	   
	  }
	  fclose(F);
	  fclose(f);
	  fclose(fille);
	  
}

int recherch_num_abscen(int Num){
	
	FILE *f;
	f=fopen("abscenc.txt","r");
	while(fscanf(f,"%d ;%d ;%d \n",&absenc.Num_etd,&absenc.Num_matiere,&absenc.absent)==3){
	if(absenc.Num_etd==Num) { fclose(f);return 1;}
	}
	fclose(f);return 0;
}

void enregistrer_absence(){
    FILE *F,*f,*fille;
    int niv,num_matiere,num_etudiant ;
   
    f=fopen("abscenc.txt","a+");
    F = fopen("etudiant.txt", "r");
     fille= fopen("matiere.txt", "r");
    ff:printf("\t\t\t---Entrer le numero de l etudinat :");
    dd:scanf("%d",&num_etudiant);if(!recherch_num(num_etudiant)){printf("\t\t\t---Erreur !! Etudiant n exixste pas ---");goto ff;}
    gg:printf("\t\t\t---Entrer le numero de matiere :");
    scanf("%d",&num_matiere);if(!matiere_ch(num_matiere)){printf("\t\t\t---Erreur !! Matiere n exixste pas ---");goto gg;}
    d: printf("\t\t\t---Entrer le semestre :");
    scanf("%d",&niv);

   
   while(fscanf(F,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
	   if(etud.Num==num_etudiant){if(etud.niveau!=niv){
	                                                     printf("\t\t\t--- L etudiant n est pas inscrit dans ce semestre !!!");goto d;} 
	   	                    
	   	                         else {while(fscanf(fille,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)){
	   	                        if(num_matiere==mat.Num&&mat.niveau==niv){
								 	absenc.Num_etd=num_etudiant;absenc.Num_matiere=num_matiere;absenc.absent=1;
								   fprintf(f,"%d ;%d ;%d \n",absenc.Num_etd,absenc.Num_matiere,absenc.absent);break;  }
								if(num_matiere==mat.Num&&mat.niveau!=niv){printf("\t\t\t*** La matier n est pas de meme niveau de l etudiant !!!***");goto dd;
								}
								}
								
									                                                             	}
							                                                                            
																								  }
																								  }									   	                                       
	  fclose(fille);					
	  fclose(F);
      fclose(f);
}

int afficher_absce(int Num){
	FILE *F,*f,*file;
	file=fopen("etudiant.txt","r");
	F=fopen("abscenc.txt","r");
	f=fopen("matiere.txt","r");
	printf("\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t------------ Liste des matieres et nombre d absences ------------\n");
	printf("\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t-----------------------------------------------------------------\n\n");
    if(recherch_num_abscen(Num)==0){
    	while(fscanf(file,"%d ;%s ;%s ;%d \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau)==4){
    	    if(etud.Num==Num){
    	                 	while(fscanf(f,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
    	    	                if(etud.niveau==mat.niveau)printf("\t\t\t-- %s  : \t0\t\n",mat.matiere);
				                                                                            }
	}
	                                                                                             }
	            }
    else{
    	 	while(fscanf(file,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
    	    if(etud.Num==Num){
    	    	while(fscanf(f,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
    	    	   if(etud.niveau==mat.niveau){int i=0;
    	    	   	                           while(fscanf(F,"%d ;%d ;%d \n",&absenc.Num_etd,&absenc.Num_matiere,&absenc.absent)==3)
    	    	                                  if(absenc.Num_matiere==mat.Num && absenc.Num_etd==Num)i++;
    	    	                                  
			                                   	printf("\t\t\t--%s\t: \t%d\n",mat.matiere,i);i==0;rewind(F);
				                              } 
				}
    	   	
		                	}
	       }
	       printf("\n\t\t\t-----------------------------------------------------------------\n");
	       printf("\n\t\t\t-----------------------------------------------------------------\n");
	    }
	    fclose(file);
    	fclose(F);
    	fclose(f);
}

int check_emploi(int num_mat){
	FILE *F;
	F=fopen("emploi.txt","r");
	while(fscanf(F,"%d ;%s \n",&empl.num_mat,&empl.temps)==2){
		if(num_mat==empl.num_mat){fclose(F);return 1;	}
	}
	fclose(F);return 0;
}

void remplir_emploi_de__temps(){
	FILE *f,*F;int num;
	f=fopen("matiere.txt","r");
	F=fopen("emploi.txt","a+");
	printf("\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t------------------------ Emploi du temps ------------------------\n");
	printf("\t\t\t-----------------------------------------------------------------\n\n");
    d:printf("\t\t\t---donner le numero de matiere:");
	scanf("%d",&num);
	if(matiere_ch(num)){while(fscanf(f,"%d ;%s ;%d \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
    	    	   if(num==mat.Num){  if(check_emploi(num)==0){
		                printf("\t\t\t--- Donner le temps de la matiere %s EX(jeudi 9-13) :",mat.matiere);
						scanf("%s",&empl.temps);empl.num_mat=num;
						fprintf(F,"%d ;%s \n",empl.num_mat,empl.temps);}
						                else printf("\n\n\t\t\t\t***Deja le temps de cette matiere est definie ***\n\n");}
			              }
	                   }
	else {printf("\t\t\t\t*** ERREUR!! le numero de matiere n existe pas ***\n\n");goto d;
	}                   
	printf("\n\n\t\t\t-----------------------------------------------------------------\n");
	printf("\t\t\t-----------------------------------------------------------------\n\n");
	fclose(f);
	fclose(F);
}

void voir_emploi_de__temps(int num_etu){
	FILE *f,*F,*file;int num;
	F=fopen("matiere.txt","r");
    file=fopen("etudiant.txt","r");
    f=fopen("emploi.txt","r");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t------------------ Voila votr emploi du temps ------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n\n");
    
	while(fscanf(file,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5){
		if(num_etu==etud.Num)
		                      while(fscanf(F,"%d ;%s ;%d ;%s \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
							  if(etud.niveau==mat.niveau)while(fscanf(f,"%d ;%s \n",&empl.num_mat,&empl.temps)==2){
							  	if(empl.num_mat==mat.Num)
							            printf("\t\t\t-- %s :\t %s \n",mat.matiere,empl.temps);
							            
							  }rewind(f);}}
			           printf("\t\t\t----------------------------------------------------------------\n");   
	                   printf("\t\t\t----------------------------------------------------------------\n\n");
	fclose(F);
	fclose(file);
	fclose(f);
}
void affiche_matiere(int num){
	FILE *F,*f;int niv;
	F=fopen("matiere.txt","r");
	f=fopen("etudiant.txt","r");
	 printf("\t\t\t----------------------------------------------------------------\n");
	     printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t------------------ Voila votr table de matiere -----------------\n");
     printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n\n");
    
	while(fscanf(f,"%d ;%s ;%s ;%d ;%s \n",&etud.Num,&etud.Nom,&etud.Prenom,&etud.niveau,&etud.password)==5)
		if(num==etud.Num){niv=etud.niveau;break;
		}
	while(fscanf(F,"%d ;%s ;%d ;%s \n",&mat.Num,&mat.matiere,&mat.niveau)==3){
	  if(niv==mat.niveau)printf("\t\t\t--- %s\n",mat.matiere);	
	}	
	fclose(F);
	fclose(f);
printf("\t\t\t----------------------------------------------------------------\n");
 printf("\t\t\t----------------------------------------------------------------\n\n\n");
}
void interface_admin(){
    printf("\t\t\t----------------------------------------------------------------\n");
	printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t------------------ Bienvenu Dans Votr Espace -------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------- [1]: pour ajouter etudiant               -----------\n");
    printf("\t\t\t----------- [2]: pour suprimer etudiant              -----------\n");
    printf("\t\t\t----------- [3]: pour chercher etudiant              -----------\n");
    printf("\t\t\t----------- [4]: pour afficher la list des etudiants -----------\n");
    printf("\t\t\t----------- [5]: pour inserer les notes              -----------\n");
    printf("\t\t\t----------- [6]: pour enregistrer l abscence         -----------\n");
    printf("\t\t\t----------- [7]: pour inserer l emploi du temps      -----------\n");
    printf("\t\t\t----------- [8]: Quiter                              -----------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n\n");
}   

void interface_etudiant(){
    printf("\t\t\t----------------------------------------------------------------\n");
	printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t-------------- Beinvenu Dans Votr Espace Etudiant --------------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------- [1]: pour voir mes informations          -----------\n\n");
    printf("\t\t\t----------- [2]: pour voir mes matieres              -----------\n\n");
    printf("\t\t\t----------- [3]: pour voir les notes                 -----------\n\n");
    printf("\t\t\t----------- [4]: pour voir les abscences             -----------\n\n");
    printf("\t\t\t----------- [5]: pour voir l emploi du temps         -----------\n\n");
    printf("\t\t\t----------- [6]: Quiter                              -----------\n\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t----------------------------------------------------------------\n");
    
}



int main(){
	int n,inte,ch_et,i,aw,v;
	char nom_etd[30],pass[60];	    
   
    debut:
    printf("     -------------------------------------------------------------------------------------------------------------\n");
	printf("     -------------------------------------------------------------------------------------------------------------\n");
	printf("     --------------------------- BIENVENU DANS L APPLICATION DE GESTION DES ETUDINATS ----------------------------\n");
	printf("     -------------------------------------------------------------------------------------------------------------\n");
	printf("     -------------------------------------------------------------------------------------------------------------\n\n");
	printf("        \t\t\t\t\t\t---logine---\n\n");
	printf("\t\t\t\t\t-Entrer votr nom         : ");scanf(" %s",&nom_etd);
	printf("\t\t\t\t\t le mot de pass est de form prenom + 2023\n\t\t\t\t\t-Entrer votr mot de pass :");scanf(" %s",&pass);
	
	printf("\n\n     -------------------------------------------------------------------------------------------------------------\n");
	printf("     -------------------------------------------------------------------------------------------------------------\n");
	printf("     -------------------------------------------------------------------------------------------------------------\n\n");
	
	inte=cheeck_admin(nom_etd,pass);
	ch_et=cheeck_etud(nom_etd,pass);
	
	if(inte==1){
	c:system("cls");interface_admin();
	d:scanf("%d",&i);
	 if(i==1){system("cls");ajout_etud();aa:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto aa;
	 }
	 else if(i==2){system("cls");supprimer();a:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto a;
	 }
	 else if(i==3){system("cls");chercher();b:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto b;
	 }
	 else if(i==4){system("cls");affich_list();k:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto k;
	 }
	 else if(i==5){system("cls");inser_note();e:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto e;
	 }
	 else if(i==6){system("cls");enregistrer_absence();j:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto j;
	 }
	 else if(i==7){system("cls");remplir_emploi_de__temps();h:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto c;else goto h;
	 }
	 else if(i==8){system("cls");goto debut;
	 }
     else {printf("\t\t\t--- Erreur !!! numero de service n est pas dans le menu ---\n\t\t\t\t  --- ENTRER UN AUTRE NOMBRE ---\n");goto d;
	 }
   	      }
	else {if(ch_et!=0){
	x:system("cls");interface_etudiant();
	w:scanf("%d",&i);
	 if(i==1){system("cls");affich_info(ch_et);bb:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto x;else goto bb;
	 }
	 else if(i==2){system("cls");affiche_matiere(ch_et);ss:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto x;else goto ss;
	 }
	 else if(i==3){system("cls");voir_matier_note(ch_et);cc:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto x;else goto cc;
	 }
	 else if(i==4){system("cls");afficher_absce(ch_et);dd:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto x;else goto dd;
	 }
	 else if(i==5){system("cls");voir_emploi_de__temps(ch_et);kk:printf("\t\t\t\t\t\t--- Retour(0) --- ");scanf("%d",&n);if(n==0)goto x;else goto kk;
	 }
	 else if(i==6){system("cls");goto debut;
	 }
	     else {printf("\t\t\t--- Erreur !!! numero de service n est pas dans le menu ---\n\t\t\t\t  --- ENTRER UN AUTRE NOMBRE ---\n");goto w; 
 	 } 
	                  }
	else {	system("cls");printf("\n\n\t\t\t\t\t--- Desole vous n avais pas de compte ---\n \t\t\t\t\t   *** CONTACTER L ADMINISTRATION ***\n");
	}
}
}