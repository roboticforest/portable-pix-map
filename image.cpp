//
// Created by david on 11/11/20.
//

#include "image.h"

#include <string>
#include <iostream>
#include <sstream>

namespace DV {

    Image::Image() : _width(0), _height(0), _pixels(nullptr) {}

    Image::~Image() { delete[] _pixels; }

    // This method is crazy unsafe.
    // TODO: Make Image::load() safe and sane, and not so much like a quick script.
    // TODO: Make Image::load() handle comments.
    bool Image::load(std::ifstream & file) {
        std::string input;
        std::istringstream buffer;

        if (file.is_open()) {

            // Read the magic number for binary 24bit color PPM files.
            getline(file, input);
            if (input != "P6") { return false; }

            // Read the width and height (in that order).
            getline(file, input);
            buffer.str(input);
            buffer >> _width;
            buffer >> _height;

            // Read the max color value possible.
            getline(file, input);
            if (input != "255") { return false; }

            // Start reading pixels...
            _pixels = new unsigned int[_width * _height];
            char rawPixel[3] = {0};
            file.read(rawPixel,3);
            if (file.gcount() == 3 && file.good()){
                _pixels[0] = ((unsigned int)rawPixel[0] << 16) + ((unsigned int)rawPixel[1] << 8) + rawPixel[2];
            }
        }
        return false;
    }

} // namespace DV