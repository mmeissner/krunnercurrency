add_definitions(-DTRANSLATION_DOMAIN=\"plasma_runner_org.kde.krunner_currency\")

add_library(krunner_currency MODULE)

target_sources(krunner_currency
    PRIVATE
        krunnercurrency.cpp
        currencyrepository.cpp
        fawazahmed0.cpp
)

set_target_properties(
    krunner_currency
    PROPERTIES AUTOMOC ON
)

find_package(Qt6Network REQUIRED)
target_link_libraries(krunner_currency KF6::Runner KF6::I18n Qt6::Network Qt6::Widgets)

install(TARGETS krunner_currency DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/krunner)
