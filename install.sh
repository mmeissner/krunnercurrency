#!/bin/bash

set -e

rm -rf build
mkdir -p build
cd build

cmake -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)

sudo make install

kquitapp6 krunner 2>/dev/null || kquitapp5 krunner 2>/dev/null || true
