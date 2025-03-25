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

namespace JobOffers {

    struct JobOffer {
        char companyName[Constants::MAX_NAME_SIZE];
        unsigned teamSize;
        unsigned vacationDays;
        long long salary;
    };

    struct JobOfferList {
        JobOffer offers[Constants::MAX_GROUP_SIZE];
        unsigned offerSize;
    };

    JobOffer readJobOffer() {
        JobOffer offer;
        std::cin.getline(offer.companyName, Constants::MAX_NAME_SIZE);
        std::cin >> offer.teamSize;
        std::cin >> offer.vacationDays;
        std::cin >> offer.salary;
        std::cin.get();
        return offer;
    }

    JobOfferList readJobOfferList() {
        JobOfferList list;
        std::cin >> list.offerSize;
        std::cin.get();
        for (int i = 0; i < list.offerSize; i++) {
            list.offers[i] = readJobOffer();
        }
        return list;
    }

    JobOffer readJobOffer(std::ifstream& ifs) {
        JobOffer offer;
        if (ifs.is_open()) {
            ifs.read((char*)&offer, sizeof(JobOffer));
        }
        return offer;
    }

    JobOfferList readJobOfferList(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            return {};
        }

        JobOfferList list;
        ifs.read((char*)&list.offerSize, sizeof(list.offerSize));
        for (int i = 0; i < list.offerSize; i++) {
            list.offers[i] = readJobOffer(ifs);
        }

        return list;
    }

    void saveJobOffer(std::ofstream& ofs, const JobOffer& offer) {
        if (!ofs.is_open()) {
            return;
        }

        ofs.write((const char*)&offer, sizeof(JobOffer));
    }

    void saveJobOfferList(std::ofstream& ofs, const JobOfferList& list) {
        if (!ofs.is_open()) {
            return;
        }

        ofs.write((const char*)&list.offerSize, sizeof(list.offerSize));
        for (int i = 0; i < list.offerSize; i++) {
            saveJobOffer(ofs, list.offers[i]);
        }
    }

    void saveJobOfferList(const char* fileName, const JobOfferList& list) {
        std::ofstream ofs(fileName, std::ios::binary | std::ios::ate);
        saveJobOfferList(ofs, list);
        ofs.close();
    }

    void printJobOffer(const JobOffer &offer) {
        std::cout << offer.companyName << " " << offer.teamSize << " " << offer.vacationDays << " " << offer.salary << std::endl;
    }

    void filterOffers(const char* filePath, long long minSalary) {
        std::ifstream ifs(filePath, std::ios::binary);
        if (!ifs.is_open()) {
            return;
        }

        JobOfferList list = readJobOfferList(ifs);
        ifs.close();

        for (int i = 0; i < list.offerSize; i++) {
            if (list.offers[i].salary >= minSalary) {
                printJobOffer(list.offers[i]);
            }
        }

    }

    bool existOffer(const char* filePath, const char* name) {
        std::ifstream ifs(filePath, std::ios::binary);
        if (!ifs.is_open()) {
            return false;
        }

        JobOfferList list = readJobOfferList(ifs);
        ifs.close();

        for (int i = 0; i < list.offerSize; i++) {
            if (strcmp(list.offers[i].companyName, name) == 0) {
                return true;
            }
        }

        return false;
    }

    bool existOffer(const JobOfferList& list, const char* name) {
        for (int i = 0; i < list.offerSize; i++) {
            if (strcmp(list.offers[i].companyName, name) == 0) {
                return true;
            }
        }

        return false;
    }

    bool isPerfectOffer(const JobOffer &offer, int maxCoworkers, int minVacancyDays, int minSalary) {
        return offer.teamSize <= maxCoworkers && offer.vacationDays >= minVacancyDays && offer.salary >= minSalary;
    }

    void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
        std::ifstream ifs(filePath, std::ios::binary);
        if (!ifs.is_open()) {
            return;
        }

        JobOfferList list = readJobOfferList(ifs);
        ifs.close();

        for (int i = 0; i < list.offerSize; i++) {
            if (isPerfectOffer(list.offers[i], maxCoworkers, minVacancyDays, minSalary)) {
                printJobOffer(list.offers[i]);
            }
        }

    }

    void addOrder(JobOfferList& list, const JobOffer& offer) {
        if (list.offerSize >= Constants::MAX_GROUP_SIZE) {
            return;
        }

        list.offers[list.offerSize++] = offer;
    }

    struct JobOfferSystem {
        JobOfferList offers;
    };

    void printAllJobOffers(const JobOfferSystem &system) {
        for (int i = 0; i < system.offers.offerSize; i++) {
            printJobOffer(system.offers.offers[i]);
        }
    }

    void printJobOffersWithHigherSalary(const JobOfferSystem &system, long long minSalary) {
        for (int i = 0; i < system.offers.offerSize; i++) {
            if (system.offers.offers[i].salary >= minSalary) {
                printJobOffer(system.offers.offers[i]);
            }
        }
    }

    void startSystem() {
        JobOfferSystem system;
        while (true) {
            char action;
            std::cin >> action;
            bool shouldBreak = false;
            JobOffer offer;

            char buffer[Constants::MAX_NAME_SIZE];

            switch (action) {
                case 'a':
                    offer = readJobOffer();
                    addOrder(system.offers, offer);
                    break;
                case 'i':
                    printAllJobOffers(system);
                    break;
                case 's':
                    std::cin.getline(buffer, Constants::MAX_NAME_SIZE);
                    if (existOffer(system.offers, buffer)) {
                        std::cout << "Offer exists!" << std::endl;
                    } else {
                        std::cout << "Offer does not exist!" << std::endl;
                    }
                    break;
                case 'f':
                    int minSalary;
                    std::cin >> minSalary;
                    printJobOffersWithHigherSalary(system, minSalary);
                case 'q':
                    shouldBreak = true;
                default:
                    break;
            }

            if (shouldBreak) {
                break;
            }
        }
    }

}

int main() {
    
}