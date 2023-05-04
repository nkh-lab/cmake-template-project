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

#include "ConfigMy.h"
#include "IntPairMaker.h"
#include "LibMy.h"
#include "UtilsMy.h"

using namespace nkhlab::projectmy;

int main(int argc, char const* argv[])
{
    UNUSED(argc);

    int ret = EXIT_SUCCESS;

    std::cout << "Hello World from " << argv[0] << ", v" << kProjectVer << "!\n";
    std::cout << "Git commit: " << kProjectGitCommit << "\n";
#ifdef MY_DEFINE
    std::cout << MY_DEFINE << "\n";
#endif

    std::cout << "\n";

    if (argc == 2)
    {
        std::cout << "Integer pairs:\n";

        size_t pairs_number = std::stoi(argv[1]);

        IntPairMaker pair_maker(CreateLibMyCounter(), CreateLibMyRandomizer());

        for (size_t i = 0; i < pairs_number; ++i)
        {
            auto p = pair_maker.GetPair();

            std::cout << p.first << " " << p.second << "\n";
        }
    }
    else
    {
        std::cout << "Wrong usage!\n";
        std::cout << "Specify the number of integer pairs to generate:\n";
        std::cout << argv[0] << " <number of integer pairs>\n";
        ret = EXIT_FAILURE;
    }

    return ret;
}
