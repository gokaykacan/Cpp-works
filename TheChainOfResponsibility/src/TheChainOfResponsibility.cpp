//============================================================================
// Name        : TheChainOfResponsibility.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//
//  main.cpp
//  chain-of-responsibility
//
//

#include <iostream>
#include <vector>
#include <regex>

class StringValidator {
public:
    virtual StringValidator *setNext(StringValidator *nextValidator) = 0;
    virtual ~StringValidator() {};
    virtual std::string validate(std::string) = 0;
};

class BaseValidator : public StringValidator {
protected:
    StringValidator *next = nullptr;
public:
    ~BaseValidator() { delete next; };
    StringValidator *setNext(StringValidator *nextValidator) override {
        next = nextValidator;
        return nextValidator;
    }
    virtual std::string validate(std::string testString) override {
        if (this->next) {
            return this->next->validate(testString);
        }
        return "Success!";
    }
};

class NotEmptyValidator: public BaseValidator {
public:
    std::string validate(std::string testString) override {
        std::cout << "Checking if empty...\n";

        if (testString.empty()) {
            return "Error! Please enter a value";
        }

        return BaseValidator::validate(testString);
    }
};

class LengthValidator: public BaseValidator {
    unsigned int minLength;
public:
    LengthValidator(int minLength) : minLength(minLength) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if length equals " << minLength << "...\n";

        if (testString.length() < minLength) {
            return "Error! Please enter a value longer than " + std::to_string(minLength);
        }

        return BaseValidator::validate(testString);
    }
};

class RegexValidator: public BaseValidator {
    std::string patternName;
    std::string regexString;
public:
    RegexValidator(std::string patternName, std::string regexString)
    : patternName(patternName), regexString(regexString) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if string is a valid " << patternName << "...\n";

        if (!std::regex_match(testString, std::regex(regexString))) {
            return "The value entered is not a valid " + patternName;
        }

        return BaseValidator::validate(testString);
    }
};

bool in_vector(const std::string &value, const std::vector<std::string> &v) {
    return std::find(v.begin(), v.end(), value) != v.end();
}

class HistoryValidator: public BaseValidator {
    std::vector<std::string> historyItems;
public:
    HistoryValidator(std::vector<std::string> historyItems) : historyItems(historyItems) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if string is in history...\n";

        if (in_vector(testString, historyItems)) {
            return "Error Please enter a value that you haven't entered before";
        }

        return BaseValidator::validate(testString);
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::string> oldPasswords = { "abc123", "123456", "hello" };

    BaseValidator *emailValidator = new BaseValidator;

    emailValidator->setNext(new NotEmptyValidator)->setNext(new LengthValidator(6))->setNext(new HistoryValidator(oldPasswords));

        std::cout << "Checking Password ---------------\n";
        std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
        std::cout << "Input: 12345\n" << emailValidator->validate("12345") << "\n\n";
        std::cout << "Input: 123456\n" << emailValidator->validate("123456") << "\n\n";
        std::cout << "Input: 1234567\n" << emailValidator->validate("1234567") << "\n\n";

    delete emailValidator;

    return 0;
}
