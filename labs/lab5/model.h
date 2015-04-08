//#include <list>
#include "lists.h"

#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, DOWN, LEFT, RIGHT, DEAD };

typedef struct {
    /*unsigned*/ int x; //maybe get rid of unsigned?
    /*unsigned*/ int y;
} Coordinate;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Which way should the snake face?
    void go(Direction d);
    // Move forward one
    void crawl();
    // Is the game over?
    bool gameOver();
    // Did we just collide with food?
    bool eating();
    // Quit the game
    void end();
    // TODO: swap this out with your own list implementation
    // The snake
    ///std::list<Coordinate> snake; //old
	List<Coordinate> snake;
    // The food
    Coordinate food;
    // Which way is the snake moving?
    Direction direction;
	//what was the last direction the snake was moving? because trying to move backwards doesnt kill you but doesnt move you
	Direction last_direction;
    // What's the width?
    int width;
    // What's the height?
    int height;
	//iterator
	Node<Coordinate> * it;	
private:
    bool ended;
};

#endif