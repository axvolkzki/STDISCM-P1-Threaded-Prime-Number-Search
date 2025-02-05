#include "MainMenu.h"

#include "../Variation/VariationManager.h"
#include "../PrimeSearch/SearchRange.h"
#include "../PrimeSearch/SearchLinear.h"
#include "../Print/PrintImmediately.h"
#include "../Print/PrintAtTheEnd.h"



MainMenu* MainMenu::sharedInstance = nullptr;

MainMenu::MainMenu() {
}

/************ Public Functions ************/

MainMenu* MainMenu::getInstance() {
    if (MainMenu::sharedInstance == nullptr) {
        MainMenu::sharedInstance = new MainMenu();
    }

    return MainMenu::sharedInstance;
}

void MainMenu::initialize()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new MainMenu();
    }
}

void MainMenu::destroy()
{
    if (sharedInstance != nullptr) {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

void MainMenu::start()
{
    this->showMenu();
    this->variant = this->validateInput();

    switch (this->variant) {
        case 1:   // Search for prime numbers in a range and print them immediately
            this->searchMethod = new SearchRange();
            this->printer = new PrintImmediately();
            break;
        case 2:   // Search for prime numbers in a range and print them at the end
            this->searchMethod = new SearchRange();
            this->printer = new PrintAtTheEnd();
            break;
        case 3:   // Search for prime numbers linearly and print them immediately
            this->searchMethod = new SearchLinear();
            this->printer = new PrintImmediately();
            break;
        case 4:   // Search for prime numbers linearly and print them at the end
            this->searchMethod = new SearchLinear();
            this->printer = new PrintAtTheEnd();
            break;
        default:
            this->exit();
            break;
    }

    if (this->running) {
        this->displayCurrentConfig();

        if (searchMethod != nullptr && printer != nullptr) {
            VariationManager variationManager(GlobalConfig::getInstance()->getTargetNumber(), GlobalConfig::getInstance()->getNumberOfThreads(), this->searchMethod, this->printer, this->variant);
            variationManager.executeVariation();
        }
    }
}


bool MainMenu::isRunning() const
{
    return this->running;
}


/************ Private Functions ************/
void MainMenu::showMenu() const
{
    cout << "Welcome to Prime Finder!" << endl;
    cout << "Choose a variation for the configuration of checking and printing prime numbers:" << endl;
    cout << "[1] Search for prime numbers in a range and print them immediately" << endl;
    cout << "[2] Search for prime numbers in a range and print them at the end" << endl;
    cout << "[3] Search for prime numbers linearly and print them immediately" << endl;
    cout << "[4] Search for prime numbers linearly and print them at the end" << endl;
    cout << "[5] Exit" << endl;
    cout << endl;
}

void MainMenu::displayCurrentConfig() const
{
    color.yellow();
    cout << "Current configuration" << endl;
    cout << "Number of threads  : " << GlobalConfig::getInstance()->getNumberOfThreads() << endl;
    cout << "Target number      : " << GlobalConfig::getInstance()->getTargetNumber() << endl;
    cout << "Variant            : " << this->variant << endl;
    cout << endl;
    color.reset();
}


int MainMenu::validateInput()
{
    String input;
    bool validInput = false;
    bool attemptInput = false;

    do {
        if (attemptInput) {
            cout << "Invalid input. Please try again." << endl;
        }

        cout << "Enter your choice: ";
        cin >> input;

        validInput = this->isValidInput(input);
        attemptInput = true;
    } while (!validInput);

    return input[0] - '0';
}

bool MainMenu::isValidInput(String& input) const
{
    if (input.length() != 1) {
        return false;
    }

    char choice = input[0];

    if (choice < '1' || choice > '5') {
        return false;
    }

    return true;
}

void MainMenu::exit()
{
    this->running = false;
}

