#include <iostream>
#include <fstream>

namespace Constants {
	const constexpr unsigned MAX_SIZE = 100;
	const constexpr unsigned MAX_INT_LEN = 20;
	const constexpr unsigned MAX_NAME_SIZE = 17;
	const constexpr unsigned MAX_GROUP_SIZE = 1024;
    const constexpr unsigned MAX_CLIENT_NAME_SIZE = 51;
    const constexpr unsigned MAX_CLIENT_PHONE_SIZE = 21;
    const constexpr unsigned MAX_CLIENT_ADDRESS_SIZE = 101;
}

namespace PizzaDelivery {

    enum class PizzaSize {
        S,
        M,
        L
    };

    enum class PizzaType {
        Margarita,
        Capricciosa,
        Kalzone,
        QuattroStagioni,
        QuattroFormaggi,
        Vegetariana,
        Marinara
    };

    struct Pizza {
        PizzaSize size;
        PizzaType type;
        double price;
    };

    struct PizzaOrder {
        char name[Constants::MAX_CLIENT_NAME_SIZE];
        char phone[Constants::MAX_CLIENT_PHONE_SIZE];
        char address[Constants::MAX_CLIENT_ADDRESS_SIZE];

        Pizza pizzas[Constants::MAX_GROUP_SIZE];
        unsigned orderSize;
    };

    struct PizzaOrderList {
        PizzaOrder orders[Constants::MAX_GROUP_SIZE];
        unsigned orderSize;
    };

    Pizza readPizza(std::ifstream& ifs) {
        Pizza pizza;
        if (ifs.is_open()) {
            ifs.read((char*)&pizza, sizeof(Pizza));
        }

        return pizza;
    }

    Pizza readPizza(const char* fileName) {
        std::ifstream ifs(fileName, std::ios::binary);

        Pizza pizza = readPizza(ifs);
        ifs.close();
        return pizza;
    }

    void savePizza(std::ofstream& ofs, const Pizza& pizza) {
        if (ofs.is_open()) {
            ofs.write((const char*)&pizza, sizeof(Pizza));
        }
    }

    void savePizza(const char* fileName, const Pizza& pizza) {
        std::ofstream ofs(fileName, std::ios::binary);
        savePizza(ofs, pizza);
        ofs.close();
    }

    PizzaOrder readPizzaOrder(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            return {};
        }

        PizzaOrder order;
        ifs.read((char*)&order.address, sizeof(order.address));
        ifs.read((char*)&order.name, sizeof(order.name));
        ifs.read((char*)&order.phone, sizeof(order.phone));
        ifs.read((char*)&order.orderSize, sizeof(order.orderSize));
        for (int i = 0; i < order.orderSize; i++) {
            order.pizzas[i] = readPizza(ifs);
        }

        return order;
    }

    PizzaOrder readPizzaOrder(const char* fileName) {
        std::ifstream ifs(fileName, std::ios::binary);
        PizzaOrder order = readPizzaOrder(ifs);
        ifs.close();
        return order;
    }

    void savePizzaOrder(std::ofstream& ofs, const PizzaOrder& order) {
        if (!ofs.is_open()) {
            return;
        }

        ofs.write((const char*)&order.address, sizeof(order.address));
        ofs.write((const char*)&order.name, sizeof(order.name));
        ofs.write((const char*)&order.phone, sizeof(order.phone));
        ofs.write((const char*)&order.orderSize, sizeof(order.orderSize));
        for (int i = 0; i < order.orderSize; i++) {
            savePizza(ofs, order.pizzas[i]);
        }
    }

    void savePizzaOrder(const char* fileName, const PizzaOrder& order) {
        std::ofstream ofs(fileName, std::ios::binary);
        savePizzaOrder(ofs, order);
        ofs.close();
    }

    PizzaOrderList readPizzaOrderList(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            return {};
        }

        PizzaOrderList list;
        ifs.read((char*)&list.orderSize, sizeof(list.orderSize));
        for (int i = 0; i < list.orderSize; i++) {
            list.orders[i] = readPizzaOrder(ifs);
        }

        return list;
    }

    PizzaOrderList readPizzaOrderList(const char* fileName) {
        std::ifstream ifs(fileName, std::ios::binary);
        PizzaOrderList list = readPizzaOrderList(ifs);
        ifs.close();
        return list;
    }


    void savePizzaOrderList(std::ofstream& ofs, const PizzaOrderList& list) {
        if (!ofs.is_open()) {
            return;
        }

        ofs.write((const char*)&list.orderSize, sizeof(list.orderSize));
        for (int i = 0; i < list.orderSize; i++) {
            savePizzaOrder(ofs, list.orders[i]);
        }
    }

    void savePizzaOrderList(const char* fileName, const PizzaOrderList& list) {
        std::ofstream ofs(fileName, std::ios::binary);
        savePizzaOrderList(ofs, list);
        ofs.close();
    }

}

int main() {
    
}