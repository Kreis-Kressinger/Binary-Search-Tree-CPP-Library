// Using GNU AFFERO GENERAL PUBLIC LICENSE Version 3

class Node {

	Node* parent = nullptr;
	Node* smallerChild = nullptr;
	Node* largerChild = nullptr;
	int value;
	
	public:

	Node(int value, Node* parent = nullptr){
		this->value = value;
		this->parent = parent;
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

	Node* getSmallerChild(){
	return this->smallerChild;
	}

	Node* getLargerChild(){
	return this->largerChild;
	}

	Node* getParent(){
	return this->parent;
	}
	
	int getValue(){
		return this->value;
	}


	// These two following methods are the most confusing things I probably ever coded. Why would anyone make something like this? Why? 

	Node* smallestDescendant(Node* Node){
		
		if(Node->getLargerChild() == nullptr){
			return Node;
		}
	
		return smallestDescendant(Node->getLargerChild());
	}


	Node* largestDescendant(Node* Node){
		
		if(Node->getSmallerChild() == nullptr){
			return Node;
		}
	
		return smallestDescendant(Node->getSmallerChild());
	}

	void addAlgorithm(Node* Node){
		
		if(this->value == Node->getValue()){
		return;
		}

		if(this->value > Node->getValue()){
			if(this->smallerChild == nullptr){
				this->setSmallerChild(Node);
			}else{
				smallerChild->addAlgorithm(Node);
			}
		}
		if(this->value < Node->getValue()){
			if(this->largerChild == nullptr){
				this->setLargerChild(Node);
			}else{
				largerChild->addAlgorithm(Node);
			}
		}
	return;
	}

	void removeAlgorithm(int value){

		// I have created a Monster. I apologize to the World for ever creating such a... such a... I can't even describe it in words. It is absolutely horrendous. I am terribly sorry. 
		// Please forgive me. AND DO NOT READ TROUGH IT, I AM BEGGING YOU! I do not want to be associated with this.
		
		if(this->value == value){
		
			if(this->parent->getSmallerChild() == this){
				this->parent->setSmallerChild(this->smallerChild);
				this->smallerChild->setParent(this->parent);
				
				if(this->largerChild != nullptr){
					this->largerChild->setParent(smallestDescendant(this->largerChild));
					this->largerChild->smallestDescendant(this->smallerChild)->setLargerChild(this->largerChild);
				}
			}else if(this->parent->getLargerChild() == this){
				this->parent->setLargerChild(this->largerChild);
				this->largerChild->setParent(this->parent);
				
				if(this->smallerChild != nullptr){
					this->smallerChild->setParent(largestDescendant(this->smallerChild));
					this->smallerChild->smallestDescendant(this->largerChild)->setSmallerChild(this->smallerChild);
				}
			}
			
		}

		if(this->value > value){
			if(this->smallerChild == nullptr){
				return;
			}else{
				smallerChild->removeAlgorithm(value);
			}
		}
		if(this->value < value){
			if(this->largerChild == nullptr){
				return;
			}else{
				largerChild->removeAlgorithm(value);
			}
		}

	} 

	int searchAlgorithm(int value){
		if(this->value == value){
			return this->value;
		}
		if(this->value > value){
			return this->smallerChild->searchAlgorithm(value);
		}
		if(this->value < value){
			return this->largerChild->searchAlgorithm(value);
		}
	return 0;
	}

	
	void exterminateAlgorithm(){
		if(this->smallerChild != nullptr){
			this->smallerChild->exterminateAlgorithm();
		}
		if(this->largerChild != nullptr){
			this->largerChild->exterminateAlgorithm();
		}
		delete this;
		return;
	}
};

class Tree {

	Node* root;
	
	public:

	Tree(int rootValue = 100){
		Node* Nroot = new Node(rootValue);
		this->root = Nroot;
	}

	~Tree(){
		root->exterminateAlgorithm();
	}

	void add(int value){
		Node* addedNodePointer = new Node(value);
		this->root->addAlgorithm(addedNodePointer);
	}
	
	void remove(int value){
		this->root->removeAlgorithm(value);
	}
	
	int search(int value){
		return this->root->searchAlgorithm(value);
	}
};
