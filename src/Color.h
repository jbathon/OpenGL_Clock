//
// Created by jaden on 8/31/2022.
//

#ifndef OPENGL_BRESENHAM_LINE_ALGORITHM_COLOR_H
#define OPENGL_BRESENHAM_LINE_ALGORITHM_COLOR_H


#include <vector>

class Color {

private:
    std::vector<int> rgba;

    void getRandomColor();

    void getRandomColor(int alpha);

public:

    Color();

    Color(int alpha);

    Color(int red, int green, int blue);

    Color(int red, int green, int blue, int alpha);

    Color(std::vector<int> rgba);

    void set(int red, int green, int blue);

    void set(int red, int green, int blue, int alpha);

    void set(std::vector<int> rgba);

    int getRed();

    int getGreen();

    int getBlue();

    int getAlpha();

    std::vector<int> getRGBA();

    ~Color();
};

#endif //OPENGL_BRESENHAM_LINE_ALGORITHM_COLOR_H
