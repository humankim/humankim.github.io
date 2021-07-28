---
layout: post
title: "package of testsw-common"
subtitle: "package of testsw-common"
categories: etc
tags: devtest 
---

#### Packaging of testsw-common
- 목적 : yocto 기반 환경을 cmake로만 빌드하여 ubuntu linux에서 동작시키기 위함
- 대상 : testsw-common (audi one info testsw project)

1. mkdir ext  ("under files directory")

2. cmake (latest version due to compatibility with log4cplus)
    (cd ~)
    (wget https://github.com/Kitware/CMake/releases/download/v3.21.0/cmake-3.21.0.tar.gz and Extract it)
    (./bootstrap --prefix=../ext/cmake)
    (make)
    (make install)
    (Check ~/cmake/bin and using its cmake)
    (Edit .bashrc)
    ```
    alias cmake='~/cmake/bin/cmake'
    ```

3. Downlaod googletest and copy it
    (ext/googletest-release-1.7.0)
    (cmake CMakeListst.txt)
    (make)

4. log4cplus
    (cd ext)
    (git clone  https://github.com/log4cplus/log4cplus.git  --recursive)
    (cmake CMakeLists.txt)
    (make)

5. jsoncpp
   (cd ext)
   (git clone https://github.com/open-source-parsers/jsoncpp.git -b 0.y.z)
   (cd jsoncpp)
   (mkdir -p build/debug)
   (cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=ON -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../..)
   (make)
   (find . -name *.a && find . -name *.so)

6. Edit files/CMakeLists.txt
```
    add_subdirectory(ext/googletest-release-1.7.0)
    add_subdirectory(ext/log4cplus-2.0.6)
    add_subdirectory(ext/jsoncpp)

    include_directories(
      include
      ext/jsoncpp/include
      ext/log4cplus-2.0.6/include
      ext/googletest-release-1.7.0/include
    )

    \#set(LIBS jsoncpp log4cplus)
```