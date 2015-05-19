# summer-conf
--------------------------------------------------

### What is the summer-conf ?
==================================================
Summer-conf is a program developing by C++ and 
can read configure easily.    
The confiure style likes that:
    # main section
    [main]
    name = aleda
    age  = 13
    # other section
    [other]
    codename = aleda
    nickname = aleda
    array    = 1, 2, 3, 4
and you can read the element through these steps:
    1. summerconf::Config conf = summerconf::Config('test.conf');    
    2. int num_value = conf["main"]["age"]->int_value();    
    3. std::string string_value = conf["main"]["name"]->string_value();    
    4. std::vector<std::string> string_arr = conf["other"]["array"]->string_value_list();    
and you should note these:
    1. if section dose not find, secion_name that value was "__INTER_MARK__" will return;
    2. if value dose not find, value that was "__NOT_FOUND__" will return;
more details, you should see test/summerconf_test.cpp.    

### How to use it ?
==================================================
    1. make clean
    2. make ar
    or you will just:
    make output
    more details, see makefile;

### Any qustion?
==================================================
    Please contact with Aleda[aleda.cn | aledalee@foxmail].    
