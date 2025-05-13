#include <iostream>

const size_t INIT_CAPACITY = 8;

enum class PerifDev {
    MOUSE_PAD,
    KEYBOARD,
    MIC,
    HEADPHONES,
    MONITOR,
    JOYSTICK
};

class Computer {

public:

    Computer();
    Computer(const Computer& other);
    Computer(Computer&& other) noexcept;

    Computer& operator=(const Computer& other);
    Computer& operator=(Computer&& other) noexcept;

    ~Computer();

    void setProcPower(double procPower);
    void setCardModel(const char* cardModel);
    void setSupplyPower(int supplyPower);
    void setRam(int ram);

    virtual void printComputerType() const = 0;
    const PerifDev* getDevices() const;

    void addPerifDevice(PerifDev dev);

private:
    double procPower = 0.0;
    char* cardModel = nullptr;
    int supplyPower = 0;
    int ram = 0;

    PerifDev* devices = nullptr;
    size_t devCount = 0;
    size_t devCapacity = INIT_CAPACITY;


    void copyFrom(const Computer& other);
    void moveFrom(Computer&& other);
    void free();

    void resizeDevices();
};