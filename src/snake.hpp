#include <list>

struct snake_part {
        int row;
        int col;
    snake_part(int X, int Y): row(X), col(Y) {}
};

enum direction {
    left = 0,
    right = 1,
    up = 2,
    down = 3,
};

class snake{
    direction dir = right;
    public:
        std::list<snake_part> pos_list{{2,1}, {2,2}, {2,3}};  // init start snake

    void move_snake();

    void extend_snake();

    void change_dir(direction new_dir) {
        dir = new_dir;
    }
    
};