#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::MagicalContainer()
{
}

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

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer mgcContainer)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
{
}

MagicalContainer::AscendingIterator::~AscendingIterator()
{
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator&(const AscendingIterator &iter)
{
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &iter) const
{
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &iter) const
{
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &iter) const
{
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &iter) const
{
}

int MagicalContainer::AscendingIterator::operator*()
{
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
{
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
}

// ***************************************//
// SideCrossIterator                      //
// ***************************************//

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer mgcContainer)
{
}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
{

}

MagicalContainer::SideCrossIterator::~SideCrossIterator()
{
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator&(const SideCrossIterator &iter)
{

}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &iter) const
{

}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &iter) const
{

}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &iter) const
{

}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &iter) const
{

}

int MagicalContainer::SideCrossIterator::operator*()
{

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
{

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{

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

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer mgcContainer)
{
}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
{
}

MagicalContainer::PrimeIterator::~PrimeIterator()
{
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator&(const PrimeIterator &iter)
{
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &iter) const
{
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &iter) const
{
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &iter) const
{
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &iter) const
{
}

int MagicalContainer::PrimeIterator::operator*()
{
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
{
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
}
