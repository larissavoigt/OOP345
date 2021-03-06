// Milestone 1 - Utilities Interface
// Utilities.cpp
// Larissa Voigt

#include "Utilities.h"
#include <iostream>

char Utilities::delimiter = '|';

Utilities::Utilities(size_t minimum_field_width) : field_width(minimum_field_width) {
}

void Utilities::setFieldWidth(size_t w) {
    field_width = w;
}

size_t Utilities::getFieldWidth() const {
    return field_width;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& ok) {
    std::string token = "";

    while (str.size() != next_pos && str[next_pos] != delimiter) {
        token += str[next_pos];
        next_pos++;
    }

    if (str.size() == next_pos) {
        ok = false;
    } else {
        ok = true;
        next_pos++;
    }

    size_t p = token.find_first_not_of(" \t\r\n");
    token.erase(0, p);

    p = token.find_last_not_of(" \t\r\n");
    if (std::string::npos != p) {
        token.erase(p+1);
    }

    if (field_width < token.size()) {
        field_width = token.size();
    }

    return token;
}

void Utilities::setDelimiter(const char c) {
    delimiter = c;
}

const char Utilities::getDelimiter() {
    return delimiter;
}
