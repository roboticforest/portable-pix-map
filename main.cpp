/**
 * @file
 * @author David Vitez (AKA: Robotic Forest)
 * @copyright All rights reserved © 2020 David Vitez
 *
 * @brief Program Entry Point
 * @details This is a test program for a number of tools that load and save Portable Pixmap files.
 */

#include <iostream>
#include <fstream>

#include "image.h"

int main() {
    std::cout << "Hello Portable Pixmap World!" << std::endl;

    std::ifstream vidFrame("frame1.ppm");

    DV::Image testImg;
    testImg.load(vidFrame);

}