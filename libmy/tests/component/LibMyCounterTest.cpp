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

#include <iostream>

#include "LibMy.h"

using namespace nkhlab::projectmy;

int main(int argc, char const* argv[])
{
    int ret = EXIT_SUCCESS;

    if (argc == 2)
    {
        size_t calls_number = std::stoi(argv[1]);

        ILibMyPtr_t lm = CreateLibMyCounter();

        int val{};

        for (size_t i = 0; i < calls_number; ++i)
        {
            val = lm->GetInt();

            std::cout << "GetInt() returned: " << val << "\n";
        }
        std::cout << "Expected Value: " << calls_number << "\n";
        std::cout << "Obtained Value: " << val << "\n";
        std::cout << "Validation:        ";

        if (val == static_cast<int>(calls_number))
            std::cout << "PASSED\n";
        else
        {
            std::cout << "FAILED\n";
            ret = EXIT_FAILURE;
        }
    }
    else
    {
        std::cout << "Wrong usage!\n";
        std::cout << "Specify the number of GetInt() calls:\n";
        std::cout << argv[0] << " <number of GetInt() calls>\n";
        ret = EXIT_FAILURE;
    }

    return ret;
}