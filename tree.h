// Using GNU AFFERO GENERAL PUBLIC LICENSE Version 3
#include <iostream>

class Node {

	Node* parent = nullptr; // wird das überhaupt irgendwo verwendet?
	Node* smallerChild = nullptr;
	Node* largerChild = nullptr;
	int value;

	public:

	Node(int value, Node* parent = nullptr){
		this->value = value;
		this->parent = parent;
		std::cout << "Kontruktor von Node " << this << " mit Parent " << this -> parent << std::endl;
	}

	void setSmallerChild(Node* smallerChild){
		this->smallerChild = smallerChild;
	}

	void setLargerChild(Node* largerChild){
		this->largerChild = largerChild;
	}

	void setParent(Node* parent){
		this->parent = parent;
	}

	int getValue(){
		return this->value;
	}

	void addAlgorithm(Node* Node){
		std::cout << "Node " << this << " zu Vergleichsnode " << Node  <<": ";
		if(this->value > Node->getValue()){
				// Ist der Wert des aktuellen Nodes größer als der Wert des Vergleichsnodes
				// und ist das smallerChild noch nicht gesetzt, dann setze das Vergleichsnode
				// als smallerChild.
			if(this->smallerChild == nullptr){
				this->setSmallerChild(Node);
				std::cout << "smallerChild von " << this << " ist " << Node << std::endl;
			}else{
				// Ist das smallerChild doch schon gesetzt, rufe diese Funktion für das smallerChild
				// mit dem aktuellen Vergleichsnode auf.
		        std::cout << "Du stehst unter mir! Such!!!" << std::endl;
				smallerChild->addAlgorithm(Node);
			}
		}
		// => Es entsteht eine verkettete Liste und Vergleichsnodes werden ggf. nach unten einsortiert,
		// wenn sie kleiner sind als der Wert des aktuellen Nodes.

		if(this->value < Node->getValue()){
				// gleiche Verfahrensweise wie oben...
			if(this->largerChild == nullptr){
				this->setLargerChild(Node);
				std::cout << "largerChild von " << this << " ist " << Node << std::endl;
			}else{
		        std::cout << "Du stehst über mir! Such!!!" << std::endl;
				largerChild->addAlgorithm(Node);
			}
		}
		// => Es entsteht gleichermaßen eine verkettete Liste nach oben.
		return;
	}

	int searchAlgorithm(int value){
		if(this->value == value){
			std::cout << "Wert " << value << " beim aktuellen Node " << this << " gefunden!" << std::endl;
			return this->value;
		}
		if(this->value > value){
			std::cout << "Hier ist Node " << this << ", frage Node smallerChild bei " << this->smallerChild <<
					" nach Wert " << value << "..." << std::endl;
			return this->smallerChild->searchAlgorithm(value);
		}
		if(this->value < value){
			std::cout << "Hier ist Node " << this << ", frage Node largerChild bei " << this->smallerChild <<
					" nach Wert " << value << "..." << std::endl;
			return this->largerChild->searchAlgorithm(value);
		}
		return 0;
	}
};

class Tree {

	Node* root;

	public:

	// Konstruktor mit Standardwert
	Tree(int rootValue = 100){
		Node* Nroot = new Node(rootValue);
		this->root = Nroot;
	}

	// Destruktor
	~Tree(){
		this->root = nullptr; // Reicht das aus? Was passiert hier noch?
		std::cout << "Destruktor ausgeführt!" << std::endl;
	}

	// Getter-Funktion für Root-Node
	Node* getRoot(){
		return this->root;
	}

	void add(int value){
		Node* addedNodePointer = new Node(value);
		std::cout << "Added node with value " << value <<
			" at position " << addedNodePointer << std::endl;
		this->root->addAlgorithm(addedNodePointer);
	}

	void remove(){
		//this->root.removeAlgorithm();
	}

	int search(int value){
		return this->root->searchAlgorithm(value);
	}
};
