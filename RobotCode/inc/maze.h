// Header file for the maze

#ifndef MAZE
#define MAZE

struct block {
    float time;
    bool mark;
    bool * moves;
    int * previous;
    block();
};

class Maze
{
    block maze[16][16];
    int * start;   
    int (*goal)[2];

public:
    Maze();
    float getTime(int x, int y);
    bool isMarked(int x, int y);
    int * getPrevious(int x, int y);
    bool hasWall(int x, int y, int direction);
};

#endif