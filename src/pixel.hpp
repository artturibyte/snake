



class pixel {
    public:
    bool snake;
    bool apple;

    pixel(): snake(false), apple(false) {}

    void contains_snake() {
        snake = true;
    }

    void contains_apple(bool apple_state) {
        apple = apple_state;
    }

};