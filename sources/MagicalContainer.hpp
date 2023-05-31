#include <stdio.h>
#include <vector>
namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> mContainer;

    public:
        MagicalContainer();

        void addElement(int element);
        void removeElement(int element);
        int size();

        class AscendingIterator
        {
        public:
            AscendingIterator() = default;
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(MagicalContainer mgcContainer);
            ~AscendingIterator();
            AscendingIterator operator&(const AscendingIterator &iter);
            bool operator==(const AscendingIterator &iter)const;
            bool operator!=(const AscendingIterator &iter) const;
            bool operator<(const AscendingIterator &iter) const;
            bool operator>(const AscendingIterator &iter) const;
            int operator*();
            AscendingIterator operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        public:
            SideCrossIterator() = default;
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(MagicalContainer mgcContainer);
            ~SideCrossIterator();
            SideCrossIterator operator&(const SideCrossIterator &iter);
            bool operator==(const SideCrossIterator &iter) const;
            bool operator!=(const SideCrossIterator &iter) const;
            bool operator<(const SideCrossIterator &iter) const;
            bool operator>(const SideCrossIterator &iter) const;
            int operator*();
            SideCrossIterator operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        public:
            PrimeIterator() = default;
            PrimeIterator(MagicalContainer mgcContainer);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
            PrimeIterator operator&(const PrimeIterator &iter);
            bool operator==(const PrimeIterator &iter) const;
            bool operator!=(const PrimeIterator &iter) const;
            bool operator<(const PrimeIterator &iter) const;
            bool operator>(const PrimeIterator &iter) const;
            int operator*();
            PrimeIterator operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };

}
