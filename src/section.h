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
* @file section.h
* @brief section
* @author Aleda(aledalee@foxmail.com | aleda.cn)
* @version 1.0.0
* @date 2015-04-26
*/

#ifndef SECTION_H_
#define SECTION_H_

#include <string>
#include <map>

#include "value.h"

namespace summerconf {

class Section {
public:
    Section() {}
    Section(const std::string& section_name, 
            std::map<std::string, Value*> item_map): 
    section_name(section_name),
    item_map(item_map) {}
    ~Section() {}
public:
    //std::map<std::string, Value*>& get();
    const Value* operator[](const std::string& key);
public:
    const std::string& get_section_name() const {return section_name;}
    const std::map<std::string, Value*>& get_item_map() const{return item_map;}
private:
    std::string section_name;
    std::map<std::string, Value*> item_map;
};

} // namesapce summerconf

#endif

