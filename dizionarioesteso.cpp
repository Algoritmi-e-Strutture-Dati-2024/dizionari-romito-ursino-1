#include <iostream>

template <typename T>
class Dizionario {
private:
    static const int TABLE_SIZE = 100; // Dimensione fissa della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    // Funzione hash di base
    int hashFunction(const std::string key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE; // Algoritmo di hashing semplice
        }
        return hash;
    }

public:
    // Metodo per aggiungere una coppia chiave-valore
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            std::cerr << "Collision detected for key: " << key << " at index " << index << ". Not handling collisions.\n";
            return;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    // Metodo per ottenere il valore associato a una chiave
    T recupera(const std::string key) const {
        int index = hashFunction(key);

        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        return "Key not found!";
    }

    // Metodo per cancellare una coppia chiave-valore
    void cancella(const std::string key) {
        int index = hashFunction(key);

        if (table[index].isOccupied == true && table[index].key == key) {
            table[index].isOccupied = false; // Libera la posizione
            std::cout << "Chiave " << key << " cancellata.\n";
        } else {
            std::cout << "Chiave " << key << " non trovata.\n";
        }
    }

    // Metodo per verificare se una chiave è presente nel dizionario
    bool appartiene(const std::string key) const {
        int index = hashFunction(key);

        if (table[index].isOccupied == true && table[index].key == key) {
            return true; // La chiave è presente
        }
        else
        return false; // La chiave non è presente
    }

    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
