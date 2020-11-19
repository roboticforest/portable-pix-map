/**
 * @file
 * @author David Vitez (AKA: Robotic Forest)
 * @copyright All rights reserved © 2020 David Vitez
 *
 * @brief A simple image class.
 * @details This is a small utility class for holding image data.
 */

#ifndef DV_PPM_IMAGE_H
#define DV_PPM_IMAGE_H

#include <fstream>

namespace DV {
    class Image {
      public:
        Image();
        ~Image();

        bool load(const char* filename);
        bool save(const char* filename);

      // private:  // TODO: Make these members private again!
        signed char* _pixels;
        unsigned int _width;
        unsigned int _height;
    };
}

#endif // DV_PPM_IMAGE_H
