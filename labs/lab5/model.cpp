#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    srand(time(0));
	
	ended = false;
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
	last_direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = rand() % 64;
    food.y = rand() % 48;
    snake.push_front(head);
    snake.push_back(tail);
	
	//it = snake.begin();
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return ended || snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Return true if the front of the snake has the same coordinate as the food -DONE
bool Model::eating() {
	if (food.x == (snake.front()).x && food.y == (snake.front()).y) {		
		try_again:
		food.x = rand() % 64;
		food.y = rand() % 48;
		for(it=snake.begin(); it!=snake.end(); it = it->next) {
			if (it->data.x == food.x && it->data.y == food.y) {
				goto try_again;
			}
		}
		return true;
	}
	return false;
}

void Model::end() {
    ended = true;
}

// Move forward
void Model::crawl() {
    Coordinate front = snake.front();
    
	if ((last_direction == UP && direction == DOWN) || (last_direction == DOWN && direction == UP)
		|| (last_direction == LEFT && direction == RIGHT) || (last_direction == RIGHT && direction == LEFT)) {
			direction = last_direction;
		} 
	
	switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    } 
	last_direction = direction;
 
	if (gameOver()) {
		direction = DEAD;
	}
	if (front.x > 64 || front.x < 0 || front.y > 48 || front.y < 0) {
		direction = DEAD;
		end();
	}
	for(it=snake.begin(); it!=snake.end();it = it->next) {
		if (it != snake.begin()) {
			if (it->data.x == front.x && it->data.y == front.y) {
				direction = DEAD;
				end();
			}
		}
	}
    
    if (direction != DEAD) {
        snake.push_front(front);
		if (!eating()) {
			snake.pop_back();
		}
    }
	else {
		if (snake.size() % 2 == 0){
			snake.pop_front();
		}
		else {
			snake.pop_back();
		}
	}
}
