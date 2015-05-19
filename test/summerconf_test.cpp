/* Copyright (C) 
 * 2015 - Aleda(aledalee@foxmail.com | aleda.cn)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */
/**
 * @file summerconf_test.cpp
 * @brief summerconf_test
 * @author Aleda(aledalee@foxmail.com | aleda.cn)
 * @version 1.0.0
 * @date 2015-04-26
 */

#include <iostream>
#include <vector>

#include "config.h"
#include "section.h"

int main(int argc, char* argv[])
{
    summerconf::Config conf("./test.conf");
    //summerconf::Config conf("../../summer-se/conf/crawler.conf");
    conf.read();
    std::cout << "conf[main][name] = " << conf["main"]["name"]->string_value() << std::endl;
    int age = conf["main"]["age"]->int_value();
    std::cout << "conf[main][age] = " << age << std::endl;
    summerconf::Section section_crawler = conf["crawler"];
    std::cout << "conf[crawler].section_name = " << section_crawler.get_section_name() << std::endl;
    std::cout << "conf[crawler][author] = " << conf["crawler"]["author"]->string_value() << std::endl;
    std::cout << "conf[main][nickname] = " << conf["crawler"]["nickname"]->string_value() << std::endl;
    return 0;
    // TEST: conf_file
    // ***************************************************************//
    std::string conf_file = conf.get_conf_file();
    std::cout << "conf_file = " << conf_file << std::endl;

    summerconf::Section _section = conf["main"];
    std::cout << "_section_name = " << _section.get_section_name() << std::endl;
    std::map<std::string, summerconf::Value*> _item_map = _section.get_item_map();
    std::map<std::string, summerconf::Value*>::iterator _it_map;
    for (_it_map = _item_map.begin(); _it_map != _item_map.end(); ++_it_map) {
        std::cout << "key = " << _it_map->first << std::endl;
        std::cout << "value(string) = " << _it_map->second->string_value() << std::endl;
    }
    const summerconf::Value* _val = _section["name"];
    std::cout << "_val = " << _val->string_value() << std::endl;

    std::cout << "_section[\"name\"] = " << _section["name"]->string_value() << std::endl;
    std::cout << "conf[main][name] = " << conf["main"]["name"]->string_value() << std::endl;


    // ***************************************************************//

    // TEST  : Value
    // ***************************************************************//
    // STATUS: PASS
    summerconf::Value val = summerconf::Value("123");
    int num_val = val.int_value();
    std::cout << "num_val   = " << num_val << std::endl;

    std::string string_value = summerconf::Value("aleda").string_value();
    std::cout << "string_value = " << string_value << std::endl;

    std::vector<std::string> string_list = summerconf::Value("1,2,3,4").string_value_list();
    std::vector<std::string>::iterator it;
    for (it = string_list.begin(); it != string_list.end(); ++it) {
        std::cout << "__data = " << *it << std::endl;
    }
    // ***************************************************************//

    // TEST  : Section
    // ***************************************************************//
    // STATUS: PASS
    std::vector<summerconf::Section*> section_list = conf.get_section_list();
    std::vector<summerconf::Section*>::iterator it2;
    for (it2 = section_list.begin(); it2 != section_list.end(); ++it2) {
        std::string section_name = (*it2)->get_section_name();
        std::cout << "section_name = " << section_name << std::endl;
        std::map<std::string, summerconf::Value*> item_map = (*it2)->get_item_map();
        std::map<std::string, summerconf::Value*>::iterator it3;
        for (it3 = item_map.begin(); it3 != item_map.end(); ++it3) {
            std::cout << "key = " << it3->first << std::endl;
            std::cout << "value = " << it3->second->string_value() << std::endl;
        }
    }
    // ***************************************************************//
    return 0;
}

