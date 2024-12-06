#include <iostream>
#include <dizionarioesteso.cpp>


int main() {
    Dizionario<std::string> dizionario;

    // Inserimento di chiavi e valori
    dizionario.inserisci("zebra", "animale");
    dizionario.inserisci("capra", "animale");
    dizionario.inserisci("mosca", "insetto");
    dizionario.inserisci("leone", "animale");

    dizionario.inserisci("abcde", "parola");  // Crea collisione con "zebra" perche danno lo stesso hash

    // Stampa dizionario
    std::cout << "\ndizionario:\n";
    dizionario.stampa();

    // Recupera un valore
    std::cout << "\nValore per 'zebra': " << dizionario.recupera("zebra") << "\n";
    std::cout << "Valore per 'gorilla': " << dizionario.recupera("gorilla") << "\n"; // Chiave non presente

    // Verifica se una chiave esiste
    if (dizionario.appartiene("capra")) {
    std::cout << "\n'capra' appartiene\n";
    } else {
    std::cout << "\n'capra' non appertiene\n";
    }

    if (dizionario.appartiene("leone")) {
    std::cout << "'leone' appartiene\n";
    } else {
    std::cout << "'leone' non appartiene\n";
    }

    // Cancellazione di una chiave
    std::cout << "\nCancellazione di 'zebra':\n";
    dizionario.cancella("zebra");

}
