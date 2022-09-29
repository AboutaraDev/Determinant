#include <stdio.h>
#include <stdlib.h>

#define DIM 10
typedef float ligne[DIM];
typedef ligne matrice[DIM];

long nb_appels;

void lecture(matrice t,int *lig)
/* lit une matrice (au clavier) */
 {
  int l,c;
  float f;
  puts("dimension de la matrice ?");
  scanf("%d",lig);
  for (l=0;l<*lig;l++) for(c=0;c<*lig;c++)
   {
    printf("élément [%d,%d] ? ",l,c);
    scanf("%f",&f);
    t[l][c]=f;
   }
 }


void copiesauflc(matrice source,matrice dest,int dim,int ligavirer)
 {
  int l,c,ld=0;
  for (l=0;l<dim;l++) if (l!=ligavirer)
   {
    for (c=1;c<dim;c++) dest[ld][c-1]=source[l][c];
    ld++;
   }
 }
float determinant(matrice m,int dim)
 {
  matrice sous_m;
  int l,signe=1;
  float det=0;
  nb_appels++;
  if (dim==1) return(m[0][0]);
  for(l=0;l<dim;l++)
   {
    copiesauflc(m,sous_m,dim,l);
    det+=signe*m[l][0]*determinant(sous_m,dim-1);
    signe=-signe;
   }
  return(det);
 }



void main()
 {
  int taille;
  matrice mat;
  lecture(mat,&taille);

  printf("déterminant : %20.10f ",determinant(mat,taille));
  printf(" en %ld appels\n",nb_appels);
 }
