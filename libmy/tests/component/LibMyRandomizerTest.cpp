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
#include "UtilsMy.h"

using namespace nkhlab::projectmy;

int main(int argc, char const* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    int ret = EXIT_SUCCESS;

    ILibMyPtr_t lm = CreateLibMyRandomizer();

    int val1 = lm->GetInt();
    int val2 = lm->GetInt();
    std::cout << "GetInt() returned: " << val1 << "\n";
    std::cout << "GetInt() returned: " << val2 << "\n";

    std::cout << "Expected: " << val1 << " != " << val2 << "\n";
    std::cout << "Validation:        ";

    if (val1 != val2)
        std::cout << "PASSED\n";
    else
    {
        std::cout << "FAILED\n";
        ret = EXIT_FAILURE;
    }

    return ret;
}