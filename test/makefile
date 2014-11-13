bison -d -o sql.cpp sql.y
flex -o sqlf.cpp sql.l
c++ -w -o sql sql.cpp sqlf.cpp sqltree.cpp buffer.cpp catalog.cpp error.cpp record.cpp storage.cpp tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp
./sql