/**
 * @file
 * @author David Vitez (AKA: Robotic Forest)
 * @copyright All rights reserved © 2020 David Vitez
 *
 * @brief Program Entry Point
 * @details This is a test program for a number of tools that load and save Portable Pixmap files.
 */

#include <iostream>

#include "image.h"

int main() {
    std::cout << "Hello Portable Pixmap World!" << std::endl;

    DV::Image testImg;
    testImg.load("frame1.ppm");
    testImg.save("output.ppm");

}