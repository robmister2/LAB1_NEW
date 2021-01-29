cmake_minimum_required(VERSION 3.17)
project(LAB1_NEW)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB1_NEW main.cpp Automaton.cpp Automaton.h Lexer.cpp Lexer.h MatcherAutomaton.cpp MatcherAutomaton.h Token.cpp Token.h IDAutomaton.cpp IDAutomaton.h CommentAutomaton.cpp CommentAutomaton.h StringAutomaton.cpp StringAutomaton.h)

file(COPY 1-70 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 1-90 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY 1-100 DESTINATION ${CMAKE_BINARY_DIR})