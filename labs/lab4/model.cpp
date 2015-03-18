#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    state = INIT;
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;
            // Everything's invisible at first
            visible[i][j] = '_';
            // Every other iteration...
            if (j % 2 == 1) {
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
    // Seed random number generator with time
    srand(time(0));
    // Randomize
    int otheri, otherj;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Pick a random spot in the grid
            otheri = rand() % height;
            otherj = rand() % width;
            // Swap grid[i][j] with grid[otheri][otherj]
            letter = grid[i][j];
            grid[i][j] = grid[otheri][otherj];
            grid[otheri][otherj] = letter;
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    if ((row < getHeight()) && (row >= 0) && (column < getWidth()) && (column >= 0)) {return true;}
	return false;
}
bool Model::matched(int row, int column) {
	if ((row == lastRows[0]) && (column == lastColumns[0])) {return false;}
	if (grid[row][column] != grid[lastRows[0]][lastColumns[0]]){return false;}
	return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
    switch(state){
		case INIT:
			visible[row][column] = grid[row][column];
			lastRows.push_back(row);
			lastColumns.push_back(column);
			state = FIRST;
			break;
		case FIRST:
			visible[row][column] = grid[row][column];
			lastRows.push_back(row);
			lastColumns.push_back(column);
			state = MATCH;
			break;
		case MATCH:
			if (!matched(lastRows[1], lastColumns[1]))	
			{
				visible[lastRows[0]][lastColumns[0]] = '_';
				visible[lastRows[1]][lastColumns[1]] = '_';
			}
			lastRows.clear();
			lastColumns.clear();
			visible[row][column] = grid[row][column];
			lastRows.push_back(row);
			lastColumns.push_back(column);
			state = FIRST;
			break;
	}
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    // Assume the game is over
    bool isOver = true;
    // Loop through the grid and see if any element is not visible
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visible[i][j] == '_') {
                isOver = false;
            }
        }
    }

    return isOver;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
void Model::gameIsOver() {
	for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visible[i][j] = '_';
            }
        }

	visible[0][0] = 'Y';
    visible[0][1] = 'O';
    visible[0][2] = 'U';
    visible[1][1] = 'W';
    visible[1][2] = 'I';
    visible[1][3] = 'N';
	
	return;
}
