#include <stdio.h>
#include "doctest.h"
#include <stdexcept>
#include <sstream>
#include "iostream"

#include "sources/MagicalContainer.hpp"

using namespace ariel;

// ***************************************//
// Test case for the MagicalContainer     //
// ***************************************//

TEST_CASE("MagicalContainer")
{
    MagicalContainer container;

    SUBCASE("Adding elements to MagicalContainer")
    {
        SUBCASE("Adding a single element")
        {
            container.addElement(10);
            CHECK(container.size() == 1);
        }

        SUBCASE("Adding multiple elements")
        {
            container.addElement(10);
            container.addElement(20);
            container.addElement(30);
            CHECK(container.size() == 3);
        }
    }

    SUBCASE("Removing elements from MagicalContainer")
    {
        SUBCASE("Removing an existing element")
        {
            container.addElement(10);
            container.addElement(20);
            CHECK_NOTHROW(container.removeElement(10));
            CHECK(container.size() == 1);
        }

        SUBCASE("Removing a non-existing element")
        {
            CHECK_THROWS(container.removeElement(10));
            container.addElement(10);
            container.addElement(20);
            CHECK_THROWS_AS(container.removeElement(30), runtime_error);
            CHECK(container.size() == 2);
        }
    }
}

// ***************************************//
// Test case for the AscendingIterator    //
// ***************************************//

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(15);
    container.addElement(25);

    SUBCASE("Iterating over an empty container")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it(emptyContainer);
        CHECK(it == it.begin());
    }

    SUBCASE("Copy constructor")
    {
        MagicalContainer::AscendingIterator it(container);
        MagicalContainer::AscendingIterator copyIt(it);
        CHECK(*copyIt == 10);
        CHECK(it == copyIt);
    }

    SUBCASE("Assignment operator")
    {
        MagicalContainer::AscendingIterator it(container);
        MagicalContainer::AscendingIterator assignedIt;
        assignedIt = it;
        CHECK(*assignedIt == 10);
        CHECK(it == assignedIt);
    }

    SUBCASE("Equality operator")
    {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);

        ++it1;
        CHECK(!(it1 == it2));

        ++it2;
        CHECK(it1 == it2);
    }

    SUBCASE("Iterating over elements")
    {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 20);
        ++(++it);
        CHECK(*it == 30);
        ++it;
        CHECK(it == it.end());

        CHECK_THROWS(++it);
    }

    SUBCASE("Inequality operator")
    {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(!(it1 != it2));

        ++it1;
        CHECK(it1 != it2);

        ++it2;
        CHECK(!(it1 != it2));
    }

    SUBCASE("Pre-increment operator")
    {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*++it == 20);
        CHECK(*++it == 30);
        CHECK(it == it.end());
    }

    SUBCASE("AscendingIterator comparison: < operator")
    {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        CHECK_FALSE(it1 < it1);

        CHECK_FALSE(it1 < ++it2);
        CHECK(++it1 < it2);

        CHECK_FALSE(it1 < it2.end());
        CHECK(it1 < ++it2);
    }
}

// ***************************************//
// Test case for the SideCrossIterator    //
// ***************************************//

TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);

    SUBCASE("Iterating over an empty container")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::SideCrossIterator it(emptyContainer);
        CHECK(it == it.begin());
    }

    SUBCASE("Copy constructor")
    {
        MagicalContainer::SideCrossIterator it(container);
        MagicalContainer::SideCrossIterator copyIt(it);
        CHECK(*copyIt == 10);
        CHECK(it == copyIt);
    }

    SUBCASE("Assignment operator")
    {
        MagicalContainer::SideCrossIterator it(container);
        MagicalContainer::SideCrossIterator assignedIt;
        assignedIt = it;
        CHECK(*assignedIt == 10);
        CHECK(it == assignedIt);
    }

    SUBCASE("Iterating over elements")
    {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 40);
        ++(++it);
        CHECK(*it == 20);
        ++it;
        CHECK(it == it.end());

        CHECK_THROWS(++it);
    }

    SUBCASE("Equality operator")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);

        ++it1;
        CHECK(!(it1 == it2));

        ++it2;
        CHECK(it1 == it2);
    }

    SUBCASE("Inequality operator")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(!(it1 != it2));

        ++it1;
        CHECK(it1 != it2);

        ++it2;
        CHECK(!(it1 != it2));
    }

    SUBCASE("Pre-increment operator")
    {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*++it == 20);
        CHECK(*++it == 30);
        CHECK(it == it.end());
    }

    SUBCASE("SideCrossIterator comparison: < operator")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);

        CHECK_FALSE(it1 < it1);

        CHECK_FALSE(it1 < ++it2);
        CHECK(++it1 < it2);

        CHECK_FALSE(it1 < it2.end());
        CHECK(it1 < ++it2);
    }
}

// ***************************************//
// Test case for the PrimeIterator        //
// ***************************************//

TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Iterating over an empty container")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::PrimeIterator it(emptyContainer);
        CHECK(it == it.begin());
    }

    SUBCASE("Copy constructor")
    {
        MagicalContainer::PrimeIterator it(container);
        MagicalContainer::PrimeIterator copyIt(it);
        CHECK(*copyIt == 2);
        CHECK(it == copyIt);
    }

    SUBCASE("Assignment operator")
    {
        MagicalContainer::PrimeIterator it(container);
        MagicalContainer::PrimeIterator assignedIt;
        assignedIt = it;
        CHECK(*assignedIt == 2);
        CHECK(it == assignedIt);
    }

    SUBCASE("Iterating over elements")
    {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());

        CHECK_THROWS(++it);
    }

    SUBCASE("Equality operator")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);

        ++it1;
        CHECK(!(it1 == it2));

        ++it2;
        CHECK(it1 == it2);
    }

    SUBCASE("Inequality operator")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(!(it1 != it2));

        ++it1;
        CHECK(it1 != it2);

        ++it2;
        CHECK(!(it1 != it2));
    }

    SUBCASE("Dereference operator")
    {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);

        ++(++it);
        CHECK(*it == 5);
    }

    SUBCASE("Pre-increment operator")
    {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*++it == 3);
        CHECK(*++it == 5);
        CHECK(it == it.end());
    }

    SUBCASE("SideCrossIterator comparison: < operator")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);

        CHECK_FALSE(it1 < it1);

        CHECK_FALSE(it1 < ++it2);
        CHECK(++it1 < it2);
        CHECK_FALSE(it1 < it2.end());
        CHECK(it1 < ++it2);
    }

    SUBCASE("SideCrossIterator comparison: > operator")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);

        CHECK_FALSE(it1 > it1);

        CHECK(it2 > ++it1);
        CHECK_FALSE(++it1 > it2);

        CHECK(it2.end() > it1);
        CHECK_FALSE(++it2 > it1);
    }
}