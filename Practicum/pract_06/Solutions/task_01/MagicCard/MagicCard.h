#include <iostream>

namespace MagicCardConstants {
    const int NAME_LEN = 25;
    const int EFFECT_LEN = 100;
}

enum class Type {
    trap,
    buff,
    spell,
    undef
};

class MagicCard {
public:
    MagicCard() = default;
    
    MagicCard(const char* name, const char* effect, Type type);

    void setName(const char* name);
    void setEffect(const char* effect);
    void setType(Type type);

    const char* getName() const;
    const char* getEffect() const;
    Type getType() const;

private:
    char name[MagicCardConstants::NAME_LEN] = "";
    char effect[MagicCardConstants::EFFECT_LEN] = "";
    Type type = Type::undef;
};