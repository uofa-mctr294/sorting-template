#include "sort.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <random>
#include <numeric>
#include <vector>

// Verify at least 5 sorts are enabled (3 required + 2 optional)
static constexpr int ENABLED_SORTS = 3
#if defined(ENABLE_SELECTION_SORT) || defined(ENABLE_INSERTION_SORT)
                                     + 1
#endif
#ifdef ENABLE_MERGE_SORT
                                     + 1
#endif
#ifdef ENABLE_BUCKET_SORT
                                     + 1
#endif
#ifdef ENABLE_COUNTING_SORT
                                     + 1
#endif
#ifdef ENABLE_RADIX_SORT
                                     + 1
#endif
    ;

static_assert(ENABLED_SORTS >= 4, "At least 4 sorts must be enabled (3 required + 1 optional)");

using SortFn = std::function<void(std::vector<int> &)>;

static std::vector<std::pair<std::string, SortFn>> getSorts()
{
    std::vector<std::pair<std::string, SortFn>> sorts = {
        {"Bubble", [](std::vector<int> &v)
         { bubbleSort(v); }},
#ifdef ENABLE_SELECTION_SORT
        {"Selection", [](std::vector<int> &v)
         { selectionSort(v); }},
#endif
        {"Quick", [](std::vector<int> &v)
         { quickSort(v); }},
#ifdef ENABLE_INSERTION_SORT
        {"Insertion", [](std::vector<int> &v)
         { insertionSort(v); }},
#endif
#ifdef ENABLE_MERGE_SORT
        {"Merge", [](std::vector<int> &v)
         { mergeSort(v); }},
#endif
#ifdef ENABLE_BUCKET_SORT
        {"Bucket", [](std::vector<int> &v)
         { bucketSort(v); }},
#endif
#ifdef ENABLE_COUNTING_SORT
        {"Counting", [](std::vector<int> &v)
         { countingSort(v); }},
#endif
#ifdef ENABLE_RADIX_SORT
        {"Radix", [](std::vector<int> &v)
         { radixSort(v); }},
#endif
    };
    return sorts;
}

static std::vector<int> makeRandom(std::size_t n, unsigned seed)
{
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(-10000, 10000);
    std::vector<int> data(n);
    for (std::size_t i = 0; i < n; ++i)
    {
        data[i] = dist(rng);
    }
    return data;
}

static void expectSortedMatchesStd(const std::vector<int> &input, const std::string &sortName, const SortFn &fn)
{
    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    std::vector<int> actual = input;
    fn(actual);

    EXPECT_EQ(actual, expected) << sortName << " failed to sort correctly";
}

TEST(SortAlgorithms, RandomData)
{
    auto sorts = getSorts();
    const std::vector<std::size_t> sizes = {0, 1, 2, 5, 50, 200};

    unsigned seed = 42;
    for (std::size_t n : sizes)
    {
        std::vector<int> data = makeRandom(n, seed++);
        for (const auto &entry : sorts)
        {
            SCOPED_TRACE("Testing " + entry.first + " with size " + std::to_string(n));
            expectSortedMatchesStd(data, entry.first, entry.second);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
