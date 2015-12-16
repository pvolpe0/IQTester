#include <iostream>
#include <algorithm>
#include <map>

// Node neightbors
enum Neightbors {

	LEFT,
	UP_LEFT,
	UP_RIGHT,
	RIGHT,
	DOWN_RIGHT,
	DOWN_LEFT,
	SIZE,
};

class Node {

	private :
		bool filled;

	public :

		Node* neighbors[SIZE] = {NULL}; 
 
		Node();
		~Node();

		void setFilled(bool);

		
};

Node::Node() {


	
	for (int i = 0; i < SIZE; i++ )
		std::cout << neighbors[i] << std::endl;
}

void Node::setFilled(bool fill ) {


	filled = fill;
}

class Board {

	private :
		Node* slots[15] = {NULL};

	public : 
	
		Board();	
		void printBoard();
		void printNumberedBoard();

		void buildBoard(int);
		void connectNodes();
		void clearLeft();
		void clearRight();
		void clearBottom();

};

Board::Board(){

	std::cout << "                01                "  << std::endl;
	std::cout << "            02      03            "  << std::endl;
	std::cout << "        04      05      06        "  << std::endl;
	std::cout << "    07      08      09      10    "  << std::endl;
	std::cout << "11      12      13      14      15"  << std::endl;

	std::cout << "Select slot on board to leave empty" << std::endl;

	int selection; 

	std::cin >> selection;

	buildBoard(selection);

}

void  Board::buildBoard( int emptySlot ) {

	for (int i = 0; i < 15; i++) {


		if ( i == emptySlot - 1 )
			continue;

		
		slots[i] = new Node();
		slots[i]->setFilled( true );

		std::cout << "Node " << i << " created" << std::endl;


	}
	connectNodes();

	


}

void Board::clearLeft() {

	
	slots[0]->neighbors[LEFT] = NULL;
	slots[0]->neighbors[UP_LEFT] = NULL;

	slots[1]->neighbors[LEFT] = NULL;
	slots[1]->neighbors[UP_LEFT] = NULL;

	slots[3]->neighbors[LEFT] = NULL;
	slots[3]->neighbors[UP_LEFT] = NULL;

	slots[6]->neighbors[LEFT] = NULL;
	slots[6]->neighbors[UP_LEFT] = NULL;

	slots[10]->neighbors[LEFT] = NULL;
	slots[10]->neighbors[UP_LEFT] = NULL;
}

void Board::clearRight() {

	slots[0]->neighbors[RIGHT] = NULL;
	slots[0]->neighbors[UP_RIGHT] = NULL;

	slots[2]->neighbors[RIGHT] = NULL;
	slots[2]->neighbors[UP_RIGHT] = NULL;

	slots[5]->neighbors[RIGHT] = NULL;
	slots[5]->neighbors[UP_RIGHT] = NULL;

	slots[9]->neighbors[RIGHT] = NULL;
	slots[9]->neighbors[UP_RIGHT] = NULL;

	slots[14]->neighbors[RIGHT] = NULL;
	slots[14]->neighbors[UP_RIGHT] = NULL;
}

void Board::clearBottom() {


	slots[10]->neighbors[DOWN_LEFT] = NULL;
	slots[10]->neighbors[DOWN_RIGHT] = NULL;

	slots[11]->neighbors[DOWN_LEFT] = NULL;
	slots[11]->neighbors[DOWN_RIGHT] = NULL;

	slots[12]->neighbors[DOWN_LEFT] = NULL;
	slots[12]->neighbors[DOWN_RIGHT] = NULL;

	slots[13]->neighbors[DOWN_LEFT] = NULL;
	slots[13]->neighbors[DOWN_RIGHT] = NULL;

	slots[14]->neighbors[DOWN_LEFT] = NULL;
	slots[14]->neighbors[DOWN_RIGHT] = NULL;
}

void Board::connectNodes() {


	std::map<int,int> slotToRow;

	slotToRow[0] = 1;
	slotToRow[1] = 2;
	slotToRow[2] = 2;
	slotToRow[3] = 3;
	slotToRow[4] = 3;
	slotToRow[5] = 3;
	slotToRow[6] = 4;
	slotToRow[7] = 4;
	slotToRow[8] = 4;
	slotToRow[9] = 4;
	slotToRow[10] = 5;
	slotToRow[11] = 5;
	slotToRow[12] = 5;
	slotToRow[13] = 5;
	slotToRow[14] = 5;

	for (int slot = 0; slot < 15; slot++) {


		if (slots[slot] == NULL)
			continue;

		int row = slotToRow[slot];
		

		int bottom_left = slot + row;
		if (bottom_left < 0 || bottom_left > 14)
			slots[slot]->neighbors[DOWN_LEFT] = NULL;
		else 			
			slots[slot]->neighbors[DOWN_LEFT] = slots[bottom_left];


		int bottom_right = slot + row + 1;
		if (bottom_right < 0 || bottom_right > 14)
			slots[slot]->neighbors[DOWN_RIGHT] = NULL;
		else 			
			slots[slot]->neighbors[DOWN_RIGHT] = slots[bottom_right];
		
		int left = slot - 1;
		if (left < 0 || left > 14)
			slots[slot]->neighbors[LEFT] = NULL;
		else 			
			slots[slot]->neighbors[LEFT] = slots[left];
		
		int right = slot + 1;
		if (right < 0 || right > 14)
			slots[slot]->neighbors[RIGHT] = NULL;
		else 			
			slots[slot]->neighbors[RIGHT] = slots[right];
		
		int up_left = slot - row;	
		if (up_left < 0 || up_left > 14)
			slots[slot]->neighbors[UP_LEFT] = NULL;
		else 			
			slots[slot]->neighbors[UP_LEFT] = slots[up_left];

		int up_right = slot - row + 1;
		if (up_right < 0 || up_right > 14)
			slots[slot]->neighbors[UP_RIGHT] = NULL;
		else 			
			slots[slot]->neighbors[UP_RIGHT] = slots[up_right];

	}


	clearLeft();
	clearRight();
	clearBottom();
}


int main (int argc, char argv[]) {

	
	Board* board = new Board();


	return 0;
}
