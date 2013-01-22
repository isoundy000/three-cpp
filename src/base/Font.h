/**
 * Copyright (c) 2013 Daniel Wiberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include "base/Vector2.h"
#include "base/Color.h"

namespace three {

  // Forward declaration
  class Texture;
  class Geometry;

  class Font
  {
    public:
      struct Glyph
      {
        Vector2 topLeft;
        Vector2 bottomRight;
        Vector2 uvTopLeft;
        Vector2 uvBottomRight;
        float advance;
      };

    public:
      Font();

      float textLength(const char * str);
      void buildTextGeometry(const char * str, Vector2 const& offset, Geometry * geom, Color const& textColor);

    public:
      Texture * texture;
      Glyph glyphs[96];
  };

}

