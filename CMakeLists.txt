cmake_minimum_required(VERSION 3.17)
project(LAB1_NEW)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB1_NEW main.cpp Automaton.cpp Automaton.h Lexer.cpp Lexer.h MatcherAutomaton.cpp MatcherAutomaton.h Token.cpp Token.h IDAutomaton.cpp IDAutomaton.h CommentAutomaton.cpp CommentAutomaton.h StringAutomaton.cpp StringAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Expression.cpp Expression.h PlainParameter.cpp PlainParameter.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h Database.cpp Database.h Interpreter.cpp Interpreter.h)

file(COPY 1-70 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 1-90 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 1-100 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 2-80 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 2-100 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 3-80 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 3-100 DESTINATION ${CMAKE_BINARY_DIR})