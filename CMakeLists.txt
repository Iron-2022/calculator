cmake_minimum_required(VERSION 3.14)

project(QmlApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем пакет Quick
find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

# Определяем компилируемые файлы
qt_add_executable(QmlApp
  main.cpp
)

qt_add_resources(QmlApp_RESOURCES
    PREFIX "/new/prefix1"
    FILES
        res.qrc  # Убедитесь, что файл существует в папке проекта!
)

# Добавляем файлы qml
qt_add_qml_module(QmlApp
    URI path      # ссылка, по которой будут загружаться файлы qml
    VERSION 1.0
    QML_FILES main.qml
    SOURCES counter.h counter.cpp
    SOURCES
    SOURCES historymodel.h historymodel.cpp
    RESOURCES res.qrc
)

target_link_libraries(QmlApp
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS QmlApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
