#include <list>

struct snake_part {
        int row{0};
        int col{0};
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
        std::list<snake_part> pos_list{snake_part{2,1}, snake_part{2,2}, snake_part{2,3}};  // init start snake

    void move_snake();

    void extend_snake();

    void change_dir(direction new_dir) {
        dir = new_dir;
    }
    
};