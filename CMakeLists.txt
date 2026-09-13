cmake_minimum_required(VERSION 3.20)

project(krunnercurrency)

set(QT_MIN_VERSION "6.5.0")
set(KF6_MIN_VERSION "6.0.0")

find_package(ECM ${KF6_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
find_package(Qt6 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Widgets Network)
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS Runner I18n)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
