#include <string>
#include "Dizionarioesteso.cpp"

int main() {

    Dizionario<std::string> dict;

    // Inserimento di chiavi e valori
    dict.inserisci("zebra", "animale");
    dict.inserisci("capra", "animale");
    dict.inserisci("mosca", "insetto");
    dict.inserisci("leone", "animale");

    dict.inserisci("abcde", "parola");  // Crea collisione con "zebra" perche danno lo stesso hash

    // Stampa dizionario
    std::cout << "\ndizionario:\n";
    dict.stampa();

    // Recupera un valore
    std::cout << "\nValore per 'zebra': " << dict.recupera("zebra") << "\n";
    std::cout << "Valore per 'gorilla': " << dict.recupera("gorilla") << "\n"; // Chiave non presente

    // Verifica se una chiave esiste
    if (dict.appartiene("capra")) {
    std::cout << "\n'capra' appartiene\n";
    } else {
    std::cout << "\n'capra' non appertiene\n";
    }

    if (dict.appartiene("leone")) {
    std::cout << "'leone' appartiene\n";
    } else {
    std::cout << "'leone' non appartiene\n";
    }

    // Cancellazione di una chiave
    std::cout << "\nCancellazione di 'zebra':\n";
    dict.cancella("zebra");

}
