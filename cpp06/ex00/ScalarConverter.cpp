#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace {

enum LiteralType {
    TYPE_INVALID,
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO_FLOAT,
    TYPE_PSEUDO_DOUBLE
};

bool isNan(double value) {
    return value != value;
}

bool isInf(double value) {
    return value == std::numeric_limits<double>::infinity()
        || value == -std::numeric_limits<double>::infinity();
}

bool hasExponent(const std::string &s) {
    return s.find('e') != std::string::npos || s.find('E') != std::string::npos;
}

bool isSign(char c) {
    return c == '+' || c == '-';
}

bool isPseudoFloat(const std::string &literal) {
    return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

bool isPseudoDouble(const std::string &literal) {
    return literal == "nan" || literal == "+inf" || literal == "-inf";
}

bool isCharLiteral(const std::string &literal) {
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))) {
        return true;
    }
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool isIntLiteral(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }

    std::size_t i = 0;
    if (isSign(literal[i])) {
        ++i;
    }
    if (i >= literal.length()) {
        return false;
    }

    for (; i < literal.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
            return false;
        }
    }
    return true;
}

bool isDecimalCore(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }

    std::size_t i = 0;
    if (isSign(literal[i])) {
        ++i;
    }
    if (i >= literal.length()) {
        return false;
    }

    bool hasDigit = false;
    bool hasDot = false;
    for (; i < literal.length(); ++i) {
        char c = literal[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
            continue;
        }
        if (c == '.' && !hasDot) {
            hasDot = true;
            continue;
        }
        return false;
    }
    return hasDigit && hasDot;
}

bool isFloatLiteral(const std::string &literal) {
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f') {
        return false;
    }
    return isDecimalCore(literal.substr(0, literal.length() - 1));
}

bool isDoubleLiteral(const std::string &literal) {
    if (literal.empty() || hasExponent(literal)) {
        return false;
    }
    return isDecimalCore(literal);
}

LiteralType detectType(const std::string &literal) {
    if (isPseudoFloat(literal)) {
        return TYPE_PSEUDO_FLOAT;
    }
    if (isPseudoDouble(literal)) {
        return TYPE_PSEUDO_DOUBLE;
    }
    if (isCharLiteral(literal)) {
        return TYPE_CHAR;
    }
    if (isIntLiteral(literal)) {
        return TYPE_INT;
    }
    if (isFloatLiteral(literal)) {
        return TYPE_FLOAT;
    }
    if (isDoubleLiteral(literal)) {
        return TYPE_DOUBLE;
    }
    return TYPE_INVALID;
}

bool parseDouble(const std::string &literal, double &out) {
    char *end = NULL;
    errno = 0;
    out = std::strtod(literal.c_str(), &end);
    if (errno == ERANGE || end == literal.c_str() || *end != '\0') {
        return false;
    }
    return true;
}

bool parseInt(const std::string &literal, double &out) {
    char *end = NULL;
    errno = 0;
    long value = std::strtol(literal.c_str(), &end, 10);
    if (errno == ERANGE || end == literal.c_str() || *end != '\0') {
        return false;
    }
    if (value < INT_MIN || value > INT_MAX) {
        return false;
    }
    out = static_cast<double>(value);
    return true;
}

bool parseFloat(const std::string &literal, double &out) {
    std::string core = literal.substr(0, literal.length() - 1);
    return parseDouble(core, out);
}

double pseudoToDouble(const std::string &literal) {
    if (literal == "nan" || literal == "nanf") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (literal == "+inf" || literal == "+inff") {
        return std::numeric_limits<double>::infinity();
    }
    return -std::numeric_limits<double>::infinity();
}

std::string formatFloat(float value) {
    if (isNan(static_cast<double>(value))) {
        return "nanf";
    }
    if (value == std::numeric_limits<float>::infinity()) {
        return "+inff";
    }
    if (value == -std::numeric_limits<float>::infinity()) {
        return "-inff";
    }

    std::ostringstream oss;
    oss << std::setprecision(std::numeric_limits<float>::digits10) << value;
    std::string out = oss.str();
    if (out.find('.') == std::string::npos && !hasExponent(out)) {
        out += ".0";
    }
    out += 'f';
    return out;
}

std::string formatDouble(double value) {
    if (isNan(value)) {
        return "nan";
    }
    if (value == std::numeric_limits<double>::infinity()) {
        return "+inf";
    }
    if (value == -std::numeric_limits<double>::infinity()) {
        return "-inf";
    }

    std::ostringstream oss;
    oss << std::setprecision(std::numeric_limits<double>::digits10) << value;
    std::string out = oss.str();
    if (out.find('.') == std::string::npos && !hasExponent(out)) {
        out += ".0";
    }
    return out;
}

void printImpossibleAll(void) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void printChar(double value) {
    std::cout << "char: ";
    if (isNan(value) || isInf(value) || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (!std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "Non displayable" << std::endl;
        return;
    }
    std::cout << "'" << c << "'" << std::endl;
}

void printInt(double value) {
    std::cout << "int: ";
    if (isNan(value) || isInf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(value) << std::endl;
}

void printFloat(double value) {
    std::cout << "float: ";
    if (!isNan(value) && !isInf(value) && (value > FLT_MAX || value < -FLT_MAX)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << formatFloat(static_cast<float>(value)) << std::endl;
}

void printDouble(double value) {
    std::cout << "double: " << formatDouble(value) << std::endl;
}

} // namespace

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string &literal) {
    LiteralType type = detectType(literal);
    double value = 0.0;
    bool ok = true;

    switch (type) {
        case TYPE_CHAR:
            if (literal.length() == 3) {
                value = static_cast<double>(literal[1]);
            } else {
                value = static_cast<double>(literal[0]);
            }
            break;
        case TYPE_INT:
            ok = parseInt(literal, value);
            break;
        case TYPE_FLOAT:
            ok = parseFloat(literal, value);
            break;
        case TYPE_DOUBLE:
            ok = parseDouble(literal, value);
            break;
        case TYPE_PSEUDO_FLOAT:
        case TYPE_PSEUDO_DOUBLE:
            value = pseudoToDouble(literal);
            break;
        case TYPE_INVALID:
            ok = false;
            break;
    }

    if (!ok) {
        printImpossibleAll();
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
