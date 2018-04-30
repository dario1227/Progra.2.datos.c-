//
// Created by kenneth on 4/30/18.
//

#include <iostream>
#include <sstream>
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