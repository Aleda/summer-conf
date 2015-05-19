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
* @file config.h
* @brief config
* @author Aleda(aledalee@foxmail.com | aleda.cn)
* @version 1.0.0
* @date 2015-04-26
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>

#include "section.h"
#include "value.h"

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&); \
    TypeName& operator=(const TypeName&)

namespace summerconf {

class Config {
public:
    explicit Config(const std::string& conf_file): conf_file(conf_file) {}
    ~Config();
public:
    bool read();
    Section& get(const std::string& section_name);
    Section& operator[](const std::string& section_name);
public:
    const std::vector<Section* >& get_section_list() const {return section_list;}
    const std::string& get_conf_file() const {return conf_file;};
    const std::vector<std::string>& get_data() const {return data;}
protected:
    bool parse();
private:
    bool judge(const std::string& section, 
               const std::string& key,
               const std::string& value);
private:
    std::string conf_file;
    std::vector<std::string> data;
    std::vector<Section* > section_list;
    class Iterator {
    public:
        Iterator(const std::vector<std::string>& data);
        ~Iterator() {};
    public:
        const std::string& get_section() const;
    public:
        bool loop();
        std::string get_key();
        std::string get_value();
        Iterator& operator++();
    private:
        bool parse();
        bool judge();
        int erase(std::string& str_src, const std::string& std_d);
    private:
        std::vector<std::string> data;
        std::string section;
        std::vector<std::string>::iterator index;
        std::vector<std::string>::iterator size;
    };
    DISALLOW_COPY_AND_ASSIGN(Config);
};

} // namespace summerconf

#endif

