/**
 * @file
 * @author David Vitez (AKA: Robotic Forest)
 * @copyright All rights reserved © 2020 David Vitez
 *
 * @brief Program Entry Point
 * @details This is a test program for a number of tools that load and save Portable Pixmap files.
 */

#include <iostream>
#include <algorithm>

#include "image.h"

int main() {
    std::cout << "Hello Portable Pixmap World!" << std::endl;

    DV::Image testImg;
    testImg.load("frame1.ppm");

    // Extract the red components.
    char reds[testImg._width * testImg._height];
    char greens[testImg._width * testImg._height];
    char blues[testImg._width * testImg._height];
    for (int y = 0; y < testImg._height; ++y) {
        for (int x = 0; x < testImg._width; ++x) {
            reds[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 0];
            greens[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 1];
            blues[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 2];
        }
    }

    // Sort each row of pixels.
    for (int y = 0; y < testImg._height; ++y) {
        std::sort(reds + (y * testImg._width), reds + ((y * testImg._width) + testImg._width));
        std::sort(greens + (y * testImg._width), greens + ((y * testImg._width) + testImg._width));
        std::sort(blues + (y * testImg._width), blues + ((y * testImg._width) + testImg._width));
    }

    // Reconstruct the image
    for (int y = 0; y < testImg._height; ++y) {
        for (int x = 0; x < testImg._width; ++x) {
            testImg._pixels[(x * 3) + (testImg._width * y * 3)] = reds[x + (testImg._width * y)];
            testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 1] = greens[x + (testImg._width * y)];
            testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 2] = blues[x + (testImg._width * y)];
        }
    }




// ATTEMPT TWO
//    // Extract the red components.
//    char reds[testImg._width * testImg._height];
//    char greens[testImg._width * testImg._height];
//    char blues[testImg._width * testImg._height];
//    for (int y = 0; y < testImg._height; ++y) {
//        for (int x = 0; x < testImg._width; ++x) {
//            reds[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 0];
//            greens[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 1];
//            blues[x + (testImg._width * y)] = testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 2];
//        }
//    }
//
//    std::sort(reds, reds + (testImg._width * testImg._height));
//    std::sort(greens, greens + (testImg._width * testImg._height));
//    std::sort(blues, blues + (testImg._width * testImg._height));
//
//    // Reconstruct the image
//    for (int y = 0; y < testImg._height; ++y) {
//        for (int x = 0; x < testImg._width; ++x) {
//            testImg._pixels[(x * 3) + (testImg._width * y * 3)] = reds[x + (testImg._width * y)];
//            testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 1] = greens[x + (testImg._width * y)];
//            testImg._pixels[((x * 3) + (testImg._width * y * 3)) + 2] = blues[x + (testImg._width * y)];
//        }
//    }


// ATTEMPT ONE
// This sorts every byte of the image, and looks too boring.
// std::sort(testImg._pixels, testImg._pixels + (testImg._width * testImg._height * 3));

    testImg.save("output.ppm");

}