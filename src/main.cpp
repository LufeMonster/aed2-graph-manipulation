#include <iostream>
using namespace std;

#include "../include/Graph.h"

void printMenu() {
    cout << "MENU GRAPHS" << endl;
    cout << "1) Print graph (adjacency matrix)" << endl;
    cout << "2) Search city" << endl;
    cout << "3) Search path between cities" << endl;
    cout << "4) Insert city" << endl;
    cout << "5) Insert path between cities" << endl;
    cout << "6) Remove city" << endl;
    cout << "7) Algorithm (to be defined)" << endl;
    cout << "8) Exit" << endl;
}

int main() {
    int option = 0, aux, distance;
    string city1, city2;
    Graph g;

    do {
        printMenu();
        cout << "Choose an option: ";
        cin >> option;

        cin.ignore();
        cout << endl;
        switch(option) {
            case 1:
                cout << "GRAPH" << endl;
                g.printGraph();
                break;
            case 2:
                cout << "SEARCH CITY" << endl;
                cout << "Enter city: ";
                getline(cin, city1);
                
                aux = g.getPosMap(city1);
                if (aux == -1) cout << endl << "City not found! Try again..." << endl;
                else cout << "City in position (" << aux << ")" << endl;
                break;
            case 3: 
                cout << "SEARCH PATH BETWEEN CITIES" << endl;
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);

                aux = g.getEdge(city1, city2);
                if (aux == -1) cout << endl << "Connection not found! Try again..." << endl;
                else cout << city1 << " is " << aux << " km away from " << city2  << endl;
                break;
            case 4:
                cout << "INSERT CITY" << endl;
                cout << "Enter city: ";
                getline(cin, city1);

                aux = g.getPosMap(city1);
                if (aux == -1) {
                    g.insertNode(city1);
                    cout << endl << "Successful insert of city " << city1 << endl;
                } else cout << "City already in graph! Try again..." << endl;
                break;
            case 5:
                cout << "INSERT PATH BETWEEN CITIES" << endl;
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);
                cout << "Enter distance (in Km): ";
                cin >> distance;
                g.addEdge(city1, city2, distance);
                break;
            case 6:
                cout << "REMOVE CITY" << endl;
                cout << "Enter city: ";
                getline(cin, city1);
                g.deleteNode(city1);
                break;
            case 7:
                break;
            case 8: 
                break;
            default:
                cout << "Invalid option! Try again..." << endl;
                break;
        }

        cout << endl;
    } while (option != 8);
    return 0; 
}