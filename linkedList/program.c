#include "student.h"


int main() {
	int brojStudenata, ID;
	STUDENT* trazeni = NULL;
	printf("Koliko studenata zelite unijeti:\t");
	scanf("%d", &brojStudenata);
	STUDENT *glava = kreirajListu(brojStudenata);
	//glava = noviCvor(glava); //dodavanje novog cvora na pocetak liste
	printf("\nUnesite ID koji zelite pretraziti:\t");
	scanf("%d", &ID);
	printf("REZULTATI:\n");
	ispisListe(glava);
	prosjekSvihStudenata(glava);
	trazeni = pretraziId(glava, ID);
	if (trazeni == NULL) {
		printf("Student s trazenim ID-em nije pronadjen\n");
	}
	obrisiStudenta(&glava, trazeni);
	ispisListe(glava);
	prosjekSvihStudenata(glava);
	//glava = obrisiListu(glava);
	//ispisListe(glava); // nakon brisanja trebalo bi ispisati lista je prazna 
	return 0;
}