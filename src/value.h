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
* @file value.h
* @brief value
* @author Aleda(aledalee@foxmail.com | aleda.cn)
* @version 1.0.0
* @date 2015-04-26
*/

#ifndef VALUE_H_
#define VALUE_H_

#include <string>
#include <vector>

namespace summerconf {

class Value {
public:
    Value(const std::string& data): data(data) {}
    ~Value() {};
public:
    int int_value() const;
    std::string string_value() const;
    std::vector<std::string> string_value_list() const;
public:
    const std::string& get_data() const {return data;}
private:
    std::string data;
};

} // namespace summerconf

#endif

