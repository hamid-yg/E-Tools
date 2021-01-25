/*
** EPITECH PROJECT, 2021
** day02m
** File description:
** test_redirect
*/

#ifndef TEST_REDIRECT_H
#define TEST_REDIRECT_H

#include <ostream>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <list>
#include <vector>

void redirect_stdout(void);

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;

    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

#endif /* !TEST_REDIRECT_H */