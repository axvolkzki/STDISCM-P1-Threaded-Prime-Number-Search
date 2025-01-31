#include "MainMenu.h"  



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

void MainMenu::startApp()
{
    int variant = 0;

    this->showMenu();
    variant = this->validateInput();

    switch (variant) {
    case '1':
        cout << "Choice 1" << endl;
        break;
    case '2':
        cout << "Choice 2" << endl;
        break;
    case '3':
        cout << "Choice 3" << endl;
        break;
    case '4':
        cout << "Choice 4" << endl;
        break;
    default:
        cout << "Exiting..." << endl;
        this->exitApp();
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

    return input[0];
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

void MainMenu::exitApp()
{
    this->running = false;
}

