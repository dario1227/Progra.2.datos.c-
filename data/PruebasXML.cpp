//
// Created by kenneth on 4/30/18.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "PruebasXML.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

void PruebasXML::prueba() {
    using namespace rapidxml;

    xml_document<> doc;
// xml declaration
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

// root node
    xml_node<>* root = doc.allocate_node(node_element, "rootnode");
    root->append_attribute(doc.allocate_attribute("version", "1.0"));
    root->append_attribute(doc.allocate_attribute("type", "example"));
    doc.append_node(root);

// child node
    xml_node<>* child = doc.allocate_node(node_element, "childnode");
    root->append_node(child);

    std::string xml_as_string;
// watch for name collisions here, print() is a very common function name!
    print(std::back_inserter(xml_as_string), doc);
// xml_as_string now contains the XML in string form, indented
// (in all its angle bracket glory)

    std::string xml_no_indent;
// print_no_indenting is the only flag that print() knows about
    std::stringstream ss;
    ss <<doc;
    std::string result_xml = ss.str();
    std::cout <<result_xml<<std::endl;
}
using namespace std;
using namespace rapidxml;
void PruebasXML::prueba2() {
    cout << "Parsing my beer journal..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile ("/home/kenneth/CLionProjects/Progra.2.datos.c-/data/LOL.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("MyBeerJournal");
    // Iterate over the brewery
    std::stringstream ss;
    ss <<doc;
    std::string result_xml = ss.str();
    std::cout <<result_xml<<std::endl;
    for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
    {
        printf("I have visited %s in %s. ",
               brewery_node->first_attribute("name")->value(),
               brewery_node->first_attribute("location")->value());
        // Interate over the beers
        for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
        {
            printf("On %s, I tried their %s which is a %s. ",
                   beer_node->first_attribute("dateSampled")->value(),
                   beer_node->first_attribute("name")->value(),
                   beer_node->first_attribute("description")->value());
            printf("I gave it the following review: %s", beer_node->value());
        }
        cout << endl;
    }
}