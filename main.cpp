#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <fstream>
#include "LinkedList.h"
//#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "../Locations.csv";
const std::string SEARCH_FILE = "../Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    //BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    std::ifstream documento(LOCATION_FILE);
    if (documento.is_open()) {
        std::string e[7];
        std::string linea;
        std::getline(documento, linea);
        while (!documento.eof()) {
            std::getline(documento, linea);
            std::istringstream iss(linea);
            unsigned int count = 0;
            while (std::getline(iss, linea, ',')) {
                e[count] = linea;
                count++;
            }
            Location nodeValue(std::stoi(e[0]), e[1], e[2], std::stod(e[3]), std::stod(e[4]), e[5], e[6]);
            ll.add_tail(nodeValue);
        }
    } documento.close();
    ll.print();




    // Grabar Datos del archivo "Locations.csv" en bst

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch

    /*std::ifstream buscar(SEARCH_FILE);
    if (buscar.is_open()) {
        std::string buscado;
        while (!buscar.eof()) {
            std::getline(buscar, buscado);
            vsearch.push_back(stoi(buscado));
        }
    } buscar.close();*/

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (const auto& id: vsearch) {

        // Buscar en ll
        //ll.search(id);

        // Buscar en bsd
    }

    return 0;
}