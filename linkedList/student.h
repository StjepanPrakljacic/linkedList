#ifndef STUDENT_H_
#define STUDENT_H_ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int id;
	char* ime;
	char* prezime;
	float prosjek;
	struct student* nextNode;  
}STUDENT;
/* fuc -  STUDENT* kreirajListu(int brojStudenata)
	@parametar (parm) - broj studenata
	@povratna vrijednost (pv) - adresa kreirane glave povezanog popisa (pp)
	opis - funkcija prvo kreira glavu povezanog popisa (kratica pp) tj. kreira prvi element, potom gleda koliko je trazenih elemenata te kreira noce elemente
	funkcija unosPodataka(STUDENT* glava) prima prethodno kreiranu glavu te trazi od korisnika unos potrebnih podatata 
	VAZNO! pri dodavanju novih elemenata sacuvati glavu, kako se adresa originalnog pocetka popisa (glave) ne bi izgubila
*/
STUDENT* kreirajListu(int brojStudenata);

/* void unosPodataka(STUDENT* student)
	@parm - pokazivac na element strukture (glavu pp)
	@pv - nema
	opis - funkcija alocira potreba polja i trazi unos podataka za element strukture
*/
void unosPodataka(STUDENT* glava);

/* void noviCvor(STUDENT* student)
	@parm - pokazivac na element strukture
	@pv - nema
	opis - funkcija ce krirati novi cvor te ce ga ubaciti na pocetak kao novu glavu (pp). Stara glava tada postaje drugi elemant u (pp)
*/
STUDENT* noviCvor(STUDENT* glava);

/* float prosjekSvihStudenata(STUDENT* student)
	@parm - pokazivac na element strukture
	@pv - nema
	opis - funkcija ce proci kroz (pp), prebrojiti studente i zbrojiti prosjek te ce vratiti ukupan prosjek svih studenata u popisu
*/

void prosjekSvihStudenata(STUDENT* glava);

/* STUDENT* pretraziId(STUDENT* glava, int ID)
	@parm - pokazivac na element strukture (glavu pp)
	@parm - ID studenta 
	@pv - vraca adresu studenta ako je pronaden ili NULL ako nije  
*/

STUDENT* pretraziId(STUDENT* glava, int ID);

/* void obrisiStudenta(STUDENT* glava, STUDENT* student)
	@parm - pokazivac na element strukture(glavu pp)
	@parm - pokazivac na studenta kojeg brisemo
	@pv - nema
*/

void obrisiStudenta(STUDENT** glava, STUDENT* student);

/* void obrisiListu(STUDENT* glava)
	@parm - pokazivac na element strukture(glavu pp)
	@pv - pokazivac na element strukture(glavu pp)
	opis- ide kroz popis i brise sve elemente popisa 
*/

STUDENT* obrisiListu(STUDENT* glava);

/* void  ispisListe(STUDENT* glava)
	@parm - pokazivac na element strukture (glavu pp)
	@pv - nema
	opis - funkcija ispisuje elemente (pp)
*/
void ispisListe(STUDENT* glava);

#endif // !STUDENT_H_

