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
* @file value.cpp
* @brief value
* @author Aleda(aledalee@foxmail.com | aleda.cn)
* @version 1.0.0
* @date 2015-04-26
*/

#include <string.h>
#include <string>
#include <stdlib.h>

#include "value.h"

namespace summerconf {

int Value::int_value() const
{
    return atoi(data.c_str());
}

std::string Value::string_value() const
{
    return data;
}

std::vector<std::string> Value::string_value_list() const
{
    std::string data_temp = data;
    std::vector<std::string> ans_list;
    ans_list.clear();
    std::size_t pos;
    // space split
    std::string delim = ",";
    while (std::string::npos != (pos = data_temp.find(delim))) {
        ans_list.push_back(data_temp.substr(0, pos));
        data_temp.erase(0, pos + delim.length());
    }
    ans_list.push_back(data_temp);
    return ans_list;
}

} // namespace summerconf

