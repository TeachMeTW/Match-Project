g++ -std=gnu++11 -o report  ../report.cpp   ../data/data.cpp ../match/match.cpp   -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest
g++ -std=gnu++11 -o match_test ../test/match_test.cpp  ../data/data.cpp ../match/match.cpp        -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest



