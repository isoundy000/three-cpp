/**
 * Copyright (c) 2012 Daniel Wiberg
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

#include "base/BackendMaterial.h"

namespace three {

  class GLMaterial : public BackendMaterial
  {
    public:
      GLMaterial(uint32_t uniformCount);
      virtual ~GLMaterial();

      void uniform(uint32_t id, float value);
      void uniform(uint32_t id, Vector3 const& value);
      void uniform(uint32_t id, Vector4 const& value);
      void uniform(uint32_t id, Color const& value);

    public:
      uint32_t program;
      int32_t * uniforms;
      uint32_t uniformCount;

      int32_t objectMatrix;
      int32_t modelViewMatrix;
      int32_t projectionMatrix;
      int32_t viewMatrix;
      int32_t normalMatrix;
      int32_t cameraPosition;
  };

}

