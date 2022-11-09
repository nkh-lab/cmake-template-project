@rem
@rem Copyright (C) 2022 https://github.com/nkh-lab
@rem
@rem This is free software. You can redistribute it and/or
@rem modify it under the terms of the GNU General Public License
@rem version 3 as published by the Free Software Foundation.
@rem
@rem This software is distributed in the hope that it will be useful,
@rem but WITHOUT ANY WARRANTY.
@rem 

@rem Usage:
@rem Script input arguments: 
@rem   '-z' - no need to archive a package
@rem

@echo off

SET ZIP=1

FOR %%A IN (%*) DO (
    IF "%%A"=="-z" SET ZIP=0
)

SET DIR=%~dp0
cd %DIR\..
SET PROJECT_ROOT=%cd%
SET PORTABLE_DIR_REL_PATH="build\portable"
SET PORTABLE_ARCHIVE_NAME="projectmy-portable"

rd /s /q build\ 2>nul
mkdir build && cd build

cmake -G "Visual Studio 17 2022" .. 
cmake --build . --config Release

cd %PROJECT_ROOT%

mkdir %PORTABLE_DIR_REL_PATH%

copy build\appmy\Release\appmy.exe %PORTABLE_DIR_REL_PATH%
copy build\libmy\Release\libmy.dll %PORTABLE_DIR_REL_PATH%

cd %PORTABLE_DIR_REL_PATH%

IF %ZIP%==1 tar -czf ../%PORTABLE_ARCHIVE_NAME%.tar.gz *