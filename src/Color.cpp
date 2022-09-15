//
// Created by jaden on 8/31/2022.
//

#include "Color.h"
#include <random>
#include <iostream>

// Generates a random color with random alpha
void Color::getRandomColor() {
    int red = rand() % 255;
    int blue = rand() % 255;
    int green = rand() % 255;
    int alpha = rand() % 255;
    std::vector<int> rgba = {red, blue, green, alpha};

    this->rgba = rgba;
}

// Generates a random color with passed alpha.
void Color::getRandomColor(int alpha) {
    int red = rand() % 255;
    int blue = rand() % 255;
    int green = rand() % 255;
    std::vector<int> rgba = {red, blue, green, alpha};

    this->rgba = rgba;
}

// Defines a Color with no param as a random color.
Color::Color() {
    getRandomColor();
}

// Defines a Color with a alpha param as a random color with that alpha.
Color::Color(int alpha) {
    getRandomColor(alpha);
}

// Defines a color with the inputted red, green, blue values and defaults alpha to 255;
Color::Color(int red, int green, int blue) {
    std::vector<int> temp = {red, blue, green, 255};
    rgba = temp;
}

// Defines a color with the inputted red, green, blue, and alpha values
Color::Color(int red, int green, int blue, int alpha) {
    std::vector<int> temp = {red, blue, green, alpha};
    rgba = temp;
}

// Defines a color as an int vector of size 4
Color::Color(std::vector<int> rgba) {
    if (rgba.size() > 4) throw std::range_error(("Invalid rgba vector size"));
    this->rgba = rgba;
}

// Redefines a color with the inputted red, green, blue values and defaults alpha to 255;
void Color::set(int red, int green, int blue) {
    std::vector<int> temp = {red, blue, green, 1};
    rgba = temp;
}

// Redefines a color with the inputted red, green, blue, and alpha values
void Color::set(int red, int green, int blue, int alpha) {
    std::vector<int> temp = {red, blue, green, alpha};
    rgba = temp;
}

// Redefines a color as an int vector of size 4
void Color::set(std::vector<int> rgba) {
    if (rgba.size() > 4) throw std::range_error(("Invalid rgba vector size"));
    this->rgba = rgba;
}

// Returns the value of Red
int Color::getRed() {
    return rgba[0];
}

// Returns the value of Green
int Color::getGreen() {
    return rgba[1];
}

// Returns the value of Blue
int Color::getBlue() {
    return rgba[2];
}

// Returns the value of Alpha
int Color::getAlpha() {
    return rgba[3];
}

// Returns the rgba vector
std::vector<int> Color::getRGBA() {
    return rgba;
}

// Deletes Color
Color::~Color() {
    rgba.clear();
}


