class pixel {
    public:
    bool state;

    pixel(): state(false) {}

    void contains_snake() {
        state = true;
    }
};