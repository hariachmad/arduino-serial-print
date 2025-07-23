#ifndef LedModule_h
#define LedModule_h

class LedModule{
    private:
        int pin;
    public:
        LedModule(int pin);
        void on();
        void off();
};

#endif