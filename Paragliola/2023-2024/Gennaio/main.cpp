/*
 * TRACCIA 04/01/2024
 * 
 *
 * [1] Sviluppare una funzione che restituisca il valore maggiore contenuto nell'array numeri;
 * 
 * [2] Sviluppare una funzione che restituisca la media dei valori positivi e la media dei valori negativi
 *     contenuti nella matrice mat;
 *
 * [3] Sviluppare una funzione che restituisca il numero di occorrenza di un carattere nell'array. Il
 *     carattere è passato come parametro.
 * 
 * [4] Sviluppare una funzione che restituisca il numero di parole contenute nell'array frase.
 *
 * [5] Dato l'array lista, sviluppare una funzione che restituisce un valore booleano vero se il nome ed il
 *     cognome di una Persona sono di lunghezza pari.
 *
 * [6] Dato l'array lista, sviluppare una funzione che conti il numero di persone che hanno una doppia nel 
 *     nome
 *
 */

#include <iostream>
#include <string.h>

using namespace std;

struct Persona
{
  char nome[50];
  char cognome[50];
};


// Esecuzione punto 1
int maggioreArray(int numeri[]){
    
    /*
     * Partiamo dal primo elemento dell'array in quanto abbiamo sicuramente un elemento
     * da restituire qualora non si trovassero elementi più grandi di questo.
     * Piccolo esempio per chiarirci:
     * se l'array numeri fosse stato questo [-5], il -5 sarebbe stato il suo elemento maggiore,
     * nonchè unico; quindi... 
     *
     */
    int risultato = numeri[0];
    
    
    /*
     * Parto dal SECONDO elemento dell'array, dato che il primo lo abbiamo già.
     * Ricordiamoci che gli array partono da indice 0!
     *
     */
    for (int i = 1; i < 6; i = i + 1) {
        if (risultato < numeri[i]) {
            risultato = numeri [i];
        }
        
        /*
         * Non mi serve un else in quanto a priori ho già un elemento da restituire 
         * se il controllo non è soddisfatto.
         *
         */
    }
    
    return risultato;
}



// Esecuzione punto 2
/*
 * LE MATRICI VANNO SEMPRE PASSATE CON DIMENSIONE FISSATA, ALTRIMENTI AMERETE 
 * LA BELLISSIMA ESPERIENZA CON I PUNTATORI <3
 * 
 */
float mediaPositivi(int mat[4][4]){
    /*
     * Dobbiamo contare tutti gli elementi che troviamo all'interno della matrice che
     * sono maggiori di 0, e poi la somma di tutti questi elementi trovati che rispecchiano
     * la condizione. Il ciò col fine di trovarne la media.
     * Per ragionare in termini più semplici:
     * Se doveste fare una media di mele rosse all'interno di un cesto
     * voi contereste pure le mele verdi e gialle ?
     *
     */
    int contatoreElementiTrovati = 0;
    float media = 0;
    int sommaElementiTrovati = 0;
    
    /*
     * Cicliamo due volte la matrice per il semplice fatto che va esaminata sia 
     * per riga(i), che per colonna(j)
     *
     */
    for (int i = 0; i < 4; i = i + 1) {
        for (int j = 0; j < 4; j = j + 1) {
            if (mat[i][j] > 0 ) {
                contatoreElementiTrovati = contatoreElementiTrovati + 1;
                sommaElementiTrovati = sommaElementiTrovati + mat[i][j];
            }
        }
    }
    
    media = sommaElementiTrovati / contatoreElementiTrovati;
    return media;
}


// Stesso ragionamento della funzione di prima, solo che adesso consideriamo i negativi :D
float mediaNegativi(int mat[4][4]){
    
    int contatoreElementiTrovati = 0;
    float media = 0;
    int sommaElementiTrovati = 0;
    
    for (int i = 0; i < 4; i = i + 1) {
        for (int j = 0; j < 4; j = j + 1) {
            if (mat[i][j] < 0 ) {
                contatoreElementiTrovati = contatoreElementiTrovati + 1;
                sommaElementiTrovati = sommaElementiTrovati + mat[i][j];
            }
        }
    }
    
    media = sommaElementiTrovati / contatoreElementiTrovati;
    return media;
}


// Esecuzione punto 3
int contaCarattere(char frase[], char carattere) {
    
    int contatore = 0;
    
    /*
     * Ricordiamoci anche che le stringhe sono in fin dei conti degli array di caratteri,
     * e dato che è una stringa possiamo "abbreviare" il numero dei controlli che verranno fatti.
     * Come? Con la funzione della libreria <string.h> strlen(char *str) noi sappiamo da subito quanto sia grande
     * la stringa in questione; dunque si faranno tanti controlli quanti sono i caratteri indicati da strlen1
     *
     */
    for (int i = 0; i < strlen(frase); i = i + 1) {
        if (frase[i] == carattere) {
            contatore = contatore + 1;
        }
    }
    
    return contatore;
}


// Esecuzione punto 4
int contaParole(char frase[]){
    
    int contatoreParole = 0;
    
    /*
     * Stesso concetto di prima per il totale dei confronti, ma cambia un po quello del confronto
     * come viene attuato:
     * Ci basta sapere che il carattere che controlliamo sia uno spazio e che il carattere che lo
     * antecede e che lo segue devono essere per forza qualcosa che non siano spazii (anche il carattere di terminazione
     * ci va bene); pertanto si parte dal SECONDO carattere, in quanto partendo dal primo,
     * andremo a fare "un buco nell'acqua" detto in termini molto banali :D
     *
     */
    for (int i = 1; i < strlen(frase) - 1; i = i + 1) {
        if(frase[i] == ' ' && frase[i-1] != ' ' && frase[i+1] != ' ') {
            contatoreParole = contatoreParole + 1;
        }
    }
    
    // Lo incrementiamo di 1 perchè contiamo la fine della parole ANCHE col carattere di terminazione
    return contatoreParole + 1;
    
}


// Esecuzione punto 5
bool nomeCognomePari(Persona persona){
    bool risultato = false;
    
    // FYI: Il % è un operatore che permette di vedere il resto di una divisione
    if(strlen(persona.nome) % 2 == 0 && strlen(persona.cognome) % 2 == 0) {
        risultato = true;
    }
    
    return risultato;
}


// Esecuzione punto 6
int contaPersoneConDoppia(Persona persona[]){
    
    int totale = 0;
    // Qui effettuo il controllo per OGNI persona presente nella lista
    for (int i = 0; i < 5; i = i + 1) {
        int j = 0;
        /*
         * Utilizziamo un booleano per capire se ho trovato una doppia all'interno del nome della Persona.
         * Se esiste allora posso tranquillamente passare al nome della prossima persona.
         * Ci servirebbe un do/while o anche solo il while al psoto del for dato che ci basta la prima occorrenza trovata
         * per poter dire se il nome ha la doppia o meno.
         *
         */
        bool trovataDoppia = false;
        do {
            if(persona[i].nome[j] == persona[i].nome[j+1] || persona[i].nome[j] == persona[i].nome[j-1]){
                totale = totale + 1;
                trovataDoppia = true;
            }
            j = j + 1;
        } while (j < strlen(persona[i].nome) - 1 && trovataDoppia == false);
    }
    
    return totale;
}


int main ()
{

  int numeri[6] = { 10, -1, 22, 5, 4, 1 };
  int mat[4][4] =
    { {1, 2, 3, 4}, {-1, 2, -5, 1}, {10, -11, 3, -4}, {2, 1, -1, -5} };
  char frase[50] = "Quante parole di sono in questa frase?";
  Persona lista[5] =
    { {"Giovanni", "Rossi"}, {"Maria", "Verdi"}, {"Anna", "Giallo"},
    {"Matteo", "Nero"}, {"Aldo", "Blu"} };



  // Esecuzione primo punto (vedere funzione a riga 34):
  int maggiore = maggioreArray(numeri);
  cout<<"Il valore maggiore dell'array numeri e': "<<maggiore<<endl;
  
  
  // Esecuzione secondo punto (vedere funzione a riga 71 e 106):
  float mediaMatPositivi = mediaPositivi(mat);
  float mediaMatNegativi = mediaNegativi(mat);
  cout<<"La media dei numeri positivi della matrice mat e' : "<<mediaMatPositivi<<endl;
  cout<<"mentre per quella dei numeri negativi e' : "<<mediaMatNegativi<<endl;
  
  
  // Esecuzione terzo punto (vedere funzione riga 131):
  // Possiamo decidere noi che carattere mettere come parametro
  char carattere= 'a';
  int totaleCaratteriFrase = contaCarattere(frase, carattere);
  cout<<"Il numero di caratteri \'"<<carattere<<"\' enlla frase e' pari a: "<<totaleCaratteriFrase<<endl;
  
  
 // Esecuzione quarto punto (vedere funzione riga 153):
 int parole = contaParole(frase);
 cout<<"Ci sono "<<parole<<" parole nella frase"<<endl;
 
 
 // Esecuzione quinto punto (vedere funzione riga 179):
 for (int i = 0 ; i < 5; i = i + 1) {
    cout<<"La persona "<<i<<" ha nome e cognome di lunghezza pari? "<<nomeCognomePari(lista[i])<<endl;
 }
 
 
 // Esecuzione sesto punto (vedere funzione riga 193):
 int personeConDoppia = contaPersoneConDoppia(lista);
 cout<<"Il totale delle persone con almeno una doppia all'interno del loro nome sono: "<<personeConDoppia<<endl<<endl;

  return 0;
}
