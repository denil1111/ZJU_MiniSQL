bison -d -o sql.cpp sql.y
flex -o sqlf.cpp sql.l
c++ -w -o sql sql.cpp sqlf.cpp sqltree.cpp
./sql