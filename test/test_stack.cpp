#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> s(3));
}

TEST(Stack, cant_create_stack_with_too_large_size)
{
  ASSERT_ANY_THROW(Stack<int> s(MAX_VECTOR_SIZE + 1));
}

TEST(Stack, cant_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(Stack<int> s(-3));
}

TEST(Stack, can_get_size)
{
    Stack<int> s(3);

    EXPECT_EQ(3, s.size());
}

TEST(Stack, can_get_top)
{
    Stack<int> s(3);
    s[0] = 1; s[1] = 2; s[2] = 3;

    EXPECT_EQ(3, s.top());
}

TEST(Stack, cant_get_top_of_empty_stack)
{
    Stack<int> s(0);

    ASSERT_ANY_THROW(s.top());
}

TEST(Stack, can_push_element)
{
    Stack<int> s(3);
    s[0] = 1; s[1] = 2; s[2] = 3;

    ASSERT_NO_THROW(s.push(5));
}

TEST(Stack, cant_push_element_when_stack_is_full)
{
    Stack<int> s(MAX_VECTOR_SIZE);

    ASSERT_ANY_THROW(s.push(5));
}

TEST(Stack, can_pop_element)
{
    Stack<int> s(3);
    s[0] = 1; s[1] = 2; s[2] = 3;
    
    ASSERT_NO_THROW(s.pop());
}

TEST(Stack, cant_pop_element_when_stack_is_empty)
{
    Stack<int> s(0);

    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, stack_is_empty)
{
    Stack<int> s(0);

    EXPECT_EQ(true, s.empty());
}

TEST(Stack, stack_is_not_empty)
{
    Stack<int> s(3);

    EXPECT_EQ(false, s.empty());
}

TEST(Stack, stack_is_full)
{
    Stack<int> s(3);
    s[0] = 1; s[1] = 2; s[2] = 3;
    s.push(4);

    EXPECT_EQ(true, s.full());
}

TEST(Stack, stack_is_not_full)
{
    Stack<int> s(4);
    s[0] = 1; s[1] = 2; s[2] = 3; s[3] = 4;
    s.push(5);

    EXPECT_EQ(false, s.full());
}