#include <iostream>
#include <fstream>
#include <iomanip>

// Funzione che mi esegue la trasformazione affine da [1,5] a [-1,2]. La funzione la scrivo fuori dal main poichè nel caso mi dovesse servire 
// più volte la richiamo senza doverla scrivere ogni volta. Scrivo i nuemri con .0 (3.0 / 4.0 * x - 7.0 / 4.0) poichè altrimenti ci sarebbe un 
// errore logico: per ottenere il risultato corretto devo infatti forzare uno dei due numeri a essere un numero a virgola mobile (double),
// cosicchè la divisione venga eseguita con i numeri decimali invece che interi e ottenre quindi un output double e non intero.
double mapValue(double x) {
    return 3.0 / 4.0 * x - 7.0 / 4.0;
}

int main() {
    // Apre il file di input "data.txt" e il file di output "result.txt"
    std::ifstream inputFile("data.txt"); // apro il file data.txt in lettura (i dati li devo solo leggere e salvare successivamente)
    std::ofstream outputFile("result.txt"); // apro il file result.txt in scrittura

    // Verifico che non ci siano stati errori nell'apertura dei due file 
    if (inputFile.fail()) {
        std::cerr << "Errore nell'apertura di data.txt" << std::endl;
        return 1;
    }

    if (outputFile.fail()) {
        std::cerr << "Errore nell'apertura di result.txt" << std::endl;
        return 1;
    }
	
	// Inizializzo i dati 
    double sum = 0.0;
    double value;
    
    // Scrive l'intestazione nel file di output
    outputFile << "# N Mean\n";
    
    int count = 0;
    // Legge i valori dal file di input
    while (inputFile >> value) {
        // Esegue la trasformazione affine del numero da [1, 5] a [-1, 2]. Somma a sum il valore trasformato,
		// incrementa il contatore di 1 e calcola la media dei primi "i" (ovvero il valore di cunt) valori mappati.
        double finalValue = mapValue(value);
        sum = sum + finalValue; 
        count = count + 1;
        double mean = sum / count;
        
        // Scrive il risultato nel file di output in formato scientifico con 16 cifre decimali. 
		// Ho già incluso precedentemente #include <iomanip>
        outputFile << count << " " << std::scientific << std::setprecision(16) << mean << "\n";
    }

    // Chiudo i due file aperti precedentemente
    inputFile.close();
    outputFile.close();
    
    std::cout << "I risultati sono stati salvati con successo nel file result.txt." << std::endl;

    return 0;
}