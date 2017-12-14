#ifndef TEST_FCNS_H
#define TEST_FCNS_H

#include "token.h"
#include "binary_fcns.h"
#include "doubles.h"
#include "unary_fcns.h"
#include "variable.h"
#include "special.h"
#include "stack.h"
#include "queue.h"
#include "shunting_yard.h"
#include "rpn.h"
#include "animate.h"

void print_queue(queue<token*> a);
void test_stack();
void test_queue();
void test_tokenizer();
void test_shunting_yard();
void test_rpn();
void test_graph();

#endif // TEST_FCNS_H
