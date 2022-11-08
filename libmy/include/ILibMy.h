/*
 * Copyright (C) 2022 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#pragma once

#include <string>
#include <vector>

#ifdef __linux__
#define DLL_EXPORT
#else
#define DLL_EXPORT __declspec(dllexport)
#endif

namespace nkhlab {
namespace projectmy {

class DLL_EXPORT ILibMy
{
public:
    virtual ~ILibMy() = default;

    virtual int GetInt() = 0;
};

} // namespace projectmy
} // namespace nkhlab

#undef DLL_EXPORT