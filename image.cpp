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
    bool Image::load(const char* filename) {
        std::ifstream file;
        std::string input;
        std::istringstream buffer;

        file.open(filename, std::ifstream::binary);

        if (file.is_open()) {

            // Find the file size.
            file.seekg(0, std::ifstream::end);  // seekg() is not well documented. Relative move from start to end.
            long bytesRemaining = file.tellg(); // Getting the size of the file in bytes (pos at end of file).
            file.seekg(0, std::ifstream::beg);  // **really** make sure we're at the start.

            // Read the magic number for binary 24bit color PPM files.
            getline(file, input);
            if (input != "P6") { return false; }
            bytesRemaining -= 3;

            // Read the width and height (in that order).
            getline(file, input);
            buffer.str(input);
            bytesRemaining -= (input.length() + 1);
            buffer >> _width;
            buffer >> _height;

            // Read the max color value possible.
            getline(file, input);
            if (input != "255") { return false; }
            bytesRemaining -= 4;

            // Read all of the pixels.
            // TODO: Don't assume there are no comments in the file.
            _pixels = new signed char[_width * _height * 3];
            char rawPixel[3] = {0};
            long i = 0;
            while (bytesRemaining > 0) {
                file.read(rawPixel, 3);
                bytesRemaining -= 3;
                _pixels[i + 0] = rawPixel[0];
                _pixels[i + 1] = rawPixel[1];
                _pixels[i + 2] = rawPixel[2];
                i += 3;
            }
            return true;
        }
        return false;
    }

    bool Image::save(const char* filename) {
        std::ofstream file;
        file.open(filename, std::ofstream::binary);

        if (file.is_open()) {
            file << "P6" << '\n';
            file << _width << ' ' << _height << '\n';
            file << "255" << '\n';
            for (long i = 0; i < _width * _height * 3; ++i) {
                file.put(_pixels[i]);
            }
        }

        return false;
    }

} // namespace DV