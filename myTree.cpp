#include "tree.h"
#include <random>
#include <iostream>

int main(){
	// erzeuge Tree
	Tree* myTree = new Tree(10-9); // Standardwer 100 hier überschrieben
	Tree* myTree2 = new Tree(10); // Standardwer 100 hier überschrieben

	// Ahha! Warum geht das nicht?! Sollte das gehen, und wenn nein, warum nicht?!
	// std::cout << "myTree rootValue " << myTree->root->getValue() << std::endl;
	
	// So geht das!
	Node* myRootNode = myTree->getRoot();
	std::cout << "myTree rootValue " << myRootNode->getValue() << std::endl;
	
	// Zufallszahlengenerator vorbereiten
	std::random_device rd;
    std::mt19937 gen(rd());

	std::uniform_int_distribution<> distr(1,10);
	int random_number = distr(gen);
	
	// Schleife mit 10 Zufallszahlen
	for(size_t i = 0; i < 10; ++i){
		myTree->add(distr(gen));
		myTree2->add(distr(gen));
	}
	
	std::cout << "myTree" << std::endl;
	myTree->search(1); // der erste Schuss ist immer ein Treffer

	std::cout << "myTree2" << std::endl;
	myTree2->search(2);

	return 0;	
}
