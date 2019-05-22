
#ifndef FOLLOWPATH
#define FOLLOWPATH
#include <deque>

struct command
{
    char movement;
    int amount;
};

class FollowPath
{
    public:
        FollowPath();
        void pushMovement(char move);
        void runList();

    private:
        stack <char> pathlist;

};

#endif