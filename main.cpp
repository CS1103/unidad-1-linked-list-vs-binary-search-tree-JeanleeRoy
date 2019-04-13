#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "../Locations.csv";
const std::string SEARCH_FILE = "../Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    load_locations(&ll, LOCATION_FILE);
    //ll.print();

    // Grabar Datos del archivo "Locations.csv" en bst
    load_locations(&bst, LOCATION_FILE);
    //bst.print();

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream buscar(SEARCH_FILE);
    if (buscar.is_open()) {
        std::string buscado;
        while (!buscar.eof()) {
            if (!buscar.eof()) {
                std::getline(buscar, buscado);
                vsearch.push_back(stoi(buscado));
            }
        }
    }
    buscar.close();

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    double avgtime_ll = clock();
    for (const auto &id: vsearch) {

        // Buscar en ll
        ll.search(id);
    }
    double after = clock();
    std::cout<< "Tiempo promedio para buscar un Nodo en Lista enlazada: " << (after - avgtime_ll) / 100 << "us" <<std::endl;

    double avgtime_bst = clock();
    for (const auto &id: vsearch) {
        // Buscar en bsd
        bst.search(id);
    }
    after = clock();
    std::cout<<"Tiempo promedio para buscar un Nodo en Arbol binario: " << (after - avgtime_bst) / 100 << "us" << std::endl;

    return 0;
}