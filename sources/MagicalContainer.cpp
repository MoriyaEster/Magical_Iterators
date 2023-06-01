#include "MagicalContainer.hpp"
using namespace ariel;

// ***************************************//
// MagicalContainer                       //
// ***************************************//

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int element)
{
    mContainer.emplace_back(element);
}

void MagicalContainer::removeElement(int element)
{
    for (auto it = mContainer.begin(); it != mContainer.end(); ++it)
    {
        if (*it == element)
        {
            mContainer.erase(it);
            break;
        }
    }
}

int MagicalContainer::size()
{
    return mContainer.size();
}

// ***************************************//
// AscendingIterator                      //
// ***************************************//
MagicalContainer::AscendingIterator::AscendingIterator()
    : container(nullptr), index(0)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : container(other.container), index(other.index)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other)
    : container(&other), index(0)
{
}

MagicalContainer::AscendingIterator::~AscendingIterator()
{
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return (container == other.container) && (index == other.index);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return (container == other.container) && (index > other.index);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return (container == other.container) && (index < other.index);
}

int MagicalContainer::AscendingIterator::operator*()
{
    return container->mContainer[index];
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
{
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(*container);
    iter.index = container->mContainer.size();
    return iter;
}

// ***************************************//
// SideCrossIterator                      //
// ***************************************//

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0)
{
}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : container(other.container), index(other.index)
{
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &other)
    : container(&other), index(0)
{
}

MagicalContainer::SideCrossIterator::~SideCrossIterator()
{
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return (container == other.container) && (index == other.index);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return ! (*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return (container == other.container) && (index < other.index);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return (container == other.container) && (index > other.index);
}

int MagicalContainer::SideCrossIterator::operator*()
{
    return container->mContainer[index];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
{
    ++index;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(*container);
    iter.index = container->mContainer.size();
    return iter;
}

// ***************************************//
// PrimeIterator                          //
// ***************************************//

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), index(0)
{
}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : container(other.container), index(other.index)
{
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &other)
    : container(&other), index(0)
{
}

MagicalContainer::PrimeIterator::~PrimeIterator()
{
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        container = other.container;
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return (container == other.container) && (index == other.index);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return ! (*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return (container == other.container) && (index < other.index);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return (container == other.container) && (index > other.index);
}

int MagicalContainer::PrimeIterator::operator*()
{
    return container->mContainer[index];
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
{
    ++index;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator iter(*container);
    iter.index = container->mContainer.size();
    return iter;
}
