#include "student.h"

STUDENT* kreirajListu(int brojStudenata) 
{
	STUDENT *glava = (STUDENT*)calloc(1, sizeof(STUDENT)); //glava (pp)
	STUDENT *noviStudent, *temp;
	int i;
	if (glava == NULL)
	{
		printf("Memorija nije zauzeta!");
	}
	else 
	{
		unosPodataka(glava);
		glava->nextNode = NULL; // element prema kojem glava pokazuje u pocetku je NULL jer je glava sama u (pp) (podesavanje uz pomoc temp, temp->next koji pokazuje tj. cuva original (glavu)
		temp = glava; //sacuvati glavu (pp)  radimo s pomocnim pokazivacem
		for (i = 1; i < brojStudenata; i++) 
		{
			noviStudent = (STUDENT*)calloc(1, sizeof(STUDENT));
			if (noviStudent == NULL) 
			{
				printf("Memorija za noviStudent nije zauzeta!");
				break;
			}
			else
			{
				unosPodataka(noviStudent);
				noviStudent->nextNode = NULL;// novi student trenutno ne pokazuje na nikoga jer tek trebamo dodati neki novi element

				temp->nextNode = noviStudent; // prethodni pokazivac sada pokazuje na novi ilustracija 
				/*
				* glava->next=NUll
				* temp-> glava
				* novi->next = NULL
				* ali sada temp->next = novi tj u prijevodu glava tj element prije ovog kreiranog sada pokazuje na njega
				*/
				temp = temp->nextNode; // taj se privremeni sada pomjera na ovaj novi i ceka da se napravi jos neki element 
				/*
				temp -> glava, next -> nista ... kreiramo novi
				next od ovoga prije -> novi, novi -> next - nista (jer jos nema nista)
				temp dolazi kod novi glava - temp - novi (temp ujedno i novi) i sad cekamo jos neki element
				*/
			}	
		}
	}
	return glava;
}

void unosPodataka(STUDENT* student)
{
	printf("Unesite ID:");
	scanf("%d", &student->id);
	printf("Unesite ime:");
	student->ime = (char*)calloc(30, sizeof(char)); // dim alokacija polja od 30 chara za ime (moze biti bilo koji broj)
	scanf("%s", student->ime);
	printf("Unesite prezime:");
	student->prezime = (char*)calloc(30, sizeof(char)); // dim alokacija polja od 30 chara za prezime (moze biti bilo koji broj)
	scanf("%s", student->prezime);
	printf("Unesite prosjek:");
	scanf("%f", &student->prosjek);
}

STUDENT* noviCvor(STUDENT* glava) {
	STUDENT* noviStudent = (STUDENT*)calloc(1, sizeof(STUDENT));
	if (noviStudent == NULL) {
		printf("Alokacije memorije za novog studenta nije uspjela!\n");
	}
	else {
		unosPodataka(noviStudent); // pozivamo funkciju uz pomoc koje korisinik unosi podatke 
		noviStudent->nextNode = glava; // novi next pokazuje na prethodnog prvog tj na glavu (pp)
	}
	return noviStudent; // vracamo adresu novog cvora koji je sada pocetni cvor tj nova glava (pp) 
}
void prosjekSvihStudenata(STUDENT* glava) {
	STUDENT* temp = glava;
	float ukupniProsjek = 0;
	int br = 0;
	while (temp != NULL)
	{
		br++;
		ukupniProsjek += temp->prosjek;
		temp = temp->nextNode;
	}
	printf("Ukupan prosjek svih studenata je: %.2f\n",(ukupniProsjek / br));
}
STUDENT* pretraziId(STUDENT* glava, int ID) {
	STUDENT* temp;
	if (glava == NULL)
	{
		printf("List je prazna.");
	}
	temp = glava; 
	while (temp != NULL)
	{
		if (temp->id == ID) {
			return temp;
		}
		else {
			temp = temp->nextNode;
		}
	}
	return NULL;
}

void obrisiStudenta(STUDENT** glava, STUDENT* student) {
	/*
	u slucaju da je trazeni element glava znaci ID koji je korisnik unio je ID glave pa student i glava pokazuju na isto
	nije potrebno raditi temp jer su i student i glava na istoj mem adresi
	*/
	if (*glava == student) 
	{
		*glava = (*glava)->nextNode;
		free(student->ime);
		free(student->prezime);
		free(student);
	}
	else 
	{
		/*
		u slucaju da je neki drugi element koji nije glava
		*/
		STUDENT* temp = *glava; // sacuvamo origanila i uz pomoc temp se krecemo po listi i trazimo koji je to element
		while (temp != NULL)
		{
			if (temp->nextNode == student)
			{
				temp->nextNode = student->nextNode; // kad smo ga nasli "preskocimo ga" i oslobodimo Nije-> Nije-> Je -> Nije  tu veza puca pa igleda ovako 
													// Nije-> Nije (JE - izliramo ga tj temp->next usmjerimo na onaj iduci na koji on pokazuje) -> Nije
				free(student->ime);
				free(student->prezime);
				free(student);
				break;
			}

			temp = temp->nextNode;
		}
	}
}


STUDENT* obrisiListu(STUDENT* glava) {
	STUDENT* temp = glava;
	while (glava != NULL) 
	{
		temp = temp->nextNode;
		free(glava->ime);
		free(glava->prezime);
		free(glava);
		glava = temp;
	}
	return glava;
}

void ispisListe(STUDENT* glava)
{
	STUDENT* temp;
	if (glava == NULL)
	{
		printf("List je prazna.");
	}
	else
	{
		temp = glava; //cuvamo original
		while (temp != NULL)
		{
			printf("ID: %d - %s %s, prosjek: %.2f\n", temp->id, temp->ime, temp->prezime, temp->prosjek);       
			temp = temp->nextNode; // pomaka na iduci element (pp)  1 ele (ispis) ->(trenutni temp postaje onaj prema kojem trenutni pokazuje), a to je 2 ele (ispis)-> 3 elem (ispis) -> NULL - nema dalje         
		}
	}
	
}