cmake_minimum_required(VERSION 3.10)
project(Progra.2.datos.c-)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "/opt/qt/5.6/gcc_64/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5Xml REQUIRED)
set(SOURCE_FILES main.cpp server/Archive_manager.cpp server/Archive_manager.h Estructuras/BTree.cpp Estructuras/BTree.h Estructuras/BTreeNode.cpp Estructuras/BTreeNode.h Estructuras/BubbleSort.cpp Estructuras/BubbleSort.h Estructuras/Lista.h Estructuras/Nodo.h Estructuras/Quicksort.cpp Estructuras/Quicksort.h Estructuras/RadixSort.cpp Estructuras/RadixSort.h data/Cancion.cpp data/Cancion.h data/User.cpp data/User.h data/JsonFactory.cpp data/JsonFactory.h Estructuras/HashEntry.cpp Estructuras/HashEntry.h Estructuras/HashMap.cpp Estructuras/HashMap.h server/Server.cpp server/Server.h Estructuras/Binary_search_tree.cpp Estructuras/Binary_search_tree.h Estructuras/Node.cpp Estructuras/Node.h data/Data_parser.cpp data/Data_parser.h data/Data_Holder.cpp data/Data_Holder.h data/PruebasXML.cpp data/PruebasXML.h data/rapidxml_utils.hpp data/rapidxml_print.hpp data/rapidxml_iterators.hpp data/rapidxml.hpp server/XML_handler.cpp server/XML_handler.h data/XML_generator.cpp data/XML_generator.h Estructuras/ArbolB.cpp Estructuras/ArbolB.h Estructuras/BinarySearch.cpp Estructuras/BackTracking.cpp Estructuras/BackTracking.h Estructuras/BinarySearch.h Estructuras/AVL.cpp Estructuras/AVL.h data/base64.cpp data/base64.h server/OdysseyServer.cpp server/OdysseyServer.h server/Server_Holder.cpp server/Server_Holder.h server/Holder.cpp server/Holder.h data/Factory.cpp data/Factory.h data/frien.cpp data/frien.h)
add_executable(Progra.2.datos.c- ${SOURCE_FILES} main.cpp data/Factory.cpp data/Factory.h)
target_link_libraries(Progra.2.datos.c- json-c)
target_link_libraries(Progra.2.datos.c- Qt5::Widgets Qt5::Core Qt5::Network Qt5::Sql
        ${Boost_LIBRARIES})
target_link_libraries(Progra.2.datos.c- -lpthread)
