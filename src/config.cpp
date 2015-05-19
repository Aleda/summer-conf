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
 * @file config.cpp
 * @brief config
 * @author Aleda(aledalee@foxmail.com | aleda.cn)
 * @version 1.0.0
 * @date 2015-04-26
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "config.h"
#include "value.h"

namespace summerconf {

Config::~Config()
{
    //TODO 
    //erase the section_list;
    std::vector<Section*>::iterator it;
    for (it = section_list.begin(); it != section_list.end(); ++it) {
        std::map<std::string, Value*> _item_map = (**it).get_item_map();
        std::map<std::string, Value*>::iterator it_map;
        for (it_map = _item_map.begin(); it_map != _item_map.end(); ++it_map) {
            if (it_map->second != NULL) {  
                delete it_map->second;
                it_map->second = NULL;
            }
        }
        if (*it != NULL) {
            delete *it;
            *it = NULL;
        }
    }
}

bool Config::read()
{
    std::string line;
    std::ifstream ifs(conf_file.c_str());
    if (ifs) {
        while (getline(ifs, line)) {
            data.push_back(line);
        }
        ifs.close();
        return parse();
    } else {
        return false;
    }
}

bool Config::parse() {
    Iterator it(data);
    std::string old_section = it.get_section();
    std::map<std::string, Value*> item_map;
    item_map.clear();
    std::string section;
    while (it.loop()) {
        section = it.get_section();
        std::string key     = it.get_key();
        std::string value   = it.get_value();
        if (old_section.compare(section) != 0 &&
            old_section.compare("") != 0) {
            item_map["__NOT_FOUND__"] = new Value("__NOT_FOUND__");
            Section* obj_section = new Section(old_section, item_map);
            section_list.push_back(obj_section);
            item_map.clear();
        }
        if (judge(section, key, value)) {
            // yinyong is ok????
            // I am not sure!
            item_map[key] = new Value(value);
        }
        old_section = section;
        ++it;
    }
    if (old_section.compare("") != 0) {
        Section* obj_section = new Section(section, item_map);
        section_list.push_back(obj_section);
    }
    // Added strategy: if not have section, return NULL
    item_map.clear();
    item_map["__NOT_FOUND__"] = new Value("__NOT_FOUND__");
    section = "__INTER_MARK__";
    Section* obj_section = new Section(section, item_map);
    section_list.push_back(obj_section);
    return true;
}

bool Config::judge(const std::string& section,
                   const std::string& key,
                   const std::string& value)
{
    if (section.compare("") == 0) {
        return false;
    } else {
        if (key.compare("") == 0) {
            return false;
        }
    }
    return true;
}

Section& Config::operator[](const std::string& key)
{
    std::vector<Section*>::iterator it;
    std::vector<Section*>::iterator it_not_found;
    for (it = section_list.begin(); it != section_list.end(); ++it) {
        if ((*it)->get_section_name().compare(key) == 0) {
            return **it;
        }
        if ((*it)->get_section_name().compare("__INTER_MARK__") == 0) {
            it_not_found = it;
        }
    }
    return **it_not_found;
}

Config::Iterator::Iterator(const std::vector<std::string>& data)
{
    this->data = data;
    index = this->data.begin();
    size  = this->data.end();
    section = "";
}

std::string Config::Iterator::get_key()
{
    if (!Config::Iterator::judge()) {
        return std::string("");
    }
    //TODO
    //THIS SHOULD REPLACE space & tab;
    std::string normal_str = (*index);
    erase(normal_str, " ");
    erase(normal_str, "\t");
    std::size_t pos = normal_str.find("=");
    if (std::string::npos != pos) {
        return normal_str.substr(0, pos);
    } else {
        return std::string("");
    }
}

std::string Config::Iterator::get_value()
{
    if (!Config::Iterator::judge()) {
        return std::string("");
    }
    //THIS SHOULD REPLACE space & tab;
    std::string normal_str = (*index);
    erase(normal_str, " ");
    erase(normal_str, "\t");
    std::size_t pos = normal_str.find("=");
    if (std::string::npos != pos) {
        return normal_str.substr(pos + 1);
    } else {
        return std::string("");
    }

}

bool Config::Iterator::parse()
{
    if (index == size) {
        return false;
    }
    std::size_t start = (*index).find_first_not_of(" \t");
    if ('[' == (*index).at(start)) {
        std::size_t end = (*index).find("]");
        section = (*index).substr(start + 1, end - 1);
        return true;
    }
    return false;
}

bool Config::Iterator::judge()
{
    if ((*index).length() <= 0 || (*index).at(0) == '#') {
        return false;
    } else {
        return true;
    }
}

int Config::Iterator::erase(std::string& str_src, const std::string& str_d)
{
    int count = 0;
    std::size_t pos = 0;
    std::size_t str_d_size = str_d.size();
    while (std::string::npos != (pos = str_src.find(str_d, 0))) {
        str_src.erase(pos, str_d_size);
        ++count;
    }
    return count;
}

Config::Iterator& Config::Iterator::operator++()
{
    if (index != size) {
        ++index;
        parse();
    }
    return *this;
}

const std::string& Config::Iterator::get_section() const
{
    return section;
}

bool Config::Iterator::loop()
{
    if (index == size) {
        return false;
    }
    std::string normal_data = *index;
    //erase(normal_data, " ");
    //erase(normal_data, "\t");

    std::size_t start = normal_data.find_first_not_of(" \t");
    if ('[' == normal_data.at(start)) {
        std::size_t end = normal_data.find("]");
        section = normal_data.substr(start + 1, end - 1);
        index++;
    }
    return index != size;
}

} // namespace summerconf


