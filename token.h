#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "queue.h"

class token {
protected:
    std::string _data;
    std::string _type;
    int _precedence;
    virtual std::string what_type() const;
    virtual int precedence() const;
public:
    token();
    token(std::string data, std::string type);
    std::string get_token_type() const {return _type;}
    std::string get_data() const {return _data;}
    int get_precedence() const {return _precedence;}
    static queue<token*> tokenize(std::string input);
};

#endif // TOKEN_H
