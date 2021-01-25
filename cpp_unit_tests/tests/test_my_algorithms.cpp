/*
** EPITECH PROJECT, 2021
** day06
** File description:
** test_my_cat
*/

#include "test_redirect.hpp"
#include "../MyAlgorithms.hpp"

static void mult2(int& i)
{
    i *= 2;
}

static bool isGreaterThan(int a, int b)
{
    return a > b;
}

Test(how_many, test_how_many, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    std::list<int> list;
    list.push_back(15);
    list.push_back(27);
    list.push_back(40);
    list.push_back(15);
    list.push_back(46);

    std::cout << vHowMany(list, 15) << std::endl;
    cr_assert_eq(oss.getContent(), "2\n");
}

Test(isSimilar, test_is_similar, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    std::list<int> list;
    list.push_back(15);
    list.push_back(27);
    list.push_back(40);
    list.push_back(15);
    list.push_back(46);

    int tab[] = { 15, 27, 40, 15, 46};

    std::cout << vIsSimilar(list, tab) << std::endl;
    cr_assert_eq(oss.getContent(), "1\n");
}

Test(vAssing, test_assign, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 1};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));

    vAssign(list.begin(), list.begin() + 2, 0);
    cr_assert(list[0] == 0);
    cr_assert(list[1] == 0);
    cr_assert(list[2] == 1);
}

Test(vApply, test_apply, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 1};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));

    vApply(list.begin(), list.begin() + 2, &mult2);
    cr_assert(list[0] == 8);
    cr_assert(list[1] == 18);
    cr_assert(list[2] == 1);
}

Test(vGiveMeTheFirst, test_give_me_first, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 1};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    std::vector<int>::iterator it;

    it = vGiveMeTheFirst(list, 1);
    cr_assert(list[2] == *it);
}

Test(vFlip, test_flip, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 1};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));

    vFlip(list);
    cr_assert(list[0] == 1);
    cr_assert(list[1] == 1);
    cr_assert(list[2] == 9);
    cr_assert(list[3] == 4);
}

Test(vRemoveDuplicate, test_remove_duplicate, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 1};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    std::vector<int>::iterator it = vRemoveDuplicate(list);
    list.resize(it - list.begin());

    cr_assert(list[0] == 4);
    cr_assert(list[1] == 9);
    cr_assert(list[2] == 1);
}

Test(vToAscOrder, test_asc_order, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    vToAscOrder(list);

    cr_assert(list[0] == 1);
    cr_assert(list[1] == 4);
    cr_assert(list[2] == 5);
    cr_assert(list[3] == 9);
}

Test(vToSpecificOrder, test_spec_order, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    vToSpecificOrder(list, &isGreaterThan);

    cr_assert(list[0] == 9);
    cr_assert(list[1] == 5);
    cr_assert(list[2] == 4);
    cr_assert(list[3] == 1);
}

Test(vShift, test_shift, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    vShift(list, 2);

    cr_assert(list[0] == 1);
    cr_assert(list[1] == 5);
    cr_assert(list[2] == 4);
    cr_assert(list[3] == 9);
}

Test(vFindAndModify, test_find_and_modify, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    vFindAndModify(list, 1, 0);

    cr_assert(list[0] == 4);
    cr_assert(list[1] == 9);
    cr_assert(list[2] == 0);
    cr_assert(list[3] == 5);
}

Test(vFindAndKill, test_find_and_kill, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    std::vector<int>::iterator it;
    it = vFindAndKill(list, 1);
    list.resize(it - list.begin());

    cr_assert(list[0] == 4);
    cr_assert(list[1] == 9);
    cr_assert(list[2] == 5);
}

Test(vFusionOrderedLists, test_fusion_list, .init=redirect_stdout) {
    OSRedirector oss(std::cout);

    int tab[] = { 4, 9, 1, 5};
    int tab2[] = { 0, 3, 7, 9};

    std::vector<int> list(tab, tab + sizeof(tab) / sizeof(*tab));
    std::vector<int> list2(tab2, tab2 + sizeof(tab2) / sizeof(*tab2));
    std::vector<int>::iterator it;

    it = vFindAndKill(list, 1);
    list.resize(it - list.begin());

    cr_assert(list[0] == 4);
    cr_assert(list[1] == 9);
    cr_assert(list[2] == 5);
}