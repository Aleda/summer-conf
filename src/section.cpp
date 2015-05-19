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
* @file section.cpp
* @brief section
* @author Aleda(aledalee@foxmail.com | aleda.cn)
* @version 1.0.0
* @date 2015-04-26
*/

#include <iostream>
#include <string>
#include <map>

#include "value.h"
#include "section.h"

namespace summerconf {

const Value* Section::operator[](const std::string& key)
{
    if (item_map.find(key) != item_map.end()) {
        return item_map[key];
    } else {
        return item_map["__NOT_FOUND__"];
    }
}

} // namespace summerconf

